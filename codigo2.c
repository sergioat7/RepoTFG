#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd1;
	int fd2;
	int n=1;
	int leido=0;
	int len=0;
	char a;char b;char c;
	char c2[3]="";

	char entrada[16];
	char salida[100];

	char sal[]="<?php\n";
	char sal2[]="?>";
	
	fd2 = open("codigoPHP.php",O_WRONLY);
	if(fd2 == -1){
		printf("Error al abrir el fichero de salida\n");
		return -1;
	}

	write(fd2, &sal, strlen(sal));


	while(n<142){
		memset(entrada, '\0', sizeof(entrada));
		memset(c2, '\0', sizeof(c2));
		strcpy(entrada,"salidas/s");
		sprintf(&c2, "%d", n);
		strcat(entrada,c2);
		n++;
		strcat(entrada,".txt");
		
		fd1 = open(entrada,O_RDONLY);
		if(fd1 == -1){
			printf("Error al abrir el fichero de entrada\n");
			return -1;
		}
		
		/* CORREO */
		while(1){
			leido = read(fd1,&c,1);
			if(leido==-1){
				printf("ERROR: Read fd1\n");
				exit(-1);
			}
			else{
				if(c=='p'){
					read(fd1,&a,1);read(fd1,&b,1);read(fd1,&c,1);
					if(a=='a' && b=='t' && c=='h'){//path
						memset(salida, '\0', sizeof(salida));
						strcpy(salida,"echo html_entity_decode(");
						len = strlen(salida);
						salida[len] = '"';
						salida[len+1] = (char)NULL;
						while(1){
							read(fd1,&c,1);
							if(c=='y')
								break;
						}
						while(1){
							read(fd1,&c,1);
							if(c==' ')
								break;
						}
						read(fd1,&a,1);
						while(1){
							read(fd1,&c,1);
							if(c=='\n')
								break;
							else if((int)c==39 || c=='+' || c==' '){}
							else{
								len = strlen(salida);
								salida[len] = c;
								salida[len+1] = (char)NULL;
							}
						}
						len = strlen(salida);
						salida[len-1] = '"';
						salida[len] = ')';
						salida[len+1] = '.';
						salida[len+2] = '"';
						salida[len+3] = (char)92;
						salida[len+4] = 'n';
						salida[len+5] = '"';
						salida[len+6] = ';';
						salida[len+7] = '\n';
						salida[len+8] = (char)NULL;
						break;
					}
				}
			}
		}
		
		
		close(fd1);
		write(fd2, &salida, strlen(salida));
	}
	
	write(fd2, &sal2, strlen(sal2));
	close(fd2);
	return 0;
}
