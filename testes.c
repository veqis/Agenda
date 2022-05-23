#include <stdio.h>
#include <stdlib.h>

#define TAM_NOME 200
#define TAM_VET 20

typedef struct {
    char nome [ TAM_NOME ], cep [ TAM_NOME ], telefone [ TAM_NOME ];
    int id;
} registro;

void addPessoa ( registro pessoa [ ], int *qtdPessoa );
void editar ( registro pessoa [ ], int qtdPessoa );
void imprime ( registro pessoa [ ], int qtdPessoa );
void remover ( registro pessoa [ ], int *qtdPessoa );
void limparTela ( void );
void aguardarParaSeguir ( void );

int main()
{
    registro pessoa [ TAM_VET ];
    int menu, qtdPessoa = 0;
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

        case 1: addPessoa ( pessoa, &qtdPessoa ); break;

        case 2: editar ( pessoa, qtdPessoa ); break;
        
        case 3: imprime ( pessoa, qtdPessoa ); break;

        case 4: remover ( pessoa, &qtdPessoa ); break;

        default: printf ( "Opcao invalida!\n" ); break;
        }
        aguardarParaSeguir ();
        //função de limpar tela.
    } 
    while (menu != 0);
    
}

void addPessoa ( registro pessoa [ TAM_VET ], int *qtdPessoa )
{
    char continua;

    do
    {
        printf ( "Digite o nome: " );
        fflush ( stdin );
        scanf  ( "%[^\n]s", &pessoa[*qtdPessoa].nome );
        
        printf ( "Digite o numero: ");
        fflush ( stdin );
        scanf ( "%s", &pessoa[*qtdPessoa].telefone );

        printf ( "Digite o cep: " );
        fflush ( stdin );
        scanf ( "%s", &pessoa[*qtdPessoa].cep );
        
        pessoa[*qtdPessoa].id = *qtdPessoa + 1;
        *qtdPessoa+=1;

        printf( "Deseja inserir mais uma pessoa? (S/N)\n" ); 
        //Filtragem de entrada       
        do
        {
            fflush ( stdin );
            continua = tolower ( getchar () );
            if (continua != 'n' && continua != 's')
            {
                printf("Entrada invalida, tente novamente: ");
            }
            
        } while (continua != 'n' && continua != 's');
        
    } while (continua != 'n');
    
}

void editar ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    int entrada;
    char continua;

    printf ( "Digite o id do contato a editar: " );
    //Filtragem de entrada   
    do
    {
        scanf ( "%i", &entrada );
        entrada--;
        if (entrada > qtdPessoa || entrada < 0)
        {
            printf ( "ID nao encontrado, tente novamente: " );
        }
        
    } while (entrada > qtdPessoa || entrada < 0);

    printf ( "\n--ID [%i]--\n", pessoa[entrada].id );
    printf ( "Nome----: %s\n", pessoa[entrada].nome );
    printf ( "Telefone: %s\n", pessoa[entrada].telefone );
    printf ( "Cep-----: %s\n\n", pessoa[entrada].cep );    
    
    printf("Deseja alterar o contato selecionado? (S/N): ");

    //Filtragem de entrada       
    do
    {
        fflush ( stdin );
        continua = tolower ( getchar () );
        if (continua != 'n' && continua != 's')
        {
            printf( "Entrada invalida, tente novamente: " );
        }else if ( continua == 'n' )
        {
            printf( "Edicao cancelada!" );
            return 0;
        }
        
    } while ( continua != 'n' && continua != 's' );

    //edição do contato
    printf ( "Digite o novo nome: " );
    fflush ( stdin );
    scanf  ( "%[^\n]s", &pessoa[entrada].nome );
    
    printf ( "Digite o novo numero: ");
    scanf ( "%s", &pessoa[entrada].telefone );

    printf ( "Digite o novo cep: " );
    scanf ( "%s", &pessoa[entrada].cep );

}

void imprime ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    for (int i = 0; i < qtdPessoa; i++)
    {
        printf ( "\n--ID [%i]--\n", pessoa[i].id );
        printf ( "Nome----: %s\n", pessoa[i].nome );
        printf ( "Telefone: %s\n", pessoa[i].telefone );
        printf ( "Cep-----: %s\n", pessoa[i].cep );
    }
}

void remover ( registro pessoa [ TAM_VET ], int *qtdPessoa )
{
    int entrada;
    entrada+=1;

    printf ( "Digite o id do contato a ser removido: " );
    do
    {
        scanf ( "%i", &entrada );
        if (entrada > *qtdPessoa || entrada < 0)
        {
            printf ( "ID nao encontrado, tente novamente: " );
        }        
    } while (entrada > *qtdPessoa || entrada < 0);

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
