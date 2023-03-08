#include <stdio.h>
#include <conio2.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ESC 27
#define KEY_ENTER 13
#define KEY_LEFT 75
#define KEY_RIGTH 77

int x,y,c=219,direcao,aux,direcao,flag=-1; 
int	sample[5][16]={	0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0,
					1,1, 1,0, 0,0, 1,1, 1,0, 0,0, 1,1, 1,0,
			    	1,0, 1,0, 1,1, 0,0, 1,0, 0,0, 0,0, 1,0,
			    	0,0, 1,0, 1,0, 0,0, 1,1, 0,0, 1,0, 1,0,
			    	0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0};
int s_alt[7][16]={	2,1, 1,1, 3,0, 2,0, 2,1, 3,1, 1,0, 2,1,//v1
					2,0, 1,0, 3,2, 2,0, 3,2, 2,0, 1,0, 2,1,//v2
					3,1, 1,0, 2,1, 2,0, 1,0, 2,1, 3,1, 2,1,//v3
					3,0, 2,1, 3,1, 1,1, 2,1, 3,0, 0,0, 2,1,
					1,1, 1,0, 0,0, 1,1, 1,0, 0,0, 1,1, 1,0,//gabaritoA
			    	1,0, 1,0, 1,1, 0,0, 1,0, 0,0, 0,0, 1,0,//gabaritoB
			    	0,0, 1,0, 1,0, 0,0, 1,1, 0,0, 1,0, 1,0,};//gabaritoC
void mA();
void mB();
void mC();
void mG();
void mR();
void movevetor();

main(){
	srand(time(NULL));
	int caract;
	sleep(1);
	do{
		stop:clrscr();
	y = rand() % 4;
	
		for(x=0;x<16;x++){
			sample[0][x]= s_alt[y][x];
			sample[1][x]= s_alt[4][x];
			sample[2][x]= s_alt[5][x];
			sample[3][x]= s_alt[6][x];
		}
		
		gotoxy(45,15); textcolor(RED); printf_s("Resident Evil 3!"); textcolor(YELLOW);
		gotoxy(49,16); printf("Nemesis!");textcolor(WHITE);
		gotoxy(43,17); printf("Puzzle Water Sample!");textcolor(LIGHTBLUE);
		gotoxy(44,19); printf("Press ENTER to START ");
		gotoxy(44,20); printf(" Press ESC to left");
		
		caract = getch();
		if(caract==KEY_ESC){
			clrscr();
			gotoxy(45,15);printf("---------MISSION FAILED---------");
			exit(1);
		}
	}while(caract!=13);
	while(1){
		aux =1;
		while(1){
			clrscr();
			mG();
			mA();
			mB();
			mC();
		
			textcolor(WHITE);
			gotoxy(22,25); printf("Which wave range will you adjust?");
			if(aux==1){gotoxy(22,26);printf(">A<   B    C   Cancel ");}
			if(aux==2){gotoxy(22,26);printf(" A   >B<   C   Cancel ");}
			if(aux==3){gotoxy(22,26);printf(" A    B   >C<  Cancel ");}
			if(aux==4){gotoxy(22,26);printf(" A    B    C  >Cancel<");}
			caract = getch();
			if(caract==KEY_RIGTH) aux++;
			if(caract==KEY_LEFT) aux--;
			if(caract==KEY_ENTER) break; 
			if(aux==5)aux=1; if(aux==0)aux=4;
		}
		direcao=1;
		while(1){
			if(aux==4)
				goto stop;
			clrscr();
			mG();
			mA();
			mB();
			mC();
			textcolor(WHITE);
			gotoxy(22,25); printf("Which wave range will you adjust?");
			if(direcao==1){gotoxy(22,26);printf(">LEFT<    RIGTH     CHECK     BACK ");}
			if(direcao==2){gotoxy(22,26);printf(" LEFT    >RIGTH<    CHECK     BACK ");}
			if(direcao==3){gotoxy(22,26);printf("LEFT      RIGTH    >CHECK<    BACK ");}
			if(direcao==4){gotoxy(22,26);printf("LEFT      RIGTH     CHECK    >BACK<");}
			caract = getch();
			if(caract==KEY_RIGTH) direcao++;
			if(caract==KEY_LEFT) direcao--;
			if(direcao==5)direcao=1; if(direcao==0)direcao=4;
			if(caract==KEY_ENTER){
				if(direcao==1||direcao==2)
					movevetor(aux,direcao);
				if(direcao==3)
					mR();
				if(direcao==4)break;
				if(flag==1){
					sleep(5);
					goto stop2;
				}
			}
			
		}
	}
	stop2:
		clrscr();
		gotoxy(45,15);
		printf("---You have only two mission now---"); sleep(1);
		gotoxy(45,17); printf("   RUN and... ");sleep(2);textcolor(RED);printf(" SURVIVE!!    ");
}









void mA(){
	textcolor(WHITE);
	gotoxy(10,9); printf("---------------------------------------------------------------");
	textcolor(RED);
	
	gotoxy(15,10);
	printf("A:");
	gotoxy(21,10);
	printf("   |");
	for(x=0;x<=15;x++){
		if(sample[1][x]==1)
			printf("%c%c%c",c,c,c);
		else
			printf("   ");
	}
	printf("|");
}
void mB(){
	textcolor(WHITE);
	gotoxy(10,11); printf("---------------------------------------------------------------");
	textcolor(YELLOW);
	gotoxy(15,12); printf("B:"); gotoxy(21,12); printf("   |");
	for(x=0;x<=15;x++){
		if(sample[2][x]==1)
			printf("%c%c%c",c,c,c);
		else
			printf("   ");
	}
	printf("|");
}
void mC(){
	textcolor(WHITE);
	gotoxy(10,13); printf("---------------------------------------------------------------");
	textcolor(LIGHTBLUE);
	gotoxy(15,14); printf("C"); gotoxy(21,14); printf("   |");
	for(x=0;x<=15;x++){
		if(sample[3][x]==1)
			printf("%c%c%c",c,c,c);
		else
			printf("   ");
	}
	printf("|");
	gotoxy(10,15); printf("---------------------------------------------------------------");
}
void mG(){
	textcolor(WHITE);
	int in,on;
	gotoxy(10,8); printf("SAMPLE:       |");
	in =22;on=8;
	for(x=0;x<=15;x++){
		in = in+3;
		on = 8;	
		if(sample[0][x]>0){
			for(y=1;y<=sample[0][x];y++){
				gotoxy(in,on);
				printf("%c%c%c",c,c,c);
				on--;
			}	
		}
		else{
				gotoxy(in,on);
				printf("   ",c,c,c);
				on--;	
		}
	}
	gotoxy(73,8);printf("|");
	
}
void mR(){
	textcolor(WHITE);
	int in,on;
	gotoxy(10,18); printf("RESULT:       |");
	in =22;on=18;
	
	for(x=0;x<=15;x++)
	sample[4][x]=sample[1][x]+sample[2][x]+sample[3][x];
	
	for(x=0;x<=15;x++){
		in = in+3;
		on = 18;
		sleep(1);	
		if(sample[4][x]>0){
			for(y=1;y<=sample[4][x];y++){
				gotoxy(in,on);
				printf("%c%c%c",c,c,c);
				
				on--;
			}	
		}
		gotoxy(22,18);
	}
	
		gotoxy(73,18);printf("|");
		flag=0;
		for(x=0;x<=15;x++)
			if(sample[0][x]!=sample[4][x])
				flag++;
		flag++;
		gotoxy(22,25);
		if(flag==1){
			printf("Water quality check has passed the safety level.");
		}
		else
			printf("The result graph is different from the sample.");
			gotoxy(22,26);delline();
		sleep(1);
			
	
}
void movevetor(){
	int troca,backup;
	
	if(direcao==1){
		for(x=1;x<=2;x++){
//			sleep(1);
			troca = sample[aux][0];
			for(y=0;y<15;y++)
				sample[aux][y] = sample [aux][y+1];
			sample[aux][y] = troca;
			
		}
		
	}
	else{
		for(x=1;x<=2;x++){
//			sleep(1);
			troca = sample[aux][15];
			for(y=15;y>0;y--)
				sample[aux][y]=sample[aux][y-1];
			sample[aux][y] =troca;
			}
				
	}	
}
