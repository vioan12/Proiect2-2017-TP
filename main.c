///\file main.c

#include"head.h"
int main()
{
	///\fn int main()
	///\brief Functia principala.
	///\var c1 primul sir de caractere
	///\var c2 al doilea sir de caractere
	///\var file1 un fisier
	///\var read un alt fisier
    FILE *file1,*read;
    int sw,i,x,j,st,sw2;
    char *c1,*c2,c,d[99999],nr[11];
    c1=c2=NULL;
    i=1;
    //printf("\n\nAveti urmatoarele optiuni:\n\t1)Citirea sirului de caractere c1\n\t2)Citirea sirului de caractere c2\n\t3)Afisarea sirului de caractere c1\n\t4)Afisarea sirului de caractere c2\n\t5)Afisarea lungimei sirului c1\n\t6)Afisarea lungimei sirului c2\n\t7)Copierea sirului c2 in sirul c1\n\t8)Copierea sirului c1 in sirul c2\n\t9)Concatenarea sirului c1 cu sirul c2\n\t10)Concatenarea sirului c2 cu sirul c1\n\t11)Compararea sirului c1 cu sirul c2\n\t12)Compararea sirului c2 cu sirul c1\n\t13)Cautarea unui caracter dat in sirul c1\n\t14)Cautarea unui caracter dat in sirul c2\n\t15)Cautarea sirului c2 in sirul c1\n\t16)Cautarea sirului c1 in sirul c2\n\t17)Cautarea unui sir dat in sirul c1\n\t18)Cautarea unui sir dat in sirul c2\n\t19)Iesire\n");
    file1=fopen("out.txt","w");
    fclose(file1);
    read=fopen("in.txt","r");
    do{
        fscanf(read,"%d",&sw);
        switch(sw){

            case 1:
                if(c1!=NULL){
                    free(c1);
                    c1=NULL;
                }
                file=fopen("a.txt","r");
                file1=fopen("out.txt","a+");
                j=0;
                x=0;
                do{
                    fscanf(file,"%c",&nr[j]);
                    j++;
                }while((nr[j-1]!=10)); // (nr[j-1]!=13)&&
                nr[j-1]=NULL;
                for(j=0;nr[j]!=NULL;j++)
                    x=x*10+nr[j]-48;
                c1=(char*)calloc(x+11, sizeof(char));
                fprintf(file1,"\n%d: %d)",i,sw);
                fclose(file);
                fclose(file1);
                filegetstring(c1,"a.txt");
                i++;
            break;

            case 2:
                if(c2!=NULL){
                    free(c2);
                    c2=NULL;
                }
                file=fopen("b.txt","r");
                file1=fopen("out.txt","a+");

                j=0;
                x=0;
                do{
                    fscanf(file,"%c",&nr[j]);
                    j++;
                }while((nr[j-1]!=10)); // (nr[j-1]!=13)&&
                nr[j-1]=NULL;
                for(j=0;nr[j]!=NULL;j++)
                    x=x*10+nr[j]-48;
                c2=(char*)calloc(x+11, sizeof(char));
                fprintf(file1,"\n%d: %d)",i,sw);
                fclose(file);
                fclose(file1);
                filegetstring(c2,"b.txt");
                i++;
            break;

            case 3:
                file1=fopen("out.txt","a+");
                fprintf(file1,"\n%d: %d)%s",i,sw,c1);
                fclose(file1);
                i++;
            break;

            case 4:
                file1=fopen("out.txt","a+");
                fprintf(file1,"\n%d: %d)%s",i,sw,c2);
                fclose(file1);
                i++;
            break;

            case 5:
                file1=fopen("out.txt","a+");
                fprintf(file1,"\n%d: %d)%d",i,sw,stringlength(c1));
                fclose(file1);
                i++;
            break;

            case 6:
                file1=fopen("out.txt","a+");
                fprintf(file1,"\n%d: %d)%d",i,sw,stringlength(c2));
                fclose(file1);
                i++;
            break;

            case 7:
                file1=fopen("out.txt","a+");
                stringcopy(c1,c2);
                fprintf(file1,"\n%d: %d)%s",i,sw,c1);
                fclose(file1);
                i++;
            break;

            case 8:
                file1=fopen("out.txt","a+");
                stringcopy(c2,c1);
                fprintf(file1,"\n%d: %d)%s",i,sw,c2);
                fclose(file1);
                i++;
            break;

            case 9:
                file1=fopen("out.txt","a+");
                stringconcatenate(c1,c2);
                fprintf(file1,"\n%d: %d)%s",i,sw,c1);
                fclose(file1);
                i++;
            break;

            case 10:
                file1=fopen("out.txt","a+");
                stringconcatenate(c2,c1);
                fprintf(file1,"\n%d: %d)%s",i,sw,c2);
                fclose(file1);
                i++;
            break;

            case 11:
                file1=fopen("out.txt","a+");
                x=stringcompare(c1,c2);
                fprintf(file1,"\n%d: %d)%d ",i,sw,x);
                if(x==0)
                    fprintf(file1,"c1=c2");
                else
                    if(x>0)
                        fprintf(file1,"c1>c2");
                    else
                        fprintf(file1,"c1<c2");
                fclose(file1);
                i++;
            break;

            case 12:
                file1=fopen("out.txt","a+");
                x=stringcompare(c2,c1);
                fprintf(file1,"\n%d: %d)%d ",i,sw,x);
                if(x==0)
                    fprintf(file1,"c2=c1");
                else
                    if(x>0)
                        fprintf(file1,"c2>c1");
                    else
                        fprintf(file1,"c2<c1");
                fclose(file1);
                i++;
            break;

            case 13:
                file1=fopen("out.txt","a+");
                sw2=0;
                do{
                    fscanf(read,"%c",&c);
                    st=c;
                    if(st>=48&&st<=57)
                        sw2=1;
                    if(st>=65&&st<=90&&sw2==0)
                        sw2=1;
                    if(st>=97&&st<=122&&sw2==0)
                        sw2=1;
                }while(sw2==0);
                fprintf(file1,"\n%d: %d)%s",i,sw,stringcharsearch(c1,c));
                fclose(file1);
                i++;
            break;

            case 14:
                file1=fopen("out.txt","a+");
                sw2=0;
                do{
                    fscanf(read,"%c",&c);
                    st=c;
                    if(st>=48&&st<=57)
                        sw2=1;
                    if(st>=65&&st<=90&&sw2==0)
                        sw2=1;
                    if(st>=97&&st<=122&&sw2==0)
                        sw2=1;
                }while(sw2==0);
                fprintf(file1,"\n%d: %d)%s",i,sw,stringcharsearch(c2,c));
                fclose(file1);
                i++;
            break;

            case 15:
                file1=fopen("out.txt","a+");
                fprintf(file1,"\n%d: %d)%s",i,sw,stringstringsearch(c1,c2));
                fclose(file1);
                i++;
            break;

            case 16:
                file1=fopen("out.txt","a+");
                fprintf(file1,"\n%d: %d)%s",i,sw,stringstringsearch(c2,c1));
                fclose(file1);
                i++;
            break;

            case 17:
                file1=fopen("out.txt","a+");
                fscanf(read,"%c",&c);
                fscanf(read,"%[^\n]",d);
                fprintf(file1,"\n%d: %d)%s",i,sw,stringstringsearch(c1,d));
                fclose(file1);
                i++;
            break;

            case 18:
                file1=fopen("out.txt","a+");
                fscanf(read,"%c",&c);
                fscanf(read,"%[^\n]",d);
                fprintf(file1,"\n%d: %d)%s",i,sw,stringstringsearch(c2,d));
                fclose(file1);
                i++;
            break;

            case 19:
            break;

            default:
                fscanf(read,"%d",&sw);
            break;
        }
    }while(sw!=19);
    fclose(read);
    return 0;
}
