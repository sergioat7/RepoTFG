#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd1;
	int fd2;
	int fd3;	
	int n=1;
	int leido=0;
	int i;
	int len=0;
	char a;char b;char c;char d;
	char c2[3]="";

	char entrada[16];
	char salida[100];
	char sal[100];
	
	fd2 = open("extra.csv",O_WRONLY);
	if(fd2 == -1){
		printf("Error al abrir el fichero de salida\n");
		return -1;
	}

	fd3 = open("correos.txt",O_RDONLY);
	if(fd3 == -1){
		printf("Error al abrir el fichero de los correos\n");
		return -1;
	}

	while(n<142){
		memset(entrada, '\0', sizeof(entrada));
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
		memset(sal, '\0', sizeof(sal));
		while(1){
			leido = read(fd3,&c,1);
			if(leido==-1){
				printf("ERROR: Read fd3\n");
				exit(-1);
			}
			else{
				if(c=='\n')
					break;
				len = strlen(sal);
				sal[len] = c;
				sal[len+1] = (char)NULL;
			}
		}
		
		
		/* RESTO DE INFORMACIÓN */
		while(1){	
			leido = read(fd1,&c,1);
			if(leido==-1){
				printf("ERROR: Read fd1\n");
				exit(-1);
			}
			/* L1"> */
			if(c=='L'){
				read(fd1,&a,1);read(fd1,&b,1);read(fd1,&c,1);
				if(a=='1' && b=='"' && c=='>'){
					break;
				}
			}
			/*  NOMBRE  */
			else if(c=='N'){
				read(fd1,&a,1);read(fd1,&b,1);read(fd1,&c,1);
				if(a=='o' && b=='m' && c=='b'){
					memset(salida, '\0', sizeof(salida));
					while(1){
						read(fd1,&c,1);
						if(c==':')
							break;
					}
					for(i=0;i<48;i++){
						read(fd1,&c,1);
					}
					while(1){
						read(fd1,&c,1);
						if(c=='<')
							break;
						else{
							len = strlen(salida);
							salida[len] = c;
							salida[len+1] = (char)NULL;
						}
					}
					len = strlen(salida);
					salida[len] = ' ';
					salida[len+1] = (char)NULL;
					write(fd2, &salida, strlen(salida));
				}
			}
			/*  APELLIDOS  */
			else if(c=='A'){
				read(fd1,&a,1);read(fd1,&b,1);read(fd1,&c,1);
				if(a=='p' && b=='e' && c=='l'){
					memset(salida, '\0', sizeof(salida));
					while(1){
						read(fd1,&c,1);
						if(c==':')
							break;
					}
					for(i=0;i<48;i++){
						read(fd1,&c,1);
					}
					while(1){
						read(fd1,&c,1);
						if(c=='<')
							break;
						else{
							len = strlen(salida);
							salida[len] = c;
							salida[len+1] = (char)NULL;
						}
					}
					len = strlen(salida);
					salida[len] = ',';
					salida[len+1] = (char)NULL;
					strcat(salida,",,,,,,,,,,,,,,,,,,,,,,,,,* My Contacts,* ,");
					strcat(salida,sal);
					len = strlen(salida);
					salida[len] = ',';
					salida[len+1] = ',';
					salida[len+2] = (char)NULL;
					write(fd2, &salida, strlen(salida));
				}
			}
			/*  TELEFONO  */
			else if(c=='T'){
				read(fd1,&a,1);read(fd1,&b,1);read(fd1,&c,1);
				if(a=='e' && b=='l' && c=='&'){
					memset(salida, '\0', sizeof(salida));
					while(1){
						read(fd1,&c,1);
						if(c==':')
							break;
					}
					for(i=0;i<48;i++){
						read(fd1,&c,1);
					}
					while(1){
						read(fd1,&c,1);
						if(c=='<')
							break;
						else if(c==' '){}
						else{
							len = strlen(salida);
							salida[len] = c;
							salida[len+1] = (char)NULL;
						}
					}
					write(fd2, &salida, strlen(salida));
				}
			}
			else{}
		}
		
		close(fd1);
		if(n<142){
			c = '\n';
			write(fd2, &c, 1);
		}
	}
	
	close(fd2);
	close(fd3);
	return 0;
}
