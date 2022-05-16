#include <stdio.h>
#include <stdlib.h>

#define TAM_NOME 200
#define TAM_VET 20

typedef struct {
    char nome [ TAM_NOME ], cep [ TAM_NOME ], telefone [ TAM_NOME ];
    int id;
} registro;

void addPessoa ( registro pessoa [ TAM_VET ], int *qtdPessoa );
void editar ( registro pessoa [ TAM_VET ], int *qtdPessoa );
void imprime ( registro pessoa [ TAM_VET ], int *qtdPessoa );
void remover ( registro pessoa [ TAM_VET ], int *qtdPessoa );
void limparTela ( void );
void aguardarParaSeguir ( void );

int main()
{
    registro pessoa [ TAM_VET ];
    int menu, *qtdPessoa = 0;
    do
    {
        printf ( "     AGENDA\n" );
        printf ( "1 - Adicionar pessoas\n" );
        printf ( "2 - Editar contato\n" );
        printf ( "3 - Imprimir\n" );
        printf ( "4 - Remover contato\n" );
        printf ( "0 - Finalizar\n" );
        printf ( "Digite sua opcao: " );
        scanf  ( "%i", &menu );

        switch (menu)
        {
        case 0: break;

        case 1: addPessoa ( pessoa[ TAM_VET ].nome, &qtdPessoa ); break;

        case 2: editar ( pessoa [ TAM_VET ].nome, &qtdPessoa ); break;
        
        case 3: imprime ( pessoa [ TAM_VET ].nome, &qtdPessoa ); break;

        case 4: remover ( pessoa [ TAM_VET].nome, &qtdPessoa ); break;

        default: printf ( "Opcao invalida!\n" ); break;
        }

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
        
        printf ( "Digite o numero: ");
        scanf ( "%s", &pessoa[*qtdPessoa].telefone );

        printf ( "Digite o cep: " );
        scanf ( "%s", &pessoa[*qtdPessoa].cep );
        
        (*qtdPessoa)++;

        printf( "Deseja inserir mais uma pessoa? (S/N)\n" );        
        do
        {
            fflush ( stdin );
            continua = tolower ( getchar () );
        } while (continua != 'n' && continua != 's');
        
    } while (continua != 'n');
    
}

void editar ( registro pessoa [ TAM_VET ], int *qtdPessoa )
{
    int entrada;

    printf ( "Digite o id do contato a editar: " );
    do
    {
        scanf ( "%i", &entrada );
        if (entrada > *qtdPessoa - 1 || entrada < 0)
        {
            printf ( "ID nao encontrado, tente novamente: " );
        }
        
    } while (entrada > *qtdPessoa - 1 || entrada < 0);

    printf ( "\n--ID [%i]--\n", pessoa[entrada].id );
    printf ( "Nome----: %s\n", pessoa[entrada].nome );
    printf ( "Telefone: %s\n", pessoa[entrada].telefone );
    printf ( "Cep-----: %s\n\n", pessoa[entrada].cep );    
    
    getchar();
    printf ( "Digite o nome: " );
    fflush ( stdin );
    scanf  ( "%[^\n]s", &pessoa[entrada].nome );
    
    printf ( "Digite o numero: ");
    scanf ( "%s", &pessoa[entrada].telefone );

    printf ( "Digite o cep: " );
    scanf ( "%s", &pessoa[entrada].cep );

}

void imprime ( registro pessoa [ TAM_VET ], int *qtdPessoa )
{
    for (int i = 0; i < *qtdPessoa; i++)
    {
        printf ( "\n--ID [%i]--\n", i );
        printf ( "Nome----: %s\n", pessoa[i].nome );
        printf ( "Telefone: %s\n", pessoa[i].telefone );
        printf ( "Cep-----: %s\n", pessoa[i].cep );
    }
}

void remover ( registro pessoa [ TAM_VET ], int *qtdPessoa )
{
    int entrada;

    printf ( "Digite o id do contato a ser removido: " );
    do
    {
        scanf ( "%i", &entrada );
        if (entrada > *qtdPessoa - 1 || entrada < 0)
        {
            printf ( "ID nao encontrado, tente novamente: " );
        }        
    } while (entrada > *qtdPessoa - 1 || entrada < 0);

    for ( int i = entrada; i <= *qtdPessoa; i++ )
    {
        pessoa[ i ] = pessoa[ i + 1 ];
    }
    (*qtdPessoa)--;

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
