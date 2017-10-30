#include <stdio.h>
#include <string.h> 
#include <sys/socket.h>  
#include <arpa/inet.h>
 
int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[2000];
     
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 80 );
    listen(socket_desc , 3);
    c = sizeof(struct sockaddr_in);
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    while((read_size = recv(client_sock , client_message , 2000 , 0)) > 0)
    {
        //insert hackery stuff and use this:
        //write(client_sock , msg , strlen(msg));
    }
    return 0;
}
