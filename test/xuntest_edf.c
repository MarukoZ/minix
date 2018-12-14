#include <unistd.h>
#include <stdio.h>
#define Num_of_Threads 3
#define Length_of_proc 3
#define Proc_step 5
static int count = 0;
static char start_char = 'A';
static int end_place[Num_of_Threads];
void print_self(char a)
{
    int iter = 0;
    int i = 0;
    for (iter = 0; iter < 10; iter++)
    {
        printf("This is process %c printing.\n", a);
        for (i = 0; i < 100000000; i++)
        {
            count++;
        }
    
    }
    

    end_place[a - start_char] = count;
}

int main()
{
    pid_t fpid;
    char test = start_char;
    int i = 0;
    int time_limit = Length_of_proc;
    for (i = 0; i < Num_of_Threads; i++)
    {
        fpid = fork();
        if (fpid < 0)
            printf("error in fork!");
        else if (fpid == 0)
        {
            chrt(-1, time_limit);
            print_self(test);
            break;
        }
        else
        {
            test++;
            time_limit = time_limit - Proc_step;
        }
    }
    return 0;
}
