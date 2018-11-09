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

bool isHere(Lista* list, int value)
{
	if(isEmpty(list))
	{
		cout << "-----------------------" << endl;
		cout << "Lista vazia" << endl;
		cout << "-----------------------" << endl;

		return false;
	}
	else
	{
		Lista* inicio = list;
		Lista* aux = inicio;
		do
		{
			if (aux->info == value)
				return true;
			aux = aux->prox;
		}
		while (aux != inicio);
		return false;
	}

}

void imprimirInicioFim(Lista* list)
{
	if (isEmpty(list))
	{
		cout << "-----------------------" << endl;
		cout << "Lista vazia" << endl;
		cout << "-----------------------" << endl;
		return;
	};
	cout << "-----------------------" << endl;
	cout << "Imprimindo lista do inicio ao fim" << endl;
	cout << "-----------------------" << endl;

	Lista* inicio = list;
	// e percorre a lista enquanto o elemento atual nÃ£o for nulo
	Lista* aux = inicio;
	cout << "-----------------------" << endl;
	do
	{
		cout << aux->info << endl;
		aux = aux->prox;
	}
	while (aux != inicio);
	cout << "-----------------------" << endl;
	cout << endl;

	return;
}

void imprimirFimInicio(Lista* list)
{
	if (isEmpty(list))
	{
		cout << "-----------------------" << endl;
		cout << "Lista vazia" << endl;
		cout << "-----------------------" << endl;
		return;
	};
	cout << "-----------------------" << endl;
	cout << "Imprimindo lista do fim ao inicio" << endl;
	cout << "-----------------------" << endl;
	Lista* inicio = list;
	// e percorre a lista enquanto o elemento atual nÃ£o for nulo
	Lista* aux = inicio;
	aux = aux->ant;
	do
	{
		cout << aux->info << endl;
		aux = aux->ant;
	}
	while (aux != inicio->ant);
	cout << "-----------------------" << endl;
	cout << endl;

	return;
}

Lista* inserir(Lista* list, int valor)
{
	// Alocando memoria para o novo item
	Lista* novo = new Lista;
	novo->info = valor;
	cout << "-----------------------" << endl;
	cout << "Inserindo novo valor: " << novo->info << endl;
	cout << "-----------------------" << endl;
	// Casos
	if(list == NULL)
	{
		// Caso 1 lista vazia

		novo->prox = novo;
		novo->ant = novo;

		cout << "-----------------------" << endl;
		cout << "Lista vazia. Criando novo elemento." << endl;
		cout << "-----------------------" << endl;
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

		cout << "-----------------------" << endl;
		cout << "Caso de elemento menor no inicio." << endl;
		cout << "-----------------------" << endl;
	}
	else
	{
		// Caso 3 - valores iniciais maiores que o valor

		Lista* aux = list;

		while(aux->prox != list && aux->prox->info < valor)
		{
			aux = aux->prox;
		}
		cout << endl;

		novo->prox = aux->prox;
		novo->prox->ant = novo;
		novo->ant = aux;
		novo->ant->prox = novo;

		cout << "-----------------------" << endl;
		cout << "Caso do elemento maior no inicio" << endl;
		cout << "-----------------------" << endl;

		return list;
	}

	return novo;
}

Lista* remover(Lista* list, int valor)
{
	if (list == NULL)
	{
		cout << "-----------------------" << endl;
		cout << "Lista Vazia! Nada para remover" << endl;
		cout << "-----------------------" << endl;
		return NULL;
	}

	else if (list->info == valor)
	{

		if (list->prox == list)
		{
			cout << "-----------------------" << endl;
			cout << "Elemento Removido com Sucesso!" << endl;
			cout << "-----------------------" << endl;
			delete list;
			return NULL;
		}

		else
		{

			Lista* aux = list;
			while (aux->prox != list)
				aux = aux->prox;

			aux->prox = list->prox;

			delete list;
			cout << "-----------------------" << endl;
			cout << "Elemento Removido com Sucesso!" << endl;
			cout << "-----------------------" << endl;

			return aux->prox;
		}
	}

	else
	{
		Lista* inicio = list;
		Lista* atual = list;
		Lista* anterior = NULL;


		do
		{
			anterior = atual;
			atual = atual->prox;
			if(atual->info == valor)
			{
				cout << "-----------------------" << endl;
				cout << "Elemento Removido com Sucesso!" << endl;
				cout << "-----------------------" << endl;
			}
			else if(atual == inicio)
			{
				cout << "-----------------------" << endl;
				cout << "Elemento NAO encontrado!" << endl;
				cout << "-----------------------" << endl;
			}
		}
		while (atual != inicio && atual->info != valor);

		if (atual != inicio)
		{
			anterior->prox = atual->prox;
			delete atual;
		}



		return list;
	}
}

void menu()
{
	bool sair = false;
	int opcao;
	int valor;

	cout << "--------------" << endl;
	cout << "Uma lista nula foi criada!" << endl;
	cout << "--------------" << endl;

	Lista* l = criar();

	while(!sair)
	{
		cout << "--------------" << endl;
		cout << "MENU" << endl;
		cout << "1. Inserir novo elemento para lista" << endl;
		cout << "2. Remover elemento da lista" << endl;
		cout << "3. Verificar se um elemento esta na lista" << endl;
		cout << "4. Verificar se a lista esta vazia" << endl;
		cout << "5. Imprimir do inicio ao fim" << endl;
		cout << "6. Imprimir do fim ao inicio" << endl;
		cout << "7. Sair" << endl;
		cout << "Entre com a opcao desejada: ";
		cin >> opcao;
		switch(opcao)
		{
		case 1:
			// 1. Inserir novo elemento para lista
			cout << "Insira o valor do novo elemento: ";
			cin >> valor;
			l = inserir(l, valor);
			break;
		case 2:
			// 2. Remover elemento da lista
			cout << "Insira o valor do elemento a ser removido: ";
			cin >> valor;
			l = remover(l, valor);
			break;
		case 3:
			// 3. Verificar se um elemento está na lista
			cout << "Pesquisar elemento: ";
			cin >> valor;
			if(isHere(l, valor))
			{
				cout << "--------------" << endl;
				cout << "O elemento esta na lista" << endl;
				cout << "--------------" << endl;
			}
			else
			{
				cout << "--------------" << endl;
				cout << "O elemento NAO esta na lista" << endl;
				cout << "--------------" << endl;
			};
			break;
		case 4:
			// 4. Verificar se a lista está vazia
			if(isEmpty(l))
			{
				cout << "--------------" << endl;
				cout << "A lista esta vazia" << endl;
				cout << "--------------" << endl;
			}
			else
			{
				cout << "--------------" << endl;
				cout << "A lista NAO esta vazia" << endl;
				cout << "--------------" << endl;
			};
			break;
		case 5:
			// 5. Imprimir do inicio ao fim
			imprimirInicioFim(l);
			break;
		case 6:
			// 6. Imprimir do fim ao inicio
			imprimirFimInicio(l);
			break;
		case 7:
			cout << "--------------" << endl;
			cout << "Tchau!" << endl;
			cout << "--------------" << endl;
			sair = true;
			// 7. Sair
			break;
		default:
			// Opcao invalida
			cout << "--------------" << endl;
			cout << "Opcao invalida!" << endl;
			cout << "--------------" << endl;

			break;
		}
	}
}

int main(int argc, char** argv)
{

	menu();

	return 0;
}
