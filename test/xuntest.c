#include <unistd.h>
#include <stdio.h>
#define Num_of_Threads 4
static int count = 0;
static char start_char = 'A';
static int end_place[Num_of_Threads];
void print_self(char a)
{
    int i,j;
    for (i = 0; i < 10000; i++)
    {
        printf("This is process %c printing.\n", a);
        for(j=0;j<100000;j++);
        count++;
    }
    end_place[a - start_char] = count;
}

int main(){
    pid_t fpid;
    char test = start_char;

    int i;
    for (i = 0; i < Num_of_Threads; i++)
    {
        fpid = fork();
        if (fpid < 0)
            printf("error in fork!");
        else if (fpid == 0)
        {
            print_self(test);
            break;
        }
        else
        {
            test++;
        }
    }
    return 0;
}
