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

private:
    string hostname_to_ip(char * hostname )
{
    if (isLocal==1){
        //cout<<"local host"<<endl;
        return "127.0.0.1";
    }
	struct hostent *he;
	struct in_addr **addr_list;
	int i;
		
	if ( (he = gethostbyname( hostname ) ) == NULL) 
	{
		// get the host info
		herror("gethostbyname");
		return "None";
	}

	addr_list = (struct in_addr **) he->h_addr_list;
	
	for(i = 0; addr_list[i] != NULL; i++) 
	{
		//Return the first one;
        //cout<<inet_ntoa(*addr_list[i])<<endl;
        //cout<<"not local host"<<endl;
		return inet_ntoa(*addr_list[i]);
	}
	//cout<<"oof local host"<<endl;
	return "127.0.0.1";
}
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *key = "";
    char buffer[4096] = {0};
    bool Auth = 0;
};
void *Client::Auth_(string key)
{
    send(sock, key.c_str(), strlen(key.c_str()), 0);
    valread = recv(sock, &buffer, 1024,0);
    if ((strcmp(buffer,"Null")==0)||(strcmp(buffer,"0")==0)){
        cout<<"Key is invalid"<<endl;
        exit(0);
    }
    //cout<<buffer<<endl;
    //cout<<"You have been auth by the Reltt Server"<<endl;
}
Client::Client()
{

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, this->hostname_to_ip("auth.reltt.ovh").c_str(), &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        //return -1;
    }
    //cout<<this->hostname_to_ip("auth.reltt.ovh")<<endl;
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        //return -1;
    }
}