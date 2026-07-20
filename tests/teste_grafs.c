#include "kernel/types.h"
#include "user/user.h"

/**
 * Programa de teste para coleta de métricas no XV6.
 * Este programa mede o Turnaround Time (tempo total) de cada processo.
 */

void
work(char *name, int priority, int start_tick)
{
    setpriority(priority);

    volatile int i, j;
    for(i = 0; i < 10000; i++) {
        for(j = 0; j < 10000; j++) {
        }
    }

    int end_tick = uptime();
    int turnaround = end_tick - start_tick;

    printf("METRICA: Processo %s | Prioridade: %d | Inicio: %d | Fim: %d | Turnaround: %d ticks\n", 
           name, priority, start_tick, end_tick, turnaround);

    exit(0);
}

int
main(void)
{
    int pid;
    int start_all = uptime();

    printf("Iniciando teste de escalonamento para coleta de graficos...\n");

    // Processo A - Baixa Prioridade
    pid = fork();
    if(pid == 0){
        work("A", 15, start_all);
    }

    // Processo B - Prioridade Media
    pid = fork();
    if(pid == 0){
        work("B", 10, start_all);
    }

    // Processo C - Alta Prioridade
    pid = fork();
    if(pid == 0){
        work("C", 5, start_all);
    }

    // Processo D - Prioridade Maxima
    pid = fork();
    if(pid == 0){
        work("D", 1, start_all);
    }

    for(int i = 0; i < 4; i++) {
        wait(0);
    }

    int end_all = uptime();
    printf("\nTeste finalizado. Tempo total de execucao: %d ticks\n", end_all - start_all);
    
    exit(0);
}
