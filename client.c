#include "client.h"
int client_init(char*addr,char*port)
{
   memset(&hints,0,sizeof(hints));
   hints.ai_family   = AF_UNSPEC;
   hints.ai_socktype = SOCK_STREAM;
   hints.ai_flags    = AI_PASSIVE;
   printf("TCP client\n");
   if((status = getaddrinfo(addr,port,&hints,&servinfo))!=0){
      fprintf(stderr,"getaffrinfo error: %s\n",gai_strerror(status));
      return -1;
   }  
   s = socket(servinfo->ai_family,servinfo->ai_socktype,servinfo->ai_protocol);
   if(s==-1){

       printf("socket error\n");
       return -1;

   }
   while(1){
   if(connect(s,servinfo->ai_addr,servinfo->ai_addrlen)==-1){
  
       printf("connect failed , try again!\n");
       sleep(1);       
   }
   else
    {
         break;
    
	} 
   }
   printf("conect success!\n"); 
   return 0;
   

}
int client_exit()
{



        freeaddrinfo(servinfo);
        close(s);
        return 0;
}
int rev_buf(int s,char*buf)
{

  
        int len =  recv(s,buf,100,0);
        if(len==0)
        {
            return 0;
        }
        buf[len] = '\0';
        printf("clinet : received %s \n",buf);
        if(strcmp(buf,"q")==0)
        {
        client_exit();
        return 0;  
        }
        return 1;
}
