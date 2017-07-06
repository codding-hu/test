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
    
    
          if( rev_buf(s,buf)<=0)
          {
                printf("client exit!\n");
                break;
          }
    
        }
        return 0;
    }

