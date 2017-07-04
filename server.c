/************* server ************************/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#define  MAX_BACKLOG 20
int main()
{
   int status;
   int s,s_bind;
   struct addrinfo hints;
   struct addrinfo *servinfo;
   struct sockaddr_storage their_addr;
   memset(&hints,0,sizeof(hints));
   hints.ai_family   = AF_UNSPEC;
   hints.ai_socktype = SOCK_STREAM;
   hints.ai_flags    = AI_PASSIVE;
   printf("TCP server\n");
   if((status = getaddrinfo(NULL,"3920",&hints,&servinfo))!=0){
      fprintf(stderr,"getaffrinfo error: %s\n",gai_strerror(status));
      exit(1);

   }
   s = socket(servinfo->ai_family,servinfo->ai_socktype,servinfo->ai_protocol);
   if(s==-1){
   
       printf("socket error\n");
       exit(1); 
      
   }
   
   s_bind = bind(s,servinfo->ai_addr,servinfo->ai_addrlen);
   if(s_bind == -1){
       printf("bind error\n");
       exit(1); 
    }  
   listen(s,MAX_BACKLOG);
   int addr_size = sizeof(their_addr);
   int new_fd    = accept(s,(struct sockaddr *)&their_addr,&addr_size);
   if(new_fd!= -1)
   {
     char  msg[100];
     while(1){
      scanf("%s",msg);
      int len  = strlen(msg);
      msg[len] = '\0';
      if(send(new_fd,msg,len,0)!=len){
      
            printf("send error\n");
            return -1; 

      }                                  
     if(strcmp(msg,"q")==0){

            freeaddrinfo(servinfo);
            close(s);
            return 0;

     }
     }
   }
   printf("end server\n");
   freeaddrinfo(servinfo);
   close(s);
   return 0;

}
