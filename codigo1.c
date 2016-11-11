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
	char c2[10]="";
	
	char salida[120];
	
	fd1 = open("codigoHTML.txt",O_RDONLY);
	if(fd1 == -1){
		printf("Error al abrir el fichero de entrada\n");
		return -1;
	}

	fd2 = open("salida.sh",O_WRONLY);
	if(fd2 == -1){
		printf("Error al abrir el fichero de salida\n");
		return -1;
	}

	while(1){
		leido = read(fd1,&c,1);
		if(leido==0)
			break;
		else if(leido==-1){
			printf("ERROR: Read fd1\n");
			exit(-1);
		}
		else{
			if(c=='p'){
				read(fd1,&c2,10);
				if(strcmp(c2,"age-header")==0){
					while(1){
						read(fd1,&c,1);
						if(c=='h'){
							 read(fd1,&a,1);read(fd1,&b,1);read(fd1,&c,1);
							if(a=='r' && b=='e' && c=='f'){
								read(fd1,&c,1);read(fd1,&c,1);read(fd1,&c,1);read(fd1,&c,1);read(fd1,&c,1);
								memset(salida, '\0', sizeof(salida));
								strcpy(salida,"curl http://www.inf.uc3m.");
								while(1){
									read(fd1,&c,1);
									if(c=='"')
										break;
									else{
										len = strlen(salida);
										salida[len] = c;
										salida[len+1] = (char)NULL;
									}
								}
								strcat(salida," > salidas/s");
								sprintf(&c2, "%d", n);
								strcat(salida,c2);
								n++;
								strcat(salida,".txt");
								len = strlen(salida);
								salida[len] = '\n';
								salida[len+1] = (char)NULL;
								write(fd2, &salida, strlen(salida));
							}
						}
						else if(c=='!'){
							read(fd1,&a,1);read(fd1,&b,1);read(fd1,&c,1);
							if(a=='-' && b=='-' && c==' ')
								break;
						}
						else{}
					}
				}
			}
		}
	}
	
	close(fd1);
	close(fd2);
	return 0;
}

