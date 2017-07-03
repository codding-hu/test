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
   printf("TCP client\n");
   if((status = getaddrinfo("127.0.0.1","3920",&hints,&servinfo))!=0){
      fprintf(stderr,"getaffrinfo error: %s\n",gai_strerror(status));
      exit(1);
   }  
   s = socket(servinfo->ai_family,servinfo->ai_socktype,servinfo->ai_protocol);
   if(s==-1){

       printf("socket error\n");
       exit(1);

   }
   if(connect(s,servinfo->ai_addr,servinfo->ai_addrlen)==-1){
  
       printf("connect failed\n");

   }
   char buf[100];
   while(1){
        int len =  recv(s,buf,100,0);
        buf[len] = '\0';
        printf("clinet : received %s \n",buf);
        if(strcmp(buf,"q")==0)
        {

        freeaddrinfo(servinfo);
        close(s);
        return 0;  
        }
   }
        freeaddrinfo(servinfo);
        close(s);
    /*************/
   return 0;
   

}
