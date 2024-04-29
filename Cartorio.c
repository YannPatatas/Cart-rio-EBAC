#include <stdio.h> //biblioteca de comunicaçãoo com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocaçoes de texto por regiao
#include <string.h> //biblioteca responsável por cuidar das string( string = conjunto de variaveis )
		
int registro()      //função responsavel por cadastrar os usuarios nos sistemas 
{
	//inicio de criação de variaveis /string 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de criação de variaveis /string 
	
	printf("Digite o CPF a ser cadastrado: ");  //coletando informação do usuario 
	scanf("%s", cpf);           //%s refere-se a strings  - o %s é usado toda vez que precisa salvar as informações na string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "W" significa escrever (write)
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");  //se coloca o "A" pq eu não quero criar um outro arquivo, só quero acessar um arquivo para atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //se coloca o "A" pq eu não quero criar um outro arquivo, só quero acessar um arquivo para atualizar
	fprintf(file,nome);        
	fclose(file);
	
	file = fopen(arquivo, "a"); //se coloca o "A" pq eu não quero criar um outro arquivo, só quero acessar um arquivo para atualizar
	fprintf(file,",");          // SE COLOCA A "," PARA COLOCAR UMA VIRGULA NO FINAL DA INFORMAÇÃO
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //se coloca o "A" pq eu não quero criar um outro arquivo, só quero acessar um arquivo para atualizar
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //se coloca o "A" pq eu não quero criar um outro arquivo, só quero acessar um arquivo para atualizar
	fprintf(file,",");           // SE COLOCA A "," PARA COLOCAR UMA VIRGULA NO FINAL DA INFORMAÇÃO
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //se coloca o "A" pq eu não quero criar um outro arquivo, só quero acessar um arquivo para atualizar
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta() //função responsavel pela consulta de usuarios no sistema 
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
	printf ("Não foi possivel abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf ("\n Essas são as informações do usuario:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar() //função responsavel para deletar usuarios do sistema 
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    
    FILE *file;
    file = fopen(cpf,"r"); // O "r" SIGNIFICA LER O ARQUIVO (read)

    
    if(file == NULL)
    {
    printf("Usuario não se encontra no sistema .\n");
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
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls"); //ELE É O RESPONSAVEL POR LIMPAR A TELA

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opçãoo desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls");
	
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //CHAMADA DE FUNÇÕES
			break;
			
			case 2:
			consulta(); //CHAMADA DE FUNÇÕES
			break;
		
			case 3:
			deletar();//CHAMADA DE FUNÇÕES
			break;
		
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		} //fim da seleção
			
	}	
}
