/* name - 18
 author : Tathagata Das
 Write a program to find out total number of directories on the pwd.
    execute ls -l | grep ^d | wc ? Use only dup2.
Date - 20th sept 2024

   
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main()
{
    int pipefd[2], pipefd2[2];
    pid_t cid, cid2;

    if (pipe(pipefd) == -1)
    {
        printf("ERROR");
    }
    if (pipe(pipefd2) == -1)
    {
        printf("ERROR");
    }
    else
    {
        cid = fork();
        if (cid == 0)
        {
            cid2 = fork();
            if (cid2 == 0)
            {
                close(pipefd[0]);   
                close(pipefd[1]);  
                close(pipefd2[1]); \

                // closing stdin
                close(0);

                // reassigning stdin to pipe reading end;
                // dup2 will reassign pipefd2[0] to 0 as it avalible.so now pipefd2[0] will act as STDIN
                dup2(pipefd2[0], 0);
                execl("/usr/bin/wc", "wc", NULL);
            }
            else
            {
                close(pipefd[1]);  
                close(pipefd2[0]); 

                
                close(0);
                // reassigning stdin to pipe reading end;
                // dup2 will reassign pipefd[0] to 0 as it avalible.so now pipefd[0] will act as STDIN
                dup2(pipefd[0], 0);

                
                close(1);
                // reassigning stdout to pipe writing end
                // dup2 will reassign pipefd2[1] to 1(STDOUT) as it is avalible fd. so now pipefd2[1] will act as STDOUT
                dup2(pipefd2[1], 1);
                execl("/usr/bin/grep", "grep ^d", "^d", NULL);
            }
        }
        else
        {
            close(pipefd2[0]); 
            close(pipefd2[1]); 
            close(pipefd[0]);  

            close(1); 
            dup2(pipefd[1], 1); 

            execl("/usr/bin/ls", "ls -l", "-l", NULL);
        }
    }
}
