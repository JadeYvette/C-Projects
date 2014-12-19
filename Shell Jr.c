#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h> 
#include <string.h> 
#include <errno.h> 
#include <unistd.h>   
#include <sys/types.h>
#include <sys/wait.h>
#include <err.h>



#define MAX_LEN 1024

int main(int argc, char *argv[]) {
   FILE *input; 
   pid_t result;
   char buffer[MAX_LEN];
   char command_function[MAX_LEN] = "";
   char dir[MAX_LEN] = "" ;
   char extra[MAX_LEN] = "" ;
   char *cmd[3];
   int count = 0;


 while(1 && count == 0) { 
     
     while (waitpid(-1, NULL, WNOHANG) > 0); 
   

   if (argc == 1) {
      input = stdin;   /* standard input */
   } else if (argc == 2) { 
      /* Using file provided by the user */
       input = fopen(argv[1], "r");
         
   } 
       if(count == 0){
        printf("shell_jr: "); 
        fflush(stdout);
       }
         
   /* checking for end of file */
   while(fgets(buffer, MAX_LEN + 1, input) != NULL){
         sscanf(buffer,"%s %s %s",command_function,dir,extra);


       if((result = fork()) < 0){
                
            err(EX_OSERR,"fork error");

           }

        if(result == 0){
          
               if(strcmp("exit",command_function) == 0 || 
                  strcmp("hastalavista",command_function) == 0 ){

                     printf("See you\n");
                     exit(0);
               }

                       
               if(strcmp("cd",command_function) == 0){
                          chdir(dir);
                          
                         

                          }else{
                                 cmd[0] = command_function;

                                  if(strcmp("",dir) == 0){
                                         cmd[1] = NULL;   
                                    }else{
                                           cmd[1] = dir;
                                           cmd[2] = NULL;
                               
                                          }
                 
                           execvp(cmd[0],cmd); 
                           
                           printf("Failed to execute %s",buffer);
                           fflush(stdout);
                           exit(71);

                          }
                            
                         
                         exit(0);
                        } else{
                               wait(NULL);

                               if(strcmp("exit",command_function) == 0 || 
                                  strcmp("hastalavista",command_function) == 0 ){
                                  exit(0);
                               }

                               if(strcmp("cd",command_function) == 0){
                                  chdir(dir);

                                 }
                            
                           } 

                         printf("shell_jr: "); 
                         fflush(stdout);

                    }

              fclose(input);
              count = 1;
                            
  
     }
    return 0;

}