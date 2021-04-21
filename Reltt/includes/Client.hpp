#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <cstdlib>
#include <netdb.h>
#include <unistd.h>

#define isLocal 0
#define PORT 5000
using namespace std;
class Client

{
public:
    Client();
    void *Auth_(string);

    string hostname_to_ip(char *);
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *key = "";
    char buffer[4096] = {0};
    bool Auth = 0;
};