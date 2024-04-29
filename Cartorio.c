#include <stdio.h> //biblioteca de comunica��oo com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca�oes de texto por regiao
#include <string.h> //biblioteca respons�vel por cuidar das string( string = conjunto de variaveis )
		
int registro()      //fun��o responsavel por cadastrar os usuarios nos sistemas 
{
	//inicio de cria��o de variaveis /string 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de cria��o de variaveis /string 
	
	printf("Digite o CPF a ser cadastrado: ");  //coletando informa��o do usuario 
	scanf("%s", cpf);           //%s refere-se a strings  - o %s � usado toda vez que precisa salvar as informa��es na string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "W" significa escrever (write)
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");  //se coloca o "A" pq eu n�o quero criar um outro arquivo, s� quero acessar um arquivo para atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //se coloca o "A" pq eu n�o quero criar um outro arquivo, s� quero acessar um arquivo para atualizar
	fprintf(file,nome);        
	fclose(file);
	
	file = fopen(arquivo, "a"); //se coloca o "A" pq eu n�o quero criar um outro arquivo, s� quero acessar um arquivo para atualizar
	fprintf(file,",");          // SE COLOCA A "," PARA COLOCAR UMA VIRGULA NO FINAL DA INFORMA��O
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //se coloca o "A" pq eu n�o quero criar um outro arquivo, s� quero acessar um arquivo para atualizar
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //se coloca o "A" pq eu n�o quero criar um outro arquivo, s� quero acessar um arquivo para atualizar
	fprintf(file,",");           // SE COLOCA A "," PARA COLOCAR UMA VIRGULA NO FINAL DA INFORMA��O
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //se coloca o "A" pq eu n�o quero criar um outro arquivo, s� quero acessar um arquivo para atualizar
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta() //fun��o responsavel pela consulta de usuarios no sistema 
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf ("N�o foi possivel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf ("\n Essas s�o as informa��es do usuario:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar() //fun��o responsavel para deletar usuarios do sistema 
{
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    
    FILE *file;
    file = fopen(cpf,"r"); // O "r" SIGNIFICA LER O ARQUIVO (read)

    
    if(file == NULL)
    {
    printf("Usuario n�o se encontra no sistema .\n");
    system("pause");
	}
	
	
    if (file != NULL ) 
    {

    printf("Usuario deletado com sucesso ! .\n \n ");
    system("pause");
	}

   	
}


	
int main()
	{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls"); //ELE � O RESPONSAVEL POR LIMPAR A TELA

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��oo desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls");
	
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //CHAMADA DE FUN��ES
			break;
			
			case 2:
			consulta(); //CHAMADA DE FUN��ES
			break;
		
			case 3:
			deletar();//CHAMADA DE FUN��ES
			break;
		
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		} //fim da sele��o
			
	}	
}
