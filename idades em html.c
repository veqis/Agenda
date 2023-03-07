#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char nomeVelho[100];
int velho=0;
int mvelho, dvelho;

char nomeJovem[100];
int jovem = 1000;
int mjovem, djovem;

int main()
{
    FILE *in;
    FILE *out;
    char nome[20];
    char barr;
    int dia,mes,ano;
    
    in = fopen("entrada.txt","r");
    out = fopen("saida.html","w");
    
    while (!feof(in))
    {
        fscanf(in,"%s %d %c %d %c %d",nome,&dia,&barr,&mes,&barr,&ano);

        printf("%s %d / %d / %d\n",nome,dia,mes,ano);

        fprintf(out,"%s tem %d anos<br>\n",nome,idade(ano,mes,dia,nome));

    }
    fprintf(out,"%s é a pessoa mais velha(o) <br>\n",nomeVelho);
    fprintf(out,"%s é a pessoa mais jovem <br>\n",nomeJovem);

    fclose(in);
    fclose(out);
    return 0;
}

int idade(int ano, int mes, int dia,char *nome)
{
    int idade;
    idade = 2023 - ano;

    if (idade > velho)
    {
        velho = idade;
        mvelho = mes;
        dvelho = dia;
        strcpy(nomeVelho,nome);
    }else if (idade == velho)
    {
        if (mes<mvelho)
        {
            velho = idade;
            mvelho = mes;
            dvelho = dia;
            strcpy(nomeVelho,nome);
        }
    }else if (idade == velho && mvelho == mes)
    {
        if (dia<dvelho)
        {
            velho = idade;
            mvelho = mes;
            dvelho = dia;  
            strcpy(nomeVelho,nome);
        }
        
    }
    
    if (idade < jovem)
    {
        jovem = idade;
        mjovem = mes;
        djovem = dia;
        strcpy(nomeVelho,nome);
    }else if (idade == jovem)
    {
        if (mes<mjovem)
        {
            jovem = idade;
            mjovem = mes;
            djovem = dia;
            strcpy(nomeJovem,nome);
        }
    }else if (idade == jovem && mjovem == mes)
    {
        if (dia<djovem)
        {
            jovem = idade;
            mjovem = mes;
            djovem = dia;  
            strcpy(nomeJovem,nome);
        }
    }   
    
    return idade;
}
