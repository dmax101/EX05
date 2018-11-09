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

bool isHere(Lista* list, int value) {
	bool here;
	
	Lista* inicio = list;
	Lista* aux = inicio;
	do {
		here = aux->info == value;
		aux = aux->prox;
	} while(aux != inicio);
	
	return here;
}

void imprimirInicioFim(Lista* list)
{
	if (isEmpty(list))
	{
		cout << "Lista vazia" << endl;
		return;
	};
	cout << "Imprimindo lista do inicio ao fim" << endl << endl;
	Lista* inicio = list;
    // e percorre a lista enquanto o elemento atual nÃ£o for nulo
    Lista* aux = inicio;
    do {
        cout << aux->info << endl;
        aux = aux->prox;
    } while (aux != inicio);
    cout << endl;
    
    return;
}

void imprimirFimInicio(Lista* list)
{
	if (isEmpty(list))
	{
		cout << "Lista vazia" << endl;
		return;
	};
	cout << "Imprimindo lista do fim ao inicio" << endl << endl;
	Lista* inicio = list;
    // e percorre a lista enquanto o elemento atual nÃ£o for nulo
    Lista* aux = inicio;
    aux = aux->ant;
    do {
        cout << aux->info << endl;
        aux = aux->ant;
    } while (aux != inicio);
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
		}
		cout << endl;
		
		novo->prox = aux->prox;
		novo->prox->ant = novo;
		novo->ant = aux;
		novo->ant->prox = novo;

		cout << "Caso do elemento maior no inicio" << endl;
		
		return list;
	}
	
	return novo;
}

Lista* remover(Lista* list, int valor)
{
	if(list == NULL)
	{
		// Caso 1 - Lista vazia
		
		cout << "Nada para remover!" << endl;
		
		return list;
	}
	else if(valor == list->info)
	{
		list->prox->ant = list->ant;
		list->ant->prox = list->prox;
		
		return list->prox;
	}
	else if(isHere(list, valor))
	{
		cout << "Elemento nao encontrado" << endl;
		return list;
	}
	else
	{
		Lista* aux = list;
		while(aux->prox != list && aux->prox->info != valor)
		{
			aux = aux->prox;
			//cout << aux->info << endl;
		}
		aux = aux->prox;
		aux->prox->ant = aux->ant;
		aux->ant->prox = aux->prox;
	
		while(aux->prox != list)
		{
			aux = aux->prox;
		}
		
		return aux->prox;
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
			inserir(l, valor);
			break;
		case 2:
			// 2. Remover elemento da lista
			cout << "Insira o valor do elemento a ser removido: ";
			cin >> valor;
			remover(l, valor);
			break;
		case 3:
			// 3. Verificar se um elemento está na lista
			cout << "Pesquisar elemento: ";
			cin >> valor;
			if(isHere(l, valor))
			{
				cout << "O elemento esta na lista" << endl;
			}
			else
			{
				cout << "O elemento NAO esta na lista"<< endl;
			};
			break;
		case 4:
			// 4. Verificar se a lista está vazia
			if(isEmpty(l))
			{
				cout << "A lista esta vazia" << endl;
			}
			else
			{
				cout << "A lista NAO esta vazia"<< endl;
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
			cout << "Tchau!" << endl;
			sair = true;
			// 7. Sair
			break;
		default:
			cout << "Opcao invalida!" << endl;
			// Opcao invalida
			
			break;
		}
	}
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
	ml = inserir(ml, 5);
	ml = inserir(ml, 8);
	ml = inserir(ml, 3);
	ml = inserir(ml, 10);
	imprimirInicioFim(ml);
	imprimirFimInicio(ml);
	
	cout << "10 esta presente? " << isHere(ml, 1) << endl;
	
	ml = remover(ml, 7);
	ml = remover(ml, 5);
	ml = remover(ml, 8);
	ml = remover(ml, 10);
	imprimirInicioFim(ml);
	
	menu();
	
	return 0;
}
