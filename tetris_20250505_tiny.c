#include <conio.h>    //   ████████  ██████  ████████  ████████  ██  ██████  ██
#include <stdio.h>    //      ██     ██         ██     ██    ██  ██  ██      ██
#include <time.h>     //      ██     ████       ██     ████████  ██  ██████  ██
#include <windows.h>  //      ██     ██         ██     ██  ██    ██      ██
int W=10,H=20,X,Y,Z,c //      ██     ██████     ██     ██    ██  ██  ██████  ██
,i,j,k,m[200]={0},n[28]={214375,218778,148833,148834,148832,148890,153225};void
I(){X=W/2-2,Y=0,Z=rand()%7;}void F(int v){for(c=0,k=n[Z];k>4;k>>=4)i=X+k%4,j=Y+
k/4%4,c+=0<=i&&i<W&&j<H?m[j*W+i]^=v:1;}int S(int*K,int v){return*K+=v,F(0),c?*K
-=v,1:0;}int main(){for(i=7;i<28;++i)for(k=n[i-7],j=n[i]=k>>16;k>4;k>>=4)n[i]=n
[i]<<4|k%4*4|j-k/4%4;srand(time(0));I();for(;;system("cls")){F(1);for(i=0;i<W*H
;++i%W||puts("#"))printf(m[i]?"[]":"  ");F(1);c=getch();c-'d'||S(&X,1);c-'a'||S
(&X,-1);c-'w'||S(&Z,Z<21?7:-21);if(c=='s'&&S(&Y,1)){if(Y==0)break;for(F(1),I(),
i=0,c=1;i<W*H;)if(c*=m[i],++i%W==0){if(c)memmove(m+W,m,(i-W)*4);c=1;}}}}
