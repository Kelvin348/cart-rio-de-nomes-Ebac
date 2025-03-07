#include <stdio.h> // biblioteca de comuni��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o na mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() // fun��o respons�vel por cadastrar os usuarios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o cpf a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s" ,sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s" ,cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	 
	 	 
}

int consultar()
{
	setlocale(LC_ALL, "portuguese"); //idioma
	
	char cpf [40];
	char conteudo [200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE * file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
	printf("N�o foi possivel abrir o arquivo , n�o localizado!.\n");
    }
	
	while(fgets(conteudo, 200, file) != NULL) ;
	{
		printf("\nEssas s�o as informac�es do usuario: ");
		printf("%s", conteudo);
	}
	
	system ("pause");	
	
	
}

int deletar()
{
    char cpf [40];
	
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) 
	{
	    printf("O usu�rio na� se encontra no sistema!.\n");
		system("pause");	
	}	
	
} 



int main()
{
    int opcao=0;
    int laco=1;
    
    for(laco=1; laco=1;)
    {
	system("cls"); 
    
	setlocale(LC_ALL, "portuguese"); //idioma
	
	printf("### Cart�rio da EBAC ### \n\n");
	printf("Escolha a op��o desejada do menu: \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n");
	printf("\t4 - Sair do sistema\n\n");
	
	scanf("%d" , &opcao); // armazenando a escolha do usu�rio 
	
	system("cls"); // respons�vel por limpar a tela
	
	switch(opcao) // inicio da sele��o
    {
	
	case 1:
    registro(); // chamada de fun��es 
    system("pause");
	break;
	
	case 2:
    consultar();
	system("pause");	
	break;
	
	case 3:
    deletar();
	system("pause");
	break;
	
	case 4:
	printf("Obigado por utilizar o sistema!\n");
	return 0;
	break;
	
	default:
	printf("Esta op��o n�o esta disponivel!\n");
	system("pause");
	break;
	
	} //fim
    }
}
