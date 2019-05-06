#include <iostream>
#include"Fila_Encadeada.h"
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

using namespace std;

int GeraRandom(){
     int Random = rand()% 10 + 1;
    return Random;
}

void ExibeFila(struct Node<int> *aux){
    if(aux != NULL){
        cout<<aux->info<<" ";
        ExibeFila(aux->prox);
    }
}

int NumeroDeElementos(struct Node<int> *aux){
    int cont = 0;
    while(aux != NULL){
        cont ++;
        aux = aux->prox;
    }
    return cont;
}

int main()
{
    Fila<int>F = Fila<int>();
    srand(time(NULL));

    int senha = 0;
    int TempoDeExecucao;

    cout<<"Defina o tempo total de execucao (em segundos): ";
    cin>>TempoDeExecucao;

    for(int i = 0;i<=TempoDeExecucao;i++){
        system("CLS");
        cout<<"\nTempo total decorrido: "<<i<<endl;
        cout<<"Situacao da Fila:"<<endl;
        if(F.FilaVazia()){
            cout<<"Nao ha ninguem na fila"<<endl;
        }
        else{
            cout<<"Sendo atendido: ";
            cout<<F.Inicio->info<<endl;

            cout<<"Situacao da fila toda: ";
            ExibeFila(F.Inicio);
        }
        //checagem para ver se alguem entra na fila
        if(GeraRandom()>5){
            F.Adiciona(senha);
            if(senha == 0){
                senha = 1;
            }
            else{
                senha++;
            }
        }
        //checagem para saber se o atendimento do momento acabou e iniciar o proximo
        if((!F.FilaVazia()) && GeraRandom()<=5){
            F.Remove();
        }
        //Se o programa terminar
        if(i == TempoDeExecucao){
            system("CLS");
            cout<<"Tempo total decorrido: "<<TempoDeExecucao<<endl;
            cout<<"Numero de pessoas atendidas: "<< senha - NumeroDeElementos(F.Inicio)<<endl;
            if(!F.FilaVazia())
                cout<<"Numero de pessoas nao atendidas: "<<NumeroDeElementos(F.Inicio)<<endl;

            cout<<"Aperte qualquer tecla para sair"<<endl;
            getch();
            break;
        }
        Sleep(1000);
    }

    return 0;
}
