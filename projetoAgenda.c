#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 200
#define TAM_VET 20

typedef struct {
    char nome [ TAM_NOME ], telefone [ TAM_NOME ], redeSocial [ TAM_NOME ], endereco [ TAM_NOME ], email [ TAM_NOME ], tipoContato [ TAM_NOME ];
    int id, numeroCasa, tipoTelefone, tipoSocial;
    enum { Celular, Fixo, Comercial, Pessoal, Fax } tipoEndereco;
} registro;

void addPessoa ( registro pessoa [ ], int *qtdPessoa );
void editar ( registro pessoa [ ], int qtdPessoa );
void imprime ( registro pessoa [ ], int qtdPessoa );
void remover ( registro pessoa [ ], int *qtdPessoa );
void consultar ( registro pessoa [ ], int qtdPessoa);
void verificaTelefone ( registro pessoa [ ], int qtdPessoa );
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
        printf ( "3 - Consutar contato\n");
        printf ( "4 - Remover contato\n" );
        printf ( "5 - Imprimir\n" );
        printf ( "0 - Finalizar\n" );
        printf ( "Digite sua opcao: " );
        scanf  ( "%i", &menu );

        switch (menu)
        {
        case 0: break;

        case 1: addPessoa ( pessoa, &qtdPessoa ); break;

        case 2: editar ( pessoa, qtdPessoa ); break;
        
        case 3: consultar ( pessoa, qtdPessoa ); break;

        case 4: remover ( pessoa, &qtdPessoa ); break;

        case 5: imprime ( pessoa, qtdPessoa ); break;

        default: printf ( "Opcao invalida!\n" ); break;
        }
        //funcão de limpar tela.
        aguardarParaSeguir ();
    } 
    while (menu != 0);
    
}

void addPessoa ( registro pessoa [ TAM_VET ], int *qtdPessoa )
{
    char continua;

    do
    {
        //NOME DO CONTATO
        printf ( "\nDigite o nome: " );
        fflush ( stdin );
        scanf  ( "%[^\n]s", &pessoa[*qtdPessoa].nome );
        
        //FUNÇÂO QUE ESPECIFICA O TIPO DE TELEFONE
        printf ( "\n\nSelecione o tipo de telefone\n" );
        printf ( "1 - Celular\n" );
        printf ( "2 - Fixo\n" );
        printf ( "3 - Comercial\n" );
        printf ( "4 - Pessoal\n" );
        printf ( "5 - Fax\n" );

        fflush ( stdin );
        scanf ( "%i", &pessoa[*qtdPessoa].tipoTelefone );

        switch ( pessoa[*qtdPessoa].tipoTelefone )
        {
        case 1: pessoa[*qtdPessoa].tipoEndereco = Celular; break;

        case 2: pessoa[*qtdPessoa].tipoEndereco = Fixo; break;

        case 3: pessoa[*qtdPessoa].tipoEndereco = Comercial; break;

        case 4: pessoa[*qtdPessoa].tipoEndereco = Pessoal; break;

        case 5: pessoa[*qtdPessoa].tipoEndereco = Fax; break;
        
        default: printf ( "Opcao invalida!\n" ); break;
        }


        printf ( "\nDigite o numero de telefone: ");
        fflush ( stdin );
        fgets ( pessoa[*qtdPessoa].telefone, 12, stdin );      

        //TIPO ENDEREÇO
        printf ( "\nDigite o endereco: ");
        fflush ( stdin );
        scanf ( "%[^\n]s", &pessoa[*qtdPessoa].endereco );
        
        /*printf ( "Digite o numero da casa: " );
        scanf ( "%i", &pessoa[*qtdPessoa].numeroCasa );*/

        /*printf ( "Selecione o tipo de contato\n" );
        printf ( "1 - Celular" );
        printf ( "2 - Fixo");*/

        /*printf ( "Digite o e-mail ");
        fflush ( stdin );
        scanf ( "%s", &pessoa[*qtdPessoa].email );*/

        //Configuracão do id da pessoa
        pessoa[*qtdPessoa].id = *qtdPessoa + 1;
        *qtdPessoa+=1;

        //Filtragem de entrada 
        printf( "\nDeseja inserir mais uma pessoa? (S/N)\n" );       
        do
        {
            fflush ( stdin );
            continua = tolower ( getchar () );
            if (continua != 'n' && continua != 's')
            {
                printf("\nEntrada invalida, tente novamente: ");
            }
            
        } while (continua != 'n' && continua != 's');
        
    } while (continua != 'n');
    
}

void editar ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    int entrada;
    char continua;

    //Filtragem de entrada
    printf ( "Digite o id do contato a editar: " );   
    do
    {
        scanf ( "%i", &entrada );
        entrada--;
        if (entrada > qtdPessoa || entrada < 0)
        {
            printf ( "ID nao encontrado, tente novamente: " );
        }
        
    } while (entrada > qtdPessoa || entrada < 0);

    //Impressão do contato
    printf ( "\n--ID [%i]--\n", pessoa[entrada].id );
    printf ( "Nome----: %s\n", pessoa[entrada].nome );
    editarTelefone ( pessoa, entrada );  

    
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

    //edicão do contato
    printf ( "Digite o novo nome: " );
    fflush ( stdin );
    scanf  ( "%[^\n]s", &pessoa[entrada].nome );
    
    printf ( "Digite o novo numero: ");
    scanf ( "%s", &pessoa[entrada].telefone );

    printf ( "Digite o novo numero de telefone: ");
    fflush ( stdin );
    scanf ( "%s", &pessoa[entrada].telefone );

}

void imprime ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    for (int i = 0; i < qtdPessoa; i++)
    {
        printf ( "\n--ID [%i]--\n", pessoa[i].id );
        printf ( "Nome----: %s\n", pessoa[i].nome );
        printf ( "Endereco: %s\n", pessoa[i].endereco );
        verificaTelefone ( pessoa, i);
        editarTelefone ( pessoa, i );

    }
}

void remover ( registro pessoa [ TAM_VET ], int *qtdPessoa )
{
    int entrada;
    char continua;

    //Filtragem de entrada e exibicão de contato
    printf ( "Digite o id do contato a ser removido: " );
    do
    {
        scanf ( "%i", &entrada );
        entrada--;
        if (entrada > *qtdPessoa || entrada < 0)
        {
            printf ( "ID nao encontrado, tente novamente: " );
        }        
    } while (entrada > *qtdPessoa || entrada < 0);

    printf ( "\n--ID [%i]--\n", pessoa[entrada].id );
    printf ( "Nome----: %s\n", pessoa[entrada].nome );
    editarTelefone ( pessoa, entrada );

 
    //Filtragem de entrada 
    printf("Deseja deletar o contato selecionado? (S/N): ");      
    do
    {
        fflush ( stdin );
        continua = tolower ( getchar () );
        if (continua != 'n' && continua != 's')
        {
            printf( "Entrada invalida, tente novamente: " );
        }else if ( continua == 'n' )
        {
            printf( "Remocao cancelada!" );
            return 0;
        }
        
    } while ( continua != 'n' && continua != 's' );

    //Realocacão de posicões e remocão de contato
    for ( int i = entrada; i <= *qtdPessoa; i++ )
    {
        pessoa[ i ] = pessoa[ i + 1 ];
    }
    (*qtdPessoa)--;

}

void consultar ( registro pessoa [ TAM_VET ], int qtdPessoa)
{
    int entrada;
    char continua;

    printf( "Digite o ID do contato que deseja consultar: " );
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
    editarTelefone ( pessoa, entrada );


    //Filtragem de entrada 
    printf( "Deseja consultar outro contato? (S/N)\n" );       
    do
    {
        fflush ( stdin );
        continua = tolower ( getchar () );
        if (continua != 'n' && continua != 's')
        {
            printf("Entrada invalida, tente novamente: ");
        }
        
    } while (continua != 'n' && continua != 's');
        
}

void editarTelefone ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    //Funcão que pega o numero de telefone e separa o ddd e cloca a barra entre os numeros
    char DDD[3], parte1[6], parte2[6];

    strncpy ( DDD, &pessoa [ qtdPessoa ].telefone [ 0 ], 2 );
    strncpy ( parte1, &pessoa [ qtdPessoa ].telefone [ 2 ], 5 );
    strncpy ( parte2, &pessoa [ qtdPessoa ].telefone [ 7 ], 5 );
    DDD [ 2 ] = parte1 [ 5 ] = parte2 [ 5 ] = '\0';

    printf ( "(%s) %s-%s\n", DDD, parte1, parte2);
}

void verificaTelefone ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    if (pessoa[qtdPessoa].tipoEndereco == Celular)
    {
        printf("Telefone: Celular ");
    }
    if (pessoa[qtdPessoa].tipoEndereco == Fixo)
    {
        printf("Telefone: Fixo ");
    }
    if (pessoa[qtdPessoa].tipoEndereco == Comercial)
    {
        printf("Telefone: Comercial ");
    }
    if (pessoa[qtdPessoa].tipoEndereco == Pessoal)
    {
        printf("Telefone: Pessoal ");
    }
    if (pessoa[qtdPessoa].tipoEndereco == Fax)
    {
        printf("Telefone: Fax ");
    }
    
    
}
//Funcões para limpar tela
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
