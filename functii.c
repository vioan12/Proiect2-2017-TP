///\file functii.c
///\brief Librarie implementata pentru functiile programului

#include"head.h"
int stringlength(char *str1)
{
	///\fn int stringlength(char *str1)
    ///\brief vede cat de lung este un sir de caractere
	
    int nr=0;
    if(str1!=NULL){
        while(str1[nr]!=NULL){
            nr++;
        }
    }
    return nr;
}

void stringconcatenate(char *str1,char *str2)
{
	///\fn void stringconcatenate(char *str1,char *str2)
    ///\brief concateneaza doua siruri de caractere
	
    int i,j,n_str1,MEM1;
    if((str1!=NULL)&&(str2!=NULL)){
        n_str1=stringlength(str1);
        MEM1=mem_aloc(str1);
        if(MEM1>stringlength(str1)+stringlength(str2)){
            for(i=n_str1+stringlength(str2)+1,j=stringlength(str1)+1;str1[j]!=NULL;i++,j++)
                str1[i]=str1[j];
            str1[i]=NULL;
            for(i=n_str1;i<=n_str1+stringlength(str2);i++)
                str1[i]=str2[i-n_str1];
        }else
            printf("\n-------\nEROARE!\nstringconcatenate:memoria alocata(%dbyti) pt str1(%s) este prea putina, mai sunt necesari %dbyti\n-------\n",sizeof(char)*MEM1,str1,(1+sizeof(char)*((stringlength(str1)+stringlength(str2))-MEM1)));
    }
}

void stringcopy(char *str1,char *str2)
{
	///\fn void stringcopy(char *str1,char *str2)
    ///\brief copiaza un sir de caractere in alt sir de caractere
	
    int i,MEM1,j;
    if((str1!=NULL)&&(str2!=NULL)){
        MEM1=mem_aloc(str1);
        if(MEM1>stringlength(str2)){
            for(i=stringlength(str2)+1,j=stringlength(str1)+1;str1[j]!=NULL;i++,j++)
                str1[i]=str1[j];
            str1[i]=NULL;
            for(i=0;i<=stringlength(str2);i++)
                str1[i]=str2[i];
        }else
            printf("\n-------\nEROARE!\nstringcopy:memoria alocata(%dbyti) pt str1(%s) este prea putina, mai sunt necesari %dbyti\n-------\n",sizeof(char)*MEM1,str1,(1+sizeof(char)*((stringlength(str2)-MEM1))));
    }
}

void filegetstring(char *str1,char file_nm[])
{
	///\fn void filegetstring(char *str1,char file_nm[])
    ///\brief citeste un sir de carcatere din fisier

    int i,j,x=0,k,sw=0;
    char nr[11],c;
    file=fopen(file_nm,"r");
    i=0;
    do{
        fscanf(file,"%c",&nr[i]);
        i++;
    }while((nr[i-1]!=10)); // (nr[i-1]!=13)&&
    nr[i-1]=NULL;
    for(j=0;nr[j]!=NULL;j++)
        x=x*10+nr[j]-48;
    i=0;
    do{
        fscanf(file,"%c",&str1[i]);
        i++;
    }while((str1[i-1]!=10)&&(i<x)); //(str1[i-1]!=13)&&
    if((str1[i-1]!=10)) // (str1[i-1]!=13)&&
        sw=1;
    str1[i-1]=NULL;
    k=i-1;
    for(j=0;nr[j]!=NULL;j++,i++)
        str1[i]=nr[j];
    str1[i]=NULL;
    if(sw==1)
        printf("\n-------\nEROARE!\nfilegetstring:memoria alocata(%dbyti) pt str1(%s) este prea putina au fost citite si memorate %d caractere\n-------\n",sizeof(char)*x,str1,k);
    fclose(file);
}

int mem_aloc(char *str)
{
	///\fn void mem_aloc(char *str)
    ///\brief vede cata memorie este alocata pentru un sir de caractere

    int i,x=0;
    if(str!=NULL){
        for(i=stringlength(str)+1;str[i]!=NULL;i++)
            x=x*10+str[i]-48;
        return x;
    }
    return 0;
}

int stringcompare(char *str1,char *str2)
{
	///\fn stringcompare(char *str1,char *str2)
    ///\brief compara doua siruri de caractere

    int i,j,x=0;
    if((str1!=NULL)&&(str2!=NULL)){
        i=-1;j=-1;
        do{
            i++;
            j++;
            x=str1[i]-str2[j];
        }while((str1[i]!=NULL)&&(str2[i]!=NULL)&&(x==0));
    }
    return x;
}

char* stringcharsearch(char *str1,char c)
{
	///\fn char* stringcharsearch(char *str1,char c)
	///\brief cauta un caracter intr-un sir de caractere
	
    int i;
    if((str1!=NULL)&&(c!=NULL)){
        i=0;
        while((str1[i]!=c)&&(str1[i]!=NULL))
            i++;
        if(str1[i]!=NULL)
            return str1+i;
    }
    return NULL;
}

char* stringstringsearch(char *str1,char *str2)
{
	///\fn char* stringstringsearch(char *str1,char *str2)
	///\brief cauta un sir de caractere intr-un alt sir de caractere
	
    int i,j,sw=0;
    if((str1!=NULL)&&(str2!=NULL)){
        for(i=0;str1[i]!=NULL;i++)
            if(str2[0]==str1[i]){
                if(stringlength(str2)<=stringlength(str1+i)){
                    sw=1;
                    for(j=0;(str2[j]!=NULL)&&(str1[i+j]!=NULL)&&(sw==1);j++)
                        if(str2[j]!=str1[i+j])
                            sw=0;
                }
				if(sw==1)
					return str1+i;
			}
    }
    return NULL;
}
