/* name - 30d
 author : Tathagata Das
.description -  Write a program to create a shared memory.
d.remove the shared memory
Date - 20th sept 2024*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
int main()
{
    key_t key = ftok(".", 2);
    // shared memory created
    int shmid = shmget(key, 1024, IPC_CREAT | 0744);
    // attach shared memory to process adress space
    char *data_pointer;
    data_pointer = shmat(shmid, (void *)0, 0);
    if (data_pointer == (void *)-1)
    {
        perror("Shared memory not attach");
        return 1;
    }
    printf("Shared memory attached press any key to delete shared memory\n");
    getchar();
    printf("Deleting shared memory\n");
    shmctl(key, IPC_RMID, NULL);
    return 1;
}
