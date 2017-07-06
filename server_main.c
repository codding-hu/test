#include "include.h"

void    *ring;
int     user1;
int     user2;

char data[1024];

unsigned debug_level = 7;

void *test_in(void *p){
    while(1){
        ringfifo_api_put( ring, data, 1024 );
        usleep(90000);
        DLLOGV("---->1");
    }
}

void *test_out(void *p){
    char    tv_data[1024];
    int     i;
    while(1){
        ringfifo_api_get( ring, user1, tv_data, 1024 );
        for( i=0; i<1024; i++ )
            if( data[i] != tv_data[i] )
                DLLOGE("DATA error : %d", i );
        usleep(1000000);
        DLLOGV("---->2");
    }
}

void *test_out2(void *p){
    char    tv_data[1024];
    int     i;
    int     j = 300;
    while( j-- ){
        ringfifo_api_get( ring, user2, tv_data, 1024 );
        for( i=0; i<1024; i++ )
            if( data[i] != tv_data[i] )
                DLLOGE("DATA error : %d", i );
        usleep(10000);
        DLLOGV("---->3");
    }
    ringfifo_api_user_del( ring, user2 );
}

int main( int argc, char *argv ){
    pthread_t   tv_thrd_id;
    int         i;

    srand((unsigned)time(NULL));
    for( i=0; i<1024;i++ )
        data[i] = i%2;
    ring = ringfifo_api_create( 1600*2, 2 );
    user1 = ringfifo_api_user_add( ring );
    user2 = ringfifo_api_user_add( ring );
    pthread_create( &tv_thrd_id, NULL, test_in, NULL );
    pthread_create( &tv_thrd_id, NULL, test_out2, NULL );
    pthread_create( &tv_thrd_id, NULL, test_out, NULL );
    pthread_join( tv_thrd_id, NULL );

    return 0;
}

/*int main()
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
*/
