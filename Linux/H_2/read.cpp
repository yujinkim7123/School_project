#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define BUF_SIZE 301

const char *tag[]={"\"NAME: ", "\"AGE: ", "\"HEIGHT: ", "\"POINT: ", "\"CLASS: ", "ABCF", "name: ", "age: ", "height: ", "point: ", "class: "};
char input[BUF_SIZE]={0,}, buf[BUF_SIZE]={0,};
typedef char info_t[5][BUF_SIZE];  //name, age, height, point, old_class
std::vector<info_t*> v;

static inline bool mycompare(info_t* x, info_t* y){ return atoi((*x)[3]) > atoi((*y)[3]);}

void process(info_t *info, char *str){
    printf("%s", str);
    char *b=NULL, *e=NULL, *ptr=(char *)info;
    for (unsigned int i=0; i<5; i++, ptr+=BUF_SIZE){
        b = strstr(str, tag[i]) + strlen(tag[i]);
        e = (char*)memchr(b, '\"', BUF_SIZE);
        memset(ptr, 0, sizeof(char)*BUF_SIZE);
        strncpy(ptr, b, e-b);   
    }
    v.push_back(info);
}

void printout(){
    FILE *out = fopen(strcat(input, ".recovery2"), "w");
    fprintf(out,"1. Recovered Information\n");
    fprintf(out,"Total Items: %ld\n", v.size());
    
    double a=0., h=0.;
    for (unsigned int i=0;i<v.size();i++){
        fprintf(out,"\n[%d]\n", i);
        for (unsigned int j=0;j<5;j++){
            fprintf(out,"%s", tag[j+6]);    //let's use lowercase tags
            if (j==1 || j==2 || j==3){      //age, height, point
                int var = atoi((*v[i])[j]);
                if (j!=3 && var<0) var=-var;
                if (j==1) a+=var;
                if (j==2) h+=var;
                fprintf(out,"%d\n", var);
            }
            else if (j==4){ //class
                char old_c = (*v[i])[j][0]>='a' ? (*v[i])[j][0]-'a'+'A' : (*v[i])[j][0];   
                fprintf(out,"%c (<-- %c)\n", tag[5][i/(v.size()/4)], old_c);
            }
            else{   //name
                fprintf(out,"%s\n", (*v[i])[j]);
            }
        }
    }

    fprintf(out,"\n2. Statistics\n");
    fprintf(out,"avg. age = %.2f\n",a/v.size());
    fprintf(out,"avg. height = %.2f\n",h/v.size());
    fclose(out);
}

int main(int argc, char *argv[]){
    FILE *in = fopen(argv[1], "r");
    if (in == NULL){
        perror("err");
        return -1;
    }
    strcat(input,argv[1]);
    while(fgets(buf, BUF_SIZE, in)!=NULL && strlen(buf)!=1){
        process((info_t*)malloc(sizeof(info_t)), buf);
        memset(buf, 0, sizeof(char)*BUF_SIZE);        
    }
    std::sort(v.begin(), v.end(), mycompare);
    printout();
    fclose(in);
    return 0;
}