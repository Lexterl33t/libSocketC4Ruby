#include "ruby.h"
#include "extconf.h"
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>



//VALUE is object in rb

VALUE tcp_socket_client(VALUE self, VALUE ip, VALUE port) {

    int sock;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        printf("Socket error\n");
        return Qnil;
    }
    
    struct sockaddr_in server;

    server.sin_addr.s_addr = inet_addr(RSTRING_PTR(ip));
    server.sin_port = htons(atoi(RSTRING_PTR(port)));
    server.sin_family = AF_INET;

    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0){
        
        return INT2FIX(1);
    }

    printf("Connected\n");
    //use RSTRING_PTR to convert date in C to string in ruby
    return Qnil;
}

void Init_socket_rb_c()
{
    //rb_define_global_function(name function in ruby, name function in C , number of param)
    rb_define_global_function("tcp_socket_client", tcp_socket_client, 2);
}