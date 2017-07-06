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
int count;
struct addrinfo hints;
struct addrinfo *servinfo;
struct sockaddr_storage their_addr;
char buf[1024*96];
int rev_buf(int s,char*buf);
int client_init(char*addr,char*port);
int client_exit();
