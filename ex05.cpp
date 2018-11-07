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
    // CriaÃ§Ã£o da lista
    return NULL;
}

bool isEmpty(Lista* list)
{
	return list == NULL;
}

void imprimirInicioFim(Lista* list)
{
	cout << "Imprimindo lista" << endl << endl;
	Lista* inicio = list;
    // e percorre a lista enquanto o elemento atual nÃ£o for nulo
    Lista* aux = inicio;
    do {
        cout << aux->info << endl;
        aux = aux->prox;
    } while (aux != inicio);
    cout << endl;
}

Lista* inserir(Lista* list, int valor)
{
	// Alocando memoria para o novo iten
	Lista* novo = new Lista;
	novo->info = valor;
	cout << "-----------------------" << endl;
	cout << "Inserindo novo valor: " << novo->info << endl;
	
	// Casos
	if(list == NULL)
	{
		// Caso 1 lista vazia 
		novo->prox = novo;
		novo->ant = novo;
		
		cout << "Lista vazia. Criando novo elemento." << endl;
	}
	else if(valor < list->info)
	{
		// Caso 2 valor do novo->info menor que o list->info
		
		novo->prox = list;
		novo->prox->ant = novo;

		Lista* aux = list;
		while(aux->prox != list)
		{
			aux = aux->prox;
		}
		novo->ant = aux;
		novo->ant->prox = novo;
		
		cout << "Caso de elemento menor no inicio." << endl;
	}
	else
	{
		// Caso 3 - valores iniciais maiores que o valor
		
		Lista* aux = list;
		while(aux->prox != list && aux->prox->info < valor)
		{
			aux = aux->prox;
			//cout << "valor do aux atual: " << aux->info << endl;
		}
		novo->prox = aux->prox;
		//cout << "valor do aux->prox->info: " << aux->prox->info << endl;
		novo->prox->ant = novo;
		novo->ant = aux;
		novo->ant->prox = novo;
		//cout << "valor novo->ant->info: " << novo->ant->info << endl;
		

		
		aux = novo;
		while(aux->info >= aux->prox->info)
		{
			aux = aux->prox;
			//cout << "Valor atual do aux: " << aux->info << endl;
		}
		//cout << "imprimindo lista aux:" << endl;

		//imprimirInicioFim(aux);
		
		novo = aux;
		//imprimirInicioFim(novo);
		//cout << novo->info << endl;
		//cout << novo->ant->info << endl;
		//cout << novo->ant->ant->info << endl;
		
		
		cout << "Caso do elemento maior no inicio" << endl;
	}
	imprimirInicioFim(novo);
	return novo;
}

int main(int argc, char** argv)
{
	Lista* ml = criar();
	
	ml = inserir(ml, 5);	
	ml = inserir(ml, 4);	
	ml = inserir(ml, 3);	
	ml = inserir(ml, 7);	
	ml = inserir(ml, 7);	
	ml = inserir(ml, 2);
	
	return 0;
}
