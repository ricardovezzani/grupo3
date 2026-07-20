#include "kernel/types.h"
#include "user/user.h"

void
work(char *name, int priority)
{
    setpriority(priority);

    // Imprime uma mensagem única por processo
    printf("Processo %s com prioridade %d executou primeiro\n", name, priority);

    exit(0);
}

int
main(void)
{
    int pid;

    pid = fork();
    if(pid == 0){
        work("A", 10);
    }

    pid = fork();
    if(pid == 0){
        work("B", 5);
    }

    pid = fork();
    if(pid == 0){
        work("C", 1);
    }

    wait(0);
    wait(0);
    wait(0);

    printf("Teste de escalonamento finalizado\n");
    exit(0);
}