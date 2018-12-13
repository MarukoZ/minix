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

#if USE_CHRT

/*===========================================================================*
 *				do_chrt					     *
 *===========================================================================*/
PUBLIC int do_chrt(m_ptr) register message *m_ptr; /* pointer to request message */
{
  int o, n;
  o = sched_type;
  n = m_ptr->m2_i1;
  kprintf("changing scheduling type \nfrom: %d \nto:%d\n", o, n);
  sched_type=n%3;
  return (OK);
}
#endif /* USE_CHRT */
