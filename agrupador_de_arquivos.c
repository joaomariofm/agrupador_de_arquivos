#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char nome[10] = "Ex", arq[21] = "Ex", control[21], c[3] =".c";
	int x=0;

	FILE *  arquivo;
	FILE * arquivo2;
	
	printf("Quantos arquivos voce quer acessar?\n");
	scanf("%i", &x);
	
	for(int i = 1;i<=x;i++){
	char ix[5];
	/*transforma i em string*/
	sprintf(ix,"%i",i);
	/*concatena todas as partes do nome do qruivo*/
	strcpy(control,arq);
	strcat(control,ix);
	strcat(control,c);
	strcpy(nome,arq);
	strcat(nome,ix);
	
	arquivo = fopen(control,"rt");
	arquivo2 = fopen("saida.c","a");
	if(arquivo == NULL){
		printf("ERRO na abertura do arquivo %s\n", control);
		exit(1);
	}

	fprintf(arquivo2,"\n%s:\n\n", nome);

	char c = fgetc(arquivo);
	while(c != EOF){
		fprintf(arquivo2,"%c", c);
		c = fgetc(arquivo);	
	}
	 
	fclose(arquivo);
	fclose(arquivo2);
	}
	system("pause");
	return 0;
}

