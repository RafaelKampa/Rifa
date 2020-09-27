#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define PRESENTER "\nPRESSIONE ENTER PARA CONTINUAR... !!! \n"
#define MEIO 40
#define TAM 50


typedef struct { // Struct Usuário
	int tipousuario; // 1 para Administrador e 2 para cliente
	char nome[100];
	char apelido [100];
	char sexo[1];
	char CPF[15];	
	char telefone[16];
	char email[100];
	char senha[100];
	char confirmasenha[100];
	int codigo;
	float gasto_total;
	int bilhetescomprados;
	int bilhetesreservados;
	int relatoriocompra[TAM];
	int relatorioreserva [TAM];
}Usuario;


//variavel grobal
int bilhetesorteio [TAM], bilhetesreserva [TAM], bilhetesnum [TAM];
int posicaoAtual = 0;
float valorbilhete = 0;
char rifa[TAM], premio1[TAM], premio2[TAM], premio3[TAM], premio4[TAM], premio5[TAM];
char tecla;
int s1, s2, s3, s4, s5 = 0; // Variáveis que guardam bilhetes sorteados
int cods1, cods2, cods3, cods4, cods5 = 0; // Códigos dos usuários ganhadores

Usuario Cadastro_Usuario[TAM];

struct Login{ // Para controle de Usuário Logado
	int codigo;
	int tipousuario; // 1 para Administrador e 2 para cliente
	char nome[100];
	char apelido [100];
	char senha[100];
};

struct Login Logado;

void zeraUsuarioLogado(){ // Zera a struct de Usuario Logado no sistema
int cont=0;
	for (cont=0;cont<TAM;cont++);
		Logado.codigo = 0;
		Logado.tipousuario = 0;
		strcpy (Logado.nome, "\0");
		strcpy (Logado.apelido, "\0");
		strcpy (Logado.senha, "\0");
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void simularUsuario(){
	int cont;

	posicaoAtual = 1;
	// LOGIN 1
  	Cadastro_Usuario[posicaoAtual].tipousuario = 1;
  	Cadastro_Usuario[posicaoAtual].codigo = 1;
	strcpy(Cadastro_Usuario[posicaoAtual].nome, "Rafael Kampa");
	strcpy(Cadastro_Usuario[posicaoAtual].apelido, "rafael");
	strcpy(Cadastro_Usuario[posicaoAtual].sexo, "M");	
	strcpy(Cadastro_Usuario[posicaoAtual].CPF, "076.115.729-89");
	strcpy(Cadastro_Usuario[posicaoAtual].telefone, "41 9.9289-3649");
	strcpy(Cadastro_Usuario[posicaoAtual].email, "rafael_kampa@hotmail.com");
	strcpy(Cadastro_Usuario[posicaoAtual].senha, "1234");
	Cadastro_Usuario[posicaoAtual].gasto_total=0;
	Cadastro_Usuario[posicaoAtual].bilhetescomprados=0;
	Cadastro_Usuario[posicaoAtual].bilhetesreservados=0;
	
	// LOGIN 2
	posicaoAtual = 2;
 	Cadastro_Usuario[posicaoAtual].tipousuario = 2;
  	Cadastro_Usuario[posicaoAtual].codigo = 2;
	strcpy(Cadastro_Usuario[posicaoAtual].nome, "Carolina Lara Mendes");
	strcpy(Cadastro_Usuario[posicaoAtual].apelido, "carol");
	strcpy(Cadastro_Usuario[posicaoAtual].sexo, "F");	
	strcpy(Cadastro_Usuario[posicaoAtual].CPF, "732.858.776-85");
	strcpy(Cadastro_Usuario[posicaoAtual].telefone, "41 9.9904-8024");
	strcpy(Cadastro_Usuario[posicaoAtual].email, "carol_mendes@hotmail.com");
	strcpy(Cadastro_Usuario[posicaoAtual].senha, "1234");
	Cadastro_Usuario[posicaoAtual].gasto_total=0;
	Cadastro_Usuario[posicaoAtual].bilhetescomprados=0;
	Cadastro_Usuario[posicaoAtual].bilhetesreservados=0;

	//LOGIN 3
	posicaoAtual = 3;
 	Cadastro_Usuario[posicaoAtual].tipousuario = 2;
  	Cadastro_Usuario[posicaoAtual].codigo = 3;
	strcpy(Cadastro_Usuario[posicaoAtual].nome, "Marlene Barboza");
	strcpy(Cadastro_Usuario[posicaoAtual].apelido, "marlene");
	strcpy(Cadastro_Usuario[posicaoAtual].sexo, "F");	
	strcpy(Cadastro_Usuario[posicaoAtual].CPF, "022.072.530-11");
	strcpy(Cadastro_Usuario[posicaoAtual].telefone, "41 3058-1617");
	strcpy(Cadastro_Usuario[posicaoAtual].email, "marlenebbz@gmail.com");
	strcpy(Cadastro_Usuario[posicaoAtual].senha, "1234");
	Cadastro_Usuario[posicaoAtual].gasto_total=0;
	Cadastro_Usuario[posicaoAtual].bilhetescomprados=0;
	Cadastro_Usuario[posicaoAtual].bilhetesreservados=0;
	
	//LOGIN 4
	posicaoAtual = 4;
 	Cadastro_Usuario[posicaoAtual].tipousuario = 2;
  	Cadastro_Usuario[posicaoAtual].codigo = 4;
	strcpy(Cadastro_Usuario[posicaoAtual].nome, "Jose da Silva Pedroza");
	strcpy(Cadastro_Usuario[posicaoAtual].apelido, "jose");
	strcpy(Cadastro_Usuario[posicaoAtual].sexo, "M");	
	strcpy(Cadastro_Usuario[posicaoAtual].CPF, "011.002.350-09");
	strcpy(Cadastro_Usuario[posicaoAtual].telefone, "41 9.9943-2550");
	strcpy(Cadastro_Usuario[posicaoAtual].email, "josesp@gmail.com");
	strcpy(Cadastro_Usuario[posicaoAtual].senha, "1234");
	Cadastro_Usuario[posicaoAtual].gasto_total=0;
	Cadastro_Usuario[posicaoAtual].bilhetescomprados=0;
	Cadastro_Usuario[posicaoAtual].bilhetesreservados=0;
	
	//LOGIN 5
	posicaoAtual = 5;
 	Cadastro_Usuario[posicaoAtual].tipousuario = 2;
  	Cadastro_Usuario[posicaoAtual].codigo = 5;
	strcpy(Cadastro_Usuario[posicaoAtual].nome, "Ana Paula dos Santos");
	strcpy(Cadastro_Usuario[posicaoAtual].apelido, "ana");
	strcpy(Cadastro_Usuario[posicaoAtual].sexo, "F");	
	strcpy(Cadastro_Usuario[posicaoAtual].CPF, "002.580.369-78");
	strcpy(Cadastro_Usuario[posicaoAtual].telefone, "41 9.9100-2670");
	strcpy(Cadastro_Usuario[posicaoAtual].email, "aninha@outlook.com.br");
	strcpy(Cadastro_Usuario[posicaoAtual].senha, "1234");
	Cadastro_Usuario[posicaoAtual].gasto_total=0;
	Cadastro_Usuario[posicaoAtual].bilhetescomprados=0;
	Cadastro_Usuario[posicaoAtual].bilhetesreservados=0;
	
	//LOGIN 6
	posicaoAtual = 6;
 	Cadastro_Usuario[posicaoAtual].tipousuario = 2;
  	Cadastro_Usuario[posicaoAtual].codigo = 6;
	strcpy(Cadastro_Usuario[posicaoAtual].nome, "Nadir Siqueira");
	strcpy(Cadastro_Usuario[posicaoAtual].apelido, "nadir");
	strcpy(Cadastro_Usuario[posicaoAtual].sexo, "F");	
	strcpy(Cadastro_Usuario[posicaoAtual].CPF, "055.085.789-21");
	strcpy(Cadastro_Usuario[posicaoAtual].telefone, "41 9.9563-7896");
	strcpy(Cadastro_Usuario[posicaoAtual].email, "nadir@yahoo.com.br");
	strcpy(Cadastro_Usuario[posicaoAtual].senha, "1234");
	Cadastro_Usuario[posicaoAtual].gasto_total=0;
	Cadastro_Usuario[posicaoAtual].bilhetescomprados=0;
	Cadastro_Usuario[posicaoAtual].bilhetesreservados=0;
	
	//LOGIN 7
	posicaoAtual = 7;
 	Cadastro_Usuario[posicaoAtual].tipousuario = 2;
  	Cadastro_Usuario[posicaoAtual].codigo = 7;
	strcpy(Cadastro_Usuario[posicaoAtual].nome, "Gustavo de Oliveira");
	strcpy(Cadastro_Usuario[posicaoAtual].apelido, "gustavo");
	strcpy(Cadastro_Usuario[posicaoAtual].sexo, "M");	
	strcpy(Cadastro_Usuario[posicaoAtual].CPF, "123.456.987-25");
	strcpy(Cadastro_Usuario[posicaoAtual].telefone, "41 9.9741-5672");
	strcpy(Cadastro_Usuario[posicaoAtual].email, "gustavo.oliva@yahoo.com.br");
	strcpy(Cadastro_Usuario[posicaoAtual].senha, "1234");
	Cadastro_Usuario[posicaoAtual].gasto_total=0;
	Cadastro_Usuario[posicaoAtual].bilhetescomprados=0;
	Cadastro_Usuario[posicaoAtual].bilhetesreservados=0;
	
	//LOGIN 8
	posicaoAtual = 8;
 	Cadastro_Usuario[posicaoAtual].tipousuario = 2;
  	Cadastro_Usuario[posicaoAtual].codigo = 8;
	strcpy(Cadastro_Usuario[posicaoAtual].nome, "Diogo Benedito Duarte");
	strcpy(Cadastro_Usuario[posicaoAtual].apelido, "diogo");
	strcpy(Cadastro_Usuario[posicaoAtual].sexo, "M");	
	strcpy(Cadastro_Usuario[posicaoAtual].CPF, "098.146.261-80");
	strcpy(Cadastro_Usuario[posicaoAtual].telefone, "41 9.9687-2122");
	strcpy(Cadastro_Usuario[posicaoAtual].email, "ddiogoduarte@gmail.com");
	strcpy(Cadastro_Usuario[posicaoAtual].senha, "1234");
	Cadastro_Usuario[posicaoAtual].gasto_total=0;
	Cadastro_Usuario[posicaoAtual].bilhetescomprados=0;
	Cadastro_Usuario[posicaoAtual].bilhetesreservados=0;
	
	//LOGIN 9
	posicaoAtual = 9;
 	Cadastro_Usuario[posicaoAtual].tipousuario = 2;
  	Cadastro_Usuario[posicaoAtual].codigo = 9;
	strcpy(Cadastro_Usuario[posicaoAtual].nome, "Gabriela Aline Lívia Ribeiro");
	strcpy(Cadastro_Usuario[posicaoAtual].apelido, "gabi");
	strcpy(Cadastro_Usuario[posicaoAtual].sexo, "F");	
	strcpy(Cadastro_Usuario[posicaoAtual].CPF, "067.939.061-86");
	strcpy(Cadastro_Usuario[posicaoAtual].telefone, "41 9.9728-7483");
	strcpy(Cadastro_Usuario[posicaoAtual].email, "gabialine@tanby.com.br");
	strcpy(Cadastro_Usuario[posicaoAtual].senha, "1234");
	Cadastro_Usuario[posicaoAtual].gasto_total=0;
	Cadastro_Usuario[posicaoAtual].bilhetescomprados=0;
	Cadastro_Usuario[posicaoAtual].bilhetesreservados=0;
	
	//LOGIN 10
	posicaoAtual = 10;
 	Cadastro_Usuario[posicaoAtual].tipousuario = 2;
  	Cadastro_Usuario[posicaoAtual].codigo = 10;
	strcpy(Cadastro_Usuario[posicaoAtual].nome, "Luiza Pinto");
	strcpy(Cadastro_Usuario[posicaoAtual].apelido, "luiza");
	strcpy(Cadastro_Usuario[posicaoAtual].sexo, "F");	
	strcpy(Cadastro_Usuario[posicaoAtual].CPF, "858.532.780-45");
	strcpy(Cadastro_Usuario[posicaoAtual].telefone, "41 9.9262-8262");
	strcpy(Cadastro_Usuario[posicaoAtual].email, "luizasantospinto@cuvox.de");
	strcpy(Cadastro_Usuario[posicaoAtual].senha, "1234");
	Cadastro_Usuario[posicaoAtual].gasto_total=0;
	Cadastro_Usuario[posicaoAtual].bilhetescomprados=0;
	Cadastro_Usuario[posicaoAtual].bilhetesreservados=0;
	
	//LOGIN 11
	posicaoAtual = 11;
 	Cadastro_Usuario[posicaoAtual].tipousuario = 2;
  	Cadastro_Usuario[posicaoAtual].codigo = 11;
	strcpy(Cadastro_Usuario[posicaoAtual].nome, "Luan Correa");
	strcpy(Cadastro_Usuario[posicaoAtual].apelido, "luan");
	strcpy(Cadastro_Usuario[posicaoAtual].sexo, "M");	
	strcpy(Cadastro_Usuario[posicaoAtual].CPF, "153.248.967-64");
	strcpy(Cadastro_Usuario[posicaoAtual].telefone, "41 9.9487-2003");
	strcpy(Cadastro_Usuario[posicaoAtual].email, "luanrodriguescorreia@teleworm.us");
	strcpy(Cadastro_Usuario[posicaoAtual].senha, "1234");
	Cadastro_Usuario[posicaoAtual].gasto_total=0;
	Cadastro_Usuario[posicaoAtual].bilhetescomprados=0;
	Cadastro_Usuario[posicaoAtual].bilhetesreservados=0;

	//LOGIN 12
	posicaoAtual = 12;
 	Cadastro_Usuario[posicaoAtual].tipousuario = 2;
  	Cadastro_Usuario[posicaoAtual].codigo = 12;
	strcpy(Cadastro_Usuario[posicaoAtual].nome, "Gabrielle Melo");
	strcpy(Cadastro_Usuario[posicaoAtual].apelido, "gabrielle");
	strcpy(Cadastro_Usuario[posicaoAtual].sexo, "F");	
	strcpy(Cadastro_Usuario[posicaoAtual].CPF, "781.613.442-80");
	strcpy(Cadastro_Usuario[posicaoAtual].telefone, "41 9.9033-2550");
	strcpy(Cadastro_Usuario[posicaoAtual].email, "gabriellecunhamelo@armyspy.com");
	strcpy(Cadastro_Usuario[posicaoAtual].senha, "1234");
	Cadastro_Usuario[posicaoAtual].gasto_total=0;
	Cadastro_Usuario[posicaoAtual].bilhetescomprados=0;
	Cadastro_Usuario[posicaoAtual].bilhetesreservados=0;
}

void simulaBilhetesComprados(){
int i, j, x, y = 0;
j = 2;
y=1;
	for (i=0; i<=44; i++){
		bilhetesorteio[i] = Cadastro_Usuario[j].codigo;
		bilhetesnum[i] = 1;
		Cadastro_Usuario[Cadastro_Usuario[j].codigo].bilhetescomprados = Cadastro_Usuario[j].bilhetescomprados + 1;
		Cadastro_Usuario[Cadastro_Usuario[j].codigo].relatoriocompra[i] = i;
		Cadastro_Usuario[Cadastro_Usuario[j].codigo].gasto_total = y*valorbilhete;
		x++;
		y++;
			if (x==4){
				j++;
				x=0;
				y=1;
		}
	}
}

int autenticarPessoa(char apelido[], char senha[]){
	int i = 0;
	int igual = -1; 
	int retorno = 0;  
	
	for(i=0; i < TAM;i++){		
		igual = strcmp(Cadastro_Usuario[i].apelido, apelido);
		if (igual == 0){ 
			igual = strcmp(Cadastro_Usuario[i].senha, senha);
			if (igual == 0){ 
				retorno	= 1; 
				
				Logado.tipousuario = Cadastro_Usuario[i].tipousuario;
				Logado.codigo = Cadastro_Usuario[i].codigo;
				strcpy(Logado.nome, Cadastro_Usuario[i].nome);
				strcpy(Logado.apelido, Cadastro_Usuario[i].apelido);
				strcpy(Logado.senha, Cadastro_Usuario[i].senha);
			}						
			break; 
		}
	}
	return retorno; 
}

void telaGanhador(){
	int tamanhovetor, posicaogoto = 0;
	if ((Logado.codigo==cods1) || (Logado.codigo==cods2) || (Logado.codigo==cods3) || (Logado.codigo==cods4) || (Logado.codigo==cods5)){
	system("cls");
			gotoxy(36,3);
			printf ("PARAB%cNS!!!", 144);
			gotoxy (25,6);
			printf ("VOC%c FOI O VENCEDOR DO PR%cMIO:", 210, 210);		
		
		if (Logado.codigo==cods1){
			tamanhovetor = strlen(premio1);
			posicaogoto = (tamanhovetor/2)+16;
			gotoxy (40-posicaogoto,8);
			printf ("%c BILHETE N%c %i %c 1%c PR%CMIO %c %s %c", 1, 248, s1+1, 175, 248, 210, 175, premio1, 1);
		}
		if (Logado.codigo==cods2){
			tamanhovetor = strlen(premio2);
			posicaogoto = (tamanhovetor/2)+16;
			gotoxy (40-posicaogoto,9);
			printf ("%c BILHETE N%c %i %c 2%c PR%CMIO %c %s %c", 1, 248, s2+1, 175, 248, 210, 175, premio2, 1);
		}
		if (Logado.codigo==cods3){
			tamanhovetor = strlen(premio3);
			posicaogoto = (tamanhovetor/2)+16;
			gotoxy (40-posicaogoto,10);
			printf ("%c BILHETE N%c %i %c 3%c PR%CMIO %c %s %c", 1, 248, s3+1, 175, 248, 210, 175, premio3, 1);
		}
		if (Logado.codigo==cods4){	
			tamanhovetor = strlen(premio4);
			posicaogoto = (tamanhovetor/2)+16;
			gotoxy (40-posicaogoto,11);
			printf ("%c BILHETE N%c %i %c 4%c PR%CMIO %c %s %c", 1, 248, s4+1, 175, 248, 210, 175, premio4, 1);
		}
		if (Logado.codigo==cods5){	
			tamanhovetor = strlen(premio5);
			posicaogoto = (tamanhovetor/2)+16;
			gotoxy (40-posicaogoto,12);
			printf ("%c BILHETE N%c %i %c 5%c PR%CMIO %c %s %c", 1, 248, s5+1, 175, 248, 210, 175, premio5, 1);
		}
		gotoxy(12,19);
		printf ("CONTATE O ADMINISTRADOR PARA REINVINDICAR O SEU PR%cMIO!", 210);
		gotoxy (24,20);
		printf ("PRESSIONE ENTER PARA CONTINUAR...");
		
	}
	else{
		menuprincipal();
	}
	getch();
}

void Login_Tela(){
	int cont = 0;
	char apelido[100];
	char senha[100];
	int autenticado = 0;

    for(cont = 1;cont <= 1;cont++){	
    	printf("\n");
		meiotela (MEIO-3);
		printf("LOGIN\n\n");
		meiotela (MEIO-22);
		printf("DIGITE SEUS DADOS ABAIXO PARA EFETUAR LOGIN!\n", -75, -75);

		// ler apelido que é o nome do usuario
		printf("Apelido: \n");
		do{
			gotoxy(9,4);
			fflush(stdin);
			gets(apelido);
		}while (strcmp(apelido, "\0")==0);
		// ler senha
		printf("Senha: \n");
		do{
			gotoxy(7,5);
			fflush(stdin);
			gets(senha);
		}while (strcmp(senha, "\0")==0);
		
		autenticado = autenticarPessoa(apelido, senha);
		if (autenticado == 0){
			system("cls");
			printf("DADOS DO LOGIN INVALIDOS ");
			printf (PRESENTER);
			getch();
			tela_Login_ou_Cadastro();
		}else {
			printf("LOGADO COM SUCESSO");
			printf (PRESENTER);
	        getch();
	        system("cls");
	        telaGanhador();
//	        menuprincipal();//COLOCAR AQUI A MENSAGEM DE QUE O USUARIO GANHOU

		}
	}
		
}

void meiotela(int qtd){
	int i = 0;
	for(i=1; i<=qtd;i++){
		printf(" ");	
	}
}

void telainicial(){
system("color F0");
printf ("\n\n");
meiotela (MEIO-18);	
printf ("%c%c%c%c%c%c%c%c    %c%c   %c%c%c%c%c%c%c%c     %c%c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219 ,219, 219, 219, 219);
meiotela (MEIO-18);	
printf ("%c%c     %c%c        %c%c          %c%c %c%c\n", 219, 219, 219, 219, 219, 219, 219, 219, 219, 219);
meiotela (MEIO-18);	
printf ("%c%c     %c%c   %c%c   %c%c         %c%c   %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178);
meiotela (MEIO-18);
printf ("%c%c%c%c%c%c%c%c    %c%c   %c%c%c%c%c%c    %c%c     %c%c\n", 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178 ,178, 178, 178, 178, 178, 178);
meiotela (MEIO-18);	
printf ("%c%c%c%c%c%c%c     %c%c   %c%c        %c%c%c%c%c%c%c%c%c\n", 177, 177, 177, 177, 177, 177, 177,177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177, 177 ,177, 177, 177, 177);
meiotela (MEIO-18);	
printf ("%c%c   %c%c     %c%c   %c%c        %c%c     %c%c\n", 177, 177, 177, 177, 177, 177, 177,177, 177, 177, 177, 177);
meiotela (MEIO-18);	
printf ("%c%c    %c%c    %c%c   %c%c        %c%c     %c%c\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176);
meiotela (MEIO-18);	
printf ("%c%c     %c%c   %c%c   %c%c        %c%c     %c%c\n\n\n\n\n\n", 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176);
meiotela (MEIO-17);	
printf ("Pressione uma tecla para Continuar!\n\n\n\n\n\n\n\n");
meiotela (MEIO-21);
printf ("Desenvolvido por Jo%co Pedro e Rafael Kampa.",198);
getch();
tela_Login_ou_Cadastro();
}

void desenhatelaBilhetes(){
int bilhetestela[TAM], cont, cont10;
cont = cont10 = 0;	
	//Imprimindo os numeros na tela
	system ("cls");
	printf("Rifa: %s", rifa);
	printf("\nValor do Bilhete: R%c %.2f", 36, valorbilhete);
	cont10 = 1;
	system("color F0");//Cor da Tela, Cor da Letra
	printf("\n\n");
	meiotela (MEIO-9);
	printf("COMPRA DE BILHETES \n\n\n\n");
	for(cont=1; cont<=TAM;cont++){

				if (cont<10){
					if ((bilhetesnum[cont-1]==0) && (bilhetesorteio[cont-1]==0) && (Cadastro_Usuario[cont].relatoriocompra[cont-1] == 0)){
						printf(" 0%i [ ] ", cont);	
					}
					else if ((bilhetesnum[cont-1]==1) || (bilhetesorteio[cont-1]==1) || (Cadastro_Usuario[cont].relatoriocompra[cont-1] == 1)){
						printf(" 0%i [C] ", cont);	
					}
					else if (bilhetesnum[cont-1]==2){
						printf(" 0%i [R] ", cont);	
					}
				}
				if ((cont>=10) && (cont<=TAM)){
					if (bilhetesnum[cont-1]==0){
						printf(" %i [ ] ", cont);	
					}
					else if ((bilhetesnum[cont-1]==1) || (bilhetesorteio[cont-1]==1) || (Cadastro_Usuario[cont].relatoriocompra[cont-1] == 1)){
						printf(" %i [C] ", cont);	
					}
					else if ((bilhetesnum[cont-1]==2) || (Cadastro_Usuario[cont].relatoriocompra[cont-1] == 2)){
						printf(" %i [R] ", cont);	
					}
				}		
		
				if(cont10 == 10){
					printf("\n");
					cont10 = 0;
				}
				cont10++;
			}
}

void selecionaBilhetes(){
#define TECLA_C 99 //Tecla para comprar "c"
#define TECLA_C_M 67 //Tecla para comprar "c"

#define TECLA_R 114 //Tecla para reservar "r"
#define TECLA_R_M 82 //Tecla para reservar "r"

#define TECLA_X 120 //Tecla para cancelar "x"
#define TECLA_X_M 88 //Tecla para cancelar "x"

int cont, bilheteselecionado = 0;
char tecla;
	if (valorbilhete!=0){
		do{
			desenhatelaBilhetes();
			gotoxy (0,18);
			printf ("Digite o n%cmero que deseja selecionar ou [0] para sair: [  ]",163);
			gotoxy (57,18);
			fflush (stdin);
			scanf ("%i", &bilheteselecionado);
				if (bilheteselecionado!=0){
					// Primeiro analisa se o número ja está comprado ou reservado na tabela, e se o número em questão não foi adquirido ou reservado pelo usuário logado
					// Este controle permite que o usuário cancele somente os números que ele adquiriu ou reservou
					if (((bilhetesnum[bilheteselecionado-1]==1) && (bilhetesorteio[bilheteselecionado-1] != Logado.codigo)) || ((bilhetesnum[bilheteselecionado-1] == 2) && 
					(bilhetesreserva[bilheteselecionado-1] != Logado.codigo))){
						system ("cls");
						printf("\nBilhete indispon%cvel!", 161);
						printf (PRESENTER);
						getch();
						system ("cls");
						selecionaBilhetes();
					}
					gotoxy (10,20);
					printf("Digite [C] para Comprar, [R] para reservar o n%cmero digitado,\n",163);
					gotoxy (16,21);
					printf(" [X] para cancelar uma reserva ou [0] para Sair.");
					gotoxy (39,22);
					printf ("[ ]");
					gotoxy (40,22);
					fflush (stdin);
					scanf ("%c", &tecla);
					cont++;
					// COMPRA
					if ((tecla == TECLA_C) || (tecla == TECLA_C_M)){
							if (bilhetesnum[bilheteselecionado-1] == 1){ // Impede que o usuário compre novamente o mesmo número
								system ("cls");
								printf("\Bilhete indispon%cvel para esta a%c%co!", 161, 135, 198);
								printf (PRESENTER);
								getch();
								system ("cls");
								selecionaBilhetes();							
							}
							else{
									if (bilhetesnum[bilheteselecionado-1] == 2){
										if (Cadastro_Usuario[Logado.codigo].bilhetesreservados >= 1){
											Cadastro_Usuario[Logado.codigo].bilhetesreservados = Cadastro_Usuario[Logado.codigo].bilhetesreservados - 1;
										}
										Cadastro_Usuario[Logado.codigo].relatorioreserva[bilheteselecionado] = 0;
										bilhetesreserva[bilheteselecionado-1] = 0;
									}
								bilhetesnum[bilheteselecionado-1] = 1; // 1 - Comprar
								bilhetesorteio[bilheteselecionado-1] = Logado.codigo;
								Cadastro_Usuario[Logado.codigo].gasto_total = Cadastro_Usuario[Logado.codigo].gasto_total + valorbilhete;
								Cadastro_Usuario[Logado.codigo].bilhetescomprados = Cadastro_Usuario[Logado.codigo].bilhetescomprados +1; 
								Cadastro_Usuario[Logado.codigo].relatoriocompra[bilheteselecionado-1] = bilheteselecionado;
								}
					}
					// RESERVA
					else if ((tecla == TECLA_R) || (tecla == TECLA_R_M)){
							if (bilhetesnum[bilheteselecionado-1] !=0){ // Impede que o usuário reserve novamente o mesmo número
								system ("cls");
								printf("\Bilhete indispon%cvel para esta a%c%co!", 161, 135, 198);
								printf (PRESENTER);
								getch();
								system ("cls");
								selecionaBilhetes();							
							}
							else{
								bilhetesnum[bilheteselecionado-1] = 2; // 2 - Reservar
								bilhetesreserva[bilheteselecionado-1] = Logado.codigo;
								Cadastro_Usuario[Logado.codigo].bilhetesreservados = Cadastro_Usuario[Logado.codigo].bilhetesreservados+1;
								Cadastro_Usuario[Logado.codigo].relatorioreserva[bilheteselecionado] = bilheteselecionado;
								}
					}
					//CANCELA OS BILHETES COMPRADOS OU RESERVADOS
					else if ((tecla == TECLA_X) || (tecla == TECLA_X_M)){ // 0 - Cancela
						if (bilhetesnum[bilheteselecionado-1]==0){ // Impede que seja cancelado um número que ainda está disponível
							system ("cls");
							printf("\nBilhete indispon%cvel para cancelamento!", 161);
							printf (PRESENTER);
							getch();
						}
						else if (bilhetesnum[bilheteselecionado-1]==1){ // Remove bilhete comprado do usuário
							Cadastro_Usuario[Logado.codigo].bilhetescomprados = Cadastro_Usuario[Logado.codigo].bilhetescomprados -1;
							Cadastro_Usuario[Logado.codigo].relatoriocompra[bilheteselecionado-1] = 0;
							Cadastro_Usuario[Logado.codigo].gasto_total = Cadastro_Usuario[Logado.codigo].gasto_total - valorbilhete;
						}
						else{// Remove bilhete reservado do usuário
							Cadastro_Usuario[Logado.codigo].bilhetesreservados = Cadastro_Usuario[Logado.codigo].bilhetesreservados -1 ;
							Cadastro_Usuario[Logado.codigo].relatorioreserva[bilheteselecionado] = 0;
						}
						bilhetesnum[bilheteselecionado-1] = 0; // 0 - Livre
						bilhetesorteio[bilheteselecionado-1] = 0;
						bilhetesreserva[bilheteselecionado-1] = 0;
						Cadastro_Usuario[Logado.codigo].relatoriocompra[bilheteselecionado-1] = 0;
						Cadastro_Usuario[Logado.codigo].relatorioreserva[bilheteselecionado-1] = 0;
					}
				}
				else {
					system ("cls");
					menuprincipal();
				}
			}while ((tecla!=48) && (bilheteselecionado!=0));
	menuprincipal();
	}//IF RIFA CADASTRADA
	else{
		system ("cls");
		gotoxy (28,10);
		printf ("NENHUMA RIFA CADASTRADA!");
		gotoxy (26,11);
		printf("RETORNANDO AO MENU PRINCIPAL.");
		sleep(1);
		printf (".");
		sleep(1);
		printf (".");
		sleep(1);
	    system ("cls");
		menuprincipal();
	}
}

void menuprincipal(){

	system("cls");
	int s, i, cont, cont10 = 0;
	char menu1, menu2;
	printf(" Bem vindo: ");
	gotoxy (12,0);
	puts(Logado.nome);
	printf(" Rifa: ");
	gotoxy (7,1);
	puts(rifa);
	printf("\n");
	meiotela (MEIO-7);
	printf ("MENU PRINCIPAL");
	printf ("\n\n\n\n");
		if (Logado.tipousuario == 1){ // MENU DE ADMINISTRADOR
			meiotela (MEIO-10);
			printf ("[1] CADASTRO DE RIFA");
			printf ("\n\n");
			meiotela (MEIO-11);
			printf ("[2] COMPRA DE BILHETES");		
			printf ("\n\n");
			meiotela (MEIO-13);
			printf ("[3] EMISS%cO DE RELAT%cRIOS", -57 ,-32);		
			printf ("\n\n");
			meiotela (MEIO-6);
			printf ("[4] SORTEAR");
			printf ("\n\n");
			meiotela (MEIO-5);
			printf ("[5] LOGOFF");
			printf ("\n\n");
			meiotela (MEIO-4);
			printf ("[0] SAIR");
			printf ("\n\n\n");
			meiotela (MEIO-9);
			printf ("Digite uma op%c%co: ", -121, -58);
			fflush(stdin);
			scanf ("%c",&menu1); 
		    while (menu1 !=48){
		        system("cls");    
		        switch (menu1) {
		        	case 49: // Puxa a Tela de Cadastro de Rifa
		        	    cadastroDerifa();
		                break;            
		            case 50: // Puxa a Tela de Compra de Bilhetes
						selecionaBilhetes ();
		                getch(); 
		                break;
		            case 51: // Puxa Tela de Relatórios
						relatoriosTelaADM();
						system("color F0");//Cor da Tela, Cor da Letra
		                fflush (stdin);
						scanf ("%c",&menu2);
		                if ((menu2 != 48) && (menu2 != 49) && (menu2 != 50) && (menu2 != 51)) { // Digito Errado
		                	system("cls");
			               	gotoxy (18,10);
		                	printf("ERRRO DIGITE APENAS AS TECLAS INFORMADAS!!!");
		                	gotoxy (23,11);
		                	printf ("PRESSIONE ENTER PARA CONTINNUAR!!!");
							getch();
		            		system("cls");
		            		relatoriosTelaADM();
		            		scanf ("%c",&menu2);
			            }
						else if (menu2 == 49) { // Emitir Relatório de bilhetes adquiridos
	                    	system("cls");
							relatorioCompraADM();
						   	printf (PRESENTER);
		                    getch();
		                } 
						else if (menu2 == 50) { // Inicia SubMenu de relatório
	                 	  	system("cls");
							relatorioVenda();
						   	printf (PRESENTER);
		                    getch();
		                }
						else if (menu2 == 51) { // Inicia SubMenu de relatório
							system("cls");
							relatorioClientes();
						   	printf (PRESENTER);
		                    getch();
		                }
						else if (menu2 == 48) { // Retorna
		                	system("cls");
		 					break;
			            }
			            break;
			      	case 52: // // Puxa Tela de Sorteio
						sorteio();
					    break;
					case 53: //Logoff
					zeraUsuarioLogado();
					system("cls");
					tela_Login_ou_Cadastro();
					break;
					default:
	                	system("cls");
		               	gotoxy (18,10);
	                	printf("ERRRO DIGITE APENAS AS TECLAS INFORMADAS!!!");
	                	gotoxy (23,11);
	                	printf ("PRESSIONE ENTER PARA CONTINNUAR!!!");
						getch();
		    	} // switch    
			        menuprincipal();
		    }//while
				encerraSistema();
				menuprincipal();
		}//if
		if (Logado.tipousuario == 2){ // MENU CLIENTE
			meiotela (MEIO-11);
			printf ("[1] COMPRA DE BILHETES");		
			printf ("\n\n");
			meiotela (MEIO-13);
			printf ("[2] EMISS%cO DE RELAT%cRIOS", -57 ,-32);		
			printf ("\n\n");
			meiotela (MEIO-6);
			printf ("[3] LOGOFF");
			printf ("\n\n");
			meiotela (MEIO-4);
			printf ("[0] SAIR");
			printf ("\n\n\n");
			meiotela (MEIO-9);
			printf ("Digite uma op%c%co: ", -121, -58);
			fflush (stdin);
			scanf ("%c",&menu1); 
		    while (menu1 !=48){
		        system("cls");    
		        switch (menu1) {
		            case 49: // Puxa a Tela de Compra de Bilhetes
						selecionaBilhetes ();
		                getch(); 
		                break;
		            case 50: // Puxa Tela de Relatórios
						relatoriosTelaCliente();
						system("color F0");//Cor da Tela, Cor da Letra
		                fflush (stdin);
						scanf ("%c",&menu2);
		               		if ((menu2 != 48) && (menu2 != 49)) { // Digito Errado
		                	    system("cls");
		            			printf ("\nDigite uma op%c%co v%clida\n", -121, -58, -96);
		            			printf (PRESENTER);
			            		getch();
			            		system("cls");
		            			relatoriosTelaCliente();
		            			fflush(stdin);
		            			scanf ("%c",&menu2);
			            }
						else if (menu2 == 49) { // Emitir Relatório de bilhetes adquiridos
		                    system("cls");
		 					relatorioCompraCliente();
						   	printf (PRESENTER);
		                    getch();
		                } 
						else if (menu2 == 48) { // Retorna
		                    system("cls");
		 					break;
			            }
			            break;
					case 51: //Logoff
						zeraUsuarioLogado();
						tela_Login_ou_Cadastro();	
					break;
					default:    
                		system("cls");
	               		gotoxy (18,10);
                		printf("ERRRO DIGITE APENAS AS TECLAS INFORMADAS!!!");
                		gotoxy (23,11);
                		printf ("PRESSIONE ENTER PARA CONTINNUAR!!!");
						getch();
		    	} // switch    
			        menuprincipal();
		    }//while
				encerraSistema();
				menuprincipal();
			}//if
}

void tela_Login_ou_Cadastro(){
	system("cls");
	int menu1, menu2, cpf, telefone, valorbilhete, s, i, cont, cont10;
	char nomelogin [20], sexo [1], rifa, produto, senhalogin;
	senhalogin = cpf = telefone = valorbilhete = s = i = cont = cont10 = 0;
	printf ("\n");
	meiotela (MEIO-13);
	
    printf ("LOGIN / CADASTRO DE USU%cRIO\n\n\n", -75);
    meiotela (MEIO -25);
    printf("EFETUE LOGIN OU CADASTRO PARA ENTRAR NO SISTEMA!!!");
    printf ("\n\n\n\n");
    meiotela (MEIO-5);
    printf ("[1] LOGIN");
    printf ("\n\n");
    meiotela (MEIO-12);
    printf ("[2] CADASTRO DE USU%cRIO", -75);
    printf ("\n\n");
    meiotela (MEIO-5);
    printf ("[0] SAIR");
    printf ("\n\n\n");
    meiotela (MEIO-9);
	printf ("Digite uma op%c%co: ", -121, -58);
	scanf ("%i",&menu2);
                if (menu2 == 1) { // Inicia SubMenu de Login
                    system("cls");
 						Login_Tela();
                }//if
				else if (menu2 == 2) { // Inicia SubMenu de Cadastro de Usuário
	              		system("cls");
						system("color F0");//Cor da Tela             		
						TelacadastroDeusuario();
                }// else if
				else if(menu2 == 0){ // Encerra sistema
					encerraSistema();
					tela_Login_ou_Cadastro();
				}//else if
				else{ // Erro ao digitar a tecla
                	system("cls");
	               	gotoxy (18,12);
                	printf("ERRRO DIGITE APENAS AS TECLAS INFORMADAS!!!");
                	gotoxy (23,13);
                	printf ("PRESSIONE ENTER PARA CONTINNUAR!!!");
					getch();
					system ("cls");
                	tela_Login_ou_Cadastro();
				}//else
}//void

void senhaADM(int *tipousuario){
char senhaadm[6], enter;

system ("cls");
gotoxy (8,9);
printf ("DIGITE 1 PARA INSERIR A SENHA PARA CADASTRO DE NOVO ADMINISTRADOR");
gotoxy (30,10);
printf ("OU DIGITE 0 PARA SAIR");
gotoxy(39,11);
printf ("[ ]");
gotoxy(40,11);
fflush(stdin);
scanf ("%c", &enter);
	if (enter==49){
		gotoxy (33,13);
		printf ("Senha: [      ]");
		gotoxy (41,13);
		fflush (stdin);
		gets (senhaadm);
			if (strcmp (senhaadm, "147258")==0){ //COMPARA COM A SENHA DEFINIDA PARA CADASTRO DE USUÁRIO ADMINISTRADOR
				gotoxy (32,16);
				printf ("SENHA CONFIRMADA!");
				gotoxy (25,17);
				printf ("PRESSIONE ENTER PARA CONTINUAR!");
				*tipousuario = 1;
				Cadastro_Usuario[posicaoAtual+1].tipousuario = 1;
				getch();
				system("cls");
				PreenchecadastroDeusuario();
			}
			else{
				system ("cls");
				gotoxy (33,10);
				printf ("SENHA INV%cLIDA!",181);
				gotoxy (24,14);
				printf ("PRESSIONE ENTER PARA CONTINUAR!!!");
				getch();
				TelacadastroDeusuario();
			}
	}
}

void TelacadastroDeusuario(){
	int tipousuariox;
	char opcaodecadastro;
	//Dados a serem preenchidos pelo usuário
			system("cls");
			gotoxy (30,1);
			printf("CADASTRO DE USU%cRIO", 181);	//Nome da tela
				gotoxy (20, 5);
				printf("PARA CADASTRAR UM ADMINISTRADIR DIGITE 1");
				gotoxy (23, 6);
				printf ("PARA CADASTRAR UM CLIENTE DIGITE 2");
				gotoxy (29, 7);
				printf ("OU DIGITE 0 PARA VOLTAR");
				gotoxy (39, 8);
				printf ("[ ]");
				printf("\nNome: \n");
				printf("Apelido: \n");
				printf("Sexo [F ou M]: \n");
				printf("CPF: \n");
				printf("Telefone: \n");
				printf("e-mail: \n");
				printf("Digite uma senha: \n");
				printf("Confirme a Senha: \n");
						gotoxy(40,8); // Cursor para digitar o tipo de Usuário
					  	fflush(stdin);
						scanf("%c", &opcaodecadastro);
						if (opcaodecadastro == 48){
							system ("cls");
							tela_Login_ou_Cadastro();
						}
						if (opcaodecadastro == 49){
							senhaADM (&tipousuariox);
							Cadastro_Usuario[posicaoAtual+1].tipousuario = tipousuariox;
							gotoxy(40,8);
							printf ("%i", Cadastro_Usuario[posicaoAtual+1].tipousuario);
						}
						else if ((opcaodecadastro != 49) && (opcaodecadastro != 50)){
							system ("cls");
							gotoxy (28,11);
							printf ("DIGITE UMA OP%c%cO V%cLIDA", 128, 199, 181);
							gotoxy (24,12);
							printf ("PRESSIONE ENTER PARA CONTINUAR!!!");
							getch();
							system("cls");
							TelacadastroDeusuario();
						}
						else{
							
							Cadastro_Usuario[posicaoAtual+1].tipousuario = 2;
							PreenchecadastroDeusuario();
						}
}

void PreenchecadastroDeusuario(){
	int escolha = 0;
	int errosenha=0;
			do{
			system("cls");
			gotoxy (30,1);
			printf("CADASTRO DE USU%cRIO", 181);	//Nome da tela
				errosenha=0;
				gotoxy (20, 5);
				printf("PARA CADASTRAR UM ADMINISTRADIR DIGITE 1");
				gotoxy (23, 6);
				printf ("PARA CADASTRAR UM CLIENTE DIGITE 2");
				gotoxy (29, 7);
				printf ("OU DIGITE 0 PARA VOLTAR");
				gotoxy (39, 8);
				printf ("[%i]", Cadastro_Usuario[posicaoAtual+1].tipousuario);
				printf("\nNome: \n");
				printf("Apelido: \n");
				printf("Sexo [F ou M]: \n");
				printf("CPF: \n");
				printf("Telefone: \n");
				printf("e-mail: \n");
				printf("Digite uma senha: \n");
				printf("Confirme a Senha: \n");
						do{
							gotoxy(6,9); // Cursor para digitar o nome de Usuário
					  		fflush(stdin);
							gets(Cadastro_Usuario[posicaoAtual+1].nome);
						}while (strcmp(Cadastro_Usuario[posicaoAtual+1].nome, "\0")==0);
						
						do{						
							gotoxy (9,10); // Cursor para digitar o apelido do usuário	
					  		fflush(stdin);
							gets(Cadastro_Usuario[posicaoAtual+1].apelido);
						}while (strcmp(Cadastro_Usuario[posicaoAtual+1].apelido, "\0")==0);
						
						do{									
							gotoxy(15,11); // Cursor para digitar o Sexo
						   	fflush(stdin);
						   	gets(Cadastro_Usuario[posicaoAtual+1].sexo);
						}while (strcmp(Cadastro_Usuario[posicaoAtual+1].sexo, "\0")==0);	
						
						do{	
							gotoxy(5,12); // Cursor para digitar o CPF
						   	fflush(stdin);
						   	gets(Cadastro_Usuario[posicaoAtual+1].CPF);
						}while (strcmp(Cadastro_Usuario[posicaoAtual+1].CPF, "\0")==0);								   	

						do{	
							gotoxy(10,13); // Cursor para digitar o Telefone
						   	fflush(stdin);
						   	gets(Cadastro_Usuario[posicaoAtual+1].telefone);
						}while (strcmp(Cadastro_Usuario[posicaoAtual+1].telefone, "\0")==0);	
							
						do{	
							gotoxy(8,14); // Cursor para digitar o E-mail
						   	fflush(stdin);
						   	gets(Cadastro_Usuario[posicaoAtual+1].email);
						}while (strcmp(Cadastro_Usuario[posicaoAtual+1].email, "\0")==0);	
								   		   	
						do{
						   	gotoxy(18,15);  // Cursor para digitar a senha de Usuário
						   	fflush(stdin);
						   	gets(Cadastro_Usuario[posicaoAtual+1].senha);
						}while (strcmp(Cadastro_Usuario[posicaoAtual+1].senha, "\0")==0);	
						
						do{
						   	gotoxy(18,16);  // Cursor para confirmar a senha de Usuário
							fflush(stdin);
						   	gets(Cadastro_Usuario[posicaoAtual+1].confirmasenha);
						}while (strcmp(Cadastro_Usuario[posicaoAtual+1].confirmasenha, "\0")==0);					   	
											
						if (strcmp(Cadastro_Usuario[posicaoAtual+1].senha, Cadastro_Usuario[posicaoAtual+1].confirmasenha)){
							errosenha=1;
							system("cls");
							printf ("A senha digitada n%co confere!", 198);
							printf (PRESENTER);
							getch();
						}
					   	if (errosenha==0){
					   		gotoxy(19,18);
							printf("Tecle 1 casos seus dados estiverem corretos");
					   		gotoxy (25,19);
					   		printf("Tecle 2 para refazer cadastro");
					   		gotoxy (39,20);
					   		printf("[ ]\n");
							gotoxy(40,20);
						   	scanf("%i",&escolha);
					   	}
					   	if(escolha == 1){
							Cadastro_Usuario[posicaoAtual+1].codigo = posicaoAtual+1;
							//Copia os dados cadastrado para usuário Logado
							Logado.codigo = Cadastro_Usuario[posicaoAtual+1].codigo;
							Logado.tipousuario = Cadastro_Usuario[posicaoAtual+1].tipousuario;
							strcpy(Logado.nome, Cadastro_Usuario[posicaoAtual+1].nome);
							strcpy(Logado.apelido, Cadastro_Usuario[posicaoAtual+1].apelido);
							strcpy(Logado.senha, Cadastro_Usuario[posicaoAtual+1].senha);
							Cadastro_Usuario[posicaoAtual+1].gasto_total=0; //Limpa o vetor no momento do cadastro do usuário
							Cadastro_Usuario[posicaoAtual+1].bilhetescomprados=0;
							Cadastro_Usuario[posicaoAtual+1].bilhetesreservados=0;
						}
							posicaoAtual++;
							menuprincipal();
							break;
		}while((escolha == 2) || (errosenha == 1));
}

void cancelaRifa(){
	int cont = 0;
//Zera a rifa
	strcpy(rifa,"\0");
	strcpy(premio1,"\0");
	strcpy(premio2,"\0");
	strcpy(premio3,"\0");
	strcpy(premio4,"\0");
	strcpy(premio5,"\0");
	valorbilhete = 0;
//Zera números comprados
	for (cont=0; cont<TAM+1; cont++){
		bilhetesnum[cont]=0;
		bilhetesorteio[cont]=0;
	}
//Zera sorteios anteriores
	cods1 = 0;
	s1 = 0;	
	cods2 = 0;
	s2 = 0;
	cods3 = 0;
	s3 = 0;
	cods4 = 0;
	s4 = 0;
	cods5 = 0;
	s5 = 0;	
}

void cadastroDerifa(){
char escolha, escolha2 = 0;
int cont;
    system("cls");
	system("color F0");//Cor da Tela, Cor da Letra
	if (strcmp(rifa, "\0")==0){// Analisa se ja não existe uma rifa cadastrada
		printf ("\n");
		meiotela (MEIO - 8);
		printf("CADASTRO DE RIFA\n\n");
		printf("Nome da Rifa: \n");
			do{
				gotoxy(14,3);
				fflush(stdin);
				gets(rifa);
			}while (strcmp(rifa, "\0")==0);
		printf("1%c Produto: \n", 167);
			do{
				gotoxy(12,4);
			   	fflush(stdin);
			   	gets(premio1);
			}while (strcmp(premio1, "\0")==0);
		printf("2%c Produto: \n", 167);
			do{
				gotoxy(12,5);
		  	 	fflush(stdin);
		   		gets(premio2);
			}while (strcmp(premio2, "\0")==0);
		printf("3%c Produto: \n", 167);
			do{
				gotoxy(12,6);
			   	fflush(stdin);
			   	gets(premio3);
			}while (strcmp(premio3, "\0")==0);
		printf("4%c Produto: \n", 167);
			do{
				gotoxy(12,7);
			   	fflush(stdin);
			   	gets(premio4);
			}while (strcmp(premio4, "\0")==0);
		printf("5%c Produto: \n", 167);
			do{		
				gotoxy(12,8);
		 	  	fflush(stdin);
		 	  	gets(premio5);
			}while (strcmp(premio5, "\0")==0);		 	  	
		printf("O VALOR DO BILHETE DEVE SER O VALOR TOTAL DIVIDO POR 50\n");
		printf("Valor do Bilhete: \n");
				gotoxy(18,10);// Cursor para digitar o Valor do Bilhete
		 	  	fflush(stdin);
		   		scanf("%f",&valorbilhete);
	
			printf("\n");
			meiotela (MEIO-21);
			printf("Tecle 1 casos seus dados estiverem corretos\n");
			meiotela (MEIO-14);
			printf("Tecle 2 para refazer cadastro\n");
			meiotela (MEIO-4);
			printf("---[ ]---\n");
		do{
			gotoxy(40,14);
		   	scanf ("%c", &escolha);
		}while  ((escolha != 49) && (escolha != 50));
		
		if (escolha==50){
			system("cls");
			cancelaRifa();
			cadastroDerifa();
		}
		else{
			printf ("\n");
			meiotela(MEIO-15);
			printf ("RIFA CADASTRADA COM SUCESSO!!!\n\n\n\n");
			simulaBilhetesComprados();// SIMULA BILHETES COMPRADOS
		    printf (PRESENTER);
		    getch();
		    menuprincipal();
		}
	}//If análise se existe outra rifa cadastrada
	else{//Cancela rifa atualmente cadastrada
		gotoxy (25, 9);
		printf ("J%c EXISTE UMA RIFA CADASTRADA!", 181);
		gotoxy (26, 10);		
		printf ("DESEJA CANCELAR A RIFA ATUAL?");
		gotoxy (25, 11);		
		printf ("DIGITE 1 PARA SIM E 2 PARA N%cO", 199);
		gotoxy (39, 12);
		printf ("[ ]");
		gotoxy (40,12);
		fflush (stdin);
		scanf ("%c", &escolha2);
			if (escolha2 ==49){//Zera a rifa e bilhetes comprados na rifa cadastrada
				cancelaRifa();
				cadastroDerifa();
			}
	}// Else -> Cancela rifa atualmente cadastrada
}

void relatoriosTelaADM(){
    printf ("\n");
	meiotela (MEIO -5);    
	printf ("RELAT%cRIOS\n\n", -32); //Nome da tela
    printf("\n");
    meiotela (MEIO-23); 
	printf ("[1] CONSULTAR BILHETES ADQUIRIDOS POR CLIENTE\n\n");
    meiotela (MEIO-16); 
	printf ("[2] CONSULTAR BILHETES VENDIDOS\n\n");
	meiotela (MEIO-18);
    printf ("[3] CONSULTAR CLIENTES CADASTRADOS\n\n");
	meiotela (MEIO-5);
    printf ("[0] VOLTAR");
    printf ("\n\n\n");
    meiotela (MEIO-9);
	printf ("Digite uma op%c%co: ", -121, -58);

}

void relatoriosTelaCliente(){
    printf ("\n");
	meiotela (MEIO -5);    
	printf ("RELAT%cRIOS\n\n", -32); //Nome da tela
    printf("\n");
    meiotela (MEIO-17); 
	printf ("[1] CONSULTAR BILHETES ADQUIRIDOS\n\n");
	meiotela (MEIO-5);
    printf ("[0] VOLTAR");
    printf ("\n\n\n");
    meiotela (MEIO-9);
	printf ("Digite uma op%c%co: ", -121, -58);

}

void relatorioCompraADM(){
	int cont, posicaorelatorio = 0;
	printf ("Digite o c%cdigo do Cliente que deseja consultar: ",162);
	gotoxy (50,0);
	fflush (stdin);
	scanf ("%i", &posicaorelatorio);
	printf ("\n");
	meiotela(MEIO-9);
	printf ("BILHETES ADQUIRIDOS");
	printf ("\n\n");
	printf ("--------------------------------------------------------------------------------");
	gotoxy (1,5);
	printf ("Nome:");
	gotoxy (7,5);
	puts (Cadastro_Usuario[posicaorelatorio].nome);
	gotoxy (53,5);
	printf ("Telefone:");
	gotoxy (63,5);
	puts (Cadastro_Usuario[posicaorelatorio].telefone);
	gotoxy (1,6);
	printf ("CPF:");
	gotoxy(6,6);
	puts (Cadastro_Usuario[posicaorelatorio].CPF);
	gotoxy (53,6);
	printf ("Sexo:");
	gotoxy (59,6);
		if ((Cadastro_Usuario[posicaorelatorio].sexo[0]==77) || (Cadastro_Usuario[posicaorelatorio].sexo[0] == 109)){
			printf ("Masculino");
		}
		else{
			printf ("Feminino");
		}
	gotoxy (1,7);
	printf ("e-mail: ");
	gotoxy (9,7);
	puts (Cadastro_Usuario[posicaorelatorio].email);
	gotoxy(53,7);
	printf ("Tipo:");
	gotoxy(59,7);
		if (Cadastro_Usuario[posicaorelatorio].tipousuario==1){
			printf ("Administrador");
		}
		else{
			printf ("Cliente");
		}
	printf ("\n--------------------------------------------------------------------------------\n");
	printf (" Bilhetes Comprados:  ");
	for (cont=0; cont<TAM; cont++){
		if (Cadastro_Usuario[posicaorelatorio].relatoriocompra [cont] !=0 ){
			if (Cadastro_Usuario[posicaorelatorio].relatoriocompra[cont] < 10){
				printf (" [0%i] ", Cadastro_Usuario[posicaorelatorio].relatoriocompra[cont]);
			}
			else {
				printf (" [%i] ", Cadastro_Usuario[posicaorelatorio].relatoriocompra[cont]);
			}
		}
	}
		printf ("\n\n Bilhetes Reservados: ");
	for (cont=0; cont<TAM; cont++){
		if (Cadastro_Usuario[posicaorelatorio].relatorioreserva [cont] !=0 ){
			if (Cadastro_Usuario[posicaorelatorio].relatorioreserva[cont] < 10){
				printf (" [0%i] ", Cadastro_Usuario[posicaorelatorio].relatorioreserva[cont]);
			}
			else {
				printf (" [%i] ", Cadastro_Usuario[posicaorelatorio].relatorioreserva[cont]);
			}
		}
	}
	printf ("\n\n--------------------------------------------------------------------------------\n");
	printf (" Total em Bilhetes comprados:  R%c %.2f", 36, Cadastro_Usuario[posicaorelatorio].gasto_total);
	printf ("\n\n Total em Bilhetes Reservados: R%c %.2f", 36, Cadastro_Usuario[posicaorelatorio].bilhetesreservados*valorbilhete);
	printf ("\n\n--------------------------------------------------------------------------------\n");
	printf(PRESENTER);
	getch();
	system ("cls");
	menuprincipal ();
}

void relatorioCompraCliente(){
	int cont, posicaorelatorio = 0;
	posicaorelatorio = Logado.codigo;
	printf ("\n");
	meiotela(MEIO-9);
	printf ("BILHETES ADQUIRIDOS");
	printf ("\n\n");
	printf ("--------------------------------------------------------------------------------");
	gotoxy (1,5);
	printf ("Nome:");
	gotoxy (7,5);
	puts (Logado.nome);
	gotoxy (53,5);
	printf ("Telefone:");
	gotoxy (63,5);
	puts (Cadastro_Usuario[posicaorelatorio].telefone);
	gotoxy (1,6);
	printf ("CPF:");
	gotoxy(6,6);
	puts (Cadastro_Usuario[posicaorelatorio].CPF);
	gotoxy (53,6);
	printf ("Sexo:");
	gotoxy (59,6);
		if ((Cadastro_Usuario[posicaorelatorio].sexo[0]==77) || (Cadastro_Usuario[posicaorelatorio].sexo[0] == 109)){
			printf ("Masculino");
		}
		else{
			printf ("Feminino");
		}
	gotoxy (1,7);
	printf ("e-mail: ");
	gotoxy (9,7);
	puts (Cadastro_Usuario[posicaorelatorio].email);
	gotoxy (53,7);
	printf ("C%cdigo:", 162);
	printf ("%i", Cadastro_Usuario[posicaorelatorio].codigo);
	printf ("\n--------------------------------------------------------------------------------\n");
	printf (" Bilhetes Comprados:  ");
	for (cont=0; cont<TAM; cont++){
		if (Cadastro_Usuario[posicaorelatorio].relatoriocompra [cont] !=0 ){
			if (Cadastro_Usuario[posicaorelatorio].relatoriocompra[cont] < 10){
				printf (" [0%i] ", Cadastro_Usuario[posicaorelatorio].relatoriocompra[cont]);
			}
			else {
				printf (" [%i] ", Cadastro_Usuario[posicaorelatorio].relatoriocompra[cont]);
			}
		}
	}
		printf ("\n\n Bilhetes Reservados: ");
	for (cont=0; cont<TAM; cont++){
		if (Cadastro_Usuario[posicaorelatorio].relatorioreserva [cont] !=0 ){
			if (Cadastro_Usuario[posicaorelatorio].relatorioreserva[cont] < 10){
				printf (" [0%i] ", Cadastro_Usuario[posicaorelatorio].relatorioreserva[cont]);
			}
			else {
				printf (" [%i] ", Cadastro_Usuario[posicaorelatorio].relatorioreserva[cont]);
			}
		}
	}
	printf ("\n\n--------------------------------------------------------------------------------\n");
	printf (" Total em Bilhetes comprados:  R%c %.2f", 36, Cadastro_Usuario[posicaorelatorio].gasto_total);
	printf ("\n\n Total em Bilhetes Reservados: R%c %.2f", 36, Cadastro_Usuario[posicaorelatorio].bilhetesreservados*valorbilhete);
	printf ("\n\n--------------------------------------------------------------------------------\n");
	printf(PRESENTER);
	getch();
	system ("cls");
	menuprincipal ();
}

void relatorioVenda(){
int cont, posicaorelatorio = 0;
int contadorcompra=0;
float total = 0;
	printf ("\n");
	meiotela(MEIO-8);
	printf ("BILHETES VENDIDOS");
	printf ("\n\n\n");
	printf ("--------------------------------------------------------------------------------");
	printf ("\t\t\t\t\t  Quantidade   Quantidade \t Total\n");
	printf (" Nome \t\t\t C%cdigo \t   Bilhetes     Bilhetes \t Gasto\n", 224);
	printf ("\t\t\t\t\t  Adquiridos   Reservados\n");
	printf ("--------------------------------------------------------------------------------");
	
	for (cont=1; cont<=TAM;cont++){
		if (Cadastro_Usuario[cont].codigo !=0){
			gotoxy (0,8+cont);
			puts (Cadastro_Usuario[cont].nome);
			gotoxy (27, 8+cont);
			printf ("%i", Cadastro_Usuario[cont].codigo);
			posicaorelatorio = Cadastro_Usuario[cont].codigo;
			gotoxy (46, 8+cont);
			printf ("%i", Cadastro_Usuario[posicaorelatorio].bilhetescomprados);
			gotoxy (59, 8+cont);
			printf ("%i", Cadastro_Usuario[posicaorelatorio].bilhetesreservados);
			gotoxy (71, 8+cont);
			printf ("R%c %.2f", 36, Cadastro_Usuario[posicaorelatorio].gasto_total);
			printf ("\n");
		}
	}
	printf ("--------------------------------------------------------------------------------");
		for (cont=1; cont<=TAM;cont++){
				total = total + Cadastro_Usuario[cont].gasto_total;
		}
	printf ("\t\t\t\t\t\t\t     Subtotal= R%c %.2f\n", 36, total);
	printf(PRESENTER);
	getch();
	system ("cls");
	menuprincipal ();
}

void relatorioClientes(){	
int cont, linha = 0;
	printf ("\n");
	meiotela(MEIO-10);
	printf ("CLIENTES CADASTRADOS");
	printf ("\n\n\n");
	printf ("--------------------------------------------------------------------------------");
	linha = 5;
		for (cont=1; cont<=TAM; cont++){
			if (Cadastro_Usuario[cont].codigo != 0){
				printf (" Tipo de Usu%crio:", 160);
				gotoxy (18,linha);
					if (Cadastro_Usuario[cont].tipousuario == 1){
						printf ("Adminstrador");
					}
					else {
						printf ("Cliente");
					}
				gotoxy (1,linha+1);
				printf ("Nome:");
				gotoxy (7, linha+1);
				puts (Cadastro_Usuario[cont].nome);
				
				gotoxy (53, linha+1);
				printf ("Telefone:");
				gotoxy (63, linha+1);
				puts (Cadastro_Usuario[cont].telefone);
				
				gotoxy (1, linha+2);
				printf ("CPF:");
				gotoxy(6,linha+2);
				puts (Cadastro_Usuario[cont].CPF);
				
				gotoxy (53, linha+2);
				printf ("Sexo:");
				gotoxy (59,linha+2);
					if ((Cadastro_Usuario[cont].sexo[0]==77) || (Cadastro_Usuario[cont].sexo[0] == 109)){
						printf ("Masculino");
					}
					else{
						printf ("Feminino");
					}
					
				gotoxy (1, linha+3);
				printf ("e-mail: ");
				gotoxy (9,linha+3);
				puts (Cadastro_Usuario[cont].email);
				
				gotoxy (53, linha+3);
				printf ("C%cdigo: %i\n", 224, Cadastro_Usuario[cont].codigo);

				printf ("--------------------------------------------------------------------------------");
				linha = linha +5;
			}
		}
	printf(PRESENTER);
	getch();
	system ("cls");
	menuprincipal ();
}

void funcaoSortear (int *sortear){
int cont;
	for(cont=1 ; cont <= TAM ; cont++) {	
		do{
			*sortear = rand() %TAM;
		}while (bilhetesorteio[*sortear]==0);
	}
	
}

void efeitoSorteio1(){
int cont, cont2, linhaefeito, colunaefeito = 0;	
	for (cont=1; cont <78; cont++){//Desenha efeito na tela na Linha esquerda para a direita
		linhaefeito = 7;
		gotoxy (colunaefeito+cont, linhaefeito);
		printf ("%c",219);
		Sleep(20);
	}
		linhaefeito = 7;
		colunaefeito = 78;
	for (cont=0; cont<5; cont++){//Desenha efeito na tela coluna direita
		gotoxy (colunaefeito, linhaefeito+cont);
		printf ("%c",219);
		Sleep(20);
	}
		linhaefeito = 11;
		colunaefeito = 78;
	for (cont=78; cont>1; cont--){//Desenha efeito na tela na linha direita para esquerda
		gotoxy (colunaefeito, linhaefeito);
		printf ("%c",219);
		colunaefeito = colunaefeito -1;
		Sleep (20);
	}
	cont2 = 0;
		linhaefeito = 11;
		colunaefeito = 1;
	for (cont=4; cont>=0; cont--){//Desenha efeito na tela coluna direita
		gotoxy (colunaefeito, linhaefeito-cont2);
		printf ("%c",219);
		cont2++;
		Sleep(20);
	}
}

void efeitoSorteio2(){
int cont, cont2, linhaefeito, colunaefeito = 0;	

		linhaefeito = 12;
		colunaefeito = 78;
	for (cont=0; cont<4; cont++){//Desenha efeito na tela coluna direita
		gotoxy (colunaefeito, linhaefeito+cont);
		printf ("%c",219);
		Sleep(20);
	}
		linhaefeito = 15;
		colunaefeito = 78;
	for (cont=78; cont>1; cont--){//Desenha efeito na tela na linha direita para esquerda
		gotoxy (colunaefeito, linhaefeito);
		printf ("%c",219);
		colunaefeito = colunaefeito -1;
		Sleep (20);
	}
	cont2 = 0;
		linhaefeito = 15;
		colunaefeito = 1;
	for (cont=4; cont>=0; cont--){//Desenha efeito na tela coluna direita
		gotoxy (colunaefeito, linhaefeito-cont2);
		printf ("%c",219);
		cont2++;
		Sleep(20);
	}
}

void efeitoSorteio3(){
int cont, cont2, linhaefeito, colunaefeito = 0;	

		linhaefeito = 16;
		colunaefeito = 78;
	for (cont=0; cont<4; cont++){//Desenha efeito na tela coluna direita
		gotoxy (colunaefeito, linhaefeito+cont);
		printf ("%c",219);
		Sleep(20);
	}
		linhaefeito = 19;
		colunaefeito = 78;
	for (cont=78; cont>1; cont--){//Desenha efeito na tela na linha direita para esquerda
		gotoxy (colunaefeito, linhaefeito);
		printf ("%c",219);
		colunaefeito = colunaefeito -1;
		Sleep (20);
	}
	cont2 = 0;
		linhaefeito = 19;
		colunaefeito = 1;
	for (cont=4; cont>=0; cont--){//Desenha efeito na tela coluna direita
		gotoxy (colunaefeito, linhaefeito-cont2);
		printf ("%c",219);
		cont2++;
		Sleep(20);
	}
}

void efeitoSorteio4(){
int cont, cont2, linhaefeito, colunaefeito = 0;	

		linhaefeito = 20;
		colunaefeito = 78;
	for (cont=0; cont<4; cont++){//Desenha efeito na tela coluna direita
		gotoxy (colunaefeito, linhaefeito+cont);
		printf ("%c",219);
		Sleep(20);
	}
		linhaefeito = 23;
		colunaefeito = 78;
	for (cont=78; cont>1; cont--){//Desenha efeito na tela na linha direita para esquerda
		gotoxy (colunaefeito, linhaefeito);
		printf ("%c",219);
		colunaefeito = colunaefeito -1;
		Sleep (20);
	}
	cont2 = 0;
		linhaefeito = 23;
		colunaefeito = 1;
	for (cont=4; cont>=0; cont--){//Desenha efeito na tela coluna direita
		gotoxy (colunaefeito, linhaefeito-cont2);
		printf ("%c",219);
		cont2++;
		Sleep(20);
	}
}

void efeitoSorteio5(){
int cont, cont2, linhaefeito, colunaefeito = 0;	

		linhaefeito = 24;
		colunaefeito = 78;
	for (cont=0; cont<4; cont++){//Desenha efeito na tela coluna direita
		gotoxy (colunaefeito, linhaefeito+cont);
		printf ("%c",219);
		Sleep(20);
	}
		linhaefeito = 27;
		colunaefeito = 78;
	for (cont=78; cont>1; cont--){//Desenha efeito na tela na linha direita para esquerda
		gotoxy (colunaefeito, linhaefeito);
		printf ("%c",219);
		colunaefeito = colunaefeito -1;
		Sleep (20);
	}
	cont2 = 0;
		linhaefeito = 27;
		colunaefeito = 1;
	for (cont=4; cont>=0; cont--){//Desenha efeito na tela coluna direita
		gotoxy (colunaefeito, linhaefeito-cont2);
		printf ("%c",219);
		cont2++;
		Sleep(20);
	}
}

void sorteio(){
	int cont, bilhetescomprados = 0;
	char escolha;
	for (cont=0; cont<TAM; cont++){
		if (bilhetesnum[cont]!=0){
			bilhetescomprados=bilhetescomprados+1;
		}
	}
	if ((valorbilhete !=0) && (bilhetescomprados >=5)){
		printf (" Rifa: %s",rifa);
		gotoxy (37,1);    
		printf ("SORTEAR\n\n"); //Nome da tela
	    gotoxy (21,2); 
		printf ("DIGITE 1 PARA SORTEAR E 0 PARA VOLTAR\n\n");
		gotoxy (39,3);
		printf ("[ ]");
			gotoxy (40,3);
			fflush (stdin);
			scanf ("%c", &escolha);
			if (escolha == 49){
			    gotoxy(26, 5);
				printf("OS N%cMEROS SORTEADOS FORAM:\n", -23);
					if (s1==0){//Evita de realizar um sorteio sobre um outro sorteio ja realizado
						for(cont=1 ; cont <= TAM ; cont++) {	
								funcaoSortear (&s1); // 1º Prêmio
								cods1=Cadastro_Usuario[bilhetesorteio[s1]].codigo;
								
									do{
										funcaoSortear (&s2);// 2º Prêmio
									}while (s2==s1);
								cods2=Cadastro_Usuario[bilhetesorteio[s2]].codigo;
								
									do{
										funcaoSortear (&s3);// 3º Prêmio
									}while ((s3==s2) && (s3==s1));
								cods3=Cadastro_Usuario[bilhetesorteio[s3]].codigo;
								
									do{
										funcaoSortear (&s4);// 4º Prêmio
									}while ((s4==s3) && (s4==s2) && (s4==s1));
								cods4=Cadastro_Usuario[bilhetesorteio[s4]].codigo;					
								
									do{
										funcaoSortear (&s5);// 5º Prêmio
									}while ((s5==s4) && (s5==s3) && (s5==s2) && (s5==s1));
								cods5=Cadastro_Usuario[bilhetesorteio[s5]].codigo;	
								}//for
							}//if
						efeitoSorteio1();
						sleep(1);
		    			gotoxy (2,8);// Prêmio 1
		    			printf("1%c Pr%cmio: %s", 167, 136, premio1 );
		    			gotoxy (2,9);
		    			printf ("Bilhete: ");
		    			gotoxy (11,9);
		    				if (s1+1 < 10){
		    					printf ("%c 0%i %c", 16, s1+1, 17);
							}
							else{
							printf ("%c %i %c", 16, s1+1, 17);
							}
						gotoxy (2, 10);
						printf ("PARAB%cNS", 144);
						gotoxy (12,10);
						puts (Cadastro_Usuario[cods1].nome);
						
						Sleep (500);
						efeitoSorteio2();
						sleep(1);
		    			gotoxy (2,12);// Prêmio 2
		    			printf("2%c Pr%cmio: %s", 167, 136, premio2 );
		    			gotoxy (2,13);
		    			printf ("Bilhete: ");
		    			gotoxy (11,13);
		    				if (s2+1 < 10){
		    					printf ("%c 0%i %c", 16, s2+1, 17);
							}
							else{
							printf ("%c %i %c", 16, s2+1, 17);
							}
						gotoxy (2, 14);
						printf ("PARAB%cNS", 144);
						gotoxy (12,14);
						puts (Cadastro_Usuario[cods2].nome);
						
						Sleep (500);
						efeitoSorteio3();
						sleep(1);
		    			gotoxy (2,16);// Prêmio 3
		    			printf("3%c Pr%cmio: %s", 167, 136, premio3 );
		    			gotoxy (2,17);
		    			printf ("Bilhete: ");
		    			gotoxy (11,17);
		    				if (s3+1 < 10){
		    					printf ("%c 0%i %c", 16, s3+1, 17);
							}
							else{
							printf ("%c %i %c", 16, s3+1, 17);
							}
						gotoxy (2, 18);
						printf ("PARAB%cNS", 144);
						gotoxy (12,18);
						puts (Cadastro_Usuario[cods3].nome);

						Sleep (500);
						efeitoSorteio4();
						sleep(1);
		    			gotoxy (2,20);// Prêmio 4
		    			printf("4%c Pr%cmio: %s", 167, 136, premio4 );
		    			gotoxy (2,21);
		    			printf ("Bilhete: ");
		    			gotoxy (11,21);
		    				if (s4+1 < 10){
		    					printf ("%c 0%i %c", 16, s4+1, 17);
							}
							else{
							printf ("%c %i %c", 16, s4+1, 17);
							}
						gotoxy (2, 22);
						printf ("PARAB%cNS", 144);
						gotoxy (12,22);
						puts (Cadastro_Usuario[cods4].nome);
						
						Sleep (500);
						efeitoSorteio5();
						sleep(1);
		    			gotoxy (2,24);// Prêmio 5
		    			printf("5%c Pr%cmio: %s", 167, 136, premio5 );
		    			gotoxy (2,25);
		    			printf ("Bilhete: ");
		    			gotoxy (11,25);
		    				if (s5+1 < 10){
		    					printf ("%c 0%i %c", 16, s5+1, 17);
							}
							else{
							printf ("%c %i %c", 16, s5+1, 17);
							}
						gotoxy (2, 26);
						printf ("PARAB%cNS", 144);
						gotoxy (12,26);
						puts (Cadastro_Usuario[cods5].nome);
						sleep(1);
						
		        		printf("\n");
		                printf (PRESENTER);
		                getch(); 
	        }//if escolha
	        else if (escolha == 48){ // 0 para voltar ao menu principal
	        	system ("cls");
	        	menuprincipal();
			}
			else{
	        	system("cls");
	           	gotoxy (18,12);
	        	printf("ERRRO DIGITE APENAS AS TECLAS INFORMADAS!!!");
	        	gotoxy (23,13);
	        	printf ("PRESSIONE ENTER PARA CONTINNUAR!!!");
				getch();
				system ("cls");
				sorteio();
			}
		}// if para ver se é possível sortear
		if (valorbilhete==0){	
			system ("cls");
			gotoxy (28,10);
			printf ("NENHUMA RIFA CADASTRADA!");
			gotoxy (26,11);
			printf("RETORNANDO AO MENU PRINCIPAL.");
			Sleep(700);
			printf (".");
			Sleep(700);
			printf (".");
			Sleep(700);
		    system ("cls");
			menuprincipal();
	}
		
		else if (bilhetescomprados<5){			
			system ("cls");
			gotoxy (28,10);
			printf ("BILHETES INSUFICIENTES!");
			gotoxy (26,11);
			printf("RETORNANDO AO MENU PRINCIPAL.");
			Sleep(700);
			printf (".");
			Sleep(700);
			printf (".");
			Sleep(700);
		    system ("cls");
			menuprincipal();
			}
}

void encerraSistema(){
int opcao = 0;

	system ("cls");
	gotoxy (29,10);
	printf("DESEJA REALMENTE SAIR?");
	gotoxy (27,11);
	printf ("[1] PARA SIM E [2] PARA N%cO", 199);
	gotoxy (38,12);
	printf ("[ ]");
	gotoxy (39,12);
	scanf ("%i", &opcao);
		if (opcao == 1){		
		    system ("cls");
		    gotoxy (30,10);
		    printf ("ENCERRANDO O SISTEMA.");
		    Sleep (800);
		    printf (".");
		    Sleep (800);
		    printf (".");	    
		    Sleep (800);		  		    
		    exit (1);
		}
		else if (opcao == 2){
			system("cls");
		}
		else{
			system ("cls");
			gotoxy (28,11);
			printf ("DIGITE UMA OP%c%cO V%cLIDA", 128, 199, 181);
			gotoxy (24,12);
			printf ("PRESSIONE ENTER PARA CONTINUAR!!!");
			getch();
			system("cls");
			encerraSistema();
		}
}

main(){
simularUsuario();
// inicializar a semente de numero aleatorios
srand(time(NULL));
int cont;
telainicial ();

	//Zerar o vetor global
	for (cont=0; cont<TAM+1; cont++){
		bilhetesnum[cont]=0;
	}

}
