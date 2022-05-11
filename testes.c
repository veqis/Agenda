#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_VET 2
#define TAM_NOME 200

typedef struct RegistroDePessoas
{
    char nome [ TAM_NOME ];
} registro;

char registroNome(registro pessoa [ TAM_VET ]);

int main()
{
    registro pessoa [ TAM_VET ];

    registroNome ( pessoa[ TAM_VET ].nome );
    return 0;
}


char registroNome(registro pessoa [ TAM_VET ])
{
    

    for (int i = 0; i < TAM_VET; i++)
    {
        printf ( "Digite o nome: " );
        fflush ( stdin );
        scanf  ( "%[^\n]s", &pessoa[i].nome );   
    }

    for (int i = 0; i < TAM_VET; i++)
    {
        printf("%s\n", pessoa[i].nome);
    }
    

    return 0;
}
