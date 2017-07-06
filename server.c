/************* server ************************/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdlib.h>
#define  MAX_BACKLOG 20
int status;
int s,s_bind;
struct addrinfo hints;
struct addrinfo *servinfo;
struct sockaddr_storage their_addr;
int addr_size ;
int new_fd    ;
char  msg[100];
int server_init(char *port);
int server_exit();
int send_buf(int fd,char*buf);
int server_init(char * port)
{
   memset(&hints,0,sizeof(hints));
   hints.ai_family   = AF_UNSPEC;
   hints.ai_socktype = SOCK_STREAM;
   hints.ai_flags    = AI_PASSIVE;
   printf("TCP server\n");
   if((status = getaddrinfo(NULL,port,&hints,&servinfo))!=0){
      fprintf(stderr,"getaffrinfo error: %s\n",gai_strerror(status));
      return -1;

   }
   s = socket(servinfo->ai_family,servinfo->ai_socktype,servinfo->ai_protocol);
   if(s==-1){
   
       printf("socket error\n");
       return -1;      

   }
   
   s_bind = bind(s,servinfo->ai_addr,servinfo->ai_addrlen);
   if(s_bind == -1){
       printf("bind error\n");
       return -1;
    }  
   listen(s,MAX_BACKLOG);
   addr_size = sizeof(their_addr);
   new_fd    = accept(s,(struct sockaddr *)&their_addr,&addr_size);
   printf("client connect!\n");
   return 0;

}
int server_exit()
{

            printf("server exit!\n");
            freeaddrinfo(servinfo);
            close(s);

}
int send_buf(int fd,char*buf)
{

   if(fd!= -1)
   {
      scanf("%s",msg);
      int len  = strlen(msg);
      buf[len] = '\0';
      if(send(fd,buf,len,0)!=len){
      
            printf("send error\n");
            return -1; 

      }                                  
     if(strcmp(msg,"q")==0){
            server_exit();
            return 0;

     }
    return 1;
   }

}
int main()
{

  if(server_init("3920")!=0)
  {

         printf("server_init error!\n");
         return -1;
  }

  while(1)
  {
   if( send_buf(new_fd,msg)<=0)
   {
       break;
   }
  
  } 
 return 0;

}
