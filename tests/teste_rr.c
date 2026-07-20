#include "kernel/types.h"
#include "user/user.h"

void
work(char *name, int start_tick)
{
    volatile int i, j;
    for(i = 0; i < 10000; i++) {
        for(j = 0; j < 10000; j++) {
        }
    }

    int end_tick = uptime();
    int turnaround = end_tick - start_tick;

    printf("METRICA RR: Processo %s | Inicio: %d | Fim: %d | Turnaround: %d ticks\n", 
           name, start_tick, end_tick, turnaround);

    exit(0);
}

int
main(void)
{
    int pid;
    int start_all = uptime();

    printf("Iniciando teste de Round Robin...\n");

    pid = fork();
    if(pid == 0) work("A", start_all);

    pid = fork();
    if(pid == 0) work("B", start_all);

    pid = fork();
    if(pid == 0) work("C", start_all);

    pid = fork();
    if(pid == 0) work("D", start_all);

    for(int i = 0; i < 4; i++) {
        wait(0);
    }

    int end_all = uptime();
    printf("\nTeste Round Robin finalizado. Tempo total: %d ticks\n", end_all - start_all);
    
    exit(0);
}
