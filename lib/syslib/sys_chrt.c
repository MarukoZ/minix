#include "syslib.h"

PUBLIC int sys_chrt(sched_type)
int sched_type;
{
    message copy_mess;
    copy_mess.m2_i1 = sched_type;
    return (_taskcall(SYSTASK, SYS_CHRT, &copy_mess));
}
