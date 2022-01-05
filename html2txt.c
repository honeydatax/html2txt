#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	int n;
	char c[2080];
	char *cc;
	char *ccc;
	char *cccc;
	FILE *f;
	int r=0;
		f=fopen("/dev/stdin","r");
		if (f!=NULL){
			while(feof(f)!=1){
				strcpy(c,"");
				fgets(c,2070,f);
				r=0;
				ccc=c;
				while(r!=1){
					cc=strstr(ccc,"<");
					if(cc!=NULL){
						cccc=cc+1;
						cc[0]=0;
					}else{
						r=1;
					}
						printf ("%s",ccc);
						cc=strstr(cccc,">");
						if(cc!=NULL){
							cccc=cc+1;
							cc[0]=0;
						}else{
							r=1;
						}
						ccc=cccc;
				}
			}
		}
	return 0;
}