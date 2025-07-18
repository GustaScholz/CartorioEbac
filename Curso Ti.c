#include <stdio.h> //biblioteca de comunição com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings
int registro()
{
     char arquivo[40]; //inicio da criação de variaveis/strings
	 char cpf[40];
     char nome[40];
     char sobrenome[40];
     char cargo[40]; //fim da criação de variaveis/strings
     
    printf("Digite o cpf a ser cadastrado: "); //perguntando ao usuario qual cpf deseja cadastrar
    scanf("%s", cpf); //salvando na vairavel cpf na string
    
    strcpy(arquivo, cpf); // Responsavel por copoiar os valores da strings
    
    FILE *file; //criar um arquivo
    file = fopen(arquivo, "w"); //criar um arquivo
    fprintf(file,cpf); //salvar o valor da variavel
    fclose(file); //fechar o arquivo
    
    file = fopen(arquivo, "a"); //abrindo o arquivo para atualizar ele
    fprintf(file,","); //colocando uma virgula para separar a variavel 
    fclose(file); //fechar o aquivo
    
    printf("Digite o nome a ser cadastrado: "); //perguntando ao usuario qual nome vai ser cadastrado
    scanf("%s",nome); //salvando na variavel nome na string
    
    file = fopen(arquivo, "a"); //abindo o arquivo para atualizar 
    fprintf(file,nome); //salvando o conteudo da variavel dentro do arquivo nome
    fclose(file); //fehcar o aquivo
    
    file = fopen(arquivo, "a"); //abrindo o arquivo para atualizar ele
    fprintf(file,","); //colocando uma virgula para separar a variavel 
    fclose(file); //fechar o aquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); // perguntando ao usuario
    scanf("%s",sobrenome); // salvando a variavel
    
    file = fopen(arquivo,"a"); // abrindo o arquivo para atualizar
    fprintf(file,sobrenome); // salvando o conteudo dentro do arquivo sobrenome
    fclose(file);  //fechando o arquivo
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para atualizar ele
    fprintf(file,","); //colocando uma virgula para separar a variavel 
    fclose(file); //fechar o aquivo
	
	printf("Digite o cargo a ser cadastrado: "); // perguntando ao usuario 
	scanf("%s",cargo); // salvando a variavel
	
	file = fopen(arquivo, "a"); //abrindo o arquivo para atualizar
	fprintf(file,cargo); // salvando o conteudo dentro do arquivo cargo
	fclose(file); //fechando o arquivo
	
	system("pause"); //serve para congelar a pagina antes de voltar para o inicio
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40]; //armazenar o conteudo 
	char conteudo[200]; // armazenar o conteudo
	
	printf("Digite o cpf a ser consultado:"); //perguntando ao usuario
	scanf("%s",cpf); //salvndo a variavel
	
	FILE *file; //consultar o arquivo ja criado
	file = fopen(cpf,"r"); //abrir o arquivo 
	
	if(file == NULL) //validar se o arquivo é nulo
	{
		printf("Não foi possivel abrir o arquivo, não localizado.\n"); //falando para o usuario que o arquivo não foi localizado
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:\n"); //informando o usuario
		printf("%s", conteudo); //salvar o conteudo
		printf("\n\n"); //pular linhas
	}
	
	system("pause"); //serve para congelar a pagina antes de voltar para o inicio
	
}

int deletar()
{
	char cpf[40]; //armazenamento do conteudo para deletar 
	
	printf("Digite o cpf a ser deletado: "); //perguntando ao asuario 
	scanf("%s",cpf);
	
	remove(cpf); //removendo um cadastro
	
	FILE *file; //orucurar o arquivo 
	file = fopen(cpf, "r"); //abrir o arquivo 
	 
	if(file == NULL)
	{
		printf("O Usuario não se encontra no sistema.\n"); //perguntando ao usuario 
		system("pause");
	}
	
	
	
}

int main()
{
	 int opcao=0; //definindo as opções que o usuario vai escolher
	 int laco=1;
	 char senhadigitada[]="a";
	 int comparacao;
	 
	 printf("### cartório da EBAC ###\n\n");
	 printf("Login de administrador!\n\nDigite sua seha:");
	 scanf("%s", senhadigitada);
	 
	 comparacao = strcmp(senhadigitada, "admin");
	 
	 if(comparacao == 0)
	 {
	 
	 
	 for(laco=1;laco=1;)
	 {
	 
	     system("cls"); //responsavel por limpar a tela 
	 
	      setlocale(LC_ALL, "Portuguese"); //definindo a linguagem 
	 
	     printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	     printf("Escolha a opção desejada no menu:\n\n");
	     printf("\t1 - Registrar nomes\n");
	     printf("\t2 - Consultar nomes\n");
	     printf("\t3 - Deletar nomes\n\n");
		 printf("\t4 - Sair do menu\n\n"); 
	     printf("opção:"); //fim do menu
	 
	     scanf("%d", &opcao); // armazenando a escolha do usuario 
	 
	     system("cls"); //responsalve por limpar a tela 
	 
	     switch(opcao) //incio da seleção do menu
	    {
	      case 1:
	      registro(); 
	      break;
	    
	      case 2:
	      consultar();
	      break;
	    
	      case 3:
	      deletar();
		  break;
		  
		  case 4:
		  printf("Obrigado por utilizar o sistema\n");
		  return 0;
		  break;
	    
	      default:
	      printf("essa opção não esta disponivel!\n");
	      system("pause");
	      break; //Fim da seleção
	      
	     }
       
	}

}
else
   printf("senha incorreta!");
}


