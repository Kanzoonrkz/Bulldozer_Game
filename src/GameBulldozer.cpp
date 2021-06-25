#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>

#define batu char(254)
#define targetbatu char(177)
#define targetplayer char(157)
#define target char(158)
using namespace std;
char choice;
//Bulldogame
short x, y;
char peta[50][50], jalan=' ';
string password;

//Breakdoor
int n = 1; int e[5], g[5], f, q;
vector<pair<int,int> > p; 
bool sortsec(const pair<int,int> &a, const pair<int,int> &b){ //sort descending by second element (banyak senjata per tipe)
    return (a.second > b.second); 
}
bool cekhbs(int &f, vector<pair<int,int> > p);

void pintu(int row[], int col[], int x){ //buat ngluarin pintu
	system("CLS");
	char er[10][10];
	for (int i = 0; i<10;i++){
		for (int j = 0; j<10; j++){
			er[i][j] = 177;
			for (int k = 0; k<=x; k++){
				if (i == row[k] && j == col[k]){
					er[i][j] = 32;
				}
			}
			cout << char(er[i][j]);
		}
		cout << endl;
	} 
}

void ask();
void gamebatu();
void gamepintu();
//fungsi game bulldogame
void move();
void check();
void gotoxy(int x, int y);
HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

void setCursor(int x, int y){
	SetConsoleCursorPosition(handle, {x,y});
	}

int main(){
	system("COLOR F0");
	while(choice!=char(147)){
		cout<<"\r===================================  WELCOME TO BULLDOGAME  ===================================";//greeting bisa dibikin warna warni
		cout<<"\nHEY YO!\nWhat do you want rite now??\n\n1. START DA GAME\n2. I want to see my score!\n\n\n\nPress ctrl+delete to exit";
		choice=getch();
		switch(choice)
		{
			case '1': gamebatu();break;
			case '2': break;
		}
		system("cls");
	}
	system("cls");
	cout<<"Thankyou for playing our game!!";
	getch();
	exit(0);
}

//Bulldozer
void origin(){
	if(peta[x][y]=='O'){
		peta[x][y]=jalan;
	}
	else if(peta[x][y]==targetplayer){
		peta[x][y]=target;
	}
	gotoxy(x,y);cout<<peta[x][y];
}

void petaawal(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			peta[i][j]=char(178);
		}
	}
	
}

void printpeta(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(peta[i][j]==char(178)){
				SetConsoleTextAttribute(color, 242);
				cout<<peta[i][j];SetConsoleTextAttribute(color, 240);}
			else{cout<<peta[i][j];
			}
			
		}
		cout<<endl;
	}
	cout<<"Move all stone to "<<target<<" !\nPress shift+E to go back to level selection"<<"\nO = You                     "<<batu<<" = stone\n"<<char(157)<<" = You on target           "<<targetbatu<<" = Stone on target";
}

void peta1(){
	n=8;petaawal();
	peta[4][4]='O';
	peta[2][3]=jalan;peta[3][4]=jalan;peta[4][2]=jalan;
	peta[1][3]=target;peta[4][1]=target;peta[3][6]=target;peta[6][4]=target;
	peta[3][3]=batu;peta[4][3]=batu;peta[3][5]=batu;peta[5][4]=batu;
}

void peta2(){
	n=11;petaawal();
	for(int i=1; i<n-1; i++){
		for(int j=1; j<n-1; j++){
			peta[i][j]=jalan;
		}
	}
	for(int i=1; i<8; i++){peta[i][2]=char(178);}
	for(int i=4; i<n; i++){peta[i][8]=char(178);}peta[2][8]=char(178);
	peta[3][5]='O';
	peta[2][3]=batu;peta[5][5]=batu;peta[8][6]=batu;peta[8][7]=batu;
	peta[1][1]=target;peta[2][1]=target;peta[8][9]=target;peta[9][9]=target;
}

void peta3(){
	n=9;petaawal();
	for(int i=6; i<8; i++){for(int j=2; j<5; j++){peta[i][j]=jalan;}}
	for(int j=2; j<4; j++){peta[1][j]=jalan;}peta[4][3]=jalan;
	for(int j=3; j<7; j++){peta[5][j]=jalan;}peta[3][3]=jalan;
	for(int j=6; j<8; j++){peta[6][j]=jalan;}
	for(int i=2; i<4; i++){peta[i][1]=jalan;}
	peta[1][1]='O';
	peta[2][2]=batu;peta[2][3]=batu;peta[3][2]=batu;
	for(int i=3; i<6; i++){peta[i][7]=target;}
}

void peta4(){
	n=9;petaawal();
	for(int i=1; i<6; i+=4){for(int j=3; j<6; j++){peta[i][j]=jalan;}}
	for(int i=6; i<8;i++){for(int j=1; j<n-1; j++){peta[i][j]=jalan;}}
	peta[2][4]=jalan;peta[2][5]=jalan;peta[3][3]=jalan;peta[5][1]=jalan;peta[4][5]=jalan;
	peta[2][2]='O';
	peta[2][1]=target;peta[3][5]=target;peta[4][1]=target;peta[6][6]=target;peta[7][4]=target;peta[5][4]=target;
	peta[2][3]=batu;peta[3][4]=batu;peta[4][4]=batu;peta[6][4]=batu;peta[6][5]=batu;peta[6][1]=batu;
	peta[6][3]=targetbatu;
}

void gamebatu(){
	system("cls");
	cout<<"=======================================  BULLDOGAME  ========================================\nCHOOSE LEVEL\n1		2\n3		4\nPress shift+E to go back.\n";
	choice=getch();
	switch(choice)
	{
		case '1':system("cls");peta1();move();cout<<"\n\n?";choice=getch();gamebatu();break;
		case '2':system("cls");peta2();move();cout<<"\n\nMaybe learning";choice=getch();gamebatu();break;
		case '3':system("cls");peta3();move();gamebatu();break;
		case '4':system("cls");peta4();move();gamebatu();break;
		case 'E':system("cls");main();
		case '+':choice=getch();
		default: gamebatu();
	}
}

void move(){
	system("cls");printpeta();
	while(choice!=char(147) || choice!=char(0)){
	
		
		for(int i=0; i<n; i++){//cek posisi player
			for(int j=0; j<n; j++){
				if(peta[i][j]=='O' || peta[i][j]==targetplayer){
					x=i;y=j;break;
				}
			}
		}
		
		choice=getch();
		
		if(choice=='H' || choice=='w'){//atas
			if(peta[x-1][y]!=char(178) || (peta[x-1][y]==batu || peta[x-1][y]==targetbatu && (peta[x-2][y]!=char(178) || peta[x-2][y]!=batu || peta[x-2][y]!=targetbatu))){
				if(peta[x-1][y]==batu && peta[x-2][y]==target){
					peta[x-2][y]=targetbatu;gotoxy(x-2,y);cout<<peta[x-2][y];
					peta[x-1][y]='O';origin();
				}
				else if(peta[x-1][y]==batu && peta[x-2][y]==jalan){
					peta[x-2][y]=batu;gotoxy(x-2,y);cout<<peta[x-2][y];
					peta[x-1][y]='O';origin();
				}
				else if(peta[x-1][y]==targetbatu && peta[x-2][y]==target){
					peta[x-2][y]=targetbatu;gotoxy(x-2,y);cout<<peta[x-2][y];
					peta[x-1][y]=targetplayer;origin();
				}
				else if(peta[x-1][y]==targetbatu && peta[x-2][y]==jalan){
					peta[x-2][y]=batu;gotoxy(x-2,y);cout<<peta[x-2][y];
					peta[x-1][y]=targetplayer;origin();
				}
				else if(peta[x-1][y]==jalan){
					peta[x-1][y]='O';origin();
				}
				else if(peta[x-1][y]==target){
					peta[x-1][y]=targetplayer;origin();
				}
				gotoxy(x-1,y);cout<<peta[x-1][y];
			}
		}
		
		else if(choice=='K' || choice =='a'){//kiri
			if(peta[x][y-1]!=char(178) || (peta[x][y-1]==batu || peta[x][y-1]==targetbatu && (peta[x][y-2]!=char(178) || peta[x][y-2]!=batu || peta[x][y-2]!=targetbatu))){
				if(peta[x][y-1]==batu && peta[x][y-2]==target){
					peta[x][y-2]=targetbatu;gotoxy(x,y-2);cout<<peta[x][y-2];
					peta[x][y-1]='O';origin();
				}
				else if(peta[x][y-1]==batu && peta[x][y-2]==jalan){
					peta[x][y-2]=batu;gotoxy(x,y-2);cout<<peta[x][y-2];
					peta[x][y-1]='O';origin();
				}
				else if(peta[x][y-1]==targetbatu && peta[x][y-2]==target){
					peta[x][y-2]=targetbatu;gotoxy(x,y-2);cout<<peta[x][y-2];
					peta[x][y-1]=targetplayer;origin();
				}
				else if(peta[x][y-1]==targetbatu && peta[x][y-2]==jalan){
					peta[x][y-2]=batu;gotoxy(x,y-2);cout<<peta[x][y-2];
					peta[x][y-1]=targetplayer;origin();
				}
				else if(peta[x][y-1]==jalan){
					peta[x][y-1]='O';origin();
				}
				else if(peta[x][y-1]==target){
					peta[x][y-1]=targetplayer;origin();
				}
				gotoxy(x,y-1);cout<<peta[x][y-1];
			}
		}
		
		else if(choice=='M' || choice == 'd'){//kanan
			if(peta[x][y+1]!=char(178) || (peta[x][y+1]==batu || peta[x][y+1]==targetbatu && (peta[x][y+2]!=char(178) || peta[x][y+2]!=batu || peta[x][y+2]!=targetbatu))){
				if(peta[x][y+1]==batu && peta[x][y+2]==target){
					peta[x][y+2]=targetbatu;gotoxy(x,y+2);cout<<peta[x][y+2];
					peta[x][y+1]='O';origin();
				}
				else if(peta[x][y+1]==batu && peta[x][y+2]==jalan){
					peta[x][y+2]=batu;gotoxy(x,y+2);cout<<peta[x][y+2];
					peta[x][y+1]='O';origin();
				}
				else if(peta[x][y+1]==targetbatu && peta[x][y+2]==target){
					peta[x][y+2]=targetbatu;gotoxy(x,y+2);cout<<peta[x][y+2];
					peta[x][y+1]=targetplayer;origin();
				}
				else if(peta[x][y+1]==targetbatu && peta[x][y+2]==jalan){
					peta[x][y+2]=batu;gotoxy(x,y+2);cout<<peta[x][y+2];
					peta[x][y+1]=targetplayer;origin();
				}
				else if(peta[x][y+1]==jalan){
					peta[x][y+1]='O';origin();
				}
				else if(peta[x][y+1]==target){
					peta[x][y+1]=targetplayer;origin();
				}
				gotoxy(x,y+1);cout<<peta[x][y+1];
			}
		}
		
		else if(choice=='P' || choice == 's'){//bawah
			if(peta[x+1][y]!=char(178) || (peta[x+1][y]==batu || peta[x+1][y]==targetbatu && (peta[x+2][y]!=char(178) || peta[x+2][y]!=batu || peta[x+2][y]!=targetbatu))){
				if(peta[x+1][y]==batu && peta[x+2][y]==target){
					peta[x+2][y]=targetbatu;gotoxy(x+2,y);cout<<peta[x+2][y];
					peta[x+1][y]='O';origin();
				}
				else if(peta[x+1][y]==batu && peta[x+2][y]==jalan){
					peta[x+2][y]=batu;gotoxy(x+2,y);cout<<peta[x+2][y];
					peta[x+1][y]='O';origin();
				}
				else if(peta[x+1][y]==targetbatu && peta[x+2][y]==target){
					peta[x+2][y]=targetbatu;gotoxy(x+2,y);cout<<peta[x+2][y];
					peta[x+1][y]=targetplayer;origin();
				}
				else if(peta[x+1][y]==targetbatu && peta[x+2][y]==jalan){
					peta[x+2][y]=batu;gotoxy(x+2,y);cout<<peta[x+2][y];
					peta[x+1][y]=targetplayer;origin();
				}
				else if(peta[x+1][y]==jalan){
					peta[x+1][y]='O';origin();
				}
				else if(peta[x+1][y]==target){
					peta[x+1][y]=targetplayer;origin();
				}
				gotoxy(x+1,y);cout<<peta[x+1][y];
			}
		}
		
		else if(choice=='E'){
		gamebatu();
		}	
		gotoxy(0,n+1);
		check();if(choice==char(0)){
		if(choice==char(0)){
		
		system("cls");printpeta();
		cout<<"\nCONGRATULATIONS! YOU DID IT!";
		getch();
		}break;
		}
		
	}
}

void check(){
	choice=char(0);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(peta[i][j]==target || peta[i][j]==targetplayer){
				choice=' ';
			}
		}
	}
}

void gotoxy(int x, int y){
     // get the console handle
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
     COORD point;
     point.X = y;    // set the new cursor location coordinates
     point.Y = x;
     SetConsoleCursorPosition(hConsole, point);
     return;
}
//end of Bulldozer
 
