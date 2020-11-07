#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	int number_of_args = argc;
	char *str=NULL;
        int integer;
        int a;		

	for(int i=1; i<number_of_args; i++){
                 str =argv[i];
		integer = atoi(str);
	

	}
			
             
           int j;
        for(j = 2; j<integer; j++){
             if(integer % j == 0){
	     break;
	       }
        	}
                               
                  if(integer == j ||integer == 2 || integer == 1){
			  a = 1;
                      printf("%d\n", a);  
                               } 

	          else {
			  a = 0;
			  printf("%d\n",a);}
	             
				  return a;
}

