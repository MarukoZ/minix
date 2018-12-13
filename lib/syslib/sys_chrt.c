#include "syslib.h"

PUBLIC int sys_chrt(proc_ep, sched_type, deadline)
endpoint_t proc_ep;
int sched_type;
long deadline;
{
    message copy_mess;
    copy_mess.m2_i2 = proc_ep;
    copy_mess.m2_i1 = sched_type;
    copy_mess.m2_l1 = deadline;
    return (_taskcall(SYSTASK, SYS_CHRT, &copy_mess));
}
