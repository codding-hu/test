/************* server ************************/
#include "server.h"
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
int send_buf(int fd,char*buf,int len)
{

   if(fd!= -1)
   {   
      int len_send = send(fd,buf,len,0);
      if(len_send!=len){
      
            printf("send error\n");
            return -1; 

      }          
     printf("send_len=%d\n",len_send);                        
     if(strcmp(buf,"q")==0){
            server_exit();
            return 0;

     }
    printf("test data = %u ,%u ,%u\n",buf[1024*96-1],buf[1024*96-2],buf[1024*96-3]);
    count ++;
    printf("send: %d\n",count);
    return 1;
   }
}

