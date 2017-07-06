#include "include.h"

void    *ring;
int     user1;
int     user2;

char data[1024*96];

unsigned debug_level = 7;

void *test_in(void *p){
    while(1){

        ringfifo_api_put_block( ring, data, 1024*96 );
        usleep(90000);
       // DLLOGV("---->1");
    }
}

void *test_out(void *p){
    char    tv_data[1024*96];
    int     i;
    while(1){
        ringfifo_api_get( ring, user1, tv_data, 1024*96);
        for( i=0; i<1024*96; i++ )
           { if( data[i] != tv_data[i] )
                DLLOGE("DATA error : %d", i );
           
                 }
        
      
        DLLOGV("---->2");
        send_buf(new_fd,tv_data,1024*96);
        usleep(1000000);
    }
}

int main( int argc, char *argv ){
    pthread_t   tv_thrd_id;
    int         i;
    int         j=0;
    srand((unsigned)time(NULL));
    for( i=0; i<1024*96;i++ )
       { 
        
        data[i] = j;
        j++;
        if(j>200)
        {j=0;}
       }
    if(server_init("3920")!=0)
      {
    
             printf("server_init error!\n");
             return -1;
      }
    ring  = ringfifo_api_create( 1024*2*96, 1 );
    user1 = ringfifo_api_user_add( ring );
    pthread_create( &tv_thrd_id, NULL, test_in, NULL );
    pthread_create( &tv_thrd_id, NULL, test_out, NULL );
    pthread_join( tv_thrd_id, NULL );

    return 0;
}

