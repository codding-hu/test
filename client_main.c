#include "client.h"
int main()
{
    
         if(client_init("192.168.0.105","3920")!=0)
         {
    
                printf("client_init failed\n");
                return 0;
         }
    
          while(1)
         {
    
    
          int  len=rev_buf(s,buf);
          printf("len = %d\n",len);
          printf("test data = %u ,%u ,%u\n",buf[1024*96-1],buf[1024*96-2],buf[1024*96-3]);
   
        }
        return 0;
    }

