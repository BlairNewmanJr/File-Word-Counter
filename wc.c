#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
        int chars,lines,words;
        char ch;
        FILE* fp;
        fp = fopen(argv[1],"r");
        if (fp ==NULL){
                perror("error opening file");
                exit (0);
        }
        chars=lines=words=0;
        char prev;
        while((ch=fgetc(fp))!=EOF){
                chars++;
                if(ch=='\n')
                        lines++;
                if((ch==' '||ch=='\t'||ch=='\n'||ch =='\r')&&(prev!=' '&&prev!='\t'&&prev!='\n'&&prev !='\r'))
                        words++;
                prev = ch;
        }
        printf("\n%d %d %d %s\n",lines,words,chars,argv[1]);
        fclose(fp);
}
