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

