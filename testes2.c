#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_NOME 200
#define TAM_MAX_VET    2

typedef struct DemoStruct
{
    char nome [ TAM_MAX_NOME ];
} tipoRegistro;

int main(int argc, char const *argv[])
{
    
    return 0;
}


char registroNomes ()
{
    tipoRegistro vetFuncionarios [ TAM_MAX_VET ];

    for ( int i = 0; i <TAM_MAX_VET; i++ )
    {
        printf ( "Digite o nome: " );
        fflush ( stdin );
        scanf  ( "%[^\n]s", vetFuncionarios[i].nome );
    }

    printf ( "\n\nExibindo os dados informados...\n" );
    for ( int i = 0; i < TAM_MAX_VET; i++ )
    {
        printf ( "Nome do funcionario: %s.\n", vetFuncionarios[i].nome );
    }

    return 0;
}