int main(){int W=20,H=12,S=W*H,l=0,p=0,d=1,a=0,i,m[S]={},h[256]={['a']=-1,['d']
=1,['w']=-W,['s']=W};for(srand(time(0));a-p||(a=rand()%S,l++),!m[p];Sleep(100))
{for(system("cls"),m[p]=l,i=0;i<S;++i%W||puts("|"))printf(m[i]?m[i]--,"()":i-a?
"  ":"00");kbhit()&&(i=h[getch()])&&(d=i),p=(S+p+d)%S;}}
