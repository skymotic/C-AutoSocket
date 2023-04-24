#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AutoSocket.h"

#define MAXSTR 2048

void getMessage(char* buffer, size_t maxStr)
{
    bzero(buffer, maxStr);
    fgets(buffer, maxStr, stdin);
}

int main()
{
    const int port = 8090;
    const int proto = 0;
    int queueLength = 10;
    char ip[] = "127.0.0.1";

    struct AutoSocket sock;

    char* buffer = (char*)malloc(MAXSTR * sizeof(char));
    printf("Please Enter The Message You'd Like to Send:\n\t");
    getMessage(buffer, MAXSTR);

    createSocket(&sock, ip, port, proto);
    sock.lineBufferLen = MAXSTR;
    printf("[+] Socket Created!\n");

    connectToSocket(&sock);
    printf("[+] Socket Connected\n");

    sendToSocket(&sock, buffer);
    printf("[+] Message Sent!\n");

    receiveFromSocket(&sock, buffer);
    printf("Message:\n----- ----- -----\n%s\n----- ----- -----\n", buffer);
    
    closeSocket(&sock);
    printf("[+] Socket closed!\n");
}