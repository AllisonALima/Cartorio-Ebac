#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o de memorio
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca resposavel por cuidar das strings

int registro () //a fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio da cria��o de variaveis/string
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome[40];
	char cargo [40];
	//final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando infoma��o do usuario
	scanf("%s", cpf); //%s refere-se a strings, armazenando as strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file;  //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e escreve (w de "write" escrever)
	fprintf(file, "\nCPF:");
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file);  // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nNome:");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s" , nome); //amrmazenando as strings
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSobrenome:");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCargo:");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); // pausa a mensagem para o entendimento do usu�rio
	
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");  //definindo as linguagens
	
	//inicio da cria�ao das variaveis/strings
	char cpf[40];
	char conteudo[200];
	//fim da cria��o dsa variaveis/strings
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s" ,cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo e mostra, (r de "read" ler)
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
		printf("\nEssas s�o as informa��es do usu�rio: ");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	
	system("pause");
}

int deletar()
{
	//inicio da cria��o das variaveis/strings
	char cpf[40];
	//fim da cria��o das variasveis/strings
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema. \n");
		system("pause");
	    fclose(file);
	}

	else
	    printf("\nUsu�rio deletado com sucesso! \n");
	    
	
}

int main()
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	   system("cls"); // responsavel por limpar a tela
	
	   setlocale(LC_ALL,"Portuguese");  //definindo as linguagens
	
	   printf("###Cart�rio da EBAC### \n\n"); //in�cio do menu
	   printf("Escolha a op��o desejada no menu: \n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
       printf("\t3 - Deletar nomes\n\n");  
 	   printf("Op��o:");  // fim do menu
	
	   scanf("%d", &opcao);  //armazenando as escolha do usuario
	
	   system("cls");
	
	   switch(opcao)
	   {
	       	case 1:
	       	registro(); //chamada de fun��es
		   	break;
		   	
			case 2:
		   	consulta(); //chamada de fun��es
		   	break;
		   	
		   	case 3:
		   	deletar(); //chamada de fun��es
		    break;
		    
		    default:
		    printf("Esta op��o n�o est� disponivel!\n");
		    system("pause");
		    break;
	   }// fim da sele��o

      } 
}
