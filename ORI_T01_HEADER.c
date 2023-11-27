/* Bibliotecas */
#include "ORI_T01_HEADER.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <ctype.h>
#include <string.h>


/* ===========================================================================
 * ================================= FUNÇÕES =================================
 * ============= ALTERE E COLE NO AVA A PARTIR DAQUI --->>> ================== */


/* <<< COLOQUE AQUI OS DEMAIS PROTÓTIPOS DE FUNÇÕES, SE NECESSÁRIO >>> */


/* Funções auxiliares para o qsort.
 * Com uma pequena alteração, é possível utilizá-las no bsearch, assim, evitando código duplicado.
 * */

/* Função de comparação entre chaves do índice corredores_idx */
int qsort_corredores_idx(const void *a, const void *b) {
    return strcmp( ( (corredores_index *)a )->id_corredor, ( (corredores_index *)b )->id_corredor);
}

/* Função de comparação entre chaves do índice veiculos_idx */
int qsort_veiculos_idx(const void *a, const void *b) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//nov 11 11:40
	return strcmp( ( (veiculos_index *)a )->id_veiculo, ( (veiculos_index *)b )->id_veiculo);
}

/* Função de comparação entre chaves do índice pistas_idx */
int qsort_pistas_idx(const void *a, const void *b) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//nov 11 11:40
	return strcmp( ( (pistas_index *)a )->id_pista, ( (pistas_index *)b )->id_pista);
}

/* Função de comparação entre chaves do índice corridas_idx */
int qsort_corridas_idx(const void *a, const void *b) { 
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//nov 11 11:40
	int comp = strcmp( ( (corridas_index *)a )->id_pista, ( (corridas_index *)b )->id_pista);
	if (comp == 0){
		return qsort_data_idx(a, b);
	}
	return comp;
}

/* Funções de comparação apenas entre data de ocorrencia do índice corridas_idx */
int qsort_data_idx(const void *a, const void *b){ //Dúvida
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//nov 11 11:40
	return strcmp( ( (corridas_index *)b )->ocorrencia, ( (corridas_index *)a )->ocorrencia);
}

/* Função de comparação entre chaves do índice nome_pista_idx */
int qsort_nome_pista_idx(const void *a, const void *b){ //Dúvida
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//nov 11 11:40
	return strcmp( ( (nome_pista_index *)a )->nome, ( (nome_pista_index *)b )->nome);
}

/* Função de comparação entre chaves do índice preco_veiculo_idx */
int qsort_preco_veiculo_idx(const void *a, const void *b){
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	double *valor1 = (double *)a;
    double *valor2 = (double *)b;

    if (*valor1 < *valor2)
		return -1;
    if (*valor1 > *valor2)
		return 1;
    return 0;

}

/* Função de comparação entre chaves do índice secundário de corredor_veiculos_secundario_idx */
int qsort_corredor_veiculos_secundario_idx(const void *a, const void *b){ 
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	return strcmp( ( (corredor_veiculos_secundario_index *)a )->chave_secundaria, ( (corredor_veiculos_secundario_index *)b )->chave_secundaria);
}

/* Cria o índice respectivo */
void criar_corredores_idx() {
    if (!corredores_idx)
        corredores_idx = malloc(MAX_REGISTROS * sizeof(corredores_index));
 
    if (!corredores_idx) {
        printf(ERRO_MEMORIA_INSUFICIENTE);
        exit(1);
    }
 
    for (unsigned i = 0; i < qtd_registros_corredores; ++i) {
        Corredor c = recuperar_registro_corredor(i);
 
        if (strncmp(c.id_corredor, "*|", 2) == 0)
            corredores_idx[i].rrn = -1; // registro excluído
        else
            corredores_idx[i].rrn = i;
 
        strcpy(corredores_idx[i].id_corredor, c.id_corredor);
    }
 
    qsort(corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);
    printf(INDICE_CRIADO, "corredores_idx");
}

void criar_veiculos_idx() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//nov 10 16:14
	if (!veiculos_idx)
        veiculos_idx = malloc(MAX_REGISTROS * sizeof(veiculos_index));
 
    if (!veiculos_idx) {
        printf(ERRO_MEMORIA_INSUFICIENTE);
        exit(1);
    }
    for (unsigned i = 0; i < qtd_registros_veiculos; ++i) {
        Veiculo v = recuperar_registro_veiculo(i);
 
        if (strncmp(v.id_veiculo, "*|", 2) == 0)
            veiculos_idx[i].rrn = -1; // registro excluído
        else
            veiculos_idx[i].rrn = i;
 
        strcpy(veiculos_idx[i].id_veiculo, v.id_veiculo);
    }
    //qsort(veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx);
    printf(INDICE_CRIADO, "veiculos_idx");
	
}

void criar_pistas_idx() {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//nov 10 16:21

	if (!pistas_idx)
        pistas_idx = malloc(MAX_REGISTROS * sizeof(pistas_index));
 
    if (!pistas_idx) {
        printf(ERRO_MEMORIA_INSUFICIENTE);
        exit(1);
    }
 
    for (unsigned i = 0; i < qtd_registros_pistas; ++i) {
        Pista p = recuperar_registro_pista(i);
        
        pistas_idx[i].rrn = i;
        strcpy(pistas_idx[i].id_pista, p.id_pista);
    }
 
    //qsort(pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx);
    printf(INDICE_CRIADO, "pistas_idx");


}

void criar_corridas_idx() { 
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	//nov 10 16:27

	if (!corridas_idx)
        corridas_idx = malloc(MAX_REGISTROS * sizeof(corridas_index));
    if (!corridas_idx) {
        printf(ERRO_MEMORIA_INSUFICIENTE);
        exit(1);
    }
    for (unsigned i = 0; i < qtd_registros_corridas; ++i) {
        Corrida cr = recuperar_registro_corrida(i);

		strncpy(corridas_idx[i].ocorrencia, cr.ocorrencia,12);
		strncpy(corridas_idx[i].id_pista, cr.id_pista, 8);

        corridas_idx[i].rrn = i;
        
    }
 
    qsort(corridas_idx, qtd_registros_corridas, sizeof(corridas_index), qsort_corridas_idx);
    printf(INDICE_CRIADO, "corridas_idx");


}

void criar_nome_pista_idx() {
    if(!nome_pista_idx){
		nome_pista_idx = malloc(MAX_REGISTROS * sizeof(nome_pista_index));
	}
	
	if(!nome_pista_idx){
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}
	
    for (unsigned i = 0; i < qtd_registros_pistas; ++i) {
        Pista p = recuperar_registro_pista(i);
 
		strcpy(nome_pista_idx[i].nome, p.nome);
        strcpy(nome_pista_idx[i].id_pista, p.id_pista);
    }
 
    qsort(nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx);
    printf(INDICE_CRIADO, "nome_pista_idx");

}

void criar_preco_veiculo_idx() {
    if (!preco_veiculo_idx)
        preco_veiculo_idx = malloc(MAX_REGISTROS * sizeof(preco_veiculo_index));
 
    if (!preco_veiculo_idx) {
        printf(ERRO_MEMORIA_INSUFICIENTE);
        exit(1);
    }
 
    
    for (unsigned i = 0; i < qtd_registros_veiculos; ++i) {
        Veiculo v = recuperar_registro_veiculo(i);
 
        if (strncmp(v.id_veiculo, "*|", 2) == 0)
            veiculos_idx[i].rrn = -1; // registro excluído
        else
            veiculos_idx[i].rrn = i;

		preco_veiculo_idx[i].preco = v.preco;
        strcpy(preco_veiculo_idx[i].id_veiculo, v.id_veiculo);
    }
 
    qsort(preco_veiculo_idx, qtd_registros_veiculos, sizeof(preco_veiculo_index), qsort_preco_veiculo_idx);
    printf(INDICE_CRIADO, "preco_veiculo_idx");

}

void criar_corredor_veiculos_idx() {
    if(!corredor_veiculos_idx.corredor_veiculos_primario_idx || !corredor_veiculos_idx.corredor_veiculos_secundario_idx){
		corredor_veiculos_idx.corredor_veiculos_primario_idx = malloc(MAX_REGISTROS * sizeof(corredor_veiculos_primario_index));
		corredor_veiculos_idx.corredor_veiculos_secundario_idx = malloc(MAX_REGISTROS * sizeof(corredor_veiculos_secundario_index));
	}
	
	if(!corredor_veiculos_idx.corredor_veiculos_primario_idx || !corredor_veiculos_idx.corredor_veiculos_secundario_idx){
		printf(ERRO_MEMORIA_INSUFICIENTE);
		exit(1);
	}


	for (unsigned i = 0; i < qtd_registros_corredores; ++i){

        Corredor c = recuperar_registro_corredor(i);

		if(strcmp(c.veiculos[0], "") != 0)
			inverted_list_insert(c.veiculos[0], c.id_corredor, &corredor_veiculos_idx);

		
		if(strcmp(c.veiculos[1], "") != 0)
			inverted_list_insert(c.veiculos[1], c.id_corredor, &corredor_veiculos_idx);	

		
		if(strcmp(c.veiculos[2], "") != 0)
			inverted_list_insert(c.veiculos[2], c.id_corredor, &corredor_veiculos_idx);	

    }
	
	qsort(corredor_veiculos_idx.corredor_veiculos_secundario_idx, corredor_veiculos_idx.qtd_registros_secundario, sizeof(corredor_veiculos_secundario_index), qsort_corredor_veiculos_secundario_idx);
	printf(INDICE_CRIADO, "corredor_veiculos_idx");

}

/* Exibe um registro com base no RRN */
bool exibir_corredor(int rrn) {
    if (rrn < 0)
        return false;
 
    Corredor c = recuperar_registro_corredor(rrn);
 
    printf("%s, %s, %s, %s, %.2lf\n", c.id_corredor, c.nome, c.apelido, c.cadastro, c.saldo);
    return true;
}

bool exibir_veiculo(int rrn) {
    /*IMPLEMENTE A FUNÇÃO AQUI*/
	//nov 10 16:35
	if (rrn < 0)
        return false;
 
    Veiculo v = recuperar_registro_veiculo(rrn);
 
    printf("%s, %s, %s, %s, %d, %d, %d, %.2lf\n", v.id_veiculo, v.marca, v.modelo, v.poder, v.velocidade, v.aceleracao, v.peso, v.preco);
    return true;
}

bool exibir_pista(int rrn) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//nov 10 16:35
	
	if (rrn < 0)
        return false;
 
    Pista p = recuperar_registro_pista(rrn);
 
    printf("%s, %s, %d, %d, %d\n", p.id_pista, p.nome, p.dificuldade, p.distancia, p.recorde);
    return true;
}


bool exibir_corrida(int rrn) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//nov 10 16:35
	
	if (rrn < 0)
        return false;
 
    Corrida cr = recuperar_registro_corrida(rrn);
 
    printf("%s, %s, %s, %s\n", cr.id_pista, cr.ocorrencia, cr.id_corredores, cr.id_veiculos);
    return true;
}

/* Recupera do arquivo o registro com o RRN informado
 * e retorna os dados nas structs corredor, Curso e Inscricao */
Corredor recuperar_registro_corredor(int rrn) {
	Corredor c;
	char temp[TAM_REGISTRO_CORREDOR + 1], *p;
	strncpy(temp, ARQUIVO_CORREDORES + (rrn * TAM_REGISTRO_CORREDOR), TAM_REGISTRO_CORREDOR);
	temp[TAM_REGISTRO_CORREDOR] = '\0';

	p = strtok(temp, ";");
	strcpy(c.id_corredor, p);
	p = strtok(NULL, ";");
	strcpy(c.nome, p);
	p = strtok(NULL, ";");
	strcpy(c.apelido, p);
	p = strtok(NULL, ";");
	strcpy(c.cadastro, p);
	p = strtok(NULL, ";");
	c.saldo = atof(p);
	p = strtok(NULL, ";");

	for(int i = 0; i < QTD_MAX_VEICULO; ++i)
		c.veiculos[i][0] = '\0';

	if(p[0] != '#') {
		p = strtok(p, "|");

		for(int pos = 0; p; p = strtok(NULL, "|"), ++pos)
			strcpy(c.veiculos[pos], p);
	}

	return c;
}

Veiculo recuperar_registro_veiculo(int rrn) {
	Veiculo v;
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//nov 11 10:31
	char temp[TAM_REGISTRO_VEICULO + 1], *aux;
	strncpy(temp, ARQUIVO_VEICULOS + (rrn * TAM_REGISTRO_VEICULO), TAM_REGISTRO_VEICULO);
	temp[TAM_REGISTRO_VEICULO] = '\0';

	aux = strtok(temp, ";");
	strcpy(v.id_veiculo, aux);
	aux = strtok(NULL, ";");
	strcpy(v.marca, aux);
	aux = strtok(NULL, ";");
	strcpy(v.modelo, aux);
	aux = strtok(NULL, ";");
	strcpy(v.poder, aux);
	aux = strtok(NULL, ";");
	v.velocidade = atoi(aux);
	aux = strtok(NULL, ";");
	v.aceleracao = atoi(aux);
	aux = strtok(NULL, ";");
	v.peso = atoi(aux);
	aux = strtok(NULL, ";");
	v.preco = atof(aux);
	
	
	return v;
}

Pista recuperar_registro_pista(int rrn) {
	Pista p;
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//nov 11 10:31
	char temp[TAM_REGISTRO_PISTA + 1], *aux;
	strncpy(temp, ARQUIVO_PISTAS + (rrn * TAM_REGISTRO_PISTA), TAM_REGISTRO_PISTA);
	temp[TAM_REGISTRO_PISTA] = '\0';

	aux = strtok(temp, ";");
	strcpy(p.id_pista, aux);
	aux = strtok(NULL, ";");
	strcpy(p.nome, aux);
	aux = strtok(NULL, ";");
	p.dificuldade = atoi(aux);
	aux = strtok(NULL, ";");
	p.distancia = atoi(aux);
	aux = strtok(NULL, ";");
	p.recorde = atoi(aux);

	return p;
}

Corrida recuperar_registro_corrida(int rrn) {
	//Função discutida com Matheus Rodrigues, agradecimentos a ele.
	Corrida c;
	//nov 11 10:50
	char temp[TAM_REGISTRO_CORRIDA + 1];
	char aux1[9], aux2[13], aux3[67], aux4[43];
	strncpy(temp, ARQUIVO_CORRIDAS + (rrn * TAM_REGISTRO_CORRIDA), TAM_REGISTRO_CORRIDA);
	temp[TAM_REGISTRO_CORRIDA] = '\0';

	strncpy(aux1, temp, 8);
	aux1[8] = '\0';
	strcpy(c.id_pista, aux1);

	strncpy(aux2, temp+8, 12);
	aux2[12] = '\0';
	strcpy(c.ocorrencia, aux2);

	strncpy(aux3, temp+20, 66);
	aux3[66] = '\0';
	strcpy(c.id_corredores, aux3);

	strncpy(aux4, temp+86, 42);
	aux4[42] = '\0';
	strcpy(c.id_veiculos, aux4);


	return c;
}

/* Escreve em seu respectivo arquivo na posição informada (RRN) */
void escrever_registro_corredor(Corredor c, int rrn) {
	char temp[TAM_REGISTRO_CORREDOR + 1], p[100];
	temp[0] = '\0'; p[0] = '\0';

	strcpy(temp, c.id_corredor);
	strcat(temp, ";");
	strcat(temp, c.nome);
	strcat(temp, ";");
	strcat(temp, c.apelido);
	strcat(temp, ";");
	strcat(temp, c.cadastro);
	strcat(temp, ";");
	sprintf(p, "%013.2lf", c.saldo);
	strcat(temp, p);
	strcat(temp, ";");

	for(int i = 0, k = 0; i < QTD_MAX_VEICULO; ++i) {
		if(strlen(c.veiculos[i]) > 0) {
			if (k == 0)
				k = 1;
			else
				strcat(temp, "|");
			strcat(temp, c.veiculos[i]);
		}
	}
	strcat(temp, ";");

	strpadright(temp, '#', TAM_REGISTRO_CORREDOR);

	strncpy(ARQUIVO_CORREDORES + rrn*TAM_REGISTRO_CORREDOR, temp, TAM_REGISTRO_CORREDOR);
}

void escrever_registro_veiculo(Veiculo v, int rrn) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//nov 11 10:51
	char temp[TAM_ARQUIVO_VEICULOS + 1], p[100];
	temp[0] = '\0'; p[0] = '\0';


	strcpy(temp, v.id_veiculo);
	strcat(temp, ";");
	strcat(temp, v.marca);
	strcat(temp, ";");
	strcat(temp, v.modelo);
	strcat(temp, ";");
	strcat(temp, v.poder);
	strcat(temp, ";");
	sprintf(p, "%04d", v.velocidade);
	strcat(temp, p);
	strcat(temp, ";");
	sprintf(p, "%04d", v.aceleracao);
	strcat(temp, p);
	strcat(temp, ";");
	sprintf(p, "%04d", v.peso);
	strcat(temp, p);
	strcat(temp, ";");
	sprintf(p, "%013.2lf", v.preco);
	strcat(temp, p);
	strcat(temp, ";");
	
	strpadright(temp, '#', TAM_REGISTRO_VEICULO);

	strncpy(ARQUIVO_VEICULOS + rrn*TAM_REGISTRO_VEICULO, temp, TAM_REGISTRO_VEICULO);
}

void escrever_registro_pista(Pista p, int rrn) {
	//nov 11 10:57
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	char temp[TAM_ARQUIVO_PISTAS + 1], aux[100];
	temp[0] = '\0'; aux[0] = '\0';

	strcpy(temp, p.id_pista);
	strcat(temp, ";");
	strcat(temp, p.nome);
	strcat(temp, ";");
	sprintf(aux, "%04d", p.dificuldade);
	strcat(temp, aux);
	strcat(temp, ";");
	sprintf(aux, "%04d", p.distancia);
	strcat(temp, aux);
	strcat(temp, ";");
	sprintf(aux, "%04d", p.recorde);
	strcat(temp, aux);
	strcat(temp, ";");
	

	strpadright(temp, '#', TAM_REGISTRO_PISTA);

	strncpy(ARQUIVO_PISTAS + rrn*TAM_REGISTRO_PISTA, temp, TAM_REGISTRO_PISTA);
}

void escrever_registro_corrida(Corrida i, int rrn) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//nov 11 11:05
	char temp[TAM_ARQUIVO_CORRIDAS + 1];
	temp[0] = '\0';

	strcpy(temp, i.id_pista);
	strcat(temp, i.ocorrencia);
	strcat(temp, i.id_corredores);
	strcat(temp, i.id_veiculos);
	


	strncpy(ARQUIVO_CORRIDAS + rrn*TAM_REGISTRO_CORRIDA, temp, TAM_REGISTRO_CORRIDA);
}

/* Funções principais */
void cadastrar_corredor_menu(char *id_corredor, char *nome, char *apelido){
	Corredor c;
	strcpy(c.id_corredor, id_corredor);
	strcpy(c.nome, nome);
	strcpy(c.apelido, apelido);
	c.saldo = 0.00;
	current_datetime(c.cadastro);
	strcpy(c.veiculos[0], "");
	strcpy(c.veiculos[1], "");
	strcpy(c.veiculos[2], "");
	

	corredores_index *found = bsearch(c.id_corredor, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);
	
	if (found != NULL){
		printf(ERRO_PK_REPETIDA, c.id_corredor);
	}

	else{
		escrever_registro_corredor(c, qtd_registros_corredores);
		strcpy(corredores_idx[qtd_registros_corredores].id_corredor, c.id_corredor);
		corredores_idx[qtd_registros_corredores].rrn = qtd_registros_corredores;
		qtd_registros_corredores = qtd_registros_corredores+1;
		qsort(corredores_idx->id_corredor, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);
		printf(SUCESSO);
	}

	/*

	Para criar uma nova conta de corredor, seu programa deve ler os campos cpf, nome e apelido.
Inicialmente, a conta será criada sem saldo (00000000000.00). O campo cadastro receberá a data
em que o cadastro foi realizado. A função deve falhar caso haja a tentativa de inserir um corredor
com um id_corredor já cadastrado, ou seja, um CPF que já esteja no sistema. Neste caso, deverá
ser apresentada a mensagem de erro padrão ERRO_PK_REPETIDA. Caso a operação se concretize com
sucesso, exibir a mensagem padrão SUCESSO.
Lembre-se de atualizar todos os ı́ndices necessários durante a inserção.

	*/
}

void remover_corredor_menu(char *id_corredor) {
	corredores_index *found = bsearch(id_corredor, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);

	if (found == NULL){
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	}

	else{
		char aux[2] = "*|";
		strncpy(ARQUIVO_CORREDORES + found->rrn*TAM_REGISTRO_CORREDOR, aux, 2);

		found->rrn = -1;

		qsort(corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);
		printf(SUCESSO);
	}
	/*
	O usuário deverá ser capaz de remover uma conta dado um CPF de um corredor. Caso a conta não
exista, seu programa deverá exibir a mensagem padrão ERRO_REGISTRO_NAO_ENCONTRADO. A remoção
na base de dados deverá ser feita por meio de um marcador, conforme descrito na Seção 6. Se a
operação for realizada, exibir a mensagem padrão SUCESSO.
	
	o registro de um dado corredor deverá ser localizado acessando o ı́ndice primário
(id_corredor). A remoção deverá colocar o marcador *| nas duas primeiras posições do regis-
tro removido. O espaço do registro removido não deverá ser reutilizado para novas inserções.
Observe que o registro deverá continuar ocupando exatamente 160 bytes. Além disso, no ı́ndice
primário, o RRN correspondente ao registro removido deverá ser substituı́do por -1.

	*/
}

void adicionar_saldo_menu(char *id_corredor, double valor) {
	adicionar_saldo(id_corredor, valor, true);
}

void adicionar_saldo(char *id_corredor, double valor, bool flag){
	corredores_index *found = bsearch(id_corredor, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);

	if (found == NULL){
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	}

	else if(valor <= 0){
		printf(ERRO_VALOR_INVALIDO);
	}

	else{
		Corredor c;

		c = recuperar_registro_corredor(found->rrn);
		c.saldo += valor;
		escrever_registro_corredor(c, found->rrn);		
		printf(SUCESSO);
	}
	/*O usuário deverá ser capaz de adicionar valor na conta de um corredor dado seu CPF e o valor
desejado. Caso o corredor não esteja cadastrado no sistema, o programa deve imprimir a mensagem
padrão ERRO_REGISTRO_NAO_ENCONTRADO. Caso o valor que esteja sendo adicionado seja menor ou igual
a zero, o programa deve imprimir a mensagem ERRO_VALOR_INVALIDO. Se não houver nenhum desses
problemas, o saldo deverá ser atualizado, seguido da impressão da mensagem padrão de SUCESSO.*/
}

void comprar_veiculo_menu(char *id_corredor, char *id_veiculo) {
	//recuperar veiculo e corredor
	//verificar se corredor tem saldo
	//se sim, colocar no vetor de veiculos e tirar saldo
	//verificar se corredor já tem esse carro

	corredores_index *meuCor = bsearch(id_corredor, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);
	veiculos_index *meuVei = bsearch(id_veiculo, veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx);
	
	

	if (meuCor == NULL || meuVei == NULL){
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	}

	else{
		Corredor c;
		Veiculo v;

		c = recuperar_registro_corredor(meuCor->rrn);
		v = recuperar_registro_veiculo(meuVei->rrn);

		if(c.saldo<v.preco){
			printf(ERRO_SALDO_NAO_SUFICIENTE);
		}
		else{
			int verifica = 0;
			for(int i = 0; i < QTD_MAX_VEICULO; i++){
				if(strcmp(c.veiculos[i], v.modelo) == 0){
					verifica = 1;
				}
			}
			if(verifica == 1){
				printf(ERRO_VEICULO_REPETIDO, c.id_corredor, v.id_veiculo);
			}
			else{
				c.saldo = c.saldo - v.preco;
				for(int i = 0; i < QTD_MAX_VEICULO; i++){
					if(c.veiculos[i][0] == '\0'){
						strcpy(c.veiculos[i], v.modelo);
						break;
					}
				}
				escrever_registro_corredor(c,meuCor->rrn);
				inverted_list_insert(v.modelo, c.id_corredor, &corredor_veiculos_idx);
				printf(SUCESSO);
			}
		}
	}	

/*
O usuário poderá adicionar um veı́culo a um corredor dado seu CPF e o modelo de veı́-
culo desejado (caso possua saldo para comprá-lo). Neste caso, o saldo será descontado da conta
do jogador baseado no valor do veı́culo. Caso o corredor não possua saldo, a mensagem padrão
ERRO_SALDO_NAO_SUFICIENTE deve ser impressa. Caso o corredor não exista, o programa deve impri-
mir ERRO_REGISTRO_NAO_ENCONTRADO e, caso o veı́culo novo já esteja presente nos veı́culos do corredor,
seu programa deve imprimir ERRO_VEICULO_REPETIDO. Existe um máximo de três modelos de veı́culos
por corredor e, garantidamente, não haverá nenhuma tentativa de inserir mais de três por corredor.Caso não haja nenhum erro, o programa deve atribuir o veı́culo ao corredor, atualizando todos os
ı́ndices e arquivos necessários e, então, imprimir a mensagem padrão SUCESSO.
*/
}

void cadastrar_veiculo_menu(char *marca, char *modelo, char *poder, int velocidade, int aceleracao, int peso, double preco) {
	Veiculo v;
	sprintf(v.id_veiculo, "%07d", qtd_registros_veiculos);
	strcpy(v.marca, marca);	
	strcpy(v.modelo, modelo);
	strcpy(v.poder, poder);
	v.velocidade = velocidade;
	v.aceleracao = aceleracao;
	v.peso = peso;
	v.preco = preco;

	veiculos_index *found = bsearch(v.id_veiculo, veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx);

	if(found != NULL){
		printf(ERRO_PK_REPETIDA, v.id_veiculo);
	}

	else{
		escrever_registro_veiculo(v, qtd_registros_veiculos);

		strcpy(veiculos_idx[qtd_registros_veiculos].id_veiculo, v.id_veiculo);
		veiculos_idx[qtd_registros_veiculos].rrn = qtd_registros_veiculos;

		strcpy(preco_veiculo_idx[qtd_registros_veiculos].id_veiculo, v.id_veiculo);
		preco_veiculo_idx[qtd_registros_veiculos].preco = v.preco;

		qtd_registros_veiculos++;
		
		//qsort(veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx);
		qsort(preco_veiculo_idx, qtd_registros_veiculos, sizeof(preco_veiculo_index), qsort_preco_veiculo_idx);
		
		printf(SUCESSO);
	}

	/*
	Para um veı́culo ser adicionado no banco de dados, seu programa deverá ler os campos que contém
a marca, modelo, poder, velocidade, aceleração, peso e preço. O campo 'id veiculo 'segue a ordem de
cadastro dos veı́culos. A função deve falhar caso haja a tentativa de inserir um veı́culo cujo ID já esteja
presente no banco de dados, e deverá ser apresentada a mensagem de erro padrão ERRO_PK_REPETIDA.
Caso a operação se concretize, exiba a mensagem padrão SUCESSO
	
	*/

}

void cadastrar_pista_menu(char *nome, int dificuldade, int distancia, int recorde){
	Pista p;
	snprintf(p.id_pista, sizeof(p.id_pista), "%08d", qtd_registros_pistas);
	strcpy(p.nome, nome);
	p.dificuldade = dificuldade;
	p.distancia = distancia;
	p.recorde = recorde;

	pistas_index *found = bsearch(p.nome, nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx);

	if(found != NULL){
		printf(ERRO_PK_REPETIDA, p.nome);
	}

	else{
		escrever_registro_pista(p, qtd_registros_pistas);

		strcpy(pistas_idx[qtd_registros_pistas].id_pista, p.id_pista);
		pistas_idx[qtd_registros_pistas].rrn = qtd_registros_pistas;


		strcpy(nome_pista_idx[qtd_registros_pistas].nome, p.nome);
        strcpy(nome_pista_idx[qtd_registros_pistas].id_pista, p.id_pista); 

		qtd_registros_pistas++;
		qsort(nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx);
		//qsort(pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx);
		printf(SUCESSO);
	}

	/*
	Para criar uma nova pista, seu programa deve ler os campos nome, dificuldade, recorde e dis-
tancia. O campo id_pista deverá ser preenchido de acordo com a quantidade de pistas cadastradas
no sistema, ou seja, é um valor incremental. O único campo que é opcional quanto ao fornecimento é a
dificuldade, que, caso não informado, receberá o valor padrão 1. Quando a operação se concretizar
com sucesso, exibir a mensagem padrão SUCESSO.
	*/

}

void executar_corrida_menu(char *id_pista, char *ocorrencia, char *id_corredores, char *id_veiculos) {
	//Função discutida com Felipe Bravo. Agradecimentos a ele.
	Corrida corrida;
	Corredor c[6];
	Veiculo v[6];
	Pista p;
	//printf("TESTEA\n");
	strcpy(corrida.id_pista, id_pista);
	corridas_index *foundocorrencia = bsearch(ocorrencia, corridas_idx, qtd_registros_corridas, sizeof(corridas_index), qsort_data_idx);	
	if(foundocorrencia){
		printf(ERRO_PK_REPETIDA, strcat(ocorrencia, id_pista));
		return;
	}
	strcpy(corrida.ocorrencia, ocorrencia);
	strcpy(corrida.id_corredores, id_corredores);
	strcpy(corrida.id_veiculos, id_veiculos);

	pistas_index *foundpista = bsearch(corrida.id_pista, pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx);	
	if(!foundpista){
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
		return;
	}
	p = recuperar_registro_pista(foundpista->rrn);
	double valor = 6 * (TX_FIXA * p.dificuldade);


	char participantes[6][TAM_ID_CORREDOR];
	int rrncorredores[6];

	for (int i = 0; i < 6; i++){

		//printf("TESTE C\n");
		strncpy(participantes[i], corrida.id_corredores + i * (TAM_ID_CORREDOR-1), TAM_ID_CORREDOR-1);
		participantes[i][TAM_ID_CORREDOR-1] = '\0';
		corredores_index *foundcorredores = bsearch(participantes[i], corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);	
		if(!foundcorredores){
			printf(ERRO_REGISTRO_NAO_ENCONTRADO);
			return;
		}
		c[i] = recuperar_registro_corredor(foundcorredores->rrn);
		//printf("CORREDOR NOME %s\n", c[i].nome);
		rrncorredores[i] = foundcorredores->rrn;
	}

	char veiculospart[6][TAM_ID_VEICULO];

	for (int i = 0; i < 6; i++){

		//printf("TESTE C\n");
		strncpy(veiculospart[i], corrida.id_veiculos + i * (TAM_ID_VEICULO-1), TAM_ID_VEICULO-1);
		participantes[i][TAM_ID_VEICULO-1] = '\0';
		veiculos_index *foundveiculos = bsearch(veiculospart[i], veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx);	
		if(!foundveiculos){
			printf(ERRO_REGISTRO_NAO_ENCONTRADO);
			return;
		}
		v[i] = recuperar_registro_veiculo(foundveiculos->rrn);
		//printf("VEICULO NOME %s\n", v[i].modelo);
	}

	int verifica = 0;

	for(int i = 0; i < 6; i++){
		if(strcmp(c[i].veiculos[0], v[i].modelo) != 0 && strcmp(c[i].veiculos[1], v[i].modelo) != 0 && strcmp(c[i].veiculos[2], v[i].modelo) != 0){
			printf(ERRO_CORREDOR_VEICULO, c[i].id_corredor, v[i].id_veiculo);	
			verifica = 1;
		}
	}

	if (verifica == 1){
		return;
	}
	

	

	//printf("TESTE D\n");

	c[0].saldo += valor * 0.4;
	c[1].saldo += valor * 0.3;
	c[2].saldo += valor * 0.2;

	for(int i = 0; i < 6; i++){
		escrever_registro_corredor(c[i], rrncorredores[i]);
	}

	strcpy(corridas_idx[qtd_registros_corridas].id_pista, id_pista);
	corridas_idx[qtd_registros_corridas].rrn = qtd_registros_corridas;
	strcpy(corridas_idx[qtd_registros_corridas].ocorrencia, ocorrencia);
	//qtd_registros_corridas++;
	//printf("TESTE E\n");
	
	escrever_registro_corrida(corrida, qtd_registros_corridas);
	qtd_registros_corridas++;
	

	printf(SUCESSO);

	/*
	Para executar uma nova corrida, seu programa deve ler os campos id_pista, ocorrencia,
id_corredores e id_veiculos. Todos os campos serão fornecidos de maneira regular, não havendo
a necessidade de qualquer pré-processamento da entrada. Os identificadores de corredores no campo
id_corredores estarão ordenados pela sua colocação, e os três primeiros corredores receberão uma
premiação monetária. O valor total arrecadado em uma corrida é calculado pela seguinte expressão:
V = 6 * (T * D), sendo T uma taxa de inscrição fixa e D a dificuldade da pista em que a corrida foi
executada. Dessa forma, o prêmio para primeiro colocado será 40% de V, o segundo colocado receberá
30% de V e o terceiro receberá 20% de V. Os 10% restantes serão reservados como taxa de manutenção
do sistema. Quando a operação se concretizar com sucesso, exibir a mensagem padrão SUCESSO.
	*/
}

/* Busca */
void buscar_corredor_id_menu(char *id_corredor) {
	corredores_index index;
	strcpy(index.id_corredor, id_corredor);
    corredores_index *found = busca_binaria((void*)&index, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx, true, 0);
	//corredores_index *found = bsearch(id_corredor, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);
	if (found == NULL || found->rrn < 0)
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
	else
		exibir_corredor(found->rrn);
}

void buscar_pista_id_menu(char *id_pista) {
	pistas_index index;
	strcpy(index.id_pista, id_pista);
    pistas_index *found = busca_binaria((void*)&index, pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx, true, 0);
	//pistas_index *found = bsearch(id_pista, pistas_idx, qtd_registros_pistas, sizeof(pistas_index), qsort_pistas_idx);
	if (found == NULL || found->rrn < 0){
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
		}
	else{
		exibir_pista(found->rrn);
		}
}

void buscar_pista_nome_menu(char *nome_pista) {
	nome_pista_index index;
	strcpy(index.nome, nome_pista);
	//nome_pista_index *found = bsearch(nome_pista, nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx);
    nome_pista_index *found = busca_binaria((void*)&index, nome_pista_idx, qtd_registros_pistas, sizeof(nome_pista_index), qsort_nome_pista_idx, true, 0);
	if (found == NULL){
		printf(ERRO_REGISTRO_NAO_ENCONTRADO);
		}
	else{
		buscar_pista_id_menu(found->id_pista);
		}

	/*
	Caso a pista não seja encontrada, seu programa deverá exibir a mensagem padrão
ERRO_REGISTRO_NAO_ENCONTRADO. Caso contrário, todos os dados deverão ser impressos na tela
de forma formatada. Observe que, neste caso, como a busca será realizada em dois ı́ndices, será
necessário exibir o caminho da busca binária para ambos: primeiro para o ı́ndice secundário e
depois para o ı́ndice primário.
	*/
}

/* Listagem */
void listar_corredores_id_menu() {
	if (qtd_registros_corredores == 0)
		printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
	else 	
		for (unsigned int i = 0; i < qtd_registros_corredores; i++)
			exibir_corredor(corredores_idx[i].rrn);
}

void listar_corredores_modelo_menu(char *modelo){
	//Função discutida com Felipe Bravo.
for (int i = 0; i < corredor_veiculos_idx.qtd_registros_secundario; i++) {
    if (strcmp(corredor_veiculos_idx.corredor_veiculos_secundario_idx[i].chave_secundaria, modelo) == 0) {
        int inicio, fim;
        char aux[corredor_veiculos_idx.qtd_registros_primario][12];
        inverted_list_secondary_search(&inicio, false, modelo, &corredor_veiculos_idx);
        inverted_list_primary_search(aux, true, inicio, &fim, &corredor_veiculos_idx);
        int contador = 0;

    
        for (int i = 0; i < corredor_veiculos_idx.qtd_registros_primario; i++) {
			if(strcmp(aux[i], "") == 0){
				break;
			}
			contador++;
        }

        corredores_index *c = NULL;
        c = malloc(contador * sizeof(corredores_index));
      
        for (int i = 0; i < contador; i++) {
            strncpy(c[i].id_corredor, aux[i], TAM_CHAVE_CORREDOR_VEICULO_PRIMARIO_IDX);
            for (int j = 0; j < corredor_veiculos_idx.qtd_registros_primario; j++) {
                if (strncmp(c[i].id_corredor, corredores_idx[j].id_corredor, TAM_CHAVE_CORREDOR_VEICULO_PRIMARIO_IDX) == 0) {
					//printf("ID CORREDOR%s\n", c[i].id_corredor);
                    c[i].rrn = corredores_idx[j].rrn;
                }
            }
        }
		qsort(c, contador, sizeof(corredores_index), qsort_corredores_idx);
        for (int i = 0; i < contador-1; i++) {
          exibir_corredor(c[i].rrn);
        }
		free(c);
        return;
    }
  }
  printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
  return;
	/*
	SELECT * FROM veiculos WHERE '<veiculo>'= ANY (veiculos) ORDER BY id_veiculo ASC
Exibe todos os corredores que possuem determinado modelo de veı́culo, em ordem crescente
de ID. Caso nenhum registro for retornado, seu programa deverá exibir a mensagem padrão
AVISO_NENHUM_REGISTRO_ENCONTRADO.
ATENÇÃO: antes da listagem dos corredores, o seu programa deverá imprimir os registros do
ı́ndice da lista invertida (i.e., corredor_veiculos_primario_idx, ver detalhes na Seção 4.2).
	*/
}

void listar_veiculos_compra_menu(char *id_corredor) {
	if (qtd_registros_veiculos == 0)
		printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
	else{
		corredores_index *found = bsearch(id_corredor, corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);
		if(found == NULL){
			printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
		}
		else{
			Corredor c; 
			int preco = 0;
			c = recuperar_registro_corredor(found->rrn);
			//printf("SALDO %.2lf\n", c.saldo);

			for (int i = 0; i<qtd_registros_veiculos; ++i){
				preco = preco_veiculo_idx[i].preco;
				veiculos_index *found = bsearch(preco_veiculo_idx[i].id_veiculo, veiculos_idx, qtd_registros_veiculos, sizeof(veiculos_index), qsort_veiculos_idx);
				//printf("VEICULO %s, %.2lf\n", v.modelo, v.preco);
				
				if(preco<=c.saldo)
					exibir_veiculo(found->rrn);
			}			
		}
	} 	
		

	/*
	Seu programa deve ler o ID de um corredor e, em seguida, exibir todos os veı́culos que o corredor
pode comprar, de acordo com o seu saldo. Caso nenhum registro for retornado, seu programa
deverá exibir a mensagem padrão AVISO_NENHUM_REGISTRO_ENCONTRADO.
	*/
}

void listar_corridas_periodo_menu(char *data_inicio, char *data_fim) {
	/*IMPLEMENTE A FUNÇÃO AQUI*/
	//pego todas as corridas, se forem maiores que a data de início e menor que a de fim, exibo.
	corridas_index c;
	strcpy(c.ocorrencia, data_inicio);
	corridas_index *found = busca_binaria_com_reps((void*)&c, corridas_idx, qtd_registros_corridas, sizeof(corredores_index), qsort_data_idx, true, -1, -1);
	//printf("OCORRENCIA %s, ACHADO %s\n", c.ocorrencia, found->ocorrencia);
	if(found == NULL){
		printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
		return;
	}
	bool verifica = false;
	for(int i = 0; i<qtd_registros_corridas; i++){
		if(strcmp(corridas_idx[i].ocorrencia, data_inicio) >= 0 && strcmp(corridas_idx[i].ocorrencia, data_fim) <= 0){
			exibir_corrida(corridas_idx[i].rrn);
			verifica = true;
		}
	}

	if (verifica == false){
		printf(AVISO_NENHUM_REGISTRO_ENCONTRADO);
		return;
	} 

	/*
	
	Exibe todas as corridas realizadas em um determinado perı́odo de tempo (data entre
<data_inicio> e <data_fim>), em ordem cronológica. Ambas as datas estarão no formato
<AAAAMMDDHHMM>. Para cada registro encontrado na listagem, deverá ser impresso o caminho
percorrido. Caso nenhum registro for retornado, seu programa deverá exibir a mensagem padrão
AVISO_NENHUM_REGISTRO_ENCONTRADO.

	*/


	//printf(ERRO_NAO_IMPLEMENTADO, "listar_corridas_periodo_menu()"); /* INVT */
}

/* Liberar espaço */
void liberar_espaco_menu() {
	//Função discutida com Vinicius Terra Silva. Agradecimentos a ele.
	char aux[TAM_ARQUIVO_CORREDORES+1];
	aux[0] = '\0';
	Corredor c;
	int contador = 0;
	for(int i = 0; i<qtd_registros_corredores; i++){
		c = recuperar_registro_corredor(i);
		

		if(strncmp(c.id_corredor, "*|", 2) != 0){
			corredores_idx[contador].rrn = contador;
			strcpy(corredores_idx[contador].id_corredor, c.id_corredor);

			contador++;
			char temp[TAM_REGISTRO_CORREDOR + 1], p[100];
			temp[0] = '\0', p[0] = '\0';

			strcat(temp, c.id_corredor);
			
			strcat(temp, ";");
			strcat(temp, c.nome);
			strcat(temp, ";");
			strcat(temp, c.apelido);
			strcat(temp, ";");
			strcat(temp, c.cadastro);
			strcat(temp, ";");
			sprintf(p, "%013.2lf", c.saldo);
			strcat(temp, p);
			strcat(temp, ";");

			for(int i = 0, k = 0; i < QTD_MAX_VEICULO; ++i) {
				if(strlen(c.veiculos[i]) > 0) {
					if (k == 0)
						k = 1;
					else
						strcat(temp, "|");
				strcat(temp, c.veiculos[i]);
		}
	}
	strcat(temp, ";");

	strpadright(temp, '#', TAM_REGISTRO_CORREDOR);
	strcat(aux, temp);
	}
	
	}

	strcpy(ARQUIVO_CORREDORES, aux);
	qtd_registros_corredores = contador;

	qsort(corredores_idx, qtd_registros_corredores, sizeof(corredores_index), qsort_corredores_idx);

	printf(SUCESSO);


	/*
	O arquivo de dados ARQUIVO_CORREDORES deverá ser reorganizado com a remoção fı́sica de todos
os registros marcados como excluı́dos e os ı́ndices deverão ser atualizados. A ordem dos registros no
arquivo “limpo” não deverá ser diferente do arquivo “sujo”. Se a operação se concretizar, exibir a
mensagem padrão SUCESSO.
	*/	
}

/* Imprimir arquivos de dados */
void imprimir_arquivo_corredores_menu() {
	if (qtd_registros_corredores == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_CORREDORES);
}

void imprimir_arquivo_veiculos_menu() {
	if (qtd_registros_veiculos == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_VEICULOS);
}

void imprimir_arquivo_pistas_menu() {
	if (qtd_registros_pistas == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_PISTAS);
}

void imprimir_arquivo_corridas_menu() {
	if (qtd_registros_corridas == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		printf("%s\n", ARQUIVO_CORRIDAS);
}

/* Imprimir índices primários */
void imprimir_corredores_idx_menu() {
	if (corredores_idx == NULL || qtd_registros_corredores == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		for (unsigned i = 0; i < qtd_registros_corredores; ++i)
			printf("%s, %d\n", corredores_idx[i].id_corredor, corredores_idx[i].rrn);
}

void imprimir_veiculos_idx_menu() {
	if (veiculos_idx == NULL || qtd_registros_veiculos == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		for (unsigned i = 0; i < qtd_registros_veiculos; ++i)
			printf("%s, %d\n", veiculos_idx[i].id_veiculo, veiculos_idx[i].rrn);
}

void imprimir_pistas_idx_menu() {
	if (pistas_idx == NULL || qtd_registros_pistas == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		for (unsigned i = 0; i < qtd_registros_pistas; ++i)
			printf("%s, %d\n", pistas_idx[i].id_pista, pistas_idx[i].rrn);
}	

void imprimir_corridas_idx_menu() {
	if (corridas_idx == NULL || qtd_registros_corridas == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		for (unsigned i = 0; i < qtd_registros_corridas; ++i)
			printf("%s, %s, %d\n", corridas_idx[i].ocorrencia, corridas_idx[i].id_pista, corridas_idx[i].rrn);
/*	Imprime as structs de ı́ndice primário de corridas. Caso o ı́ndice esteja vazio, imprimir
ERRO_ARQUIVO_VAZIO;*/
}

/* Imprimir índices secundários */
void imprimir_nome_pista_idx_menu() {
	if (nome_pista_idx == NULL || qtd_registros_pistas == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else{
		char upperNome[34];
		for (unsigned i = 0; i < qtd_registros_pistas; ++i){
			strcpy(upperNome, nome_pista_idx[i].nome);
			//printf("UPPER NOME %s\n", upperNome);
			for(int j = 0; j < sizeof(upperNome)/sizeof(upperNome[0]); j++){
				upperNome[j] = toupper(upperNome[j]);
			}
			//printf("UPPER NOME %s\n", upperNome);
			printf("%s, %s\n", upperNome, nome_pista_idx[i].id_pista);
			}
		}

}

void imprimir_preco_veiculo_idx_menu() {
	if (preco_veiculo_idx == NULL || qtd_registros_veiculos == 0)
		printf(ERRO_ARQUIVO_VAZIO);
	else
		for (unsigned i = 0; i < qtd_registros_veiculos; ++i)
			printf("%.2lf, %.8s\n", preco_veiculo_idx[i].preco, preco_veiculo_idx[i].id_veiculo);
}

void imprimir_corredor_veiculos_secundario_idx_menu() {
	if(corredor_veiculos_idx.corredor_veiculos_secundario_idx == NULL || corredor_veiculos_idx.qtd_registros_secundario == 0){
		printf(ERRO_ARQUIVO_VAZIO);
	}

	else{
		for(int i = 0; i < corredor_veiculos_idx.qtd_registros_secundario; ++i){
			printf("%s, %d\n", strupr(corredor_veiculos_idx.corredor_veiculos_secundario_idx[i].chave_secundaria), corredor_veiculos_idx.corredor_veiculos_secundario_idx[i].primeiro_indice);
		}
	}

}

void imprimir_corredor_veiculos_primario_idx_menu(){
	
	if(corredor_veiculos_idx.corredor_veiculos_primario_idx == NULL || corredor_veiculos_idx.qtd_registros_primario == 0){
		printf(ERRO_ARQUIVO_VAZIO);
	}

	else{
		for(int i = 0; i < corredor_veiculos_idx.qtd_registros_primario; ++i){
			printf("%s, %d\n", corredor_veiculos_idx.corredor_veiculos_primario_idx[i].chave_primaria, corredor_veiculos_idx.corredor_veiculos_primario_idx[i].proximo_indice);
		}
	}
}

/* Liberar memória e encerrar programa */
void liberar_memoria_menu() {
	free(corredores_idx);
	free(veiculos_idx);
	free(pistas_idx);
	free(corridas_idx);
	free(nome_pista_idx);
	free(preco_veiculo_idx);
	free(corredor_veiculos_idx.corredor_veiculos_primario_idx);
	free(corredor_veiculos_idx.corredor_veiculos_secundario_idx);	

	/*
	Libera a memória e encerra a execução do programa.
	char ARQUIVO_CORREDORES[TAM_ARQUIVO_CORREDORES];
	char ARQUIVO_VEICULOS[TAM_ARQUIVO_VEICULOS];
	char ARQUIVO_PISTAS[TAM_ARQUIVO_PISTAS];
	char ARQUIVO_CORRIDAS[TAM_ARQUIVO_CORRIDAS];
	corredores_index * corredores_idx= NULL;
	veiculos_index *veiculos_idx = NULL;
	pistas_index *pistas_idx = NULL;
	corridas_index *corridas_idx = NULL;
	nome_pista_index *nome_pista_idx = NULL;
	preco_veiculo_index *preco_veiculo_idx = NULL;
	inverted_list corredor_veiculos_idx = {
    .corredor_veiculos_secundario_idx = NULL,
    .corredor_veiculos_primario_idx = NULL,
    .qtd_registros_secundario = 0,
    .qtd_registros_primario = 0,
    .tam_chave_secundaria = TAM_CHAVE_CORREDOR_VEICULO_SECUNDARIO_IDX,
    .tam_chave_primaria = TAM_CHAVE_CORREDOR_VEICULO_PRIMARIO_IDX,
};


	*/
}



void inverted_list_insert(char *chave_secundaria, char *chave_primaria, inverted_list *t) {
	//Funções de lista invertidas foram discutidas com Felipe Bravo e Vinicius Terra. Agradecimentos a eles.
	int indice = 0; 

      if (inverted_list_secondary_search(&indice, false, chave_secundaria, t)){
    
	      int final = 0;
    
	      for (int i=0; i < t->qtd_registros_secundario ; i++){
              if (strcmp(chave_secundaria, t->corredor_veiculos_secundario_idx[i].chave_secundaria) == 0){
                  indice = t->corredor_veiculos_secundario_idx[i].primeiro_indice;
                  break;
	          }
	      }

          inverted_list_primary_search(NULL, false, indice, &final, t);
          t->corredor_veiculos_primario_idx[final].proximo_indice = t->qtd_registros_primario;
          t->corredor_veiculos_primario_idx[t->qtd_registros_primario].proximo_indice = -1;
          strcpy(t->corredor_veiculos_primario_idx[t->qtd_registros_primario].chave_primaria, chave_primaria);
          t->qtd_registros_primario++;

      } 
      
      else {
          strcpy(t->corredor_veiculos_secundario_idx[t->qtd_registros_secundario].chave_secundaria, chave_secundaria);
          t->corredor_veiculos_secundario_idx[t->qtd_registros_secundario].primeiro_indice = t->qtd_registros_primario;
          strcpy(t->corredor_veiculos_primario_idx[t->qtd_registros_primario].chave_primaria, chave_primaria);
          
		  
		  t->corredor_veiculos_primario_idx[t->qtd_registros_primario].proximo_indice = -1;
          t->qtd_registros_secundario++;
          t->qtd_registros_primario++;
      }

      qsort(corredor_veiculos_idx.corredor_veiculos_secundario_idx, corredor_veiculos_idx.qtd_registros_secundario, sizeof(corredor_veiculos_secundario_index), qsort_corredor_veiculos_secundario_idx);
}

bool inverted_list_secondary_search(int *result, bool exibir_caminho, char *chave_secundaria, inverted_list *t) {
	/*IMPLEMENTE A FUNÇÃO AQUI*//* INVT */
	//Funções de lista invertidas foram discutidas com Felipe Bravo e Vinicius Terra. Agradecimentos a eles.
	corredor_veiculos_secundario_index* found = busca_binaria(chave_secundaria, t->corredor_veiculos_secundario_idx,t->qtd_registros_secundario, sizeof(corredor_veiculos_secundario_index), qsort_corredor_veiculos_secundario_idx, false, 0);

	if(found){
		*result = found->primeiro_indice;
		return true;
	}
	else{
		return false;
	}

	}

int inverted_list_primary_search(char result[][TAM_ID_CORREDOR], bool exibir_caminho, int indice, int *indice_final, inverted_list *t) {
	/*IMPLEMENTE A FUNÇÃO AQUI*//* INVT */
	//Funções de lista invertidas foram discutidas com Felipe Bravo e Vinicius Terra. Agradecimentos a eles.
	int contador = 0;

	 if (exibir_caminho){
            printf(REGS_PERCORRIDOS);
	 }

    for (int i = indice; i != -1; i = t->corredor_veiculos_primario_idx[i].proximo_indice, contador++){
        if (exibir_caminho){
            printf(" %d", i);
        }
            
        if (result != NULL)
            strcpy(result[contador], t->corredor_veiculos_primario_idx[i].chave_primaria);
 
        *indice_final = i;
    }
 
    if (exibir_caminho)
        printf("\n");
 
    return contador;   
}

void* busca_binaria_com_reps(const void *key, const void *base0, size_t nmemb, size_t size, int (*compar)(const void *, const void *), bool exibir_caminho, int posicao_caso_repetido, int retorno_se_nao_encontrado) {
    const char *minhaBase = (const char *) base0;
    const void *meio;
    int fim, verifica;
 
    if (exibir_caminho == true && nmemb > 0) {
        printf("Registros percorridos:");
    }
    
 
    for (fim = nmemb; fim != 0; fim = fim / 2) {
 
        meio = minhaBase + (fim / 2) * size;
        verifica = (*compar)(key, meio);
 
        if (exibir_caminho) {
            printf(" %ld", (meio - base0) / size);
        }
        if (verifica == 0){
            if(exibir_caminho)
                printf("\n");
            
            return (void *)meio;
        }
        else if (verifica > 0) {    
            minhaBase = (const char *)meio + size;
            fim--;
        } 
    }
 
    if (exibir_caminho && nmemb !=0) {
        printf("\n");
    }
 
    if(retorno_se_nao_encontrado == -1){
        if (verifica > 0) {
    		return (void*)(meio + size);		
		} else {
    		return (void*)meio;
		}
	}

    else if(retorno_se_nao_encontrado == 0){
        return NULL;
	}

    else if(retorno_se_nao_encontrado == 1){
		if (verifica > 0) {
    		return (void*)meio;		
		} else {
    		return (void*)(meio-size);
			}
		}

	return NULL;
 }


void* busca_binaria(const void *key, const void *base0, size_t nmemb, size_t size, int (*compar)(const void *, const void *), bool exibir_caminho, int retorno_se_nao_encontrado) {
	return busca_binaria_com_reps(key, base0, nmemb, size, compar, exibir_caminho, 0, retorno_se_nao_encontrado);
}

char *strpadright(char *str, char pad, unsigned size){
	for (unsigned i = strlen(str); i < size; ++i)
		str[i] = pad;
	str[size] = '\0';
	return str;
}
char *strupr(char *str){
	for (char *p = str; *p; ++p)
		*p = toupper(*p);
	return str;
}
char *strlower(char *str){
	for (char *p = str; *p; ++p)
		*p = tolower(*p);
	return str;
}
