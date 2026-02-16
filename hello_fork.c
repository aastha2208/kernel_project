#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() 
{
    pid_t id = fork();
    if (id < 0) 
        printf("Fork Failed!\n"); 
    else if (id == 0) 
        printf("Hello! I am the Child Process. My ID is %d\n", getpid()); 
    else 
        printf("Hello! I am the Parent Process. My Child's ID is %d\n", id);
    return 0;
}