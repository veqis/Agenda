#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 200
#define TAM_VET 20

typedef struct {
    char nome [ TAM_NOME ], telefone [ TAM_NOME ], redeSocial [ TAM_NOME ], endereco [ TAM_NOME ], email [ TAM_NOME ];
    int id, numeroCasa, tipoTelefone, tipoSocial;
} registro;

void addPessoa ( registro pessoa [ ], int *qtdPessoa );
void editar ( registro pessoa [ ], int qtdPessoa );
void imprime ( registro pessoa [ ], int qtdPessoa );
void remover ( registro pessoa [ ], int *qtdPessoa );
void consultar ( registro pessoa [ ], int qtdPessoa);
void editarCep ( registro pessoa [ ], int qtdPessoa);
void addRedeSocial ( registro pessoa [ ], int *qtdpessoa );
void addTelefone ( registro pessoa [ ], int *qtdPessoa);
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
        //função de limpar tela.
        aguardarParaSeguir ();
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
        
        addTelefone ( pessoa , &qtdPessoa );

        //TELEFONE
        printf ( "Selecione o tipo de telefone\n" );
        printf ( "1 - Celular\n" );
        printf ( "2 - Fixo\n" );
        fflush ( stdin );
        scanf ( "%s", &pessoa[*qtdPessoa].tipoTelefone );

        if (pessoa[*qtdPessoa].tipoTelefone == '1')
        {
            pessoa[*qtdPessoa].tipoTelefone = "Celular";
        }else if (pessoa[*qtdPessoa].tipoTelefone == '2')
        {
            pessoa[*qtdPessoa].tipoTelefone = "Fixo";
        }else{
            do
            {
                printf ( "Entrada invalida! Tente novamente\n\n" );

                printf ( "Selecione o tipo de telefone\n" );
                printf ( "1 - Celular" );
                printf ( "2 - Fixo" );
                fflush ( stdin );
                scanf ( "%s", &pessoa[*qtdPessoa].tipoTelefone );
            } while (pessoa[*qtdPessoa].tipoTelefone == '1' || pessoa[*qtdPessoa].tipoTelefone == '2');
            
        }

        printf ( "Digite o numero de telefone: ");
        fflush ( stdin );
        scanf ( "%s", &pessoa[*qtdPessoa].telefone );
        //TELEFONE
        
        printf ( "Digite o numero da casa: " );
        scanf ( "%i", &pessoa[*qtdPessoa].numeroCasa );

        /*printf ( "Digite o e-mail ");
        fflush ( stdin );
        scanf ( "%s", &pessoa[*qtdPessoa].email );*/

        addRedeSocial ( pessoa, &qtdPessoa );

        //Configuração do id da pessoa
        pessoa[*qtdPessoa].id = *qtdPessoa + 1;
        *qtdPessoa+=1;

        //Filtragem de entrada 
        printf( "Deseja inserir mais uma pessoa? (S/N)\n" );       
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
    editarCep ( pessoa, entrada );   

    
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
        editarTelefone ( pessoa, i );
        editarCep ( pessoa, i);

    }
}

void remover ( registro pessoa [ TAM_VET ], int *qtdPessoa )
{
    int entrada;
    char continua;

    //Filtragem de entrada e exibição de contato
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
    editarCep ( pessoa, entrada);

 
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

    //Realocação de posições e remoção de contato
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
    editarCep ( pessoa, entrada);


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

/*void editarCep ( registro pessoa [ TAM_VET ], int qtdPessoa)
{
    //Função usada para pontuar o numero de cep com a barra no local correto
    char parte1[6], parte2[5];

    strncpy ( parte1, &pessoa[ qtdPessoa ].cep[ 0 ], 5 );
    strncpy ( parte2, &pessoa[ qtdPessoa ].cep[ 5 ], 4 );
    parte1 [ 5 ] = parte2 [ 4 ] = '\0';

    printf ( "Cep-----: %s-%s\n", parte1, parte2 );
}*/

void editarTelefone ( registro pessoa [ TAM_VET ], int qtdPessoa )
{
    //Função que pega o numero de telefone e separa o ddd e cloca a barra entre os numeros
    char DDD[3], parte1[6], parte2[6];

    strncpy ( DDD, &pessoa [ qtdPessoa ].telefone [ 0 ], 2 );
    strncpy ( parte1, &pessoa [ qtdPessoa ].telefone [ 2 ], 5 );
    strncpy ( parte2, &pessoa [ qtdPessoa ].telefone [ 7 ], 5 );
    DDD [ 2 ] = parte1 [ 5 ] = parte2 [ 5 ] = '\0';

    printf ( "Telefone - %s: (%s) %s-%s\n", pessoa[qtdPessoa].tipoTelefone, DDD, parte1, parte2);
}

void addRedeSocial ( registro pessoa [ TAM_VET ], int *qtdPessoa )
{

        printf ( "Selecione a rede social\n" );
        printf ( "1 - Instagram\n" );
        printf ( "2 - Facebook\n" );
        printf ( "3 - LinkedIn\n" );
        printf ( "4 - Twitter\n" );
        fflush ( stdin );
        scanf ( "%s", &pessoa[*qtdPessoa].tipoSocial );

        if (pessoa[*qtdPessoa].tipoSocial == '1')
        {
            pessoa[*qtdPessoa].tipoSocial = "Instagram";
        }else if (pessoa[*qtdPessoa].tipoSocial == '2')
        {
            pessoa[*qtdPessoa].tipoSocial = "Facebook";
        }else if (pessoa[*qtdPessoa].tipoSocial == '3')
        {
            pessoa[*qtdPessoa].tipoSocial = "LinkedIn";
        }else if (pessoa[*qtdPessoa].tipoSocial == '4')
        {
            pessoa[*qtdPessoa].tipoSocial = "Twitter";
        }else{
            do
            {
                printf ( "Entrada invalida! Tente novamente\n\n" );

                printf ( "Selecione o tipo de endereço\n" );
                printf ( "1 - Travessa\n" );
                printf ( "2 - Alameda\n" );
                printf ( "3 - Avenida\n" );
                printf ( "4 - Praça\n" );
                fflush ( stdin );
                scanf ( "%s", &pessoa[*qtdPessoa].tipoSocial );
            } while (pessoa[*qtdPessoa].tipoSocial == '1' || pessoa[*qtdPessoa].tipoSocial == '2' || pessoa[*qtdPessoa].tipoSocial == '3' || pessoa[*qtdPessoa].tipoSocial == '4');
            
        }

        printf ( "Digite a rede social: " );
        scanf ( "%i", &pessoa[*qtdPessoa].redeSocial );

}

void addTelefone ( registro pessoa [ TAM_VET ], int *qtdPessoa)
{
 printf ( "Selecione o tipo de endereco\n" );
        printf ( "1 - Travessa\n" );
        printf ( "2 - Alameda\n" );
        printf ( "3 - Avenida\n" );
        printf ( "4 - Praça\n" );
        printf ( "5 - Rua\n" );
        fflush ( stdin );
        scanf ( "%s", &pessoa[*qtdPessoa].tipoTelefone );

        if (pessoa[*qtdPessoa].tipoTelefone == '1')
        {
            pessoa[*qtdPessoa].tipoTelefone = "Travessa";
        }else if (pessoa[*qtdPessoa].tipoTelefone == '2')
        {
            pessoa[*qtdPessoa].tipoTelefone = "Alameda";
        }else if (pessoa[*qtdPessoa].tipoTelefone == '3')
        {
            pessoa[*qtdPessoa].tipoTelefone = "Avenida";
        }else if (pessoa[*qtdPessoa].tipoTelefone == '4')
        {
            pessoa[*qtdPessoa].tipoTelefone = "Praça";
        }else if (pessoa[*qtdPessoa].tipoTelefone == '5')
        {
            pessoa[*qtdPessoa].tipoTelefone = "Rua";
        }else{
            do
            {
                printf ( "Entrada invalida! Tente novamente\n\n" );

                printf ( "Selecione o tipo de endereço\n" );
                printf ( "1 - Travessa\n" );
                printf ( "2 - Alameda\n" );
                printf ( "3 - Avenida\n" );
                printf ( "4 - Praça\n" );
                printf ( "5 - Rua\n" );
                fflush ( stdin );
                scanf ( "%s", &pessoa[*qtdPessoa].tipoTelefone );
            } while (pessoa[*qtdPessoa].tipoTelefone == '1' || pessoa[*qtdPessoa].tipoTelefone == '2' || pessoa[*qtdPessoa].tipoTelefone == '3' || pessoa[*qtdPessoa].tipoTelefone == '4' || pessoa[*qtdPessoa].tipoTelefone == '5');
            
        }

        printf ( "Digite o endereco: ");
        fflush ( stdin );
        scanf ( "%[^\n]s", &pessoa[*qtdPessoa].endereco );
}

//Funções para limpar tela

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
