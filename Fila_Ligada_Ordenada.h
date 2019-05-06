#ifndef FILA_LIGADA_ORDENADA_H_INCLUDED
#define FILA_LIGADA_ORDENADA_H_INCLUDED

template<typename Tipo>
struct Node
{
    Tipo info;
    Node<Tipo> *prox;
};

template <typename Tipo>
struct ListaOrdenada
{
    Node<Tipo> *L;
    ListaOrdenada()
    {
        L = NULL;
    }

    bool listavazia()
    {
        return L==NULL;
    }

    bool insere(Tipo x)
    {
        bool v = false;
        Node<Tipo> *aux = new Node<Tipo>;
        if(aux != NULL)
        {
            v = true;
            aux->info = x;
            if(L == NULL || x < L->info)
            {
                aux->prox = L;
                L=aux;
            }
            else
            {
                Node<Tipo> *aux2 = L;
                while(aux2->prox != NULL && aux2->prox->info < x)
                {
                    aux2=aux2->prox;
                }
                aux->prox = aux2->prox;
                aux2->prox = aux;
            }
        }
        return v;
    }

    bool Remove(Tipo valor){
        bool v = false;
        Node<Tipo> *atual = L;
        Node<Tipo> *anterior = NULL;
        while(atual != NULL){
            if(atual->info == valor){
                if(anterior == NULL){
                    L = atual->prox;
                    delete atual;
                    return v = true;
                }
                else{
                    anterior->prox = atual->prox;
                    delete atual;
                    return v = true;
                }
            }
            else if(atual->info > valor){
                return v = false;
            }
            else{
                anterior = atual;
                atual = atual->prox;
            }
        }
    }
};


#endif // FILA_LIGADA_ORDENADA_H_INCLUDED
