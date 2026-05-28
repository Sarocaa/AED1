#include <stdio.h>
#include "aluno.h"
#include "menu.h"

int main()
{
    Aluno alunos[max_alunos];
    int total=0, opcao;
    
    do {
        opcao = menu();
        
        switch(opcao)
        {
            case 0:
                printf("Encerrando o programa...\n");
                break;
            case 1:
                cadastrarAluno(alunos, &total);
                break;
            case 2:
                listarAluno(alunos, total);
                break;
        }
        
    } while (opcao!=0);
    
    return 0;
}
