#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 200
#define TAM_VET 10

enum tipoEndereco { Alameda, Avenida, Praca, Rua, Travessa };
enum tipoContato { Celular, Fixo, Comercial, Pessoal, Fax };
enum tipoSocial { Instagram, Facebook, LinkedIn, outro };


typedef struct {
    char nome [ TAM_NOME ];
    char telefone [ TAM_NOME ];
    char redeSocial [ TAM_NOME ];
    char endereco [ TAM_NOME ];
    char email [ TAM_NOME ];
    char tipoContato [ TAM_NOME ];
    int numeroCasa, id;
    enum tipoEndereco tpEnd;
    enum tipoContato tpCon;
    enum tipoSocial tpSoci;
} registro;

char *obterNomeTelefone ( enum tipoEndereco tpCon );
char *obterNomeEndereco ( enum tipoEndereco tpEnd );
char *obterNomeSocial ( enum tipoEndereco tpSoci );
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

        //case 2: editar ( pessoa, qtdPessoa ); break;
        
        //case 3: consultar ( pessoa, qtdPessoa ); break;

        //case 4: remover ( pessoa, &qtdPessoa ); break;

        case 5: imprimeTodos ( pessoa, qtdPessoa ); break;

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

        //FUNÇÂO QUE ESPECIFICA O TIPO DE ENDEREÇO
        printf ( "\nSelecione o tipo de endereco\n" );
        printf ( "1 - Alameda\n" );
        printf ( "2 - Avenida\n" );
        printf ( "3 - Praca\n" );
        printf ( "4 - Rua\n" );
        printf ( "5 - Travessa\n" );
        printf ( "6 - Rodovia\n" );
        fflush ( stdin );
        scanf ( "%i", &pessoa[*qtdPessoa].tpEnd );

        //FUNÇÂO PARA INSERIR O ENDERECO
        printf ( "\nDigite o endereco: ");
        fflush ( stdin );
        scanf ( "%[^\n]s", &pessoa[*qtdPessoa].endereco );
        
        printf ( "Digite o numero da casa: " );
        scanf ( "%i", &pessoa[*qtdPessoa].numeroCasa );
        
        //FUNÇÂO QUE ESPECIFICA O TIPO DE TELEFONE
        printf ( "\nSelecione o tipo de telefone\n" );
        printf ( "1 - Celular\n" );
        printf ( "2 - Fixo\n" );
        printf ( "3 - Comercial\n" );
        printf ( "4 - Pessoal\n" );
        printf ( "5 - Fax\n" );
        fflush ( stdin );
        scanf ( "%i", &pessoa[*qtdPessoa].tpCon );

        //FUNÇÂO PARA INSERIR O NUMERO
        printf ( "\nDigite o numero de telefone: ");
        fflush ( stdin );
        fgets ( pessoa[*qtdPessoa].telefone, 12, stdin );  

        //FUNÇÂO PARA INSERIR EMAIL
        printf ( "Digite o e-mail ");
        fflush ( stdin );
        scanf ( "%s", &pessoa[*qtdPessoa].email );

        //FUNÇÂO QUE ESPECIFICA O TIPO DE REDE SOCIAL
        printf ( "\nSelecione o tipo de rede social\n" );
        printf ( "1 - Instagram\n" );
        printf ( "2 - Facebook\n" );
        printf ( "3 - LinkedIn\n" );
        printf ( "4 - outro\n" );
        fflush ( stdin );
        scanf ( "%i", &pessoa[*qtdPessoa].tpSoci );

        printf ( "\nDigite a rede social: ");
        fflush ( stdin );
        scanf ( "%s", &pessoa[*qtdPessoa].redeSocial );

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

void imprimeTodos ( registro pessoa [ TAM_VET ], int qtdPessoa )
{

    for (int i = 0; i < qtdPessoa; i++)
    {
        imprime ( pessoa, i, qtdPessoa );
    }
}

void imprime ( registro pessoa [ TAM_VET ], int i, int qtdPessoa )
{
    char subNome [ 16 ];
    char subEndereco  [ 21 ];
    char subBairro [ 11 ];
    char subContato [ 20 ];
    char subSocial [ 20 ];

    strncpy ( subNome , pessoa[i].nome, 15 );
    strncpy ( subEndereco  , pessoa[i].endereco, 20 );

    sprintf ( subEndereco, "%s %s, %i", obterNomeEndereco ( pessoa[qtdPessoa].tpEnd ), pessoa[i].endereco, pessoa[i].numeroCasa);
    sprintf ( subContato, "%s %s", obterNomeTelefone ( pessoa[qtdPessoa].tpCon ), pessoa[i].telefone );
    sprintf ( subSocial, "%s %s", obterNomeSocial ( pessoa[qtdPessoa].tpSoci ), pessoa[i].redeSocial );

    printf ( "| %i | %-15s | %-20s | %-10i | %-15s | %s |\n", pessoa[i].id, subNome, subEndereco, subContato, pessoa[i].email, subSocial );
    //          Id   Nome    Ende.   Tele.   Email   R.S.
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

char *obterNomeEndereco ( enum tipoEndereco tpEnd )
{
    const char *nomeEndereco[] =
    {
        "Al.", "Av.", "Pr.", "Rod.", "R.", "Tr."
    };

    return ( nomeEndereco [ tpEnd ] );
}

char *obterNomeTelefone ( enum tipoEndereco tpCon )
{
    const char *nomeTelefone[] =
    {
        "Cel.", "Fix.", "Com.", "Pes.", "Fax."
    };

    return ( nomeTelefone [ tpCon ] );
}

char *obterNomeSocial ( enum tipoEndereco tpSoci )
{
    const char *nomeSocial[] =
    {
        "Ins.", "Face.", "Lin.", ""
    };

    return ( nomeSocial [ tpSoci ] );
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