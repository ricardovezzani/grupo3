//arquivo para testes

#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
    printf("Teste da syscall setpriority\n");

    // Define a prioridade do processo atual
    setpriority(3);

    printf("Prioridade alterada para 3\n");

    exit(0);
}