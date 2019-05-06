#ifndef FILA_ENCADEADA_H_INCLUDED
#define FILA_ENCADEADA_H_INCLUDED
template<typename Tipo>
struct Node{
    Tipo info;
    Node<Tipo> *prox;
};

template<typename Tipo>
struct Fila{
    Node<Tipo> *Inicio;
    Node<Tipo> *Fim;

    //Construtores e Deletores

    Fila(){
        Inicio = NULL;
        Fim = NULL;
    }

    ~Fila(){
        while(!FilaVazia()){
            Remove();
        }
    }

    //Metodos

    void Adiciona(Tipo valor){
        Node<Tipo> *aux = new Node<Tipo>;
        aux->info = valor;
        aux->prox = NULL;
        if(FilaVazia()){
            Inicio = aux;
        }
        else{
            Fim->prox = aux;
        }
        Fim = aux;
    }

    Tipo Remove(){
        Node<Tipo> *aux = Inicio;
        Tipo auxInfo = Inicio->info;
        Inicio = Inicio->prox;
        delete aux;
        return auxInfo;
    }

    bool FilaVazia(){
        return Inicio == NULL;
    }

};


#endif // FILA_ENCADEADA_H_INCLUDED
