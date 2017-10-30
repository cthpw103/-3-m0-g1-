/*
this only works on posix systems beacuse fuck bsd amrite??????
no i'm actually just lazy
*/
#include <stdio.h>
#include <string.h> 
#include <sys/socket.h>  
#include <arpa/inet.h>
#include <unistd.h>
bool startswith(const char *pre, const char *str)
{
    return strncmp(pre, str, strlen(pre)) == 0;
}
int main(int argc , char *argv[])
{
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[];
    char hostname; //host name 4  the great html parse thing choo choo
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 80 );
    listen(socket_desc , 3);
    c = sizeof(struct sockaddr_in);
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    while((read_size = recv(client_sock , client_message , 2000 , 0)) > 0)
    {
        char buf[] = client_message;
        //be amazed
        int i = 0;
        char *p = strtok (buf, ":");
        char *ah[];
        char *ptr2, *temp;
        ptr2 = strtok_r(str, "\n", &temp);
        do {
         while (p != NULL) {    
            array[i++] = p;
            p = strtok (NULL, ":");
            if (p[0] = '\uD83D\uDE0C') {
             hostname = p[1];
             // doesnt even needs hostname lol
            } //since arrays doesnt starts at one ( this is hostname i guess /_(._.)_\ (why do you even need this) ) 
            if (startswith(&p[0], '\uD83D\uDE15')) {
             // get
             // uuuhhhhh 
             
            } else if (startswith(&p[0], '\uD83D\uDE24')) {
             // post
             // wait who cares lol
            }
            write(client_sock , "001 Specified hostname is not server's hostname" , strlen(msg));
         }
        } while ((ptr2 = strtok_r(NULL, "\n", &temp)) != NULL);
        
        //insert hackery stuff and use this:
        //write(client_sock , msg , strlen(msg));
    }
    return 0;
}
