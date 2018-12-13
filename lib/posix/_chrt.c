#include <lib.h>
#define chrt _chrt
#include <unistd.h>

PUBLIC int chrt(sched_type,deadline)
int sched_type;
long deadline;
{
    message m;
    m.m2_i1 = sched_type;
    m.m2_l1 = deadline;
    return (_syscall(MM, CHRT, &m));
}
