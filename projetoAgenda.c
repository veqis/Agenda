#include <stdio.h>
#include <stdlib.h>

#define TAM_NOME 200
#define TAM_VET 20

typedef struct {
    char nome [ TAM_NOME ];
    int cep;
    int telefone;
    int id;
} registro;

void addPessoa ( registro pessoa [ TAM_VET ], int *qtdPessoa );
void imprime ( registro pessoa [ TAM_VET ], int *qtdPessoa );
void limparTela ( void );
void aguardarParaSeguir ( void );

int main()
{
    registro pessoa [ TAM_VET ];
    int menu, *qtdPessoa = 0;
    do
    {
        printf ( "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" );
        printf ( "| 1 - Adicionar pessoas                            |\n" );
        printf ( "| 2 - Imprimir                                     |\n" );
        printf ( "| 0 - Finalizar                                    |\n" );
        printf ( "||||||||||||||||||||||||||||||||||||||||||||||||||||\n" );
        printf ( "Digite sua opcao: " );
        scanf  ( "%i", &menu );

        switch (menu)
        {
        case 0: break;

        case 1: addPessoa ( pessoa[ TAM_VET ].nome, &qtdPessoa); break;
        
        case 2: imprime ( pessoa [ TAM_VET ].nome, &qtdPessoa); break;

        default: printf ( "Opcao invalida!\n" ); break;
        }

        aguardarParaSeguir ();
    } 
    while (menu != 0);
    
}

void addPessoa ( registro pessoa [ TAM_VET ], int *qtdPessoa )
{
    char continua;

    do
    {
        getchar();
        printf ( "Digite o nome: " );
        fflush ( stdin );
        scanf  ( "%[^\n]s", &pessoa[*qtdPessoa].nome );

        pessoa[*qtdPessoa].id = *qtdPessoa;
        (*qtdPessoa)++;
        
        printf("Deseja inserir mais uma pessoa? (S/N)\n");
        do
        {
            fflush ( stdin );
            continua = tolower ( getchar () );

            if ( ( continua != 's' ) && ( continua != 'n' ) )
            {
                printf ( "Entrada invalida digite apenas 'S' ou 'N': " );
            }
        } while (continua != 'n' && continua != 's');
        
    } while (continua != 'n');
    
    return *qtdPessoa;
}


void imprime ( registro pessoa [ TAM_VET ], int *qtdPessoa )
{
    for (int i = 0; i < *qtdPessoa; i++)
    {
        printf("[%i] ", pessoa[i].id);
        printf("%s\n", pessoa[i].nome);
    }
    
}

void limparTela ( void )
{
    #ifdef __linux__
        system ( "clear" );
    #elif _WIN32
        system ( "cls" );
    #endif
}

void aguardarParaSeguir ( void )
{
    printf ( "\n\nTecle ENTER para continuar..." );
    fflush ( stdin );
    getchar ();
    limparTela ();
}
