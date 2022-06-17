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
  char verEnd [ TAM_NOME ];
  char verCon [ TAM_NOME ];
  char verSoci [ TAM_NOME ];
  int numeroCasa, id;
  enum tipoEndereco tpEnd;
  enum tipoContato tpCon;
  enum tipoSocial tpSoci;
} registro;

void carregarDados ( registro pessoa [ TAM_VET ], int *aux );
void printa ( registro pessoa [ TAM_VET ], int aux );

int main()
{
  int aux = 0;
  char temp [100];
  registro pessoa [ TAM_VET ];

  carregarDados ( pessoa, &aux );

  for (int i = 0; i < aux-1; i++)
  {
    for (int j = i + 1; j < aux; j++)
    {
      if (strcmp(pessoa[i].nome, pessoa[j].nome)>0) 
      {
        strcpy(temp, pessoa[i].nome);
        strcpy(pessoa[i].nome, pessoa[j].nome);
        strcpy(pessoa[j].nome, temp);
      }
    }    
  }

  printa ( pessoa, aux );

  return 0;
}

void carregarDados ( registro pessoa [ TAM_VET ], int *aux )
{
  FILE *arquivo;
  arquivo = fopen("agenda.csv", "r");

  if ( arquivo == NULL)
  {
    printf("ERRO!!!\n");
    return 1;
  }

  int lidos = 0;

  do
  {
    lidos = fscanf ( arquivo," %i ; %49[^;]; %s %49[^;]; %i ; %s %49[^;]; %s %49[^;]; %49[^;];", 
    &pessoa[*aux].id,
    pessoa[*aux].nome,
    pessoa[*aux].verEnd,
    pessoa[*aux].endereco,
    &pessoa[*aux].numeroCasa,
    pessoa[*aux].verCon,
    pessoa[*aux].telefone,
    pessoa[*aux].verSoci,
    pessoa[*aux].redeSocial,
    pessoa[*aux].email);

    if ( lidos == 10 )
    {
      *aux+=1;
    }
    if ( lidos != 10 && !feof(arquivo))
    {
      printf ( "ERRO!!!\n" );
      return 1;
    }

  } while (!feof(arquivo));

  fclose(arquivo);

}

void printa ( registro pessoa [ TAM_VET ], int aux )
{

  for (int i = 0; i < aux; i++)
  {
  printf("%i ; %s ; %s %s ; %i ; %s %s ; %s %s ; %s ;\n", 
  pessoa[i].id,
  pessoa[i].nome,
  pessoa[i].verEnd,
  pessoa[i].endereco,
  pessoa[i].numeroCasa,
  pessoa[i].verCon,
  pessoa[i].telefone,
  pessoa[i].verSoci,
  pessoa[i].redeSocial,
  pessoa[i].email);
  }
}
