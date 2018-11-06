#include <iostream>

using namespace std;

typedef struct No
{
    int info;
    struct No* ant;
    struct No* prox;
} Lista;

Lista* criar()
{
    // Criação da lista
    return NULL;
}

bool isEmpty(Lista* list)
{
	return list == NULL;
}

Lista* inserir(Lista* list, int valor)
{
	// Alocando memória para o novo íten
	Lista* novo = new Lista;
	novo->info = valor;

	cout << "Novo valor: " << novo->info << endl;
	
	if(list == NULL)
	{
		// A lista está vazia
		// Apontamentos do próximo e anterior para o único elemento
		novo->prox = novo;
		novo->ant = novo;
	}
	else
	{
		// A lista não está vazia
		// Comparando o valor da lista com o novo valor para ordenação
		// Lista auxiliar para percorrer			
		Lista* aux = list;
		
		// percorrendo e comparando até achar um valor maior ou o final da lista
	 	while(novo->info < aux->info || aux->prox == list)
		{
			 aux = aux->prox;
		}
		// ajustando o valor do novo->prox
		novo->prox = aux->prox;
		novo->ant = aux;
		aux->prox = novo;
		novo->prox->prox = novo;
		
		// acrescentando elemento onde parou
		
		
		
	}
	
	return novo;
}

int main(int argc, char** argv)
{
	Lista* ml = criar();
	
	cout << "Vazia? " << isEmpty(ml) << endl;
	
	ml = inserir(ml, 5);
	
	cout << "e agora, Vazia? " << isEmpty(ml) << endl;
	
	cout << "fazendo teste para inserir mais um valor na lista" << endl;
	
	ml = inserir (ml, 1)
	
	
	return 0;
}
