#include "client.h"
int main()
{
    
         if(client_init("127.0.0.1","3920")!=0)
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

