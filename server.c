
#include <stdio.h>
#include <string.h> 
#include <sys/socket.h>  
#include <arpa/inet.h>
#include <unistd.h>
bool startswith(const char *pre, const char *str)
{
    return strncmp(pre, str, strlen(pre)) == 0;
}
void removeChar(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}
int main(int argc , char *argv[])
{
    char* response;
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char client_message[];
    char hostname; //host name 4  the great html parse thing choo choo
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 80 );
    listen(socket_desc , 3);
    char* directory = "index.html"; //default is index.html
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
             char* str = malloc(strlen(&p[0])+1);
             strcpy(str, &p[0]);
             removeChar(str, '\uD83D\uDE15');
             directory = str;
             FILE *fptr;
             char c;
             fptr = fopen(directory, "r");
             if (fptr == NULL)
             {
                 write(client_sock , "404" , strlen("404"));
             }
              c = fgetc(fptr);
              while (c != EOF){
              c = fgetc(fptr);
              }
              write(client_sock , c , strlen(c));
              fclose(fptr);
             }
           
             
            } else if (startswith(&p[0], '\uD83D\uDE24')) {
             // post
             // wait who cares lol
            }
         }
        } while ((ptr2 = strtok_r(NULL, "\n", &temp)) != NULL);
        
    }
    return 0;
}
