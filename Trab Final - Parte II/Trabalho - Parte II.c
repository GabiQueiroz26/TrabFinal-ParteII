#include <stdio.h>
#include <stdlib.h>

int imagemCinza() {
	int linhas, colunas, vmax;
			int i, j, k, n;
			char buffer[250];
			FILE *origem;
			FILE *destino;
			
			origem = fopen("dog.ppm", "r");
			destino = fopen("dogCinza.ppm", "w");
	
			if(origem == NULL){
				printf("Erro ao abrir o arquivo.");
				return 1;
			} else {
				fgets(buffer, 250, origem); //P3
				fgets(buffer, 250, origem); //Comentario
				fscanf(origem, "%d %d", &colunas, &linhas);
				fscanf(origem, "%d", &vmax);
				int matriz[linhas][colunas][3];
		
			fprintf(destino, "P3\n");
			fprintf(destino, "#Feito por Gabriela\n");
			fprintf(destino, "%d %d\n", colunas, linhas);
			fprintf(destino, "%d\n", vmax);
		
			for(i = 0; i < linhas; i++){
				for(j = 0; j < colunas; j++){
					n = 0;
					for(k = 0; k < 3; k++){
						fscanf(origem, "%d", &matriz[i][j][k]);
						n = n + matriz[i][j][k];
					}
						n = n / 3;
						fprintf(destino, "%d %d %d ", n, n, n);
					}
				}
			}
				fclose(origem);
				fclose(destino);
				return 0;
}

int imagemHorizontal() {
			int linhas, colunas, vmax;
			int i, j, k, n;
			FILE *origem;
			FILE *destino;
		
			origem = fopen("dog.ppm", "r");
			destino = fopen("dogEspelhado.ppm", "w");
    

    		char buffer[250], tipo;
			fgets(buffer, 250, origem);
			tipo = buffer[1];
		    fgets(buffer, 250, origem);
		    fscanf(origem, "%d %d", &colunas, &linhas);
		    fscanf(origem, "%d", &vmax);
    
		    int matriz[linhas][colunas][3];
		    
		    if (tipo == '3') {
		        for (i = 0; i < linhas; i++) {
		        for (j = 0; j < colunas; j++) {
		            for (k = 0; k < 3; k++) {
		            fscanf(origem, "%d", &matriz[i][j][k]);
		            }
		        }
		        }
		    } else if(tipo == 2) {
		        for (i = 0; i < linhas; i++) {
		        for (j = 0; j < colunas; j++) {
		            fscanf(origem, "%d", &n);
		            for (k = 0; k < 3; k++) {
		            matriz[i][j][k] = n;
		            }
		        }
		        }
		    }
		
		    fprintf(destino, "P3\n");
		    fprintf(destino, "#Feito por Gabriela\n");
		    fprintf(destino, "%d %d\n", colunas, linhas);
		    fprintf(destino, "%d\n", vmax);
		
		    for(i = 0; i < linhas; i++){
		        for(j = colunas -1 ; j >= 0; j--){
		            for(k = 0; k < 3; k++){
		                fprintf(destino, "%d ", matriz[i][j][k]);
		            }
		        }
		        fprintf(destino, "\n");
		    }
		
		    fclose(origem);
		    fclose(destino);
		
		    return 0;
}

int imagemVertical() {
	int linhas, colunas, vmax;
			int i, j, k, n;
			FILE *origem;
			FILE *destino;
			
			origem = fopen("dog.ppm", "r");
			destino = fopen("dogVirado.ppm", "w");
    

		    char buffer[250], tipo;
			fgets(buffer, 250, origem);
			tipo = buffer[1];
		    fgets(buffer, 250, origem);
		    fscanf(origem, "%d %d", &colunas, &linhas);
		    fscanf(origem, "%d", &vmax);
		    
		    int matriz[linhas][colunas][3];
		    
		    if (tipo == '3') {
		        for (i = 0; i < linhas; i++) {
		        for (j = 0; j < colunas; j++) {
		            for (k = 0; k < 3; k++) {
		            fscanf(origem, "%d", &matriz[i][j][k]);
		            }
		        }
		        }
		    } else if(tipo == 2) {
		        for (i = 0; i < linhas; i++) {
		        for (j = 0; j < colunas; j++) {
		            fscanf(origem, "%d", &n);
		            for (k = 0; k < 3; k++) {
		            matriz[i][j][k] = n;
		            }
		        }
		        }
		    }
		
		    fprintf(destino, "P3\n");
		    fprintf(destino, "#Feito por Gabriela\n");
		    fprintf(destino, "%d %d\n", colunas, linhas);
		    fprintf(destino, "%d\n", vmax);
		
		    for(i = linhas -1; i >= 0; i--){
		        for(j = 0 ; j < colunas; j++){
		            for(k = 0; k < 3; k++){
		                fprintf(destino, "%d ", matriz[i][j][k]);
		            }
		        }
		        fprintf(destino, "\n");
		    }
		
		    fclose(origem);
		    fclose(destino);
		
		    return 0;
}

int imagemEsqDireita() {
		int linhas, colunas, vmax;
			int i, j, k, n;
			FILE *origem;
			FILE *destino;
			FILE *destino2;
			
			origem = fopen("dog.ppm", "r");
		    destino = fopen("dogEsquerda.ppm", "w");
		    destino2 = fopen("dogDireita.ppm", "w");
		    
		    char buffer[250], tipo;
		    fgets(buffer, 250, origem);
		    tipo = buffer[1];
		    fgets(buffer, 250, origem);
		    fscanf(origem, "%d %d", &colunas, &linhas);
		    fscanf(origem, "%d", &vmax);
		    
		    int matriz[linhas][colunas][3];
		    
		    if (tipo == '3') {
		        for (i = 0; i < linhas; i++) {
		            for (j = 0; j < colunas; j++) {
		                for (k = 0; k < 3; k++) {
		                    fscanf(origem, "%d", &matriz[i][j][k]);
		                }
		            }
		        }
		    } else if(tipo == '2') { // Corrigido para tipo ser um caractere
		        for (i = 0; i < linhas; i++) {
		            for (j = 0; j < colunas; j++) {
		                fscanf(origem, "%d", &n);
		                for (k = 0; k < 3; k++) {
		                    matriz[i][j][k] = n;
		                }
		            }
		        }
		    }
		    
		    fprintf(destino, "P3\n");
		    fprintf(destino, "#Feito por Gabriela\n");
		    fprintf(destino, "%d %d\n", colunas / 2, linhas);
		    fprintf(destino, "%d\n", vmax);
		    
		    fprintf(destino2, "P3\n");
		    fprintf(destino2, "#Feito por Gabriela\n");
		    fprintf(destino2, "%d %d\n", colunas - colunas / 2, linhas);
		    fprintf(destino2, "%d\n", vmax);
		    
		    for(i = 0; i < linhas; i++) {
		        for(j = 0; j < colunas / 2; j++) {
		            for(k = 0; k < 3; k++) {
		                fprintf(destino, "%d ", matriz[i][j][k]);
		            }
		        }
		        fprintf(destino, "\n");
		        
		        for(j = colunas / 2; j < colunas; j++) {
		            for(k = 0; k < 3; k++) {
		                fprintf(destino2, "%d ", matriz[i][j][k]);
		            }
		        }
		        fprintf(destino2, "\n");
		    }
		    
		    fclose(origem);
		    fclose(destino);
		    fclose(destino2);
		    
		    return 0;
}

int imagemSupInferior() {
				int linhas, colunas, vmax;
			int i, j, k, n;
			FILE *origem;
			FILE *destino;
			FILE *destino2;
			
			origem = fopen("dog.ppm", "r");
		    destino = fopen("dogSuperior.ppm", "w");
		    destino2 = fopen("dogInferior.ppm", "w");
		    
		    char buffer[250], tipo;
		    fgets(buffer, 250, origem);
		    tipo = buffer[1];
		    fgets(buffer, 250, origem);
		    fscanf(origem, "%d %d", &colunas, &linhas);
		    fscanf(origem, "%d", &vmax);
		    
		    int matriz[linhas][colunas][3];
		    
		    if (tipo == '3') {
		        for (i = 0; i < linhas; i++) {
		            for (j = 0; j < colunas; j++) {
		                for (k = 0; k < 3; k++) {
		                    fscanf(origem, "%d", &matriz[i][j][k]);
		                }
		            }
		        }
		    } else if(tipo == '2') {
		        for (i = 0; i < linhas; i++) {
		            for (j = 0; j < colunas; j++) {
		                fscanf(origem, "%d", &n);
		                for (k = 0; k < 3; k++) {
		                    matriz[i][j][k] = n;
		                }
		            }
		        }
		    }
		    
		    fprintf(destino, "P3\n");
		    fprintf(destino, "#Feito por Gabriela\n");
		    fprintf(destino, "%d %d\n", colunas, linhas / 2); // Alterado para linhas / 2
		    fprintf(destino, "%d\n", vmax);
		    
		    fprintf(destino2, "P3\n");
		    fprintf(destino2, "#Feito por Gabriela\n");
		    fprintf(destino2, "%d %d\n", colunas, linhas - linhas / 2); // Alterado para linhas - linhas / 2
		    fprintf(destino2, "%d\n", vmax);
		    
		    for(i = 0; i < linhas / 2; i++) { // Alterado para linhas / 2
		        for(j = 0; j < colunas; j++) {
		            for(k = 0; k < 3; k++) {
		                fprintf(destino, "%d ", matriz[i][j][k]);
		            }
		        }
		        fprintf(destino, "\n");
		    }
		    
		    for(i = linhas / 2; i < linhas; i++) { // Alterado para linhas / 2
		        for(j = 0; j < colunas; j++) {
		            for(k = 0; k < 3; k++) {
		                fprintf(destino2, "%d ", matriz[i][j][k]);
		            }
		        }
		        fprintf(destino2, "\n");
		    }
		    
		    fclose(origem);
		    fclose(destino);
		    fclose(destino2);
		    
		    return 0;
}

int imagemArtificial() {

    int linhas, colunas, vmax;
    int i, j, k, n;
    char buffer[250];
    FILE *origem;
    FILE *destino;

    origem = fopen("dog.ppm", "r");
    destino = fopen("dogCinza.ppm", "w");

    if (origem == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    } else {
        fgets(buffer, 250, origem); // P3
        fgets(buffer, 250, origem); // Comentario
        fscanf(origem, "%d %d", &colunas, &linhas);
        fscanf(origem, "%d", &vmax);
        int matriz[linhas][colunas][3];

        fprintf(destino, "P3\n");
        fprintf(destino, "#Feito por Gabriela\n");
        fprintf(destino, "%d %d\n", colunas, linhas);
        fprintf(destino, "%d\n", vmax);

        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                n = 0;
                for (k = 0; k < 3; k++) {
                    fscanf(origem, "%d", &matriz[i][j][k]);
                    n += matriz[i][j][k];
                }
                n = n / 3;
                fprintf(destino, "%d %d %d ", n, n, n);
            }
        }
    }
    fclose(origem);
    fclose(destino);

    // Abre o arquivo de imagem em escala de cinza
    origem = fopen("dogCinza.ppm", "r");
    destino = fopen("dogColorido.ppm", "w");

    if (origem == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    } else {
        fgets(buffer, 250, origem); // P3
        fgets(buffer, 250, origem); // Comentario
        fscanf(origem, "%d %d", &colunas, &linhas);
        fscanf(origem, "%d", &vmax);
        int matriz[linhas][colunas][3];

        fprintf(destino, "P3\n");
        fprintf(destino, "#Feito por Gabriela\n");
        fprintf(destino, "%d %d\n", colunas, linhas);
        fprintf(destino, "%d\n", vmax);

        srand(time(NULL)); // Inicializa a semente para gerar números aleatórios

        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                for (k = 0; k < 3; k++) {
                    fscanf(origem, "%d", &matriz[i][j][k]);
                }

                // Gera um valor aleatório entre 0 e 5 para cada canal de cor
                int r = rand() % 6;
                int g = rand() % 6;
                int b = rand() % 6;

                fprintf(destino, "%d %d %d ", matriz[i][j][0] + r, matriz[i][j][1] + g, matriz[i][j][2] + b);
            }
        }
    }
    fclose(origem);
    fclose(destino);
    return 0;
}

int imagem90GrausDireita() {

    int colunas, linhas, vmax;
    int i, j, k, n;
    FILE *origem;
    FILE *destino;

    origem = fopen("dog.ppm", "r");
    destino = fopen("dog90grausDireita.ppm", "w");

    char buffer[250], tipo;
    fgets(buffer, 250, origem);
    tipo = buffer[1];
    fgets(buffer, 250, origem);
    fscanf(origem, "%d %d", &colunas, &linhas);
    fscanf(origem, "%d", &vmax);

    int matriz[linhas][colunas][3];

    if (tipo == '3') {
        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                for (k = 0; k < 3; k++) {
                    fscanf(origem, "%d", &matriz[i][j][k]);
                }
            }
        }
    } else if (tipo == '2') {
        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                fscanf(origem, "%d", &n);
                for (k = 0; k < 3; k++) {
                    matriz[i][j][k] = n;
                }
            }
        }
    }

    fprintf(destino, "P3\n");
    fprintf(destino, "#Feito por Gabriela\n");
    fprintf(destino, "%d %d\n", linhas, colunas);
    fprintf(destino, "%d\n", vmax);

    for (j = colunas - 1; j >= 0; j--) {
        for (i = 0; i < linhas; i++) {
            for (k = 0; k < 3; k++) {
                fprintf(destino, "%d ", matriz[i][j][k]);
            }
        }
        fprintf(destino, "\n");
    }

    fclose(origem);
    fclose(destino);

    return 0;

}

int imagem90GrausEsquerda() {
	  int colunas, linhas, vmax;
    int i, j, k, n;
    FILE *origem;
    FILE *destino;

    origem = fopen("dog.ppm", "r");
    destino = fopen("dog90grausEsquerda.ppm", "w");

    char buffer[250], tipo;
    fgets(buffer, 250, origem);
    tipo = buffer[1];
    fgets(buffer, 250, origem);
    fscanf(origem, "%d %d", &colunas, &linhas);
    fscanf(origem, "%d", &vmax);

    int matriz[linhas][colunas][3];

    if (tipo == '3') {
        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                for (k = 0; k < 3; k++) {
                    fscanf(origem, "%d", &matriz[i][j][k]);
                }
            }
        }
    } else if (tipo == '2') {
        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                fscanf(origem, "%d", &n);
                for (k = 0; k < 3; k++) {
                    matriz[i][j][k] = n;
                }
            }
        }
    }

    fprintf(destino, "P3\n");
    fprintf(destino, "#Feito por Gabriela\n");
    fprintf(destino, "%d %d\n", linhas, colunas);
    fprintf(destino, "%d\n", vmax);

    for (j = 0; j < colunas; j++) {
        for (i = linhas - 1; i >= 0; i--) {
            for (k = 0; k < 3; k++) {
                fprintf(destino, "%d ", matriz[i][j][k]);
            }
        }
        fprintf(destino, "\n");
    }

    fclose(origem);
    fclose(destino);

    return 0;
}

int imagemParteCinza() {
	
	int linhas, colunas, vmax;
    int i, j, k, n;
    char buffer[250];
    FILE *origem;
    FILE *destino;

    origem = fopen("dog.ppm", "r");
    destino = fopen("dogParteCinza.ppm", "w");

     fgets(buffer, 250, origem); 
     fgets(buffer, 250, origem); 
     fscanf(origem, "%d %d", &colunas, &linhas); 
     fscanf(origem, "%d", &vmax); 
     int matriz[linhas][colunas][3];

    fprintf(destino, "P3\n");
    fprintf(destino, "#Feito por Gabriela\n");
    fprintf(destino, "%d %d\n", colunas, linhas);
    fprintf(destino, "%d\n", vmax);

    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++) {
            n = 0;
        	for(k=0; k<3; k++) {
                fscanf(origem, "%d", &matriz[i][j][k]);
                     n = n + matriz[i][j][k];
            }
                     n = n / 3; 
                        
            for(k=0; k<3; k++) {
            	if (j < colunas/2){
                    fprintf(destino, "%d ", n);
                }
                else {
                    fprintf(destino, "%d ", matriz[i][j][k]);
                 }

            }
        }

    }
		fclose(origem);
        fclose(destino);


    return 0;
}

int imagemRGB() {
	int linhas, colunas, vmax;
    int i, j, k, n;
    char buffer[250];
    FILE *origem;
    FILE *destinoR;
    FILE *destinoG;
    FILE *destinoB;

    origem = fopen("dog.ppm", "r");
    destinoR = fopen("dogR.ppm", "w");
    destinoG = fopen("dogG.ppm", "w");
    destinoB = fopen("dogB.ppm", "w");

    if (origem == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    } else {
        fgets(buffer, 250, origem); // P3
        fgets(buffer, 250, origem); // Comentário
        fscanf(origem, "%d %d", &colunas, &linhas);
        fscanf(origem, "%d", &vmax);
        int matriz[linhas][colunas][3];

        fprintf(destinoR, "P3\n");
        fprintf(destinoR, "#Feito por Gabriela\n");
        fprintf(destinoR, "%d %d\n", colunas, linhas);
        fprintf(destinoR, "%d\n", vmax);

        fprintf(destinoG, "P3\n");
        fprintf(destinoG, "#Feito por Gabriela\n");
        fprintf(destinoG, "%d %d\n", colunas, linhas);
        fprintf(destinoG, "%d\n", vmax);

        fprintf(destinoB, "P3\n");
        fprintf(destinoB, "#Feito por Gabriela\n");
        fprintf(destinoB, "%d %d\n", colunas, linhas);
        fprintf(destinoB, "%d\n", vmax);

        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                for (k = 0; k < 3; k++) {
                    fscanf(origem, "%d", &matriz[i][j][k]);
                }
            }
        }

        for (i = 0; i < linhas; i++) {
            for (j = 0; j < colunas; j++) {
                fprintf(destinoR, "%d ", matriz[i][j][0]);
                fprintf(destinoG, "%d ", matriz[i][j][1]);
                fprintf(destinoB, "%d ", matriz[i][j][2]);
            }
        }
    }

    fclose(origem);
    fclose(destinoR);
    fclose(destinoG);
    fclose(destinoB);

    return 0;
}




int main() {
	int menu;

do {

	printf("-----------------------------------------------------------------------\n");
	printf("|                    Menu para tratamento de imagens                  |\n");
	printf("-----------------------------------------------------------------------\n");
	printf("1 para converter imagem colorida para escala de cinza\n");
	printf("2 para espelhar imagem horizontalmente\n");
	printf("3 para espelhar imagem verticalmente\n");
	printf("4 para dividir imagem em dois arquivos(metade esquerda, metade direita)\n");
	printf("5 para dividir imagem em dois arquivos(metade superior, metade inferior)\n");
	printf("6 para colorir uma imagem artificialmente\n");
	printf("7 para rotacionar uma imagem 90 graus para a direita\n");
	printf("8 para rotacionar uma imagem 90 graus para a esquerda\n");
	printf("9 para gerar imagem com uma parte em escala de cinza\n");
	printf("10 para gerar tres arquivos de saida para cada camada(R, G e B)\n");
	printf("0 para sair\n");
	
	scanf("%d", &menu);
	
	switch(menu) {
		case 1: 
			imagemCinza();
			printf("Pronto! Sua imagem foi gerada, va ate a pasta do arquivo e confira!\n");
			break;
				
		case 2: 
			imagemHorizontal();
			printf("Pronto! Sua imagem foi gerada, va ate a pasta do arquivo e confira!\n");
		    break;
		
		case 3:
			imagemVertical();
			printf("Pronto! Sua imagem foi gerada, va ate a pasta do arquivo e confira!\n");
		    break;
		    
		case 4:
			imagemEsqDireita();
			printf("Pronto! Suas imagens foram geradas, va ate a pasta do arquivo e confira!\n");
		    break;
		
		case 5:
			imagemSupInferior();
			printf("Pronto! Suas imagens foram geradas, va ate a pasta do arquivo e confira!\n");
		    break;
		
		case 6:
			imagemArtificial();
			printf("Pronto! Suas imagens foram geradas, va ate a pasta do arquivo e confira!\n");
		    break;
		    
		case 7:
			imagem90GrausDireita();
			printf("Pronto! Suas imagens foram geradas, va ate a pasta do arquivo e confira!\n");
			break;
		
		case 8:
			imagem90GrausEsquerda();
			printf("Pronto! Suas imagens foram geradas, va ate a pasta do arquivo e confira!\n");
			break;
		
		case 9:
			imagemParteCinza();
			printf("Pronto! Suas imagens foram geradas, va ate a pasta do arquivo e confira!\n");
			break;
		
		case 10:
			imagemRGB();
			printf("Pronto! Suas imagens foram geradas, va ate a pasta do arquivo e confira!\n");
			break;
			
		default:
			printf("Saindo do programa\n");
			break;
	}
	
} while (menu != 0);

}
