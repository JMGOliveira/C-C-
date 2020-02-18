# include <stdio.h>
# include <stdlib.h>
# include <iostream>

using namespace std;

char op2 = 0;
int a = 0, c = 0, fil = 0, assen = 0, f = 20, l = 40;
int lugares[100][100];

void reservar(){
	
cout << "Selecione um assento vago.\n";
        while (a < f){
            for(c = 0;c < l;c++){
                if(lugares[c][a] == 0){
                	cout << "Fileira " << a + 1 <<" assento " << c + 1 <<" esta livre.\n";
                }   
            }
            a++;
        }
cout << "Selecione a fileira.\n";
cin >> fil;
cout << "Selecione o assento\n";
cin >> assen;
    
    fil = fil - 1;
    assen = assen - 1;
    
    lugares[assen][fil] = 1;
cout << "O assento " << assen + 1 << " da fileira " << fil + 1 << " esta agora reservado.\n";
    a = 0;
}

void devolver(){
	cout << "Selecione um assento reservado.\n";
        while (a < f){
            for(c = 0;c < l;c++){
                if(lugares[c][a] != 0){
                	cout << "Fileira " << a + 1 << " assento " << c + 1 << " esta ocupada.\n";
                }   
            }
            a++;
        }
        cout << "Selecione a fileira.\n";
        cin >> fil;
        cout << "Selecione o assento.\n";
        cin >> assen;
    
    fil = fil - 1;
    assen = assen - 1;
    
    lugares[assen][fil] = 0;
    cout << "O assento " << assen + 1 << " da fleira " << fil + 1 << " esta agora vago.\n";
    a = 0;
}

int main(){

char op1;
	cout << "Este programa tem como base um estabelecimento com 20 fileiras e\n40 assentos em cada uma delas.\nDeseja fazer uma alteracao?\nS-Sim\nN-Nao\n";  
    op1 = getchar();
    
        if((op1 == 's') || (op1 == 'S')){
        	cout << "Informe a quantidade de fileiras.\n";
        	cin >> f;
        	cout << "Informe a quantidade de assentos\n";
        	cin >> l;
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
		cout <<  "Informe a operacao desejada.\n1-Comprar ingresso.\n2-Devolver ingresso.\n3-Trocar de lugar.\n0-Sair.\n";   
		cin >> op2;
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
                cout << "Selecione agora um assento vago.\n";
                reservar();
                break;
            
                case '0':
                return(0);
            }
    }
}
