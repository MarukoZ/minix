#include <lib.h>
#define chrt _chrt
#include <unistd.h>

PUBLIC int chrt(sched_type)
int sched_type;
{
    message m;
    m.m2_i1 = sched_type;
    return (_syscall(MM, CHRT, &m));
}
