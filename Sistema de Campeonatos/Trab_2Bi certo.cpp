#include <stdio.h>
#include <string.h>
#include <conio2.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
//---------------------------------------------------------*STRUCTS*---------------------------------------------------------

struct TpJogos{
	int cod;
	char descr[30],status;
};

struct TpPart{
	int cod;
	char descr[50], status;
};

struct TpCamp{
	int cod, ano, codTipo;
	char titulo[50], resp[30], descr[200], status;
};

struct ControlePartCamp{
	int CodCamp, CodPart;
	char Nick[50], status;
};

//---------------------------------------------------------*MOLDURA*---------------------------------------------------------
void Moldura(int CI, int LI, int CF, int LF, int corTXT, int corFundo){
	int i;
	textcolor(corTXT);
	textbackground(corFundo);
	gotoxy(CI,LI);
	printf("%c",201);
	gotoxy(CF,LI);
	printf("%c",187);
	gotoxy(CI,LF);
	printf("%c",200);
	gotoxy(CF,LF);
	printf("%c",188);
	for(i=CI+1;i<CF;i++)
	{
		gotoxy(i,LI);
		printf("%c",205);
		gotoxy(i,LF);
		printf("%c",205);
		Sleep(5);
	}
	for(i=LI+1;i<LF;i++)
	{
		gotoxy(CI,i);
		printf("%c",186);
		gotoxy(CF,i);
		printf("%c",186);
		Sleep(5);
	}
	textcolor(7);
	textbackground(0);
}

void Clear(void){
	int i, j;
	for(i=2;i<80;i++)
		for(j=2;j<25;j++)
		{
			gotoxy(i,j);
			printf(" "); 
		}
}
//---------------------------------------------------------*MENUS*---------------------------------------------------------

char MenuPrincipal(void){
	Clear();
	gotoxy(2,2);
	printf("     _____ _____  _____ _______ ______ __  __                _____  ______    \n");
	gotoxy(2,3);
    printf("    / ____|_   _|/ ____|__   __|  ____|  \\/  |   /\\         |  __ \\\\|  ____|  \n");
    gotoxy(2,4);
    printf("   | (___   | | | (___    | |  | |__  | \\  / |  /  \\        | |  | || |__     \n");
    gotoxy(2,5);
    printf("    \\___ \\  | |  \\___ \\   | |  |  __| | |\\/| | / /\\ \\       | |  | ||  __|    \n");
    gotoxy(2,6);
    printf("    ____) |_| |_ ____) |  | |  | |____| |  | |/ ____ \\      | |__| || |____   \n");
    gotoxy(2,7);
    printf("   |_____/|_____|_____/_ _|_|_ |______|_|__|_/_/ _  \\_\\  ___|_____/|______|__\n");
    gotoxy(2,8);
    printf("  / ____|   /\\   |  \\/  |  __ \\|  ____/ __ \\| \\ | |   /\\|__   __/ __ \\ / ____|\n");
    gotoxy(2,9);
    printf(" | |       /  \\  | \\  / | |__) | |__ | |  | |  \\| |  /  \\  | | | |  | | (___  \n");
    gotoxy(2,10);
    printf(" | |      / /\\ \\ | |\\/| |  ___/|  __|| |  | | . ` | / /\\ \\ | | | |  | |\\___ \\ \n");
    gotoxy(2,11);
    printf(" | |____ / ____ \\| |  | | |    | |___| |__| | |\\  |/ ____ \\| | | |__| |____) |\n");
    gotoxy(2,12);
    printf("  \\_____/_/    \\_|_|  |_|_|    |______\\____/|_| \\_/_/    \\_|_|  \\____/|_____/ \n");
	gotoxy(16,15);
	printf("[A] Jogos");
	gotoxy(16,17);
	printf("[B] Participantes");
	gotoxy(16,19);
	printf("[C] Campeonatos");
	gotoxy(16,21);
	printf("[D] Controle de Participantes do Campeonato");
	gotoxy(16,23);
	printf("[E] Extras");
	
	return toupper(getch());
}

char MenuJogo(void){
	Clear();
	gotoxy(16,8);
	printf("---------------* MENU JOGOS *---------------\n");
	gotoxy(16,10);	
	printf("[A] Cadastrar Jogo\n");
	gotoxy(16,12);
	printf("[B] Excluir Jogo\n");
	gotoxy(16,14);
	printf("[C] Alterar Jogo\n");
	gotoxy(16,16);
	printf("[D] Consultar Jogo\n");
	gotoxy(16,18);
	printf("[E] Exibir Relatorio de Jogo(s)\n");
	
	return toupper(getch());
}

char MenuPart(void){
	Clear();
	gotoxy(16,8);
	printf("---------------* MENU PARTICIPANTES *---------------\n");
	gotoxy(16,10);
	printf("[A] Cadastrar Participante\n");
	gotoxy(16,12);
	printf("[B] Excluir Participante\n");
	gotoxy(16,14);
	printf("[C] Alterar Participante\n");
	gotoxy(16,16);
	printf("[D] Consultar Participante\n");
	gotoxy(16,18);
	printf("[E] Exibir Relatorio de Participante(s)\n");
	
	return toupper(getch());
}

char MenuCamp(void){
	Clear();
	gotoxy(16,8);
	printf("---------------* MENU CAMPEONATO *---------------\n");
	gotoxy(16,10);
	printf("[A] Cadastrar Campeonato\n");
	gotoxy(16,12);
	printf("[B] Excluir Campeonato\n");
	gotoxy(16,14);
	printf("[C] Alterar Campeonato\n");
	gotoxy(16,16);
	printf("[D] Consultar Campeonato\n");
	gotoxy(16,18);
	printf("[E] Exibir Relatorio de Campeonato(s)\n");
	
	return toupper(getch());
}

char MenuPC(void){
	Clear();
	gotoxy(8,8);
	printf("---------------* MENU PARTICIPANTE POR CAMPEONATO *---------------\n");
	gotoxy(8,10);
	printf("[A] Cadastrar Participante\n");
	gotoxy(8,12);
	printf("[B] Excluir Participante\n");
	gotoxy(8,14);
	printf("[C] Alterar Participante\n");
	gotoxy(8,16);
	printf("[D] Consultar Participante\n");
	gotoxy(8,18);
	printf("[E] Exibir Relatorio de Participante(s) por Campeonato\n");
	
	return toupper(getch());
}

char MenuAlt(void){
	Clear();
	gotoxy(16,8);
	printf("---------------* MENU ALTERAR CAMPEONATO *---------------\n");
	gotoxy(16,10);
	printf("[A] Alterar Titulo\n");
	gotoxy(16,12);
	printf("[B] Alterar Responsavel\n");
	gotoxy(16,14);
	printf("[C] Alterar Ano\n");
	gotoxy(16,16);
	printf("[D] Alterar Descricao\n");
	gotoxy(16,18);
	printf("[E] Alterar Codigo de Jogo\n");
	
	return toupper(getch());
}

char MenuExtra(void){
	Clear();
	gotoxy(16,8);
	printf("---------------* MENU EXTRA *---------------\n");
	gotoxy(16,10);
	printf("[A] Relatorio de Campeonatos por Participantes\n");
	gotoxy(16,12);
	printf("[B] Relatorio de Participantes por Campeonato\n");
	
	return toupper(getch());
}
//---------------------------------------------------------*ORENAÇÃO*---------------------------------------------------------
//void OrdenaJogos(void){
//	TpJogos R1, R2;
//	FILE *PtrJogo = fopen("Jogos.Dat", "rb+");
//	int a, b, qtde;
//	
//	fseek(PtrJogo, 0, 2);
//	qtde = ftell(PtrJogo) / sizeof(TpJogos);
//	
//	for(a = 0; a < qtde-1; a++)
//		for(b = a + 1; b < qtde; b++){
//			fseek(PtrJogo, a*sizeof(TpJogos), 0);
//			fread(&R1, sizeof(TpJogos), 1, PtrJogo);
//			fseek(PtrJogo, b*sizeof(TpJogos), 0);
//			fread(&R2, sizeof(TpJogos), 1, PtrJogo);
//			if(R1.cod > R2.cod){
//				fseek(PtrJogo, a*sizeof(TpJogos), 0);
//				fwrite(&R2, sizeof(TpJogos), 1, PtrJogo);
//				fseek(PtrJogo, b*sizeof(TpJogos), 0);
//				fwrite(&R1, sizeof(TpJogos), 1, PtrJogo);
//			}
//		}
//	fclose(PtrJogo);
//}

void OrdenaID(void){
	TpPart R1, R2;
	FILE *PtrPart = fopen("Part.Dat", "rb+");
	int qtde, i;
	
	fseek(PtrPart, 0, 2);
	qtde = ftell(PtrPart) / sizeof(TpPart);
	i = qtde - 1;
	
	if(i > 0){
		fseek(PtrPart,  (i - 1)*sizeof(TpPart), 0);
		fread(&R1, sizeof(TpPart), 1, PtrPart);
		fread(&R2, sizeof(TpPart), 1, PtrPart);
		
		if(R1.cod > R2.cod){
			fseek(PtrPart,  (i - 1)*sizeof(TpPart), 0);
			fwrite(&R2, sizeof(TpPart), 1, PtrPart);
			
			fseek(PtrPart, i*sizeof(TpPart), 0);
			fwrite(&R1, sizeof(TpPart), 1, PtrPart);
		}
		i--;
	}	
	while(i > 0 && R1.cod > R2.cod){
		fseek(PtrPart,  (i - 1)*sizeof(TpPart), 0);
		fread(&R1, sizeof(TpPart), 1, PtrPart);
		fread(&R2, sizeof(TpPart), 1, PtrPart);
		
		if(R1.cod > R2.cod){
			fseek(PtrPart,  (i - 1)*sizeof(TpPart), 0);
			fwrite(&R2, sizeof(TpPart), 1, PtrPart);
			
			fseek(PtrPart, i*sizeof(TpPart), 0);
			fwrite(&R1, sizeof(TpPart), 1, PtrPart);
		}
		i--;
	}
	fclose(PtrPart);
}

void OrdenaPart(FILE *PtrPart){
	TpPart R1, R2;
	int a, b, qtde;
	
	fseek(PtrPart, 0, 2);
	qtde = ftell(PtrPart) / sizeof(TpPart);
	
	for(a = 0; a < qtde-1; a++)
		for(b = a + 1; b < qtde; b++){
			fseek(PtrPart, a*sizeof(TpPart), 0);
			fread(&R1, sizeof(TpPart), 1, PtrPart);
			fseek(PtrPart, b*sizeof(TpPart), 0);
			fread(&R2, sizeof(TpPart), 1, PtrPart);
			if(stricmp(R1.descr, R2.descr) > 0){
				fseek(PtrPart, a*sizeof(TpPart), 0);
				fwrite(&R2, sizeof(TpPart), 1, PtrPart);
				fseek(PtrPart, b*sizeof(TpPart), 0);
				fwrite(&R1, sizeof(TpPart), 1, PtrPart);
			}
		}
}

void BBsortCamp(void){
	FILE *PtrCamp = fopen("Camp.Dat", "rb+");
	TpCamp Reg, Reg2;
	int a, qtde;
	
	fseek(PtrCamp, 0, 2);
	qtde = ftell(PtrCamp) / sizeof(TpCamp);
	
	while(qtde > 1){
		for(a = 0; a < qtde - 1; a++){
			fseek(PtrCamp, a*sizeof(TpCamp), 0);
			fread(&Reg, sizeof(TpCamp), 1, PtrCamp);
			fread(&Reg2, sizeof(TpCamp), 1, PtrCamp);
			if(Reg.cod > Reg2.cod){
				fseek(PtrCamp, a*sizeof(TpCamp), 0);
				fwrite(&Reg2, sizeof(TpCamp), 1, PtrCamp);
				fwrite(&Reg, sizeof(TpCamp), 1, PtrCamp);
			}
		}
		qtde--;
	}
	fclose(PtrCamp);
}

int PosMaior (FILE *PtrJogo, int TL){
	TpJogos Reg;
	int posMaior = 0, maior, i;
	
	fseek(PtrJogo, 0, 0);
	fread(&Reg, sizeof(TpJogos), 1, PtrJogo);
	maior = Reg.cod;
	
	for(i = 1; i < TL; i++){
		fseek(PtrJogo, i*sizeof(TpJogos), 0);
		fread(&Reg, sizeof(TpJogos), 1, PtrJogo);
		if(maior < Reg.cod){
			maior = Reg.cod;
			posMaior = i;
		}
	}
	return posMaior;	
}


void OrdenaSD(void){
	TpJogos Reg, Reg2;
	FILE *PtrJogo = fopen("Jogos.Dat", "rb+");
	int maiorPos, tl;
	
	fseek(PtrJogo, 0, 2);
	tl = ftell(PtrJogo) / sizeof(TpJogos);
	
	while(tl > 0){
		maiorPos = PosMaior(PtrJogo, tl);
		if(maiorPos < tl - 1){
			fseek(PtrJogo, maiorPos*sizeof(TpJogos), 0);
			fread(&Reg2, sizeof(TpJogos), 1, PtrJogo);
			
			fseek(PtrJogo, (tl-1)*sizeof(TpJogos), 0);
			fread(&Reg, sizeof(TpJogos), 1, PtrJogo);
			
			fseek(PtrJogo, maiorPos*sizeof(TpJogos), 0);
			fwrite(&Reg, sizeof(TpJogos), 1, PtrJogo);
			
			fseek(PtrJogo, (tl-1)*sizeof(TpJogos), 0);
			fwrite(&Reg2, sizeof(TpJogos), 1, PtrJogo);
		}
		tl--;
	}
	fclose(PtrJogo);
}

void BBsortPC(void){
	FILE *PtrPC = fopen("PartCamp.Dat", "rb+");
	TpCamp Reg, Reg2;
	int a, qtde;
	
	fseek(PtrPC, 0, 2);
	qtde = ftell(PtrPC) / sizeof(ControlePartCamp);
	
	while(qtde > 1){
		for(a = 0; a < qtde - 1; a++){
			fseek(PtrPC, a*sizeof(ControlePartCamp), 0);
			fread(&Reg, sizeof(ControlePartCamp), 1, PtrPC);
			fread(&Reg2, sizeof(ControlePartCamp), 1, PtrPC);
			if(Reg.cod > Reg2.cod){
				fseek(PtrPC, a*sizeof(ControlePartCamp), 0);
				fwrite(&Reg2, sizeof(ControlePartCamp), 1, PtrPC);
				fwrite(&Reg, sizeof(ControlePartCamp), 1, PtrPC);
			}
		}
		qtde--;
	}
	fclose(PtrPC);
}

//---------------------------------------------------------*BUSCAS*---------------------------------------------------------

int BuscaExaustiva(FILE *PtrJogo, int cod){
	TpJogos Reg;
	fseek(PtrJogo, 0, 0);
	fread(&Reg, sizeof(TpJogos), 1, PtrJogo);
	while(!feof(PtrJogo) && (Reg.cod != cod || Reg.status != 'A'))
		fread(&Reg, sizeof(TpJogos), 1, PtrJogo);
	if(!feof(PtrJogo))
		return ftell(PtrJogo)-sizeof(TpJogos);
	else
		return -1;
}

int BuscaBinaria(FILE *PtrPart, int cod){
	TpPart 	Reg;
	
	int i=0, meio, fim;
	
	fseek(PtrPart, 0, 2);
	fim = (ftell(PtrPart) - sizeof(TpPart)) / sizeof(TpPart);
	meio = fim/2;
	fseek(PtrPart, meio*sizeof(TpPart), 0);
	fread(&Reg, sizeof(TpPart), 1, PtrPart);
	while(i < fim && (Reg.cod != cod || Reg.status != 'A')){
		if(Reg.cod < cod)
			i = meio + 1;
		else
			fim = meio - 1;
		meio = (i + fim) / 2;
		fseek(PtrPart, meio*sizeof(TpPart), 0);
		fread(&Reg, sizeof(TpPart), 1, PtrPart);
	}
	if(Reg.cod == cod)
		return meio*sizeof(TpPart);
	else
		return -1;
}

int BuscaIndexada(FILE *PtrCamp, int cod){
	TpCamp Reg;
	
	fseek(PtrCamp, 0, 0);
	fread(&Reg, sizeof(TpCamp), 1, PtrCamp);
	while(!feof(PtrCamp) && (cod > Reg.cod || Reg.status != 'A'))
		fread(&Reg, sizeof(TpCamp), 1, PtrCamp);
	if(cod == Reg.cod)
		return ftell(PtrCamp) - sizeof(TpCamp);
	else
		return -1;
}

int BuscaSentinela(FILE *PtrPC, int cod, char nick[50]){
	ControlePartCamp Reg;
	FILE *PtrAux = fopen("PartCamp.Dat", "ab");
	
	Reg.CodPart = 0;
	Reg.CodCamp = cod;
	strcpy(Reg.Nick, nick);
	Reg.status = 'I';
	fseek(PtrPC, 0, 2);
	fwrite(&Reg, sizeof(ControlePartCamp), 1, PtrPC);
	fclose(PtrAux);
	
	fseek(PtrPC, 0, 0);
	fread(&Reg, sizeof(ControlePartCamp), 1, PtrPC);
	while(stricmp(Reg.Nick, nick) != 0 || Reg.CodCamp != cod)
		fread(&Reg, sizeof(ControlePartCamp), 1, PtrPC);
	if(Reg.CodPart != 0 && Reg.status == 'A')
		return ftell(PtrPC) - sizeof(ControlePartCamp);
	else
		return -1;
}

int BuscaPartCamp(FILE *PtrPC, int codC, int codP){
	ControlePartCamp Reg;
	
	fseek(PtrPC, 0, 0);
	fread(&Reg, sizeof(ControlePartCamp), 1, PtrPC);
	while(!feof(PtrPC) && (Reg.CodCamp != codC || Reg.CodPart != codP))
		fread(&Reg, sizeof(ControlePartCamp), 1, PtrPC);
	if(!feof(PtrPC) && Reg.status == 'A')
		return ftell(PtrPC) - sizeof(ControlePartCamp);
	else
		return -1;
}

//---------------------------------------------------------*ALTERAÇÕES*---------------------------------------------------------

void AlterarPart(void){
	TpPart Reg;
	FILE *PtrPart = fopen ("Part.Dat", "rb+");
	int auxCod, pos;
	
	Clear();
	if(PtrPart == NULL){
		Clear();
		gotoxy(28,13);
		printf("Arquivo nao encontrado!\n");
		getch();
	}
	else{
		gotoxy(28,11);
		printf("**ALTERAR PARTICIPANTE**\n");
		gotoxy(28,12);
		printf("Codigo do Participante: ");
		scanf("%d", &auxCod);
		while(auxCod != 0){
			pos = BuscaBinaria(PtrPart,auxCod);
			if(pos == -1){
				Clear();
				gotoxy(28,11);
				printf("Participante nao Cadastrado!\n");
				getch();
			}
			else{
				Clear();
				fseek(PtrPart, pos, 0);
				fread(&Reg, sizeof(TpPart), 1, PtrPart);
				gotoxy(28,13);
				printf("Novo Nome: ");
				fflush(stdin);
				gets(Reg.descr);
				fseek(PtrPart, pos, 0);
				fwrite(&Reg, sizeof(TpPart), 1, PtrPart);
			}
			Clear();
			gotoxy(28,11);
			printf("**ALTERAR PARTICIPANTE**\n");
			gotoxy(28,12);
			printf("Codigo do Participante: ");
			scanf("%d", &auxCod);
		}
		fclose(PtrPart);
	}
	getch();
}

void AlterarJogo(void){
	TpJogos Reg;
	FILE *PtrJogo = fopen("Jogos.Dat", "rb+");
	int auxCod, pos;
	
	Clear();
	if(PtrJogo == NULL){
		Clear();
		gotoxy(28,11);
		printf("Arquivo nao encontrado!!\n");
		getch();
	}
	else{
		gotoxy(28,11);
		printf("**ALTERAR JOGO**\n");
		gotoxy(28,12);
		printf("Codigo do jogo: ");
		scanf("%d", &auxCod);
		while(auxCod != 0){
			pos = BuscaExaustiva(PtrJogo,auxCod);
			if(pos == -1){
				Clear();
				gotoxy(28,12);
				printf("Jogo nao cadastrado!\n");
				fclose(PtrJogo);	
				getch();
			}
			else{
				fseek(PtrJogo, pos, 0);
				fread(&Reg, sizeof(TpJogos), 1, PtrJogo);
				gotoxy(28,12);
				printf("Digite o jogo novo: ");
				fflush(stdin);
				gets(Reg.descr);
				fseek(PtrJogo, pos, 0);
				fwrite(&Reg, sizeof(TpJogos), 1, PtrJogo);
			}
			Clear();
			gotoxy(28,11);
			printf("**ALTERAR JOGO**\n");
			gotoxy(28,12);
			printf("Codigo do jogo: ");
			scanf("%d", &auxCod);
		}
		fclose(PtrJogo);
	}
	getch();	
}

void AlterarCamp(void){
	TpCamp Reg;
	FILE *PtrCamp = fopen("Camp.Dat","rb+");
	FILE *PtrJogo = fopen("Jogos.Dat", "rb");
	int auxCod, pos, auxCod2, pos2;
	char op;
	Clear();
	
	gotoxy(28,11);
	printf("**ALTERACAO DE CAMPEONATO**\n");
	if(PtrCamp == NULL){
		Clear();
		gotoxy(28,12);
		printf("Arquivo nao encontrado!\n");
		getch();
	}
	else{
		gotoxy(28,12);
		printf("Codigo do campeonato: ");
		scanf("%d",&auxCod);
		while(auxCod != 0){
			pos = BuscaIndexada(PtrCamp, auxCod);
			if(pos == -1){
				Clear();
				gotoxy(22,16);
				printf("Campeonato nao encontrado!\n");
				getch();
			}
			else{
				op = MenuAlt();
				fseek(PtrCamp, pos, 0);
				fread(&Reg, sizeof(TpCamp), 1, PtrCamp);
				do{
					switch(op){
						case 'A':
							Clear();
							gotoxy(22,12);
							printf("Digite um novo titulo: ");
							fflush(stdin);
							gets(Reg.titulo);
							break;
						case 'B':
							Clear();
							gotoxy(22,12);
							printf("Digite um novo responsavel: ");
							fflush(stdin);
							gets(Reg.resp);
							break;
						case 'C':
							Clear();
							gotoxy(22,12);
							printf("Digite um novo ano: ");
							scanf("%d",&Reg.ano);
							break;
						case 'D':
							Clear();
							gotoxy(22,12);
							printf("Digite uma nova descricao: ");
							fflush(stdin);
							gets(Reg.descr);
							break;
						case 'E':
							Clear();
							gotoxy(22,12);
							printf("Digite o novo codigo de jogo: ");
							scanf("%d", &auxCod2);
							pos2 = BuscaExaustiva(PtrJogo, auxCod2);
							if(pos2 == -1){
								Clear();
								gotoxy(22,12);
								printf("Jogo nao cadastrado!");
								getch();
							}
							else
								Reg.codTipo = auxCod2;
							break;
					}
					fseek(PtrCamp, pos, 0);
					fwrite(&Reg, sizeof(TpCamp), 1, PtrCamp);
					op = MenuAlt();
				}while(op!=27);
			}
			Clear();
			gotoxy(28,11);
			printf("**ALTERACAO DE CAMPEONATO**\n");
			gotoxy(28,12);
			printf("Codigo do campeonato: ");
			scanf("%d",&auxCod);
		}
		fclose(PtrCamp);
		fclose(PtrJogo);
	}
}

void AlterarPC(void){
	ControlePartCamp Reg;
	FILE *PtrPC = fopen("PartCamp.Dat", "rb+");
	int auxCod, auxCod2, pos;
	
	Clear();
	if(PtrPC == NULL){
		gotoxy(28,11);
		printf("Arquivo nao encontrado!!\n");
		getch();
	}
	else{
		gotoxy(20,10);
		printf("**ALTERAR PARTICIPANTE POR CAMPEONATO**\n");
		gotoxy(28,11);
		printf("Codigo do campeonato: ");
		scanf("%d", &auxCod);
		gotoxy(28,12);
		printf("Codigo de Participante: ");
		scanf("%d", &auxCod2);
		while(auxCod != 0 && auxCod2 != 0){
			Clear();
			gotoxy(20,10);
			printf("**ALTERAR PARTICIPANTE POR CAMPEONATO**\n");
			pos = BuscaPartCamp(PtrPC, auxCod, auxCod2);
			if(pos != -1){
				fseek(PtrPC, pos, 0);
				fread(&Reg, sizeof(ControlePartCamp), 1, PtrPC);
				gotoxy(28,11);
				printf("Digite o novo nick: ");
				fflush(stdin);
				gets(Reg.Nick);
				fseek(PtrPC, pos, 0);
				fwrite(&Reg, sizeof(ControlePartCamp), 1, PtrPC);
			}
			Clear();
			gotoxy(20,10);
			printf("**ALTERAR PARTICIPANTE POR CAMPEONATO**\n");
			gotoxy(28,11);
			printf("Codigo do campeonato: ");
			scanf("%d", &auxCod);
			gotoxy(28,12);
			printf("Codigo de Participante: ");
			scanf("%d", &auxCod2);
		}
		fclose(PtrPC);
		BBsortCamp();
	}
	getch();
}

//---------------------------------------------------------*EXCLUSÕES*---------------------------------------------------------

void ExcLogicaJogo(void){
		TpJogos Reg;
		TpCamp Reg2;
		ControlePartCamp Reg3;
		FILE *PtrJogo = fopen("Jogos.Dat", "rb+");
		FILE *PtrCamp = fopen("Camp.Dat", "rb+");
		FILE *PtrPC = fopen("PartCamp.Dat", "rb+");
		int auxCod, pos, i, j;
		
		Clear();
		if(PtrJogo == NULL || PtrCamp == NULL || PtrPC == NULL){
			gotoxy(28,12);
			printf("**Arquivo nao encontrado!!**\n");
			getch();
		}
		else{
			Clear();
			gotoxy(28,12);
			printf("Digite o codigo do jogo: ");
			scanf("%d", &auxCod);
			while(auxCod != 0){
				pos = BuscaExaustiva(PtrJogo,auxCod);
				if(pos == -1){
					gotoxy(28,11);
					printf("Jogo nao encontrado!\n");
					printf("%d", pos);
					fclose(PtrJogo);
				}
				else{
					fseek(PtrJogo, pos, 0);
					fread(&Reg, sizeof(TpJogos), 1, PtrJogo);
					Reg.status = 'I';
					fseek(PtrJogo, pos, 0);
					fwrite(&Reg, sizeof(TpJogos), 1, PtrJogo);
					//Cascata
					i = 0;
					fseek(PtrCamp, 0, 0);
					fread(&Reg2, sizeof(TpCamp), 1, PtrCamp);
					while(!feof(PtrCamp)){
						if(Reg2.codTipo == Reg.cod){
							Reg2.status = 'I';
							fseek(PtrCamp, i*sizeof(TpCamp), 0);
							fwrite(&Reg2, sizeof(TpCamp), 1, PtrCamp);
							j = 0;
							fseek(PtrPC, 0, 0);
							fread(&Reg3, sizeof(ControlePartCamp), 1, PtrPC);
							while(!feof(PtrPC)){
								if(Reg3.CodCamp == Reg2.cod){
									Reg3.status = 'I';
									fseek(PtrPC, j*sizeof(ControlePartCamp), 0);
									fwrite(&Reg3, sizeof(ControlePartCamp), 1, PtrPC);
								}
								j++;
								fseek(PtrPC, j*sizeof(ControlePartCamp), 0);
								fread(&Reg3, sizeof(ControlePartCamp), 1, PtrPC);
							}
						}
						i++;
						fseek(PtrCamp, i*sizeof(TpCamp), 0);
						fread(&Reg2, sizeof(TpCamp), 1, PtrCamp);
					}
				}
				Clear();
				gotoxy(28,12);
				printf("Digite o codigo do jogo: ");
				scanf("%d", &auxCod);
			}
			fclose(PtrJogo);
			fclose(PtrCamp);
			fclose(PtrPC);
		}
	}
	
	void ExcFisicaJogo(void){
		TpJogos Reg;
		FILE *PtrJogo = fopen("Jogos.Dat", "rb");
		FILE *PtrNovoJogo = fopen("NovoJogo.Dat", "wb");
		
		if(PtrJogo == NULL){
			Clear();
			gotoxy(28,12);
			printf("Arquivo nao encontrado!!\n");
			getch();
		}
		else{
			fseek(PtrJogo, 0, 0);
			fread(&Reg, sizeof(TpJogos), 1, PtrJogo);
			while(!feof(PtrJogo)){
				if(Reg.status != 'I')
					fwrite(&Reg, sizeof(TpJogos), 1, PtrNovoJogo);
				fread(&Reg, sizeof(TpJogos), 1, PtrJogo);
			}
			fclose(PtrJogo);
			fclose(PtrNovoJogo);
			remove("Jogos.Dat");
		}
		rename("NovoJogo.Dat","Jogos.Dat");
	}
	
	void ExcLogicaPart(void){
		TpPart Reg;
		ControlePartCamp Reg2;
		FILE *PtrPart = fopen("Part.Dat", "rb+");
		FILE *PtrPC = fopen("PartCamp.Dat", "rb+");
		int auxCod, pos, i;
		
		Clear();
		if(PtrPart == NULL){
			gotoxy(28,12);
			printf("Arquivo nao encontrado!\n");
			getch();
		}
		else{
			Clear();
			gotoxy(24,11);
			printf("**EXCLUSAO DE PARTICIPANTES**\n");
			gotoxy(24,12);
			printf("Codigo do Participante: ");
			scanf("%d", &auxCod);
			while(auxCod != 0){
				pos = BuscaBinaria(PtrPart,auxCod);
				if(pos == -1){
					Clear();
					gotoxy(24,12);
					printf("Participante nao cadastrado\n");
					getch();
				}
				else{
					fseek(PtrPart, pos, 0);
					fread(&Reg, sizeof(TpPart), 1, PtrPart);
					Reg.status = 'I';
					fseek(PtrPart, pos, 0);
					fwrite(&Reg, sizeof(TpPart), 1, PtrPart);
					//Cascata
					i = 0;
					fseek(PtrPC, 0, 0);
					fread(&Reg2, sizeof(ControlePartCamp), 1, PtrPC);
					while(!feof(PtrPC)){
						if(Reg2.CodPart == Reg.cod){
							Reg2.status = 'I';
							fseek(PtrPC, i*sizeof(ControlePartCamp), 0);
							fwrite(&Reg2, sizeof(ControlePartCamp), 1, PtrPC);
						}
						i++;
						fseek(PtrPC, i*sizeof(ControlePartCamp), 0);
						fread(&Reg2, sizeof(ControlePartCamp), 1, PtrPC);
					}
				}
				Clear();
				gotoxy(24,11);
				printf("**EXCLUSAO DE PARTICIPANTES**\n");
				gotoxy(24,12);
				printf("Codigo do Participante: ");
				scanf("%d", &auxCod);
			}
			fclose(PtrPart);
		}
	}
	void ExcFisicaPart(void){
		TpPart Reg;
		FILE *PtrPart = fopen("Part.Dat", "rb");
		FILE *PtrNovoPart = fopen("NovoPart.Dat", "wb");
		
		if(PtrPart == NULL){
			Clear();
			gotoxy(28,12);
			printf("Arquivo nao encontrado!\n");
			getch();
		}
			else{
				fseek(PtrPart, 0, 0);
				fread(&Reg, sizeof(TpPart), 1, PtrPart);
				while(!feof(PtrPart)){
					if(Reg.status != 'I')
						fwrite(&Reg, sizeof(TpPart), 1, PtrNovoPart);
					fread(&Reg, sizeof(TpPart), 1, PtrPart);	
				}
				fclose(PtrPart);
				fclose(PtrNovoPart);
				remove("Part.Dat");
			}
			rename("NovoPart.Dat", "Part.Dat");
	}
	
	void ExcLogicaCamp(void){
		TpCamp Reg;
		ControlePartCamp Reg2;
		FILE *PtrCamp = fopen("Camp.Dat", "rb+");
		FILE *PtrPC = fopen("PartCamp.Dat", "rb+");
		int auxCod, pos, i;
		Clear();
		
		if(PtrCamp == NULL){
			gotoxy(28,12);
			printf("Arquivo nao encontrado!\n");
			getch();
		}
		else{
			gotoxy(28,10);
			printf("**Exclusao Logica de Campeonatos**\n");
			gotoxy(28,11);
			printf("Codigo do Campeonato: ");
			scanf("%d", &auxCod);
			while(auxCod != 0){
				pos = BuscaIndexada(PtrCamp, auxCod);
				if(pos == -1){
					Clear();
					gotoxy(28,11);
					printf("Campeonato nao encontrado!\n");
					getch();
				}
				else{
					fseek(PtrCamp, pos, 0);
					fread(&Reg, sizeof(TpCamp), 1, PtrCamp);
					Reg.status = 'I';
					fseek(PtrCamp, pos, 0);
					fwrite(&Reg, sizeof(TpCamp), 1, PtrCamp);
					//Cascata
					i = 0;
					fseek(PtrPC, 0, 0);
					fread(&Reg2, sizeof(ControlePartCamp), 1, PtrPC);
					while(!feof(PtrPC)){
						if(Reg2.CodCamp == Reg.cod){
							Reg2.status = 'I';
							fseek(PtrPC, i*sizeof(ControlePartCamp), 0);
							fwrite(&Reg2, sizeof(ControlePartCamp), 1, PtrPC);
						}
						i++;
						fseek(PtrPC, i*sizeof(ControlePartCamp), 0);
						fread(&Reg2, sizeof(ControlePartCamp), 1, PtrPC);
					}
				}
				Clear();
				gotoxy(28,10);
				printf("**Exclusao Logica de Campeonatos**\n");
				gotoxy(28,11);
				printf("Codigo do Campeonato: ");
				scanf("%d", &auxCod);
			}
			fclose(PtrCamp);
		}
	
	}
	
	void ExcFisicaCamp(void){
		TpCamp Reg;
		FILE *PtrCamp = fopen("Camp.Dat", "rb+");
		FILE *PtrNovo2 = fopen("Novo2.Dat", "wb");
		
		if(PtrCamp == NULL){
			Clear();
			gotoxy(28,12);
			printf("Arquivo nao encontrado!\n");
			getch();
		}
		else{
			fseek(PtrCamp, 0, 0);
			fread(&Reg, sizeof(TpCamp), 1, PtrCamp);
			while(!feof(PtrCamp)){
				if(Reg.status != 'I')
					fwrite(&Reg, sizeof(TpCamp), 1, PtrNovo2);
				fread(&Reg, sizeof(TpCamp), 1, PtrCamp);
			}
			fclose(PtrCamp);
			fclose(PtrNovo2);
			remove("Camp.Dat");
		}
		rename("Novo2.Dat", "Camp.Dat");
	}
	
	void ExcLogicaPC(void){
		ControlePartCamp Reg;
		FILE *PtrPC = fopen("PartCamp.Dat", "rb+");
		int auxCod, auxCod2, pos;
		
		Clear();
		if(PtrPC == NULL){
			gotoxy(14,11);
			printf("Arquivo nao encontrado!\n");
			getch();
		}
		else{
		gotoxy(14,10);
		printf("**EXCLUSAO LOGICA DE PARTICIPANTES POR CAMPEONATO**\n");
		gotoxy(14,11);
		printf("Codigo do campeonato: ");
		scanf("%d", &auxCod);
		gotoxy(14,11);
		printf("Codigo do participante: ");
		scanf("%d", &auxCod2);
		while(auxCod != 0 && auxCod2 != 0){
			pos = BuscaPartCamp(PtrPC, auxCod, auxCod2);
			if(pos != -1){
				fseek(PtrPC, pos, 0);
				fread(&Reg, sizeof(ControlePartCamp), 1, PtrPC);
				Reg.status = 'I';
				fseek(PtrPC, pos, 0);
				fwrite(&Reg, sizeof(ControlePartCamp), 1, PtrPC);
			}
			else{
				Clear();
				gotoxy(14,11);
				printf("Participante nao encontrado!\n");
				getch();
			}
			Clear();
			gotoxy(14,10);
			printf("**EXCLUSAO LOGICA DE PARTICIPANTES POR CAMPEONATO**\n");
			gotoxy(14,11);
			printf("Codigo do campeonato: ");
			scanf("%d", &auxCod);
			gotoxy(14,11);
			printf("Codigo do participante: ");
			scanf("%d", &auxCod2);
		}
		fclose(PtrPC);
	}

}

void ExcFisicaPC(void){
	ControlePartCamp Reg;
	FILE *PtrPC = fopen("PartCamp.Dat", "rb+");
	FILE *PtrNovoPC = fopen("NovoPC.Dat", "wb");
	
	if(PtrPC == NULL){
		Clear();
		gotoxy(28,12);
		printf("Arquivo nao encontrado!\n");
		getch();
	}
	else{
		fseek(PtrPC, 0, 0);
		fread(&Reg, sizeof(ControlePartCamp), 1, PtrPC);
		while(!feof(PtrPC)){
			if(Reg.status != 'I')
				fwrite(&Reg, sizeof(ControlePartCamp), 1, PtrNovoPC);
			fread(&Reg, sizeof(ControlePartCamp), 1, PtrPC);		
		}
		fclose(PtrPC);
		fclose(PtrNovoPC);
		remove("PartCamp.Dat");
	}
	rename("NovoPC.Dat", "PartCamp.Dat");
}

//---------------------------------------------------------*CONSULTAS*---------------------------------------------------------

void ConsultaJogo(void){
	TpJogos Reg;
	FILE *PtrJogo = fopen("Jogos.Dat", "rb");
	int auxCod, pos;
	
	Clear();
	if(PtrJogo == NULL){
		gotoxy(28,12);
		printf("Arquivo nao encontrado!!\n");
		getch();
	}
	else{
		gotoxy(28,11);
		printf("**Consulta de Jogo(s)**\n");
		gotoxy(28,13);
		printf("Codigo do jogo: ");
		scanf("%d", &auxCod);
		while(auxCod != 0){
			pos = BuscaExaustiva(PtrJogo,auxCod);
			if(pos == -1){
				Clear();
				gotoxy(28,11);
				printf("Jogo nao cadastrado!!\n");
				fclose(PtrJogo);
			}
			else{
				fseek(PtrJogo, pos, 0);
				fread(&Reg, sizeof(TpJogos), 1, PtrJogo);
				if(Reg.status != 'I'){
					gotoxy(28,15);
					printf("Codigo\tJogo\n");
					gotoxy(28,16);
					printf("%d\t\t%s\n", Reg.cod, Reg.descr);
					getch();
				}
				else{
					Clear();
					gotoxy(28,11);
					printf("\nJogo nao cadastrado!!\n");
					getch();
				}
			}
			Clear();
			gotoxy(28,11);
			printf("**Consulta de Jogo(s)**\n");
			gotoxy(28,13);
			printf("Codigo do jogo: ");
			scanf("%d", &auxCod);
		}
		fclose(PtrJogo);
	}
}

void ConsultaPart(void){
	TpPart Reg;
	FILE *PtrPart = fopen ("Part.Dat", "rb");
	int pos, auxCod;
	
	Clear();
	if(PtrPart == NULL){
		gotoxy(28,12);
		printf("Arquivo nao encontrado!!\n");
		getch();
	}
	else{
		gotoxy(28,11);
		printf("**CONSULTA DE PARTICIPANTES**\n");
		gotoxy(28,12);
		printf("Codigo do participante: ");
		scanf("%d", &auxCod);
		while(auxCod != 0){
			pos = BuscaBinaria(PtrPart,auxCod);
			if(pos == -1){
				Clear();
				gotoxy(28,12);
				printf("Participante nao cadastrado!!\n");
			}		
			else{
				fseek(PtrPart, pos, 0);
				fread(&Reg, sizeof(TpPart), 1, PtrPart);
				if(Reg.status != 'I'){
					fseek(PtrPart, pos, 0);
					fread(&Reg, sizeof(TpPart), 1, PtrPart);
					gotoxy(30,14);
					printf("Codigo\tNome");
					gotoxy(30,15);
					printf("%d\t\t%s\n", Reg.cod, Reg.descr);
					getch();
				}
				else{
					Clear();
					gotoxy(28,12);
					printf("Participante nao cadastrado!\n");
				}
			}
			Clear();
			gotoxy(28,11);
			printf("**CONSULTA DE PARTICIPANTES**\n");
			gotoxy(28,12);
			printf("Codigo do participante: ");
			scanf("%d", &auxCod);
		}
		fclose(PtrPart);
	}
}

void ConsultaCamp(void){
	TpCamp Reg;
	FILE *PtrCamp = fopen("Camp.Dat", "rb");
	int auxCod, pos;
	
	Clear();
	if(PtrCamp == NULL){
		Clear();
		gotoxy(28,12);
		printf("Arquivo nao encontrado!\n");
		getch();
	}
	else{
		Clear();
		gotoxy(28,11);
		printf("**CONSULTA DE CAMPEONATO**\n");
		gotoxy(28,12);
		printf("Codigo do campeonato: ");
		scanf("%d", &auxCod);
		while(auxCod != 0){
			pos = BuscaIndexada(PtrCamp, auxCod);
			if(pos != -1){
				Clear();
				fseek(PtrCamp, pos, 0);
				fread(&Reg, sizeof(TpCamp), 1, PtrCamp);
				gotoxy(20,10);
				printf("Codigo: %d", Reg.cod);
				gotoxy(20,11);
				printf("Titulo: %s", Reg.titulo);
				gotoxy(20,12);
				printf("Responsavel: %s", Reg.resp);
				gotoxy(20,13);
				printf("Ano: %d", Reg.ano);
				gotoxy(20,14);
				printf("Jogo: %d", Reg.codTipo);
				gotoxy(20,15);
				printf("Descricao: %s", Reg.descr);
				getch();
			}
			else{
				Clear();
				gotoxy(28,12);
				printf("Campeonato nao cadastrado!\n");
				getch();
			}
			Clear();
			gotoxy(28,11);
			printf("**CONSULTA DE CAMPEONATO**\n");
			gotoxy(28,12);
			printf("Codigo do campeonato: ");
			scanf("%d", &auxCod);
		}
		fclose(PtrCamp);
	}
}

void ConsultaPC(void){
	ControlePartCamp Reg;
	FILE *PtrPC = fopen("PartCamp.Dat", "rb");
	int auxCod, pos, auxCod2;
	
	Clear();
	if(PtrPC == NULL){
		Clear();
		gotoxy(28,12);
		printf("Arquivo nao encontrado!!\n");
		getch();
	}
	else{
		gotoxy(20,11);
		printf("**CONSULTA DE PARTICIPANTES POR CAMPEONATO**\n");
		gotoxy(20,12);
		printf("Codigo do campeonato: ");
		scanf("%d", &auxCod);
		gotoxy(20,13);
		printf("Codigo de Participante :");
		scanf("%d", &auxCod2);
		while(auxCod != 0 && auxCod2 != 0){
			pos = BuscaPartCamp(PtrPC, auxCod, auxCod2);
			if(pos != -1){
				fseek(PtrPC, pos, 0);
				fread(&Reg, sizeof(ControlePartCamp), 1, PtrPC);
				gotoxy(20,15);
				printf("Campeonato\tCod\tNick");
				gotoxy(20,17);
				printf("%d\t\t%d\t%s\n", Reg.CodCamp, Reg.CodPart, Reg.Nick);
				getch();
			}
			else{
				Clear();
				gotoxy(20,12);
				printf("Participante nao cadastrado!\n");
				getch();
			}
			Clear();
			gotoxy(20,11);
			printf("**CONSULTA DE PARTICIPANTES POR CAMPEONATO**\n");
			gotoxy(20,12);
			printf("Codigo do campeonato: ");
			scanf("%d", &auxCod);
			gotoxy(20,13);
			printf("Codigo de Participante :");
			scanf("%d", &auxCod2);
		}
		fclose(PtrPC);
	}
}

//---------------------------------------------------------*CADASTROS*---------------------------------------------------------

void CadJogo(void){
	TpJogos Reg;
	int pos;
	FILE *PtrJogo = fopen("Jogos.Dat", "ab+");
	
	Clear();
	if(PtrJogo == NULL){
		gotoxy(28,12);
		printf("Falha ao Abrir Arquivo!\n");
		getch();
	}
	else{
		gotoxy(28,11);
		printf("**CADASTRO DE JOGOS**\n");
		gotoxy(28,13);
		printf("Codigo do Jogo: ");
		scanf("%d",&Reg.cod);
		while(Reg.cod != 0){
			pos = BuscaExaustiva(PtrJogo,Reg.cod);
			if(pos != -1){
				Clear();
				gotoxy(28,12);
				printf("Jogo Ja Cadastrado!!\n");
				getch();
			}
			else{
				gotoxy(28,15);
				printf("Nome do Jogo: ");
				fflush(stdin);
				gets(Reg.descr);
				Reg.status = 'A';
				fwrite(&Reg, sizeof(TpJogos), 1, PtrJogo);
			}
			Clear();
			gotoxy(28,11);
			printf("**CADASTRO DE JOGOS**\n");
			gotoxy(28,13);
			printf("Codigo do Jogo: ");
			scanf("%d",&Reg.cod);
		}
		fclose(PtrJogo);
	}	
	getch();
}

void CadPart(void){
	TpPart Reg;
	FILE *PtrPart = fopen("Part.Dat", "ab+");
	int pos;
	
	Clear();
	if(PtrPart == NULL){
		gotoxy(28,12);
		printf("Arquivo nao encontrado!!\n");
		getch();
	}
	else{
		gotoxy(28,11);
		printf("**CADASTRO DE PARTICIPANTES**\n");
		gotoxy(28,13);
		printf("Codigo do Participante: ");
		scanf("%d", &Reg.cod);
		while(Reg.cod != 0){
			pos = BuscaBinaria(PtrPart,Reg.cod);
			if(pos != -1){
				Clear();
				gotoxy(28,12);
				printf("Participante ja cadastrado!\n");
				getch();
			}
			else{
				gotoxy(28,15);
				printf("Nome do Participante: ");
				fflush(stdin);
				gets(Reg.descr);
				Reg.status = 'A';
				fseek(PtrPart, 0, 2);
				fwrite(&Reg, sizeof(TpPart), 1, PtrPart);
				fclose(PtrPart);
				OrdenaID();
				PtrPart = fopen("Part.Dat", "ab+");	
			}
			Clear();
			gotoxy(28,11);
			printf("**CADASTRO DE PARTICIPANTES**\n");
			gotoxy(28,13);
			printf("Codigo do Participante: ");
			scanf("%d", &Reg.cod);
		}
		fclose(PtrPart);
	}
	getch();
}

void CadCamp(void){
	TpCamp Reg;
	FILE *PtrCamp = fopen("Camp.Dat", "ab+");
	FILE *PtrJogo = fopen("Jogos.Dat", "rb");
	int auxCod, pos, pos2, auxCod2;
	
	Clear();
	if(PtrCamp == NULL){
		gotoxy(28,12);
		printf("Arquivo nao encontrado!\n");
		getch();
	}
	else{
		gotoxy(28,11);
		printf("**CADASTRO DE CAMPEONATO**\n");
		gotoxy(28,13);
		printf("Codigo do Jogo: ");
		scanf("%d",&auxCod);
		while(auxCod != 0){
			pos2 = BuscaExaustiva(PtrJogo, auxCod);
			if(pos2 != -1){
				Reg.codTipo = auxCod;
				gotoxy(28,14);
				printf("Codigo do Campeonato: ");
				scanf("%d",&auxCod2);
				//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				fclose(PtrCamp);
				BBsortCamp();
				PtrCamp = fopen("Camp.Dat", "ab+");
				//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				pos = BuscaIndexada(PtrCamp, auxCod2);
				if(pos == -1){
					Reg.cod = auxCod2;
					gotoxy(28,15);
					printf("Titulo do Campeonato: ");
					fflush(stdin);
					gets(Reg.titulo);
					gotoxy(28,16);
					printf("Nome do Responsavel: ");
					fflush(stdin);
					gets(Reg.resp);
					gotoxy(28,17);
					printf("Ano do Campeonato: ");
					scanf("%d",&Reg.ano);
					gotoxy(28,18);
					printf("Digite a Descricao: ");
					fflush(stdin);
					gets(Reg.descr);
					Reg.status = 'A';
					fseek(PtrCamp, 0, 2);
					fwrite(&Reg, sizeof(TpCamp), 1, PtrCamp);
				}
				else{
					Clear();
					gotoxy(28,11);
					printf("Campeonato ja cadastrado!\n");
					getch();
				}
			}
			else{
				Clear();
				gotoxy(28,11);
				printf("\nJogo nao encontrado!\n");
				getch();
			}
			Clear();
			gotoxy(28,11);
			printf("**CADASTRO DE CAMPEONATO**\n");
			gotoxy(28,13);
			printf("Codigo do Jogo: ");
			scanf("%d",&auxCod);
		}
		fclose(PtrCamp);
		fclose(PtrJogo);
		BBsortCamp();
	}
	getch();
}

void CadPartCamp(void){
	ControlePartCamp Reg;
	FILE *PtrPC = fopen("PartCamp.Dat", "ab+");
	FILE *PtrCamp = fopen("Camp.Dat", "rb");
	FILE *PtrPart = fopen("Part.Dat", "rb");
	int auxCod, pos, auxCod2, pos2, pos3, pos4;
	char auxNick[50];
	Clear();
	
	if(PtrCamp == NULL){
		gotoxy(28,12);
		printf("Arquivo nao encontrado!\n");
	}
	else{
		gotoxy(28,11);
		printf("**PARTICIPANTES POR CAMPEONATO**\n");
		gotoxy(28,12);
		printf("Codigo do campeonato: ");
		scanf("%d", &auxCod);
		while(auxCod != 0){
			pos = BuscaIndexada(PtrCamp, auxCod);
			if(pos != -1){
				Reg.CodCamp = auxCod;
				gotoxy(28,13);
				printf("Codigo do Participante: ");
				scanf("%d", &auxCod2);
				pos2 = BuscaBinaria(PtrPart, auxCod2);
				if(pos2 != -1){
					pos3 = BuscaPartCamp(PtrPC, Reg.CodCamp, auxCod2);
					if(pos3 == -1){
						Reg.CodPart = auxCod2;
						gotoxy(28,14);
						printf("Nome do participante: ");
						fflush(stdin);
						gets(auxNick);
						pos4 = BuscaSentinela(PtrPC, Reg.CodCamp, auxNick);
						if(pos == -1){
							Clear();
							gotoxy(28,12);
							printf("\nNick ja cadastrado!\n");
							getch();
						}
						else{
							strcpy(Reg.Nick, auxNick);
							Reg.status = 'A';
							fseek(PtrPC, 0, 2);
							fwrite(&Reg, sizeof(ControlePartCamp), 1, PtrPC);
						}
					}
					else{
						Clear();
						gotoxy(28,12);
						printf("Participante ja cadastrado no campeonato!\n");
						getch();
					}
				}
				else{
					Clear();
					gotoxy(28,12);
					printf("Participante nao cadastrado!\n");
					getch();
				}
			}
			else{
				Clear();
				gotoxy(28,12);
				printf("Campeonato nao cadastrado!\n");
				getch();
			}
			Clear();
			gotoxy(28,11);
			printf("**PARTICIPANTES POR CAMPEONATO**\n");
			gotoxy(28,12);
			printf("Codigo do campeonato: ");
			scanf("%d", &auxCod);
		}	
	}
	fclose(PtrPC);
	fclose(PtrCamp);
	fclose(PtrPart);
	BBsortPC();
}

//---------------------------------------------------------*RELATORIOS*---------------------------------------------------------

void RelatorioJogo(void){
	TpJogos Reg;
	int i;
	FILE *PtrJogo = fopen("Jogos.Dat", "rb");
	Clear();
	
	if(PtrJogo == NULL){
		gotoxy(28,12);
		printf("Arquivo não encontrado!!\n");
		getch();
	}
	else{
		gotoxy(28,4);
		printf("**RELATORIO DE JOGOS**\n");
		fread(&Reg, sizeof(TpJogos), 1, PtrJogo);
		i = 8;
		while(!feof(PtrJogo)){
			if(Reg.status == 'A'){
				gotoxy(30,6);
				printf("Cod\tJogo");
				gotoxy(30,i);
				printf("%d\t\t%s\n", Reg.cod, Reg.descr);
				i++;
				if(i==23){
					gotoxy(30,i+1);
					printf("Pressione [Espaco] para Continuar");
					while(getch()!=32){
						gotoxy(30,i+1);
						printf("Pressione [Espaco] para Continuar");
					}
					i = 6;
				}
			}
			fread(&Reg, sizeof(TpJogos), 1, PtrJogo);
		}
		fclose(PtrJogo);
	}
	getch();
}

void RelatorioPart(void){
	TpPart Reg;
	int i;
	FILE *PtrPart = fopen("Part.Dat", "rb");
	Clear();
	
	if(PtrPart == NULL){
		gotoxy(28,12);
		printf("Arquivo nao encontrado!!\n");
		getch();
	}
	else{
		gotoxy(28,4);
		printf("**RELATORO DE PARTICIPANTES**\n");
		fread(&Reg, sizeof(TpPart), 1, PtrPart);
		i = 8;
		while(!feof(PtrPart)){
			if(Reg.status == 'A'){
				gotoxy(30,6);
				printf("Cod\tNome");
				gotoxy(30,i);
				printf("%d\t\t%s\n", Reg.cod, Reg.descr);
				i++;
				if(i==23){
					gotoxy(30,i+1);
					printf("Pressione [Espaco] para Continuar");
					while(getch()!=32){
						gotoxy(30,i+1);
						printf("Pressione [Espaco] para Continuar");
					}
					i = 6;
				}
			}
			fread(&Reg, sizeof(TpPart), 1, PtrPart);
		}
		fclose(PtrPart);
	}
	getch();
}

void RelatorioCamp(void){
	TpCamp Reg;
	int i, j;
	FILE *PtrCamp = fopen("Camp.Dat", "rb");
	Clear();
	
	if(PtrCamp == NULL){
		gotoxy(28,12);
		printf("Arquivo nao encontrado!\n");
		getch();
	}
	else{
		gotoxy(28,4);
		printf("**RELATORIO DE CAMPEONATOS**\n");
		fread(&Reg, sizeof(TpCamp), 1, PtrCamp);
		j = 1;
		i = 6;
		while(!feof(PtrCamp)){
			if(Reg.status == 'A'){
				gotoxy(15, i);
				printf("Cod: %d", Reg.cod);
				i++;
				gotoxy(15, i);
				printf("Titulo: %s", Reg.titulo);
				i++;
				gotoxy(15, i);
				printf("Responsavel: %s", Reg.resp);
				i++;
				gotoxy(15, i);
				printf("Ano: %d", Reg.ano);
				i++;
				gotoxy(15, i);
				printf("Jogo: %d", Reg.codTipo);
				i++;
				gotoxy(15, i);
				printf("Descricao: %s", Reg.descr);
			}
			i+=2;
			j++;
			fread(&Reg, sizeof(TpCamp), 1, PtrCamp);
			if(j>2){
				gotoxy(15, i+2);
				printf("Pressione [Espaco] para continuar");
				while(getch()!=32){
					gotoxy(15, i+2);
					printf("Pressione [Espaco] para continuar");
				}
				Clear();
				i = 6;
				j = 1;
			}
		}
		fclose(PtrCamp);
	}
	getch();
}

void RelatorioPC(void){
	ControlePartCamp Reg;
	int i;
	FILE *PtrPC = fopen("PartCamp.Dat", "rb");
	Clear();
	
	if(PtrPC == NULL){
		gotoxy(28,12);
		printf("Arquivo nao encontrado!\n");
	}
	else{
		gotoxy(20,4);
		printf("**RELATORIO DE PARTICIPANTES POR CAMPEONATO**\n");
		fread(&Reg, sizeof(ControlePartCamp), 1, PtrPC);
		gotoxy(20,6);
		printf("Cod-Camp\tCod-Part\tNick");
		i = 8;
		while(!feof(PtrPC)){
			if(Reg.status == 'A'){
				gotoxy(20,i);
				printf("%d\t\t%d\t\t%s\n", Reg.CodCamp, Reg.CodPart, Reg.Nick);
				i++;
			}
			fread(&Reg, sizeof(ControlePartCamp), 1, PtrPC);
			if(i==22){
				gotoxy(20,i+2);
				printf("Pressione [Espaco] para continuar");
				while(getch()!=32){
					gotoxy(15, i+2);
					printf("Pressione [Espaco] para continuar");
				}
				Clear();
				i = 8;
			}
		}
		fclose(PtrPC);
	}
	getch();
}

void RelatorioCampPart(void){
	
	TpJogos RegJ;
	TpPart RegP;
	TpCamp RegC;
	ControlePartCamp RegPC;
	int codPart,posPart, posPC, contTJ, contTotal = 0, i, j;
	
	FILE *PtrJogo = fopen("Jogos.Dat","rb");
	FILE *PtrPart = fopen("Part.Dat","rb");
	FILE *PtrCamp = fopen("Camp.Dat","rb");
	FILE *PtrPC = fopen("PartCamp.Dat","rb");
	
	Clear();
	gotoxy(28,13);
	printf("Digite o codigo do Participante: ");
	scanf("%d", &codPart);
	while(codPart!=0){
		contTotal = 0;
		posPart = BuscaBinaria(PtrPart, codPart);
		if(posPart == -1){
			Clear();
			gotoxy(28,12);
			printf("Participante nao encontrado");
			getch();
		}
		else{
			Clear();
			fseek(PtrPart,posPart,0);
			fread(&RegP, sizeof(TpPart), 1, PtrPart);
			gotoxy(2,4);
			printf("Jogador selecionado: %s\n", RegP.descr);
			fseek(PtrJogo,0,0);
			fread(&RegJ, sizeof(TpJogos), 1, PtrJogo);
			i = 0;
			j = 5;
			while(!feof(PtrJogo)){
				contTJ = 0;
				fseek(PtrCamp,0,0);
				fread(&RegC, sizeof(TpCamp), 1, PtrCamp);
				while(!feof(PtrCamp)){
					if(RegC.codTipo == RegJ.cod){
						posPC = BuscaPartCamp(PtrPC, RegC.cod, RegP.cod);
						if(posPC != -1){
							fseek(PtrPC, posPC,0);
							fread(&RegPC, sizeof(ControlePartCamp),1,PtrPC);
							if(contTJ == 0){
								gotoxy(2,j);
								printf("--------------------------------------------------------------");
								j++;
								gotoxy(2,j);
								printf("Tipo de Jogo: %s", RegJ.descr);
								j++;
							}
							gotoxy(2,j);
							printf("%s - Responsavel: %s (%d) - Nick: %s", RegC.titulo, RegC.resp, RegC.ano, RegPC.Nick);
							j++;
							contTJ++;
						}
					}
					fread(&RegC, sizeof(TpCamp), 1, PtrCamp);
				}
				if(contTJ > 0){
					i++;
					gotoxy(2,j);
					printf("Total de Campeonatos: %d\n", contTJ);
					j++;
					if(i>2){
						gotoxy(15, 22);
						printf("Pressione [Espaco] para continuar");
						while(getch()!=32){
							gotoxy(15, 22);
							printf("Pressione [Espaco] para continuar");
						}
						Clear();
						i = 0;
						j = 5;
					}
				}
				contTotal += contTJ;
				fread(&RegJ, sizeof(TpJogos), 1, PtrJogo);
			}
			gotoxy(2,j);
			printf("--------------------------------------------------------------");
			j++;
			gotoxy(2,j);
			printf("Total de Campeonatos do Participante %d\n", contTotal);
			j++;
			getch();
		}
		Clear();
		gotoxy(28,13);
		printf("Digite o codigo do Participante: ");
		scanf("%d", &codPart);
	}
	fclose(PtrJogo);
	fclose(PtrCamp);
	fclose(PtrPart);
	fclose(PtrPC);
}

void RelatorioPartCamp(void){
	TpJogos RegJ;
	TpPart RegP;
	TpCamp RegC;
	ControlePartCamp RegPC;
	int codCamp,posCamp, posJogo, posPC, contTJ, contTotal = 0, i;
	
	FILE *PtrJogo = fopen("Jogos.Dat","rb");
	FILE *PtrPart = fopen("Part.Dat","rb");
	FILE *PtrCamp = fopen("Camp.Dat","rb");
	FILE *PtrPC = fopen("PartCamp.Dat","rb");
	
	Clear();
	gotoxy(28,13);
	printf("Codigo do campeonato: ");
	scanf("%d", &codCamp);
	while(codCamp != 0){
		posCamp = BuscaIndexada(PtrCamp, codCamp);
		if(posCamp == -1){
			Clear();
			gotoxy(28,12);
			printf("Campeonato nao encontrado\n");
		}
		else{
			Clear();
			fseek(PtrCamp, posCamp, 0);
			fread(&RegC, sizeof(TpCamp), 1, PtrCamp);
			gotoxy(6,5);
			printf("%s", RegC.titulo);
			posJogo = BuscaExaustiva(PtrJogo, RegC.codTipo);
			fseek(PtrJogo, posJogo, 0);
			fread(&RegJ, sizeof(TpJogos), 1, PtrJogo);
			gotoxy(6,7);
			printf("Responsavel: %s - %d - %s\n", RegC.resp, RegC.ano, RegJ.descr);
			gotoxy(6,9);
			printf("Descricao:\n");
			gotoxy(6,10);
			printf("%s\n", RegC.descr);
			gotoxy(6,12);
			printf("Participantes (em ordem alfabetica):\n");
			OrdenaPart(PtrPart);
			fseek(PtrPart, 0, 0);
			fread(&RegP, sizeof(TpPart), 1, PtrPart);
			i = 14;
			while(!feof(PtrPart)){
				posPC = BuscaPartCamp(PtrPC, RegC.cod, RegP.cod);
				if(posPC != -1){
					gotoxy(6,i);
					printf(" - %s\n", RegP.descr);
					i++;
					if(i>21){
						gotoxy(15, 22);
						printf("Pressione [Espaco] para continuar");
						while(getch()!=32){
							gotoxy(15, 22);
							printf("Pressione [Espaco] para continuar");
						}
						Clear();
						i = 5;
					}
				}	
				fread(&RegP, sizeof(TpPart), 1, PtrPart);
				
			}
			getch();
		}
		Clear();
		gotoxy(28,13);
		printf("Codigo do campeonato: ");
		scanf("%d", &codCamp);
	}
	fclose(PtrJogo);
	fclose(PtrCamp);
	fclose(PtrPart);
	fclose(PtrPC);
	getch();
}

//---------------------------------------------------------*FUNÇÃO PRINCIPAL*---------------------------------------------------------

int main(void){
	char op1, opJogos, opPart, opCamp, opPC, opEx;
	
	Moldura(1, 1, 80, 25, 3, 0);
	
	op1 = MenuPrincipal();
	do{
		switch(op1){
			case 'A':
				opJogos = MenuJogo();
				do{
					switch(opJogos){
						case 'A':
							CadJogo();
							OrdenaSD();
							break;
						case 'B':
							ExcLogicaJogo();
							OrdenaSD();
							break;
						case 'C':
							AlterarJogo();
							OrdenaSD();
							break;
						case 'D':
							ConsultaJogo();
							break;
						case 'E':
							RelatorioJogo();
							break;
					}
					opJogos = MenuJogo();
				}while(opJogos!=27);
				break;
			case 'B':
				opPart = MenuPart();
				do{
					switch(opPart){
						case 'A':
							CadPart();
							break;
						case 'B':
							ExcLogicaPart();
							ExcFisicaPart();
							break;
						case 'C':
							AlterarPart();
							break;
						case 'D':
							ConsultaPart();
							break;
						case 'E':
							RelatorioPart();
							break;
					}
					opPart = MenuPart();
				}while(opPart!=27);
				break;
			case 'C':
				opCamp = MenuCamp();
				do{
					switch(opCamp){
						case 'A':
							CadCamp();
							break;
						case 'B':
							ExcLogicaCamp();
							ExcFisicaCamp();
							break;
						case 'C':
							AlterarCamp();
							break;
						case 'D':
							ConsultaCamp();
							break;
						case 'E':
							RelatorioCamp();
							break;
					}
					opCamp = MenuCamp();
				}while(opCamp!=27);
				break;
			case 'D':
					opPC = MenuPC();
					do{
						switch(opPC){
							case 'A':
								CadPartCamp();
								break;
							case 'B':
								ExcLogicaPC();
								break;
							case 'C':
								AlterarPC();
								break;
							case 'D':
								ConsultaPC();
								break;
							case 'E':
								RelatorioPC();
								break;
						}
						opPC = MenuPC();
					}while(opPC != 27);
				break;
			case 'E':
				opEx = MenuExtra();
				do{
					switch(opEx){
						case 'A':
							RelatorioCampPart();
							break;
						case 'B':
							RelatorioPartCamp();
							break;
					}
					opEx = MenuExtra();
				}while(opEx != 27);
				break;
		}
		op1 = MenuPrincipal();
	}while(op1!=27);
	ExcFisicaPC();
	ExcFisicaPart();
	ExcFisicaJogo();
	ExcFisicaCamp();
}
