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

char *obterNomeTelefone ( int tpCon );
char *obterNomeEndereco ( int tpEnd );
char *obterNomeSocial ( int tpSoci );
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
        printf ( "0 - Alameda\n" );
        printf ( "1 - Avenida\n" );
        printf ( "2 - Praca\n" );
        printf ( "3 - Rua\n" );
        printf ( "4 - Travessa\n" );
        printf ( "5 - Rodovia\n" );
        scanf ( "%i", &pessoa[*qtdPessoa].tpEnd );

        //FUNÇÂO PARA INSERIR O ENDERECO
        printf ( "\nDigite o endereco: ");
        fflush ( stdin );
        scanf ( "%[^\n]s", &pessoa[*qtdPessoa].endereco );
        
        printf ( "Digite o numero da casa: " );
        scanf ( "%i", &pessoa[*qtdPessoa].numeroCasa );
        
        //FUNÇÂO QUE ESPECIFICA O TIPO DE TELEFONE
        printf ( "\nSelecione o tipo de telefone\n" );
        printf ( "0 - Celular\n" );
        printf ( "1 - Fixo\n" );
        printf ( "2 - Comercial\n" );
        printf ( "3 - Pessoal\n" );
        printf ( "4 - Fax\n" );
        scanf ( "%i", &pessoa[*qtdPessoa].tpCon );

        //FUNÇÂO PARA INSERIR O NUMERO
        printf ( "\nDigite o numero de telefone: ");
        fflush ( stdin );
        scanf ( "%s", &pessoa[*qtdPessoa].telefone );

        //FUNÇÂO QUE ESPECIFICA O TIPO DE REDE SOCIAL
        printf ( "\nSelecione o tipo de rede social\n" );
        printf ( "0 - Instagram\n" );
        printf ( "1 - Facebook\n" );
        printf ( "2 - LinkedIn\n" );
        printf ( "3 - outro\n" );
        scanf ( "%i", &pessoa[*qtdPessoa].tpSoci );

        printf ( "\nDigite a rede social: ");
        fflush ( stdin );
        scanf ( "%s", &pessoa[*qtdPessoa].redeSocial );

        //FUNÇÂO PARA INSERIR EMAIL
        printf ( "Digite o e-mail ");
        fflush ( stdin );
        scanf ( "%s", &pessoa[*qtdPessoa].email );

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
    char subContato [ 21 ];
    char subSocial [ 21 ];

    strncpy ( subNome , pessoa[i].nome, 15 );
    strncpy ( subEndereco  , pessoa[i].endereco, 20 );

    sprintf ( subEndereco, "%s, %i", pessoa[i].endereco, pessoa[i].numeroCasa);
    sprintf ( subContato, "%s", pessoa[i].telefone );
    sprintf ( subSocial, "%s", pessoa[i].redeSocial );

    printf ( "| %i | %-15s | %s %-20s | %s %-15s | %s %-15s | %s |\n", pessoa[i].id, subNome, obterNomeEndereco ( pessoa[qtdPessoa].tpEnd ), subEndereco, obterNomeTelefone ( pessoa[qtdPessoa].tpCon ), subContato, obterNomeSocial ( pessoa[qtdPessoa].tpSoci ), subSocial, pessoa[i].email );
    //          Id   Nome    Ende.       Tele.      R.S.     Email
    printf ("AAAAAAAAAAAAAAAAAAAAA VE ISSSSSSSOOOOOOOOOOOOO%s", pessoa[i].tpCon);
}


void editar ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    int entrada, menu;
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
    imprime ( pessoa, entrada, qtdPessoa );
    

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
    printf ( "Selecione o campo a editar: \n" );
    printf ( "1 - Nome\n" );
    printf ( "2 - Tipo endereco\n" );
    printf ( "3 - Endereco\n");
    printf ( "4 - Numero\n" );
    printf ( "5 - Tipo telefone\n" );
    printf ( "6 - Telefone\n" );
    printf ( "7 - Tipo social\n" );
    printf ( "8 - Rede social\n" );
    printf ( "9 - E-mail\n" );
    printf ( "Digite sua opcao: " );
    scanf  ( "%i", &menu );

    switch (menu)
    {
    case 1:
        printf ( "Digite o novo nome: " );
        fflush ( stdin );
        scanf  ( "%[^\n]s", &pessoa[entrada].nome );
        break;
    case 2:
        printf ( "\nSelecione o novo tipo de endereco\n" );
        printf ( "0 - Alameda\n" );
        printf ( "1 - Avenida\n" );
        printf ( "2 - Praca\n" );
        printf ( "3 - Rua\n" );
        printf ( "4 - Travessa\n" );
        printf ( "5 - Rodovia\n" );
        scanf ( "%i", &pessoa[entrada].tpEnd );
        break;
    case 3:
        printf ( "\nDigite o novo endereco: ");
        fflush ( stdin );
        scanf ( "%[^\n]s", &pessoa[entrada].endereco );
        break;
    case 4:
        printf ( "Digite o novo numero da casa: " );
        scanf ( "%i", &pessoa[entrada].numeroCasa );   
        break;
    case 5:
        printf ( "\nSelecione o novo tipo de telefone\n" );
        printf ( "0 - Celular\n" );
        printf ( "1 - Fixo\n" );
        printf ( "2 - Comercial\n" );
        printf ( "3 - Pessoal\n" );
        printf ( "4 - Fax\n" );
        scanf ( "%i", &pessoa[entrada].tpCon );  
        break;
    case 6:
        printf ( "\nDigite o novo numero de telefone: ");
        fflush ( stdin );
        scanf ( "%s", &pessoa[entrada].telefone );
        break;
    case 7:
        printf ( "\nSelecione o tipo de rede social\n" );
        printf ( "0 - Instagram\n" );
        printf ( "1 - Facebook\n" );
        printf ( "2 - LinkedIn\n" );
        printf ( "3 - outro\n" );
        scanf ( "%i", &pessoa[entrada].tpSoci );
        break;
    case 8:
        printf ( "\nDigite a rede social: ");
        fflush ( stdin );
        scanf ( "%s", &pessoa[entrada].redeSocial );
        break;
    case 9:
        printf ( "Digite o e-mail ");
        fflush ( stdin );
        scanf ( "%s", &pessoa[entrada].email );
        break;
    default: printf ( "Opcao invalida!\n" ); break;
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

    imprime ( pessoa, entrada, *qtdPessoa );
 
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

void consultar ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    int entrada;
    printf ( "Digite o id do contato: " );   
    do
    {
        scanf ( "%i", &entrada );
        entrada--;
        if (entrada > qtdPessoa || entrada < 0)
        {
            printf ( "ID nao encontrado, tente novamente: " );
        }
        
    } while (entrada > qtdPessoa || entrada < 0);

        imprime ( pessoa, entrada, qtdPessoa );
}

char *obterNomeEndereco ( int tpEnd )
{
    const char *nomeEndereco[] =
    {
        "Al.", "Av.", "Pr.", "Rod.", "R.", "Tr."
    };

    return ( nomeEndereco [ tpEnd ] );
}

char *obterNomeTelefone ( int tpCon )
{
    const char *nomeTelefone[] =
    {
        "Cel.", "Fix.", "Com.", "Pes.", "Fax."
    };
    
    return ( nomeTelefone [ tpCon ] );
}

char *obterNomeSocial ( int tpSoci )
{
    const char *nomeSocial[] =
    {
        "Ins.", "Face.", "Lin.", ""
    };

    return ( nomeSocial [ tpSoci ] );
}

/*void salvar (  )
{
    FILE *file;
    file = fopen ( "teste.txt", "w" );
    fprintf ( file,"teste" );
    fclose ( file );
}*/

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
