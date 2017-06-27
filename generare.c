///\file generare.c
///\brief Librarie implementata pentru generarea datelor de input

#include"head.h"
FILE *gen;
void genereaza()
{
	///\fn void genereaza()
    ///\brief genereaza datele de input
	
    int x,i,y,sw,n,m,j;
    char t;
    gen=fopen("a.txt","w");
    srand(time(NULL));
    x=rand()%429496729+1;
    fprintf(gen,"%d\n",x);
    y=rand()%429496729+1;
    for(i=1;i<=y;i++){
        sw=0;
        do{
            x=rand()%128;
            if(x>=48&&x<=57)
                sw=1;
            if(x>=65&&x<=90&&sw==0)
                sw=1;
            if(x>=97&&x<=122&&sw==0)
                sw=1;
        }while(sw==0);
        t=x;
        fprintf(gen,"%c",t);
    }
    fprintf(gen,"\n");
    fclose(gen);
    gen=fopen("b.txt","w");
        x=rand()%429496729+1;
    fprintf(gen,"%d\n",x);
    y=rand()%429496729+1;
    for(i=1;i<=y;i++){
        sw=0;
        do{
            x=rand()%128;
            if(x>=48&&x<=57)
                sw=1;
            if(x>=65&&x<=90&&sw==0)
                sw=1;
            if(x>=97&&x<=122&&sw==0)
                sw=1;
        }while(sw==0);
        t=x;
        fprintf(gen,"%c",t);
    }
    fprintf(gen,"\n");
    fclose(gen);
    gen=fopen("in.txt","w");
    n=rand()%1000+1;
    for(j=1;j<=n;j++){
        x=rand()%18+1;
        if(j%2==0)
            x=rand()%10+1;
        if(x==13||x==14){
            sw=0;
            do{
                y=rand()%128;
                if(y>=48&&y<=57)
                    sw=1;
                if(y>=65&&y<=90&&sw==0)
                    sw=1;
                if(y>=97&&y<=122&&sw==0)
                    sw=1;
            }while(sw==0);
            t=y;
            fprintf(gen,"%d %c\n",x,t);
        }
        if(x==17||x==18){
            m=rand()%100;
            fprintf(gen,"%d ",x);
            for(i=0;i<m;i++){
                sw=0;
                do{
                    y=rand()%128;
                    if(y>=48&&y<=57)
                        sw=1;
                    if(y>=65&&y<=90&&sw==0)
                        sw=1;
                    if(y>=97&&y<=122&&sw==0)
                        sw=1;
                }while(sw==0);
                t=y;
                fprintf(gen,"%c",t);
            }
            fprintf(gen,"\n");

        }
        if(x!=13&&x!=14&&x!=17&&x!=18)
            fprintf(gen,"%d\n",x);
    }
    fprintf(gen,"19\n");
    fclose(gen);


}
