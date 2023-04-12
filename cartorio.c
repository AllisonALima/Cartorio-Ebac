#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço de memorio
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca resposavel por cuidar das strings

int registro () //a função responsavel por cadastrar os usuarios no sistema
{
	//inicio da criação de variaveis/string
	char arquivo[40];
	char cpf [40];
	char nome [40];
	char sobrenome[40];
	char cargo [40];
	//final da criação de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando infomação do usuario
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
	
	system("pause"); // pausa a mensagem para o entendimento do usuário
	
	
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese");  //definindo as linguagens
	
	//inicio da criaçao das variaveis/strings
	char cpf[40];
	char conteudo[200];
	//fim da criação dsa variaveis/strings
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s" ,cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //abre o arquivo e mostra, (r de "read" ler)
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
		printf("\nEssas são as informações do usuário: ");
	
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
	//inicio da criação das variaveis/strings
	char cpf[40];
	//fim da criação das variasveis/strings
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema. \n");
		system("pause");
	    fclose(file);
	}

	else
	    printf("\nUsuário deletado com sucesso! \n");
	    
	
}

int main()
{
	int opcao=0; //definindo as variâveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	   system("cls"); // responsavel por limpar a tela
	
	   setlocale(LC_ALL,"Portuguese");  //definindo as linguagens
	
	   printf("###Cartório da EBAC### \n\n"); //início do menu
	   printf("Escolha a opção desejada no menu: \n\n");
	   printf("\t1 - Registrar nomes\n");
	   printf("\t2 - Consultar nomes\n");
       printf("\t3 - Deletar nomes\n\n");  
 	   printf("\t4 - Sair do sistema\n\n");
	   printf("Opção:");  // fim do menu
	
	   scanf("%d", &opcao);  //armazenando as escolha do usuario
	
	   system("cls");
	
	   switch(opcao)
	   {
	       	case 1:
	       	registro(); //chamada de funções
		   	break;
		   	
			case 2:
		   	consulta(); //chamada de funções
		   	break;
		   	
		   	case 3:
		   	deletar(); //chamada de funções
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema!\n ");
		    return 0;
		    break;
			
			default:
		    printf("Esta opção não está disponivel!\n");
		    system("pause");
		    break;
	   }// fim da seleção

      } 
}
