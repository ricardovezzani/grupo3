# GBC045 – Sistemas Operacionais | Projeto Final - Tema 3

**Tema:** Priority Scheduling com syscall `setpriority(int)`

## Integrantes do Grupo
* Arthur Fernandes de Sousa - 12411BCC097
* Erik Alves Scagliarini - 12411BCC060
* Gustavo Ferreira Maia - 12411BCC094
* João Pedro de Moraes e Menezes - 12421BCC087
* Ricardo Garcia Fernandes Vezzani - 12411BCC052

## Estrutura do Repositório
Este repositório contém todas as entregas do projeto final da disciplina de Sistemas Operacionais, divididas em duas etapas complementares:

* **`slides/`**: Slides da apresentação e motivação do projeto (Entregue na Etapa 1).
* **`video/`**: Vídeo de apresentação (Entregue na Etapa 1).
* **`code/`**: Códigos-fonte dos arquivos modificados no kernel xv6.
* **`tests/`**: Programas criados para testar a syscall e avaliar métricas.
* **`report/`**: Relatório.

---

## Etapa 1 – Fundamentação (Entregue em 09/06/2026)

A primeira etapa focou na apresentação teórica do trabalho.

1. Slides com detalhes do projeto 
2. Vídeo de apresentação
3. README com nomes dos integrantes e descrição das etapas entregues.

Conteúdo abordado no vídeo:
1. Apresentação do grupo e tema escolhido
2. Motivação: por que o escalonamento por prioridade é importante?
3. Funcionamento do Priority Scheduling
4. Explicação da syscall setpriority(int)
5. Proposta de implementação no xv6 (arquivos a modificar)

---

## Etapa 2 – Implementação Prática (Entregue em 20/07/2026)

A segunda etapa consiste na implementação prática do escalonamento por prioridade no sistema operacional xv6, alterando a estrutura de dados dos processos, implementando a syscall `setpriority(int)` e modificando o escalonador original.

### Roteiro de Reprodução

Para compilar e testar as modificações implementadas, siga os passos abaixo:

1. **Pré-requisitos:** É necessário ter o ambiente xv6-riscv configurado com as ferramentas de compilação e o emulador QEMU instalados.
2. **Integração dos Arquivos:** Copie os arquivos presentes na pasta `code/` para o diretório raiz do xv6, substituindo os arquivos originais.
   * Os arquivos modificados incluem: `proc.c`, `proc.h`, `syscall.c`, `syscall.h`, `sysproc.c`, `defs.h`, `user.h`, `usys.pl` e o `Makefile`.
3. **Compilação:** Execute o comando `make` na raiz do projeto xv6 para compilar o kernel atualizado e os programas de teste.
4. **Execução dos Testes:** Inicie o sistema operacional com `make qemu`. Dentro do shell do xv6, execute os programas localizados na pasta `tests/`:
   * `priotest`: Teste básico da syscall `setpriority()`.
   * `teste`: Demonstração simples do escalonamento com três processos de diferentes prioridades.
   * `teste_grafs` e `teste_rr`: Testes experimentais para coleta de métricas e comparação com o Round Robin original.
5. **Análise dos Resultados:** Os resultados detalhados, métricas coletadas, gráficos e a análise comparativa estão documentados no arquivo PDF presente na pasta `report/`.

---

## Referências

1. xv6: a simple, Unix-like teaching operating system — https://pdos.csail.mit.edu/6.1810/2024/xv6/book-riscv-rev4.pdf
2. Repositório oficial xv6-riscv — https://github.com/mit-pdos/xv6-riscv
3. Silberschatz, A.; Galvin, P. B.; Gagne, G. Operating System Concepts, 10ª ed.
4. Tanenbaum, A. S. Modern Operating Systems, 4ª ed.
5. https://dev.to/zanfranceschi/conceito-round-robin-183
