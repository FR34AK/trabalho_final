#include <stdio.h>
#include <stdlib.h>

FILE * arq;

int i,vf,tot,aux=0;

struct produtos{
    int cod,qtd;
    char name[20],valor[10];
} cad_prod[10];


int main(int argc, char *argv[]) {      
        
    while(vf != 3){
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\tControle de estoque \n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\tDigite 1 para buscar um produto \n");
        printf("\tDigite 2 para inserir um produto \n");
        printf("\tDigite 3 para sair \n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        scanf("%d",&vf);

        if(vf==3){
           return(0);
        }

        if(vf==1){            
            
            arq = fopen("teste.txt","r");
            
            if(arq == NULL){
                printf("Erro ao abrir o arquivo.\n");
                exit(0);
            }
            
            //for(i=0;i<10;i++){
            fgets(cad_prod[10].name, 10000, arq);
            printf("%s\n",cad_prod[10].name);
           // }
            
            
            fclose(arq);

        }

        if(vf==2){
            
            printf("---------------------------------------------\n");
            arq = fopen("teste.txt", "a+r");
           
            if (arq == NULL){
                printf("Erro ao abrir o arquivo\n");
                exit(0);                
            }else
                printf("Informe a quantidade de produtos que deseja inserir: ");
                    scanf("%i",&tot);
                printf("Inserindo produtos...\n\n");

            //rewind(arq);

            for(i=0;i<tot;i++){
            
            printf("Informe o Nome do produto: ");
                scanf(" %[^\n]s",cad_prod[i].name);
            fprintf(arq, "%s           ", cad_prod[i].name);
            
            printf("Informe o Código do produto: ");
                scanf("%i",&cad_prod[i].cod);
                aux=cad_prod[i].cod;
            fprintf(arq, "%i     ",cad_prod[i].cod);
                                    
            printf("Informe a Quantidade do produto: ");
                scanf("%i",&cad_prod[i].qtd);
            fprintf(arq, "       %d     ", cad_prod[i].qtd);
            
            printf("Informe o Valor do produto: ");
                scanf("%s", cad_prod[i].valor);
            fprintf(arq, "       %s    \n", cad_prod[i].valor);
            
            printf("\n");
            
            }
            
            
            fclose(arq);

        }
    }    
}

