#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<conio.h>
void Color(int couleurDuTexte,int couleurDeFond);
void Color(int couleurDuTexte,int couleurDeFond)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
int Test(char M[3]){
if(strcmp(M," |")==0)return 1;
else return 0;
}
int Win(int S[9]){
if((S[0]+S[1]+S[2])==3)return 1;
if((S[3]+S[4]+S[5])==3)return 1;
if((S[6]+S[7]+S[8])==3)return 1;
if((S[0]+S[3]+S[6])==3)return 1;
if((S[1]+S[4]+S[7])==3)return 1;
if((S[2]+S[5]+S[8])==3)return 1;
if((S[0]+S[4]+S[8])==3)return 1;
if((S[2]+S[4]+S[6])==3)return 1;

if((S[0]+S[1]+S[2])==15)return 2;
if((S[3]+S[4]+S[5])==15)return 2;
if((S[6]+S[7]+S[8])==15)return 2;
if((S[0]+S[3]+S[6])==15)return 2;
if((S[1]+S[4]+S[7])==15)return 2;
if((S[2]+S[5]+S[8])==15)return 2;
if((S[0]+S[4]+S[8])==15)return 2;
if((S[2]+S[4]+S[6])==15)return 2;


return 0;
}
void Win1(){
       Color(12,15);
printf("Congratulation !! \n");
printf("     O    Win ^_^ \n");
Color(15, 0);
}
void Win2(){
           Color(12,15);
printf("Congratulation !! \n");
printf("      X      Win ^_^ \n");
Color(15, 0);
}
void Game(){
	system("cls");
	char n;
    int i,J=1,L=0,W=1,S[9],A=0,B=0;
    char M[9][3]={" |"," |"," |"," |"," |"," |"," |"," |"," |"};
    do{
for (i=0;i<9;i++){
if (i==L){
   Color(0,15);
   printf("%s",M[i]);
   Color(15, 0);}
   else printf("%s",M[i]);
       if(J%3==0)printf("\n------\n");
J++;
}
printf("O : %d , X : %d \n",A,B);
if(W%2==0){
                printf("X Tour \n");
}
if(W%2!=0){                printf("O Tour \n");

}


n=getch();
 if (n==80) {
        L=L+3;
        if (L==9) L=0;
        if (L==10) L=1;
        if (L==11) L=2;

	    }

   if (n==72) {
            L=L-3;
	    if (L==-3) L=6;
        if (L==-2) L=7;
        if (L==-1) L=8;
   }
   if(n==77){

    L=L+1;
	   if (L==9) L=0;
   }
   if(n==75){
	   if (L==0) L=9;
    L=L-1;
   }
    if (n==13) {
if(W%2==0){
        if(Test(M[L])==1){
            strcpy(M[L],"X|");W++;
            S[L]=1;
        }
        else {
             Color(7,15);
   printf("%s",M[L]);
   Color(15, 0);}
            printf("O Tour \n");
}

if(W%2!=0){
                if(Test(M[L])==1){
            strcpy(M[L],"O|");W++;
            S[L]=5;
        }
        else {
             Color(7,15);
   printf("%s",M[L]);
   Color(15, 0);}
            printf("X Tour \n");
}
  }
  system("cls");
  if(Win(S)==1){B++;n=18;Win2();break;}//printf("%d",B);printf("%d",A);
  if(Win(S)==2){A++;n=18;Win1();break;}//printf("%d",B);printf("%d",A);
  if(W==10){n=18;printf("DRAW\n");}
    }while(n!=18);
}
int main()
{
	int K;
	do{
    Game();
    printf("--------------------------\n");
    printf("Press[1] : Reset \n");
    printf("Press[2] : Quit \n");
    scanf("%d",&K);
}while(K!=2);

}

