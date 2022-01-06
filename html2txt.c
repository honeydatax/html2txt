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
	int style=0;
	int r=0;
		f=fopen("/dev/stdin","r");
		if (f!=NULL){
			style=0;
			while(feof(f)!=1){
				strcpy(c,"");
				fgets(c,2070,f);
				r=0;
				ccc=c;
				while(r!=1){
					cc=strstr(ccc,"<");
					if(cc!=NULL){
						cccc=ccc;
						ccc=cc+1;
						cc[0]=0;
					}else{
						cccc=ccc;
						r=1;
					}
						if(style==1)printf("%s",cccc);
						cc=strstr(ccc,"body");
						if(cc-ccc<3)style=1;
						cc=strstr(ccc,"BODY");
						if(cc-ccc<3)style=1;
						cc=strstr(ccc,">");
						if(cc!=NULL){
							ccc=cc+1;
							r=0;
						}else{
							r=1;
						}
				}
			}
		}
	return 0;
}