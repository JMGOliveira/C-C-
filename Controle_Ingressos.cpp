# include <stdio.h>
# include <stdlib.h>

char op2 = 0;
int a = 0, c = 0, fil = 0, assen = 0, f = 20, l = 40;
int lugares[100][100];

void reservar(){
    printf("Selecione um assento vago.\n");
        while (a < f){
            for(c = 0;c < l;c++){
                if(lugares[c][a] == 0){
                    printf("Fileira %d assento %d esta livre.\n", a + 1, c + 1);
                }   
            }
            a++;
        }
    printf("Selecione a fileira.\n");
    scanf("%d", &fil);
    printf("Selecione o assento.\n");
    scanf("%d", &assen);
    
    fil = fil - 1;
    assen = assen - 1;
    
    lugares[assen][fil] = 1;
    printf("O assento %d da fileira %d esta agora reservado.\n", assen + 1, fil + 1);
    a = 0;
}

void devolver(){
	printf("Selecione um assento reservado.\n");
        while (a < f){
            for(c = 0;c < l;c++){
                if(lugares[c][a] != 0){
                    printf("Fileira %d assento %d esta ocupada.\n", a + 1, c + 1);
                }   
            }
            a++;
        }
    printf("Selecione a fileira.\n");
    scanf("%d", &fil);
    printf("Selecione o assento.\n");
    scanf("%d", &assen);
    
    fil = fil - 1;
    assen = assen - 1;
    
    lugares[assen][fil] = 0;
    printf("O assento %d da fileira %d esta agora vago.\n", assen + 1, fil + 1);
    a = 0;
}

int main(){

char op1;

    printf("Este programa tem como base um estabelecimento com 20 fileiras e\n40 assentos em cada uma delas.\nDeseja fazer uma alteracao?\nS-Sim\nN-Nao\n");
    op1 = getchar();
    
        if((op1 == 's') || (op1 == 'S')){
            printf("Informe a quantidade de fileiras.\n");
            scanf("%d", &f);
            printf("Informe a quantidade de assentos.\n");
            scanf("%d", &l);
        }
system("cls");
        while (a < f){
            for(c = 0;c < l;c++){
                lugares[c][a] = 0;
            }
            a++;
        }
    a = 0;
    
    while(op2 != '0'){    
        printf("Informe a operacao desejada.\n1-Comprar ingresso.\n2-Devolver ingresso.\n3-Trocar de lugar.\n0-Sair.\n");
        scanf("%s", &op2);
system("cls");
            switch(op2){
                case '1':
                reservar();
                break;
                
                case '2':
                devolver();
                break;
                
                case '3':
                devolver();
                printf("Selecione agora um assento vago.\n");
                reservar();
                break;
            
                case '0':
                return(0);
            }
    }
}
