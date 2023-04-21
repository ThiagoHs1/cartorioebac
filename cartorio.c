#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro (){
	//Inicio da cria��o de variavel
	char arquivo[40];
	char cpf[40]; 
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf ("Digite o CPF a ser cadastrado: "); //Coletando informa��o do Usu�rio
	scanf("%s", cpf); //%s se refere a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file);  // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, "," );
	fclose(file);
	
	//
	
	printf ("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	file = fopen(arquivo, "a");
	fprintf(file, nome );
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "," );
	fclose(file);
	
	
	//
	
	printf ("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome );
	fclose(file);
	
	
	file = fopen(arquivo, "a");
	fprintf(file, "," );
	fclose(file);
	
	//
	
	printf ("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	file = fopen(arquivo, "a");
	fprintf(file, cargo );
	fclose(file);
	
	system("pause");
	
}

int consulta (){
	setlocale(LC_ALL, "Portuguese"); //Linguagem
	 
	char cpf[40];
	char conteudo[200];
	
	printf ("Digite o CPF a ser consultado: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL){
		printf("N�o foi possivel abrir o arquivo, n�o localizado! \n");
		
	}
	
	while(fgets(conteudo,200,file) != NULL ) {
		printf("\nEssas s�o as informa��es do usu�rio: " );
		printf("%s", conteudo);
		printf ("\n\n");
	}
	system("pause"); 	
}

int deletar (){
	char cpf[40];
	printf ("Digite o CPF do usuario a ser consultado: ");
	scanf("%s" ,cpf);
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause"); 
	}
	
	 
}

int main()
{
	int opcao = 0; // definindo variaveis
	int laco = 1;
	char senhadigitada[10] = "a";  // Senha para login
	int comparacao; 
	
		printf("##Cart�rio EBAC ## \n\n ");
		printf("Login de adminstrador! \n\n Digite sua senha: ");
		scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //comparar a senha digitada com a senha admin
	
	if (comparacao == 0 )
	{

		  for (laco = 1; laco = 1;){
		  	  system("cls");  // Limpa a tela
			  setlocale(LC_ALL, "Portuguese"); //Linguagem
			  printf("##Cart�rio EBAC ## \n\n ");
			  printf("Escolha a op��o desejada no menu: \n\n");
		 	  printf("\t1- Registrar Nomes \n");
		 	  printf("\t2- Consultar Nomes \n");
		 	  printf("\t3- Deletar Nomes \n");
			  printf("\t4- Sair do sistema \n");
	
		 	  printf("Op��o: ");
		
		 	  //Armazene o valor que foi digitado
		 	 scanf("%d", &opcao);
		 	 
		 	 system("cls"); //LIMPAR A TELA
		 	 switch(opcao){
		 	 	case 1:
		 	 	registro(); //Chamada de fun�ao 
		  	   	break;
		  	   	
		  	   	case 2:
			 	consulta();	 
		  	   	break;
		  	   	
		  	   	case 3:
		 	 	deletar();
		  	   	break;
		  	   	
		  	   	case 4:
		 	 	printf("Obrigado por utilizar o sistema! \n");
		 	 	return 0;
		  	   	break;
		  	   	
		  	   	default:
		 	 	printf ("Esta op��o n�o est� disponivel\n");
		 	 	system("pause");  
		  	   	break;
			  }
		}
	}
	
	else
		printf( "Senha incorreta!");
}
