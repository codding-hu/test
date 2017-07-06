#include "server.h"
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

