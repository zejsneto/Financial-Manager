#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "./headers/gastos.h"
#include "./headers/conversao.h"

#define TAM 500
#define TYPE 100
#define YEAR 1900

void controle_financeiro(int d,int m,int a);
void cadastro_receita(int d,int m,int a);
void cadastro_gasto(int d,int m,int a);
void categoriza_mov(int d,int m,int a);
void relatorio_anual(int d,int m,int a);

//struct da receita
typedef struct{
  int dia;
  int mes;
  int ano;
  char descricao[TAM];
  double valor;
} struct_receita;

//struct dos gastos
typedef struct{
  char tipo[TYPE];
  int dia;
  int mes;
  int ano;
  char descricao[TAM];
  double valor;
} struct_gasto;

int main(){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  controle_financeiro(tm.tm_mday,tm.tm_mon+1,tm.tm_year+YEAR); 
}

//Função "controle_financeiro" é responsável por mostrar o menu de opções até que o usuário desejar sair.
void controle_financeiro(d, m,a){
  int opcao_escolhida = 0;
  int dia,mes,ano;
  dia = d;
  mes = m;
  ano = a;

  //While para ficar gerando o menu.
  while(1){
    printf("---*--- Controle Financeiro ---*---\n");
    printf("1 - Cadastrar receitas.\n");
    printf("2 - Cadastrar gastos.\n");
    printf("3 - Categorizar movimentações.\n");
    printf("4 - Relatório anual e mensal.\n");
    printf("5 - Encerrar.\n");
    printf("---*--- ---*--- -*- ---*--- ---*---\n");
    printf("Digite a opção desejada: ");
    scanf("%d",&opcao_escolhida);
    if(opcao_escolhida==1){
        system("clear");
        cadastro_receita(dia,mes,ano);
      }
    else if(opcao_escolhida==2){
        system("clear");
        cadastro_gasto(dia,mes,ano);
      }
    else if(opcao_escolhida==3){
        system("clear");
        categoriza_mov(dia,mes,ano);
      }
    else if(opcao_escolhida==4){
        system("clear");
        relatorio_anual(dia,mes,ano);
      }
    else if(opcao_escolhida==5){
        system("clear");
        printf("Saindo ...\n");
        break;
      }
    else{
      system("clear");
      continue;
      }
    }
}

//a função "cadastro_receita" é responsável por cadastrar a receita do usuário
void cadastro_receita(int d,int m,int a){
  int dia,mes,ano;
  dia = d;
  mes = m;
  ano = a;
  int controle = 0;
  int totalMes = yearToMonth(mes,ano);
  char *des;
  des = (char *) malloc(501*sizeof(char)); 

  
  printf("---*--- Cadstro de Receitas ---*---\n\n");

  FILE *fp;
  fp=fopen("geral.txt", "a");
  if(fp==NULL){
    printf("Não foi possível abrir o arquivo.");
    exit(1);
  }
  struct_receita *p = (struct_receita*) malloc(sizeof(struct_receita));

  //Guardar os valores na struct
  printf("Data da receita:\n");
  printf("Digite o dia (XX): ");
  scanf("%d",&p->dia);
  printf("Digite o mes (XX): ");
  scanf("%d",&p->mes);
  printf("Digite o ano (XXXX): ");
  scanf("%d",&p->ano);
  printf("Digite a descrição: ");
  getchar();
  fgets(des,TAM,stdin);
  for(int cont = 0;cont<TAM;cont++){
    p->descricao[cont] = des[cont];
  }
  printf("Digite o valor (R$): ");
  scanf("%lf",&p->valor);
  
  int receitaMes = yearToMonth(p->mes,p->ano);

  //Bloco onde é realizado a escrita no txt
  if(totalMes-receitaMes<=12 && totalMes-receitaMes>=0){
    FILE *gAnual;
    gAnual=fopen("geralAnual.txt", "a");
    fprintf(gAnual,"Receita\nData: %d/%d/%d\nDescrição: %sValor (R$): %.2lf\n\n",p->dia,p->mes,p->ano,p->descricao,p->valor);
    fclose(gAnual);
  }
  fprintf(fp,"Receita\nData: %d/%d/%d\nDescrição: %sValor (R$): %.2lf\n\n",p->dia,p->mes,p->ano,p->descricao,p->valor);
  
  free(p);
  fclose(fp);
  free(des);

  //Condições usadas para tratar os inputs realizados pelo usuário.
  printf("Caso queira realizar outro cadastro digite (1- sim, 2- não): ");
  scanf("%d",&controle);
  if(controle==1){
    system("clear");
    cadastro_receita(dia,mes,ano);
  }
  else if(controle==2){
    system("clear");
    controle_financeiro(dia,mes,ano);
  }
  else{
    while(1){
      printf("Caso queira realizar outro cadastro digite (1- sim, 2- não): ");
      scanf("%d",&controle);
          if(controle==1){
        system("clear");
        cadastro_receita(dia,mes,ano);
      }
      else if(controle==2){
        system("clear");
        controle_financeiro(dia,mes,ano);
      }
      else{
        continue;
      }
    }
  }
}

//a função "cadastro_gasto" é usada para cadastrar 
void cadastro_gasto(int d,int m,int a){
  int dia,mes,ano;
  dia = d;
  mes = m;
  ano = a;
  int controle = 0;
  int tipo_gasto = 0;
  char *des;
  des = (char *) malloc(TAM*sizeof(char)); 
  int totalMes = yearToMonth(mes,ano);
  printf("---*--- Cadstro de Gastos ---*---\n");

  FILE *fp;
  fp=fopen("geral.txt", "a");
  if(fp==NULL){
    printf("Não foi possível abrir o arquivo.");
    exit(1);
  }

  //Função responsável por printar a tabela do tipo de gastos.
  tipoDeGastos();
  
  while(1){
    printf("Digite o tipo do gasto: "); 
    scanf("%d",&tipo_gasto);
    if(tipo_gasto>=1 && tipo_gasto<=5){
      break;
    }
    else{
      continue;
    }
  }

  struct_receita *p = (struct_receita*) malloc(sizeof(struct_receita));
  printf("Digite o dia (XX): ");
  scanf("%d",&p->dia);
  printf("Digite o mes (XX): ");
  scanf("%d",&p->mes);
  printf("Digite o ano (XXXX): ");
  scanf("%d",&p->ano);
  printf("Digite a descrição: ");
  getchar();
  fgets(des,TAM,stdin);
  for(int cont = 0;cont<TAM;cont++){
    p->descricao[cont] = des[cont];
  }
  printf("Digite o valor (R$): ");
  scanf("%lf",&p->valor);
  int gastoMes = yearToMonth(p->mes,p->ano);

  //Uma condição para cada tipo de gasto.
  if(tipo_gasto==1){
    //abre o arquivo do tipo do gasto;
    FILE *moradia;
    moradia=fopen("moradia.txt", "a");
    if(fp==NULL){
      printf("Não foi possível abrir o arquivo.");
      exit(1);
    }
    //Caso o gasto esteja no período de 12 meses.
    if(totalMes-gastoMes<=12 && totalMes-gastoMes>=0){
      FILE *gAnual;
      gAnual=fopen("geralAnual.txt", "a");
      fprintf(gAnual,"Moradia\nData: %d/%d/%d\nDescrição: %sValor (R$): %.2lf\n\n",p->dia,p->mes,p->ano,p->descricao,p->valor);
      fclose(gAnual);
    }
    //Caso o gasto seja do mês passado
    if(mes-1==p->mes && ano==p->ano){
      fprintf(moradia,"Moradia\nData: %d/%d/%d\nDescrição: %sValor (R$): %.2lf\n\n",p->dia,p->mes,p->ano,p->descricao,p->valor);
      fclose(moradia);
    }

    fprintf(fp,"Moradia\nData: %d/%d/%d\nDescrição: %sValor (R$): %.2lf\n\n",p->dia,p->mes,p->ano,p->descricao,p->valor);
    fclose(fp);

  }
    
  else if(tipo_gasto==2){
    FILE *estudo;
    estudo=fopen("estudo.txt", "a");
    if(fp==NULL){
      printf("Não foi possível abrir o arquivo.");
      exit(1);
    }
    if(totalMes-gastoMes<=12 && totalMes-gastoMes>=0){
      FILE *gAnual;
      gAnual=fopen("geralAnual.txt", "a");
      fprintf(gAnual,"Estudo\nData: %d/%d/%d\nDescrição: %sValor (R$): %.2lf\n\n",p->dia,p->mes,p->ano,p->descricao,p->valor);
      fclose(gAnual);

    }
    if(mes-1==p->mes && ano==p->ano){
      fprintf(estudo,"Estudo\nData: %d/%d/%d\nDescrição: %sValor (R$): %.2lf\n\n",p->dia,p->mes,p->ano,p->descricao,p->valor);
      fclose(estudo);
    }
    fprintf(fp,"Estudo\nData: %d/%d/%d\nDescrição: %sValor (R$): %.2lf\n\n",p->dia,p->mes,p->ano,p->descricao,p->valor);
    fclose(fp);
  }

  else if(tipo_gasto==3){
    FILE *ali;
    ali=fopen("alimentacao.txt", "a");
    if(fp==NULL){
      printf("Não foi possível abrir o arquivo.");
      exit(1);
    }

    if(totalMes-gastoMes<=12 && totalMes-gastoMes>=0){
      FILE *gAnual;
      gAnual=fopen("geralAnual.txt", "a");
      fprintf(gAnual,"Alimentação\nData: %d/%d/%d\nDescrição: %sValor (R$): %.2lf\n\n",p->dia,p->mes,p->ano,p->descricao,p->valor);
      fclose(gAnual);
    }

    if(mes-1==p->mes && ano==p->ano){
      fprintf(ali,"Alimentação\nData: %d/%d/%d\nDescrição: %sValor (R$): %.2lf\n\n",p->dia,p->mes,p->ano,p->descricao,p->valor);
      fclose(ali);
    }
    
    fprintf(fp,"Alimentação\nData: %d/%d/%d\nDescrição: %sValor (R$): %.2lf\n\n",p->dia,p->mes,p->ano,p->descricao,p->valor);
    fclose(fp);
  }

  else if(tipo_gasto==4){
    FILE *trans;
    trans=fopen("transporte.txt", "a");
    if(fp==NULL){
      printf("Não foi possível abrir o arquivo.");
      exit(1);
    }

    if(totalMes-gastoMes<=12 && totalMes-gastoMes>=0){
      FILE *gAnual;
      gAnual=fopen("geralAnual.txt", "a");
      fprintf(gAnual,"Transporte\nData: %d/%d/%d\nDescrição: %sValor (R$): %.2lf\n\n",p->dia,p->mes,p->ano,p->descricao,p->valor);
      fclose(gAnual);

    }

    if(mes-1==p->mes && ano==p->ano){
      fprintf(trans,"Transpote\nData: %d/%d/%d\nDescrição: %sValor (R$): %.2lf\n\n",p->dia,p->mes,p->ano,p->descricao,p->valor);
      fclose(trans);
    }
    
    fprintf(fp,"Transpote\nData: %d/%d/%d\nDescrição: %sValor (R$): %.2lf\n\n",p->dia,p->mes,p->ano,p->descricao,p->valor);
    fclose(fp);
  }

  else if(tipo_gasto==5){
    FILE *trab;
    trab=fopen("trabalho.txt", "a");
    if(fp==NULL){
      printf("Não foi possível abrir o arquivo.");
      exit(1);
    }

    if(totalMes-gastoMes<=12 && totalMes-gastoMes>=0){
      FILE *gAnual;
      gAnual=fopen("geralAnual.txt", "a");
      fprintf(gAnual,"Trabalho\nData: %d/%d/%d\nDescrição: %sValor (R$): %.2lf\n\n",p->dia,p->mes,p->ano,p->descricao,p->valor);
      fclose(gAnual);
    
    }

    if(mes-1==p->mes && ano==p->ano){
      fprintf(trab,"Trabalho\nData: %d/%d/%d\nDescrição: %sValor (R$): %.2lf\n\n",p->dia,p->mes,p->ano,p->descricao,p->valor);
      fclose(trab);
    }
    
    fprintf(fp,"Trabalho\nData: %d/%d/%d\nDescrição: %sValor (R$): %.2lf\n\n",p->dia,p->mes,p->ano,p->descricao,p->valor);

    fclose(fp);
  }
  
  free(p);
  free(des);

  //Condições para tratar os inputs.
  printf("Caso queira realizar outro cadastro digite (1- sim, 2- não): ");
  scanf("%d",&controle);
  if(controle==1){
    system("clear");
    cadastro_gasto(dia,mes,ano);
  }
  else if(controle==2){
    system("clear");
    controle_financeiro(dia,mes,ano);
  }
  else{
    //while para tratar os inputs do usuário.
    while(1){
      printf("\nCaso queira realizar outro cadastro digite (1- sim, 2- não): ");
      scanf("%d",&controle);
          if(controle==1){
        system("clear");
        cadastro_gasto(dia,mes,ano);
      }
      else if(controle==2){
        system("clear");
        controle_financeiro(dia,mes,ano);
      }
      else{
        continue;
      }
    }
  }
}

//a função "categoriza_mov" é responsável por printar o relatório mensal.
void categoriza_mov(int d,int m,int a){
  int dia,mes,ano;
  dia = d;
  mes = m;
  ano = a;
  int tipo_gasto = 0;
  char linha[100];
  char *line;

  printf("---*--- Relatório mensal por categoria ---*---");

  tipoDeGastos();

  //while para tratar o input do usuário.
  while(1){
    printf("Digite o tipo do gasto para exibir o relatório: "); 
    scanf("%d",&tipo_gasto);
    if(tipo_gasto>=1 && tipo_gasto<=5){
      system("clear");
      break;
    }
    else{
      continue;
    }
  }
  FILE *arq;

  //Com o input do usuário é determiando qual relatório mensal será printado.
  if(tipo_gasto==1){
  
    arq=fopen("moradia.txt", "r");
    if(arq==NULL){
      printf("Não foi possível abrir o arquivo.");
      exit(1);
    }
    while (!feof(arq)){
      line = fgets(linha, 100, arq);  
      if (line){
         printf("%s",linha); 
        }
      }
    fclose(arq);
    
  }

  else if(tipo_gasto==2){
    arq=fopen("estudo.txt", "r");
    if(arq==NULL){
      printf("Não foi possível abrir o arquivo.");
      exit(1);
    }
    while (!feof(arq)){
      line = fgets(linha, 100, arq);  
      if (line){
         printf("%s",linha); 
        }
      }
    fclose(arq);

  }

  else if(tipo_gasto==3){
    arq=fopen("alimentacao.txt", "r");
    if(arq==NULL){
      printf("Não foi possível abrir o arquivo.");
      exit(1);
    }
    while (!feof(arq)){
      line = fgets(linha, 100, arq);  
      if (line){
         printf("%s",linha); 
        }
      }
    fclose(arq);
    
  }

  else if(tipo_gasto==4){
    arq=fopen("transporte.txt", "r");
    if(arq==NULL){
      printf("Não foi possível abrir o arquivo.");
      exit(1);
    }
    while (!feof(arq)){
      line = fgets(linha, 100, arq);  
      if (line){
         printf("%s",linha); 
        }
      }
    fclose(arq);
    
  }

  else if(tipo_gasto==5){
    arq=fopen("trabalho.txt", "r");
    if(arq==NULL){
      printf("Não foi possível abrir o arquivo.");
      exit(1);
    }
    while (!feof(arq)){
      line = fgets(linha, 100, arq);  
      if (line){
         printf("%s",linha); 
        }
      }
    fclose(arq);
    
  }
  int opcao = 0;

  //while para tratar os inputs do usuário.
  while(1){
    printf("\nCaso queira realizar outra consulta digite (1- sim, 2- não): ");
    scanf("%d",&opcao);
    if(opcao==1){
      system("clear");
      categoriza_mov(dia,mes,ano);
    }
    else if(opcao==2){
      system("clear");
      controle_financeiro(dia,mes,ano);
    }  
    else{
      continue;
    }
  }

}

//a função "relatorio_anual" é usada para printar tudo que está cadastrado no geralAnual.txt
void relatorio_anual(int d,int m,int a){
  int dia,mes,ano;
  dia = d;
  mes = m;
  ano = a;
  int tipo_gasto = 0;
  char linha[100];
  char *line;
  int opcao=0;

  printf("Relatório anual\n"); 

  FILE *arq;

  arq=fopen("geralAnual.txt", "r"); 
  if(arq==NULL){
    printf("Não consegui abrir o arquivo!");
    exit(1);
  }

  //While uzado para printar cada linha do arquivo.
  while (!feof(arq)){
    line = fgets(linha, 100, arq);  
    if(line){
        printf("%s",linha); 
      }
    }
  fclose(arq);

  
  //While para tratar os inputs do usuário
  printf("\nCaso queira realizar outra consulta digite (1- ir para o menu, 2- ver relatórios mensais): ");
  while(1){
    scanf("%d",&opcao);
    if(opcao==1){
      system("clear");
      controle_financeiro(dia,mes,ano);
    }
    else if(opcao==2){
      system("clear");
      categoriza_mov(dia,mes,ano);
    }  
    else{
      continue;
    }
  }
}

//Link do projeto instanciado no GitHub
//(https://github.com/zejsneto/Projeto-Gerenciador-Financeiro)