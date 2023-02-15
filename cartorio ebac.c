#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h> 
#include <string.h>

int registro()
	{
		char arquivo[40];
		char cpf[40];
		char nome[40];	
		char sobrenome[40];
		char cargo[40];
		setlocale(LC_ALL, "portuguese");
		
		printf("Digite o CPF a ser cadastrado: ");
		scanf("%s", cpf); //le a entrada do usuario
		strcpy(arquivo, cpf); //função que copia a string pra variavel arquivo
		
		FILE *file; //cria o arquivo
		file =  fopen(arquivo, "w"); //cria o arquivo
		fprintf(file,cpf); //salvo o valor da variavel
		fclose(file); //fecha o arquivo
		file = fopen(arquivo, "a"); //abre o arquivo
		fprintf(file,","); //adiciona uma virgula
		fclose(file); //fecha o arquivo
				
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s", nome); 					//le a entrada do usuario
		file = fopen(arquivo, "a"); 		//abre o arquivo
		fprintf(file,nome); 				// salva a variavel no arquivo
		fclose(file);						//fecha o arquivo
		file = fopen(arquivo, "a"); 		//abre o arquivo
		fprintf(file,","); 					//adiciona uma virgula
		fclose(file); 						//fecha o arquivo
		
		printf("Digite o sobrenome a ser cadastrado : ");
		scanf("%s",sobrenome);				//le a entrada do usuario
		file = fopen(arquivo, "a"); 		//abre o arquivo
		fprintf(file,sobrenome);			//salva o valor da variavel no arquivo
		fclose(file);						//fecha o arquivo
		file = fopen(arquivo, "a"); 		//abre o arquivo
		fprintf(file,","); 					//adiciona uma virgula
		fclose(file); 						//fecha o arquivo
		
		printf("Digite o cargo do usuario: ");
		scanf("%s", cargo);					//le a entrada do usuario
		file = fopen(arquivo, "a");			//abre o arquivo
		fprintf(file,cargo);				//salva o valor da variavel no arquivo
		fclose(file);						//fecha o arquivo
		file = fopen(arquivo, "a"); 		//abre o arquivo
		fprintf(file,","); 					//adiciona uma virgula
		fclose(file);						//fecha o arquivo		
		system("pause");		
	}
	
int consulta()
	{
	
		char cpf[40];
		char conteudo[200];
		setlocale(LC_ALL, "portuguese");
		
			printf("Digite o cpf que deseja consultar : ");
			scanf("%s",cpf);				//le a entrada do usuario
			
			FILE *file;						//abre o arquivo
			file = fopen(cpf,"r");			//le o arquivo
			
			if(file == NULL)				//se a consulta nao existir
			{
				printf("Não foi possivel abrir o arquivo\n\n");
				
			}
			
			while(fgets(conteudo, 200, file) != NULL)   //se encontrar o cpf no banco
			{
				printf("\nEssas são as informações do usuário: ");
				printf("%s", conteudo);
				printf("\n\n");
			}
			system("pause");
	}
int deletar()
	{
		char cpf[40];
		
		printf("Insira o cpf que deseja deletar: ");
		scanf("%s", cpf);					//le a entrada do usuario
	
		FILE *file;							//abre o arquivo
		file = fopen(cpf, "r");				//busca no banco
		fclose(file);						//fecha o arquivo
		
		if(file == NULL)					//se nao encontrar o cliente
			{
			printf("Usuário nao encontrado!\n\n");
			system("pause");
  			}
  		else								//se encontrar o cliente
  			{  		  
			remove(cpf);
			printf("Usuário excluido com sucesso!\n\n");
			system("pause");
			}
		
	}
int main()

    {
    	int laco=1;
		for (laco=1;laco=1; )
	{
		system("cls");
		int opcao=0; //definindo variaveis
		setlocale(LC_ALL, "portuguese");
		printf("\t### Cartório da EBAC   ### \n\n");
		printf("\tEscolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n");
    	printf("\t4 - Sair\n");
    	printf("\t Opção: "); //fim do menu
    	scanf("%d", &opcao); //armazenando a escolha do usuário
    	system("cls");
    
    switch(opcao)
    {
    	case 1:
    	registro();
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o nosso sistema!\n\n");
		return 0;
		break;
		
		default: 
		printf("Essa opção não está disponivél!\n");
		system("pause");
		break;
	 //fim da seleção
	}
        
}
}

