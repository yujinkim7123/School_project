#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

struct Person{
	char  *name;
	int  age;
        int  height;
        int  point;
        char class;
};	


int main(int argc, char* argv[]){
	char buffer[300];
	char* index;
	struct Person p1[100];
	struct Person *p2[100];
	struct Person *p3;
        char str [5][10]  = { "\"NAME:", "\"CLASS:", "\"AGE:","\"HEIGHT:", "\"POINT:"}; 
	char str1[1] = {'"'};
       	int counter = 0; 
	float avgage = 0;
	float avgheight = 0;
	FILE *f = fopen(argv[1], "r");
           
          if( f== NULL){
		   printf("error occured\n");
	           printf("%s\n", strerror(errno));
			     
	    }
         
	while(fgets(buffer , 300 , f) != NULL){
		printf("%s", buffer);
                       index = buffer;      
		  
		    while(index != NULL){

 		  	index = strchr(index, '"');
                      int i = 0;
		      char rest[40] = {0,};
	            if(index != NULL){

                       if(strchr(index,' ') != NULL){
                         for(i = 0; *(index + i) != ' '; i++)
                         rest[i] = *(index + i);
			 rest[i] = '\0';  
                         index = strchr(index, ' ');
			 index++;
                       if(strcmp(rest, str[1]) == 0){
                        char a;
                             a = *(index);
                       if(97 <= *(index) && 122>= *(index))
			       a = (*(index) -'a' +'A');
                              p1[counter].class = a;
	                      index = strchr(index, '"');
			      index++;		     
		          		       }	
		      else if(strcmp(rest, str[0]) == 0){
                              char * name;  
                            name = strtok(index, str1);
                            p1[counter].name = (char*) malloc(strlen(name)+1);
                            strcpy(p1[counter].name, name);
                             index = strchr(index, '\0');
                             index++;
                       }

                     else if(strcmp(rest, str[2]) == 0){
                               char * num;                             
                          for(i = 0; *(index + i) != '"'; i++){
                                if(*(index+i) >= 49 && *(index +i) <= 57){
                                   index = index +i;
				  num = strtok(index, str1);
                                  p1[counter].age = atoi(num);
                                  index = strchr(index, '\0');
				  index++;  
                                   break;
                                }
			
                            }      
	      	     }


                     else if(strcmp(rest, str[3]) == 0){
                               char * num;
                          for(i = 0; *(index + i) != '"'; i++){
                                if(*(index+i) >= 49 && *(index +i) <= 57){
                                   index = index +i;
                                  num = strtok(index, str1);
                                  p1[counter].height = atoi(num);
                                  index = strchr(index, '\0');
                                  index++;
                                   break;
                                }

                            }
                          }
                    else if(strcmp(rest, str[4]) == 0){
                            char * num;        
                                  num = strtok(index, str1);
                                  p1[counter].point = atoi(num);
                                  index = strchr(index, '\0');
                                  index++;                             
                                }
		    else 
                        {
                           index = strchr(index, '"');
                           index++;	}				

		        } } }  counter++;}
                      
             fclose(f);
      
              	for(int i= 0; i < counter; i++){                 
                    p2[i] = &p1[i];
		     avgage += (float)p1[i].age;
		     avgheight += (float)p1[i].height;
		    
		}

		avgage = avgage / counter;
		avgheight = avgheight/ counter;
	
                for(int i = 0; i <counter; i++){
                  
                    for(int j = 0; j < counter - 1; j++){ 
                          if(p2[j]->point < p2[j + 1]->point){
                              
				  p3 = p2[j];
				  p2[j] = p2[j+1];
			          p2[j+1] = p3;	  
                                
			  } 
                           
                        }
		}
             
                    
                char s1[10] = ".recovery";
                strcat(argv[1], s1);
	
		FILE *fp = fopen(argv[1], "w+");
              	int n  = counter/4; 
              
	      	fprintf(fp,"1. Recovered information\n");
                fprintf(fp,"Total Items: %d\n\n",counter);     
                 char class[4] = {'A','B','C','F'};
		 int j = 0; 
                for(int i = 0; i < counter; i++){
                 fprintf(fp,"[%d]\n",i);
		 fprintf(fp,"name: %s\n",p2[i]->name);
                 fprintf(fp,"age: %d\n",p2[i]->age);
		 fprintf(fp,"height: %d\n",p2[i]->height);
		 fprintf(fp,"point: %d\n",p2[i]->point);
		 fprintf(fp,"class: %c ",class[j]);
		 fprintf(fp,"(<-- %c)\n\n",p2[i]->class);
		 if((i+1)%n == 0)
                       j++;

		}	
		fprintf(fp,"2. Statistics\n");
                fprintf(fp,"avg. age =  %.2f\n",avgage);
                fprintf(fp,"avg. age =  %.2f",avgheight);
                                 
}          
