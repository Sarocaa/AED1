#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_carros 10
#define tam_placa 8

typedef struct {
    char placa[tam_placa];
} Carro;

typedef struct {
    Carro carros[max_carros];
    int qntd_carros;
} Estacionamento;

int criarEstacionamento (Estacionamento *est)
{
    est->qntd_carros = 0;
    return 1;
}

void push (Estacionamento *estacionamento, Carro carro)
{
    if(estacionamento->qntd_carros==max_carros)
    {
        printf("Estacionamento cheio!\nNão é possível adicionar mais carros.\n\n");
        return;
    }
    else
    {
        estacionamento->carros[estacionamento->qntd_carros] = carro;
        estacionamento->qntd_carros++;
        return;
    }
}

Carro pop(Estacionamento *est)
{
    est->qntd_carros--;
    return est->carros[est->qntd_carros];
}

void removeCarro(Estacionamento *estacionamento, Carro carro)
{
    Estacionamento aux;
    criarEstacionamento(&aux);
    Carro c;
    int i, encontrado=0;
    
    if(estacionamento->qntd_carros==0)
    {
        printf("Estacionamento vazio!\n");
        return;
    }
    else
    {
        i=estacionamento->qntd_carros;
        while(estacionamento->qntd_carros>0)
        {
           c = pop(estacionamento);
           if(strcmp(c.placa, carro.placa)==0) 
           {
                printf("Carro com placa %s removido.\n", carro.placa);
                encontrado=1;
                break;   
           }
           else (push(&aux, c));
        }
        
        while (aux.qntd_carros > 0) 
        {
            push(estacionamento, pop(&aux));
        }
        
        if(encontrado==0) printf("Carro com placa %s não foi encontrado.\n", carro.placa);
    }
}

void exibirEstacionamento (Estacionamento estacionamento)
{
    int i;
    if(estacionamento.qntd_carros==0)
    {
        printf("Estacionamento vazio!\n");
        return;
    }
    else{
        printf("Histórico de carros no estacionamento: \n");
        for(i=estacionamento.qntd_carros-1; i>=0; i--)
        {
            printf("Carro: %s\n", estacionamento.carros[i].placa);
        }
    }
    
}

int main ()
{
    int escolha;
    Carro carro;
    Estacionamento estacionamento;
    criarEstacionamento(&estacionamento);
    
    while(escolha!=4)
    {
        printf("\n--------MENU-------\n");
        printf("Escolha uma opção:\n");
        printf("1- Estacionar carro\n");
        printf("2- Retirar carro\n");
        printf("3- Exibir estacionamento\n");
        printf("4- Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &escolha);
        getchar();
        printf("\n");
        
        switch(escolha) {
            case 1:
                //estacionar carro
                printf("Digite a placa do carro para estacionar: ");
                scanf("%[^\n]", carro.placa);
                printf("\n");
                push(&estacionamento, carro);
                printf("Carro com placa %s estacionado.\n", carro.placa);
                break;
            
            case 2: 
                //retirar carro
                printf("Digite a placa do carro que deseja retirar: ");
                scanf("%[^\n]", carro.placa);
                printf("\n");
                removeCarro(&estacionamento, carro);
                
                break;
            case 3:
                //exibir estacionamento
                exibirEstacionamento(estacionamento);
                break;
        }
    }
    printf("Finalizando programa!\n");
    return 0;
}
