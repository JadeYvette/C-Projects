
rdint   %eax                                 #task
irmovl $1, %ecx                              #holds 1 for if statement
irmovl $2, %edx       						 #holds 2 for if statment
subl  %eax, %ecx      						 #checked if task equaled 1
je firstif            						 #if it equals 1 jump in the if
subl %eax, %edx                              #check if task equaled 2
je firstif           						 #if it equaled 1 jump in the if
irmovl $1, %ecx       						 #random move figuring it out
irmovl $1, %edx
jmp intro             						 # skips the if statment




firstif:            rdint %ecx               #ecx is now the encode value
                    jmp intro

intro:              rdch  %edi               # reads in val 
                    irmovl $32, %edx         #checks \n
                    subl %edi,%edx
                    je intro                #goes again if \
                    jmp checkcond

checkcond:          irmovl $10, %ebx         # moves 10 to ebx
					subl %edi, %ebx          # checks ifvalue \n
					je bottom

                      

 whileloop:          irmovl $1, %edx        #moves 1 to edx
                     subl %eax, %edx        #checks if task is 1
                     je task1               #jmps if task is 1
                     
                     irmovl $2, %edx        #moves 2 to edx
                     subl %eax, %edx        #checks if task is 2
                     je task2               #jmps if task is 2

                     irmovl $1, %ecx        #moves 1 to ecx   
                     jmp neither            #jmps because its nth
                  
                     jmp checkcond


task1:              subl %ecx,%edi  
                    jmp print 


task2:             addl %ecx,%edi
                   jmp print

neither:           irmovl $97, %edx           #checks if val is  >=a
                   subl %edi,%edx
                   jge else                   #if not greater then a jmp

                   irmovl $122, %edx          #checks if val is <=z
                   subl %eax,%edx
                   jle else                   #if not less then z jmp

                   irmovl $32, %edx
                   subl %edx, %edix             # value-= 32
                   jmp print

else:             irmovl $32, %edx
                  addl  %edx, %edix 
    

print:            wrch  %edi               #prints current value
                  rdch  %edi               #takes in new value
                  jmp checkcond            #jumps back to top of whi 

bottom:           irmovl $10, %esi         #moving the new line 
                  wrch %esi                #printing the new line 
halt









