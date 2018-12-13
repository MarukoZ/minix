/* The kernel call implemented in this file:
 *   m_type:	SYS_EXEC
 *
 * The parameters for this kernel call are:
 *    m1_i1:	PR_ENDPT  		(process that did exec call)
 *    m1_p1:	PR_STACK_PTR		(new stack pointer)
 *    m1_p2:	PR_NAME_PTR		(pointer to program name)
 *    m1_p3:	PR_IP_PTR		(new instruction pointer)
 */
#include "../system.h"
#include <signal.h>

#if USE_CHRT

void reach_deadline(timer_t *tp)
{
  printf("Process %d reach deadline\n",tp->tmr_arg.ta_int);
  cause_sig(tp->tmr_arg.ta_int,SIGTERM);
  return;
}

/*===========================================================================*
 *				do_chrt					     *
 *===========================================================================*/
PUBLIC int do_chrt(m_ptr) register message *m_ptr; /* pointer to request message */
{
  int o, n;
  struct proc *rp;
  timer_t *tp;

  n=m_ptr->m2_i1;
  if(n>=0){
    o = sched_type;
    n = (m_ptr->m2_i1)%3;
    kprintf("changing scheduling type \nfrom: %d \nto:%d\n", o, n);
    sched_type = n;
  }

  rp = proc_addr(m_ptr->m2_i2);
  RTS_LOCK_SET(rp, RTS_SYS_LOCK);
  if (rp->p_deadline.tmr_exp_time!=0){
    reset_timer(&rp->p_deadline); 
    rp->p_deadline.tmr_exp_time = 0;
  }
  if (m_ptr->m2_l1!=0){
  	tp = &rp->p_deadline;
  	tp->tmr_arg.ta_int = rp->p_nr;
  	tp->tmr_exp_time = m_ptr->m2_l1*60+get_uptime();
  	tp->tmr_func = reach_deadline; 	
  	printf("Process %d set timer, deadline=%d \n",tp->tmr_arg.ta_int,tp->tmr_exp_time);
  	set_timer(tp,tp->tmr_exp_time,tp->tmr_func);
  }
	RTS_LOCK_UNSET(rp, RTS_SYS_LOCK);
  return(OK);
}


#endif /* USE_CHRT */
