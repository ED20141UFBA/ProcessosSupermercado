#include "funcoes.h"
int GeraID = 0; // A cada Processo novo sera acrescido um valor, assim o processo tera um ID unico;
float Clock_Insere=0, Clock_Apaga=0, Clock_ApagaID=0, Clock_ExibeTudo=0,Clock_ExibeID=0, Clock_ExibeProximo=0, Clock_ExibeUltimo=0, Clock_ExibeTamanho=0, Clock_LimpaTudo=0, Clock_OrganizaPorNome=0;
// Onde tem Clock eh somente para contabilizar o tempo.


int QuantidadeProcessos;

void Inicializar(Processo *Pilha)	                    //Inicia a pilha
{
	Pilha->prox = NULL;
	QuantidadeProcessos=0;
}

void Menu(Processo *Pilha)                              //Menu e chamada para as funcoes
{

	//clock_t inicio, fim;
	int op;

	while(1)
	{
        system("cls");
        printf("    Selecione a operacao desejada:   \n\n");
        printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c MENU %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c ANALISE %c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
        printf(" %c                                  %c                             %c\n",186,186,186);

        printf(" %c 0 - Inserir novo Processo        %c %c Tempo Execucao: %f  %c\n",186,186,26, ((double)(Clock_Insere)/CLOCKS_PER_SEC),186);
        printf(" %c 1 - Apagar Ultimo Processo       %c %c Tempo Execucao: %f  %c\n",186,186,26, ((double)(Clock_Apaga)/CLOCKS_PER_SEC),186);
        printf(" %c 2 - Apagar um Processo pelo ID   %c %c Tempo Execucao: %f  %c\n",186,186,26, ((double)(Clock_ApagaID)/CLOCKS_PER_SEC),186);
        printf(" %c 3 - Exibir Pilha de Processos    %c %c Tempo Execucao: %f  %c\n",186,186,26, ((double)(Clock_ExibeTudo)/CLOCKS_PER_SEC),186);
        printf(" %c 4 - Exibir por ID                %c %c Tempo Execucao: %f  %c\n",186,186,26, ((double)(Clock_ExibeID)/CLOCKS_PER_SEC),186);
        printf(" %c 5 - Exibir proximo Processo      %c %c Tempo Execucao: %f  %c\n",186,186,26, ((double)(Clock_ExibeProximo)/CLOCKS_PER_SEC),186);
        printf(" %c 6 - Exibir ultimo Processo       %c %c Tempo Execucao: %f  %c\n",186,186,26, ((double)(Clock_ExibeUltimo)/CLOCKS_PER_SEC),186);
        printf(" %c 7 - Tamanho da Pilha             %c %c Tempo Execucao: %f  %c\n",186,186,26, ((double)(Clock_ExibeTamanho)/CLOCKS_PER_SEC),186);
        printf(" %c 8 - Limpar Pilha                 %c %c Tempo Execucao: %f  %c\n",186,186,26, ((double)(Clock_LimpaTudo)/CLOCKS_PER_SEC),186);
        printf(" %c 9 - Organiza por Nome de Mercado %c %c Tempo Execucao: %f  %c\n",186,186,26, ((double)(Clock_OrganizaPorNome)/CLOCKS_PER_SEC),186);

        printf(" %c                                  %c                             %c\n",186,186,186);
        printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
        printf("\n\tOpcao: ");
        fflush(stdin);
        scanf("%d", &op);
        switch(op)
        {
            case 0: // Inserir novo Processo
                {
                    EmpilharProcesso(Pilha);
                    system("Pause");
                    break;
                }
            case 1: // Inserir novo Processo
                {
                    Apagar(Pilha);
                    system("Pause");
                    break;
                }
                case 2: // Apagar Ultimo Processo
                {
                    ApagarID(Pilha);
                    system("Pause");
                    break;
                }
            case 3: // Excluir um Processo pelo ID
                {
                    ExibirProcessos(Pilha);
                    system("Pause");
                    break;
                }
            case 4: // Exibir Pilha um ID selecionado
                {
                    ExibirID(Pilha);
                    system("Pause");
                    break;
                }
            case 5: // Exibir proximo Processo
                {
                    ExibirProximoProcesso(Pilha);
                    system("Pause");
                    break;
                }
            case 6: // Exibir ultimo processo
                {
                    ExibirUltimoProcesso(Pilha);
                    system("Pause");
                    break;
                }
            case 7: // Tamanho da Pilha
                {
                    Clock_ExibeTamanho=clock();
                    printf("A pilha possui %d elementos. \n", QuantidadeProcessos);
                    Clock_ExibeTamanho = clock() - Clock_ExibeTamanho;
                    system("Pause");
                    break;
                }
            case 8: // Zerar Pilha
                {
                    libera(Pilha);
                    Inicializar(Pilha);
                    system("Pause");
                    break;
                }
            case 9: // Organiza por Nome de Mercado
                {
                    OrganizaProcessoPorNomeMercado(Pilha);
                    system("Pause");
                    break;
                }
            default:
                printf("\nComando invalido, por favor escolha uma opcao.\n\n");
                fflush(stdin);
        }
	}
}

void ExibeNo(Processo *No)                              //Chamada so para exibir um No
{
    printf("\n%c ID: %d\n",16, No->ID);
    printf("%cCheque:\n",204);
    printf("%c\tValor do Cheque: R$ %.2f\n",186, No->ValorCheque);
    printf("%c\tData do Cheque:.... %s\n",186, No->DataCheque);
    printf("%c\tNome do Mercado:... %s\n",186, No->NomeMercado);
    printf("%cCliente:\n",204);
    printf("%c\tNome:.............. %s\n",186, No->NomeCliente);
    printf("%c\tRG:................ %s\n",186, No->RGCliente);
    printf("%c\tEndereco:.......... %s\n",186, No->EnderecoCliente);
    printf("%c\tTelefone:.......... %s\n",186, No->TelefoneCliente);
}

int teste_vazia(Processo *Pilha)                        // Testa se a pilha esta vazia. Se o primeiro elemento aponta para NULL quer dizer que a pilha nao tem elementos
{

	if(Pilha->prox == NULL)
		return 1;
	else
		return 0;
}

void ExibirProcessos(Processo *Pilha)                   // Funcao de impressao da pilha
{
    Clock_ExibeTudo=0;
    Clock_ExibeTudo = clock();
	Processo *aux= Pilha->prox;							// Cria um ponteiro aux

	if(teste_vazia(Pilha))								// Verifica se a pilha ta vazia, se a funcao teste_vazia retornar '1', ta vazia
    {
		printf("A pilha esta vazia. \n");
	}
	else												// senao, enquanto aux nao chegar ate o fim da fila (NULL), vai imprimindo cada no.
    {
		while( aux != NULL)
        {
            ExibeNo(aux);
			aux = aux->prox;
		}
	}
	Clock_ExibeTudo = clock() - Clock_ExibeTudo;
}

void ExibirID(Processo *Pilha)                          // Exibe somente o processo com a ID selecionada
{
    Clock_ExibeID=0;
    float Clock_Pause =0;
    Clock_Pause = clock();

	Processo *Pos = Pilha->prox;
    int LocalizarEsteID;

    printf("Informe o ID do Processo que deseja ver: ");
    Clock_Pause = clock() - Clock_Pause;    // Pausa a contagem do tempo para esperar o scanf.
    scanf("%d", &LocalizarEsteID);
    Clock_ExibeID = clock();
    if(Pilha->prox != NULL)
    {
        while(Pos->prox != NULL)            //Percorre a Pilha Principal ate o penultimo elemento, pois qnd o proximo apontar para NULL, nao entrara no while, sera tratado if logo abaixo.
        {
            if(LocalizarEsteID != Pos->ID)      // Se entrar aqui é pq é diferente, entao avanca os nos da Pilha principal.
            {
                Pos = Pos->prox;
            }
            else
            {
                ExibeNo(Pos);
                Clock_ExibeID = clock() - Clock_ExibeID + Clock_Pause;
                return;
            }
        }
        if(LocalizarEsteID == Pos->ID)			// Verifica se o ID para qual Pos aponta é igual ao informado pelo usuario.
        {
            ExibeNo(Pos);
            Clock_ExibeID = clock() - Clock_ExibeID + Clock_Pause;
            return;
        }
    }
    printf("O Processo solicitado nao foi encontrado.\n");
    Clock_ExibeID = clock() -  Clock_ExibeID + Clock_Pause;
}

void ExibirProximoProcesso(Processo *Pilha)             //Exibe o processo no TOPO da Pilha
{
    Clock_ExibeProximo=0;
    Clock_ExibeProximo = clock();
	if(teste_vazia(Pilha))
	{
		printf("A pilha esta vazia. \n");
	}
	else
	{
		Processo *Pos = Pilha->prox;
		while(Pos->prox != NULL)            //Percorre a Pilha Principal ate o ultimo elemento apontar para NULL.
		{
		   Pos = Pos->prox;
		}
		ExibeNo(Pos);
	}
	Clock_ExibeProximo = clock() - Clock_ExibeProximo;
}

void ExibirUltimoProcesso(Processo *Pilha)              //Exibe o processo na BASE da Pilha
{
    Clock_ExibeUltimo=0;
    Clock_ExibeUltimo = clock();
	if(teste_vazia(Pilha))
	{
		printf("A pilha esta vazia. \n");
	}
	else
	{
        ExibeNo(Pilha->prox);
	}
	Clock_ExibeUltimo = clock() - Clock_ExibeUltimo;
}

void libera(Processo *Pilha)                            //Libera todos os espaco alocado da Pilha na memoria
{
    Clock_LimpaTudo=0;
    Clock_LimpaTudo = clock();
	Processo *proxNo,*atual;

	if(!teste_vazia(Pilha))     //Verifica se a Pilha ta vazia
    {

		atual = Pilha->prox;
		while(atual != NULL)    //Atual corre a pilha e libera cada no alocado
        {
			proxNo = atual->prox;

			free(atual);
			atual = proxNo;     //atual recebe o proximo no e o laco continua se repetindo ate que a pilha seja apagada
		}
	}
    Clock_LimpaTudo = clock() - Clock_LimpaTudo;
}

void EmpilharProcesso(Processo *Pilha)                  //Inserir procesos na pilha
{
    Clock_Insere=0;
    float Clock_Pause=0;
    Clock_Pause = clock();

	Processo *novo=(Processo*) malloc(sizeof(Processo));		//Cria um novo no da estrutura na memoria e o ponteiro 'novo' ponta para esse no
	Processo *UltimoElemento= NULL;

	if(novo == NULL){											// Se o ponteiro novo apontar para NULL e nao pra nova estrutura, significa que nao tem mais memoria no computador e o programa termina
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else														// Se tiver memoria o usuario ira inserir os dados nesse novo no 'novo'.
	{
		novo->ID = ++GeraID;
        Clock_Pause = clock() - Clock_Pause;    				// Pausa a contagem do tempo para esperar o scanf.
        fflush(stdin);
        printf("Valor do Cheque: ");
        scanf("%f", &novo->ValorCheque);
        printf("Data do Cheque: ");
        fflush(stdin);
        scanf("\n\r%[^\n]", &novo->DataCheque);
        printf("Nome do Estabelecimento: ");
        scanf("\n\r%[^\n]", &novo->NomeMercado);
        printf("Nome do Cliente: ");
        scanf("\n\r%[^\n]", &novo->NomeCliente);
        printf("RG do Cliente: ");
        scanf("\n\r%[^\n]", &novo->RGCliente);
        printf("Endereco do Cliente: ");
        scanf("\n\r%[^\n]", &novo->EnderecoCliente);
        printf("Telefone do Cliente: ");
        scanf("\n\r%[^\n]", &novo->TelefoneCliente);

        Clock_Insere = clock();
		novo->prox = NULL;

		if(teste_vazia(Pilha))
			Pilha->prox= novo;									//Se a pilha estiver vazia 'novo' sera o primeiro no da pilha
		else
		{

		   UltimoElemento= Pilha->prox;							// aponta pro primeiro elemento

			while(UltimoElemento->prox != NULL)					// UltimoElemento percorre toda a pilha ate achar o ultimo elemento
			{
				UltimoElemento = UltimoElemento->prox;
			}

			UltimoElemento->prox = novo;						// O no da pilha (onde UltimoElemento ta apontando) vai apontar para o novo no (e este passara a ser o ultimo).

			OrganizarUltimoProcesso(Pilha);						// A pilha eh enviada para a funcao 'OrganizarUltimoProcesso' que vai pegar o ultimo no (o que acabamos de inserir na pilha) e organizar de acordo ao valor do cheque
		}

		QuantidadeProcessos++;									// Incrementa a quantidade de processos.
	}
	Clock_Insere = clock() - Clock_Insere + Clock_Pause;
}

void OrganizarUltimoProcesso(Processo *Pilha)           //Funcao que pega o ultimo No da Pilha e organiza no meio da Pilha de acordo ao valor do Cheque
{
	Processo *UltimoElemento = Pilha;		//Guardar o ultimo Elemento para verificar se ele eh menor que os anteriores
	Processo *PenultimoElemento = Pilha;	//Se UltimoElemento for menor, PenultimoElemento vai apontar para NULL, ja que UltimoElemento nao estara mais no topo da pilha
	Processo *Ant = Pilha->prox;			//Se ultimoElemento estiver entre Ant e Pos, Ant vai apontar pra UltimoElemento
	Processo *Pos = Pilha->prox;			//Se ultimoElemento estiver entre Ant e Pos, UltimoElemento vai apontar pra Pos;
	int ComecaAnt =0;				        //Serve para forcar PenultimoElemento ficar um no atras de UltimoElemento, tem a mesma relacao com Ant e Pos;

	while(UltimoElemento->prox != NULL) 						//acha o ultimo elemento da pilha e Penultimo Elemento e guarda esses valores;
	{
		UltimoElemento = UltimoElemento->prox;
		if(ComecaAnt>0) 										// Forca Ant ficar um no atras de Pos, PenultimoElemento so vai comecar a percorrer a partir do segundo loop do while.
		{
			PenultimoElemento = PenultimoElemento->prox;
		}
		ComecaAnt++;
	}
	if(Pilha->prox->ValorCheque > UltimoElemento->ValorCheque)	// Verifica se o UltimoElemento eh menor que o primeiro da Pilha. Aqui so trata esse caso, do segundo em diante eh tratado no else.
	{

		UltimoElemento->prox = Pilha->prox;
		Pilha->prox = UltimoElemento;
		PenultimoElemento->prox = NULL; 						//Transforma PenultimoElemento em Ultimo Elemento da Pilha;
	}
	else
	{
		ComecaAnt =0;
		Ant = Pilha->prox;
		while((Pos->prox != NULL) && (Pos->ValorCheque <= UltimoElemento->ValorCheque) )	// Enquanto nao chegar no final da pilha e o valor do novo cheque for maior entra nesse laço;
		{																					// Nesse while ele pode sair ou por ter chegado no final da pilha ou pq o cheque do UltimoElemento é maior
			Pos = Pos->prox;
			if(ComecaAnt>0) // Forca Ant ficar um no atras de Pos
			{

				Ant = Ant->prox;
			}
			ComecaAnt++;
		}
		if(Pos->ValorCheque > UltimoElemento->ValorCheque)		//Se saiu do while anterior por causa da tamanho do cheque, entao ele ira inserir o valor no intervalo (meio da pilha) correto e transformar o PenultimoElemento no ultimo no da pilha;
		{
			PenultimoElemento->prox = NULL;
			UltimoElemento->prox = Pos;
			Ant->prox = UltimoElemento;
		}
	}
}

void OrganizaProcessoPorNomeMercado(Processo *Pilha)    //Verifica os processos de um mercado para organizar no TOPO da Pilha
{
    Clock_OrganizaPorNome=0;
    float Clock_Pause=0;
    Clock_Pause = clock();

    char Mercado [31];
	Processo *PilhaAux=(Processo*) malloc(sizeof(Processo));	//Cria um novo no da estrutura na memoria e o ponteiro 'PilhaAux' ponta para esse no
	if(PilhaAux == NULL)
    {
		printf("Sem memoria disponivel!\n");
		exit(1);
	}

	PilhaAux->prox = NULL;
	Processo *Pos = Pilha->prox;
	Processo *Ant = Pilha;
	Processo *CorrePilhaAux = PilhaAux;
    Processo *NovoElementoAux = NULL;

    printf("Informe o nome do Estabelecimento para reordenar no topo: ");
    Clock_Pause = clock() - Clock_Pause;    // Pausa a contagem do tempo para esperar o scanf.
    scanf("%s",&Mercado);
    Clock_OrganizaPorNome = clock();

    if(!teste_vazia(Pilha))
    {
        while(Pos->prox != NULL)            //Percorre a Pilha Principal ate o ultimo elemento apontar para NULL.
        {
            if(stricmp(Mercado,Pos->NomeMercado) != 0)      // Se entrar no if eh pq o nome do mercado pesquisado e o nome para qual Pos aponta sao diferentes, entao Ant e Pos avanca nos nOs da Pilha principal.
            {
                Ant = Ant->prox;
                Pos = Pos->prox;
            }
            else                            //Entrando aqui os nomes sao iguais, entao ele ira passar esse no para a pilhaaux e vai retirar da Pilha Principal.
            {
                NovoElementoAux = Pos;
                if(Pos->prox != NULL)           //Verifica se o proximo aponta para NULL para avanca com Pos e Ant;
                {
                    Pos = Pos->prox;
                    Ant->prox = Pos;
                }
                CorrePilhaAux = PilhaAux;
                while(CorrePilhaAux->prox != NULL)
                    CorrePilhaAux = CorrePilhaAux->prox;
                CorrePilhaAux->prox = NovoElementoAux;
                NovoElementoAux->prox = NULL;
            }
        }

        if(stricmp(Mercado,Pos->NomeMercado) == 0)      //Esse if so verifica o ultimo elemento da Pilha principal, pois nao da pra tratar no id acima.
        {
            while(CorrePilhaAux->prox != NULL)			//Se o ultimo for igual, este no passara para a Pilha Aux.
                CorrePilhaAux = CorrePilhaAux->prox;
            CorrePilhaAux->prox = Pos;
            Ant->prox = PilhaAux->prox;         		//Ao final, o ultimo elementos que sobrarou da Pilha Principal(ou o ponteiro, caso nao tenha sobrado nenhum) apontara para o primeiro da da PilhaAux, A pilha principal esta completa e organizada.
        }
        else											//Vai entrar aqui o ultimo elemento nao for igual, nao entrando no if logo acima.
        {
            Pos->prox = PilhaAux->prox;         		//Ao final, o ultimo elementos que sobrarou da Pilha Principal(ou o ponteiro, caso nao tenha sobrado nenhum) apontara para o primeiro da da PilhaAux, A pilha principal esta completa e organizada.
        }
    }
    else
        printf("Pilha de Processos vazia!\n");
    Clock_OrganizaPorNome = clock() - Clock_OrganizaPorNome + Clock_Pause;
}

void ApagarID(Processo *Pilha)                          //Apaga um processo com o ID informado.
{
    Clock_ApagaID=0;
    float Clock_Pause=0;
    Clock_Pause = clock();

	Processo *Pos = Pilha->prox;
	Processo *Ant = Pilha;
	Processo *LiberaNo = Pilha;
    int ApagarEsteID;

    printf("Informe o ID do Processo que deseja excluir da Pilha: ");
    Clock_Pause = clock() - Clock_Pause;    // Pausa a contagem do tempo para esperar o scanf.
    scanf("%d", &ApagarEsteID);
    Clock_ApagaID = clock();
    if(Pilha->prox != NULL)
    {
        while(Pos->prox != NULL)            //Percorre a Pilha Principal ate o ultimo elemento apontar para NULL. Ou seja, ele compara ate o penultimo item,
        {
            if(ApagarEsteID != Pos->ID)      // Se entrar aqui eh pq eh diferente, entao avanca os nos da Pilha principal.
            {
                Ant = Ant->prox;
                Pos = Pos->prox;
            }
            else                            //Entrando aqui eh pq eh Igual, entao ele ira passar o novo elemento para a pilhaaux e retirar da Pilha Principal.
            {
                Pos = Pos->prox;
                LiberaNo = Ant->prox;
                Ant->prox = Pos;
                free(LiberaNo);
                QuantidadeProcessos--;
                printf("Processo '%d' excluido com sucesso!\n",ApagarEsteID);
                Clock_ApagaID = clock() - Clock_ApagaID + Clock_Pause;
                return;
            }
        }
        if(ApagarEsteID == Pos->ID)     // Verifica se o No procurado eh o ultimo
        {
            LiberaNo = Pos;
            Ant->prox = NULL;
            free(LiberaNo);
            Pos = Ant;
            QuantidadeProcessos--;
            printf("Processo '%d' excluido com sucesso!\n",ApagarEsteID);
            Clock_ApagaID = clock() - Clock_ApagaID + Clock_Pause;
            return;
        }
    }
    printf("O Processo solicitado nao existe.\n");
    Clock_ApagaID = clock() - Clock_ApagaID + Clock_Pause;
}

void Apagar(Processo *Pilha)                            //Apaga (desempilha) um no da pilha. O ultimo elemento inserido.
{
    Clock_Apaga = 0;
    Clock_Apaga = clock();
	Processo *ult=NULL, *pnult=NULL;

	if(Pilha->prox == NULL)
	{
		printf("Pilha vazia\n\n");
        Clock_Apaga = clock() - Clock_Apaga;
		return;
	}
	else
	{
		ult = Pilha->prox;
	    pnult = Pilha;

		while(ult->prox != NULL)
		{
			pnult = ult;
			ult = ult->prox;
		}

		pnult->prox = NULL;
		QuantidadeProcessos--;
		printf("Processo ID: %d retirado. \n\n", ult->ID);
		free(ult);
	}
	Clock_Apaga = clock() - Clock_Apaga;
}
