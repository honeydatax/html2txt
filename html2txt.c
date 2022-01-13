#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	int n;
	char *c;
	char *cc;
	char *ccc;
	char *cccc;
	FILE* f;
	int style=0;
	int r=0;
		if(argc>1){
			f=fopen(argv[1],"r");
			if (f!=NULL){
				fseek(f,0,SEEK_END);
				n=ftell(f);
				if(n<5000008){
					fseek(f,0,SEEK_SET);
					c=malloc(n+5);
					if (c!=NULL){
						style=0;
						c[0]=0;
						fread(c,n,1,f);
						c[n]=0;
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
							cc=strstr(ccc,"BODY");
							if(cc!=NULL && cc-ccc<3)style=1;
							cc=strstr(ccc,"body");
							if(cc!=NULL && cc-ccc<3)style=1;
							cc=strstr(ccc,"Body");
							if(cc!=NULL && cc-ccc<3)style=1;

							cc=strstr(ccc,">");
							if(cc!=NULL){
								ccc=cc+1;
								r=0;
							}else{
								r=1;
							}
						}
						free(c);
					}
				}
			}
		}
	return 0;
}
