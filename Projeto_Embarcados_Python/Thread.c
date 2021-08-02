#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>

#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

#define MAX_FLOW_SIZE 1000  //Tamanho maximo do buffer de caracteres
#define true 1

char* IP_host = "192.168.137.1";
char* PORT_Recv = "1234";
char* PORT_Send = "23";

// A normal C function that is executed as a thread 
// when its name is specified in pthread_create()

void *ThSendClient(void *vargp)
{

    printf("Dentro da Thread");
    int sockId, serverPort, sentBytes, recvBytes, connId;
	//char buf[MAX_FLOW_SIZE];
	struct sockaddr_in client;
	struct hostent *hp;

    /*******************************************************************************
        Setando e testando o endereco informado (IP_host) */

	hp = gethostbyname(IP_host);
	if (((char *) hp) == NULL) {
		printf("Host Invalido: %s\n", IP_host);
		return NULL;
	}
    /*----------------------------------------------------------------------------*/

    /********************************************************************************
               Setando os atributos da estrutura do socket
    ********************************************************************************/
	memcpy((char*)&client.sin_addr, (char*)hp->h_addr, hp->h_length);
	client.sin_family = AF_INET;
	serverPort = atoi(PORT_Send);
	if (serverPort <= 0) {
		printf("Porta Invalida: %s\n", PORT_Send);
		return NULL;
	}
	client.sin_port = htons(serverPort);
    /*----------------------------------------------------------------------------*/

    /********************************************************************************
               Abrindo um socket do tipo stream (TCP)
    ********************************************************************************/
	sockId = socket(AF_INET, SOCK_STREAM, 0);
	if (sockId < 0) {
		printf("Stream socket nao pode ser aberto\n");
		return NULL;
	}
    /*----------------------------------------------------------------------------*/

    /*----------------------------------------------------------------------------*/

    int i = 1;
    char* buf; //Mensagem a ser enviada
    char NumChar[5]; //Char auxiliar para pegar o valor de int i

	while(true) 
    {
	
    /********************************************************************************
                Enviando as mensagens para o servidor
    ********************************************************************************/
        if(i % 2 == 0) //Envia P de posicao
        {
            sprintf(NumChar, "%d", i); //Convertendo int em Char
            buf = malloc(strlen("P ")+1+5); //Preparando o tamanho do buf
            strcpy(buf, "P "); /* copy name into the new var */
            strcat(buf, NumChar); /* add the extension */
        }
        else //Envia V de velocidade
        {
            sprintf(NumChar, "%d", i); //Convertendo int em Char
            buf = malloc(strlen("V ")+1+5); //Preparando o tamanho do buf
            strcpy(buf, "V "); /* copy name into the new var */
            strcat(buf, NumChar); /* add the extension */
        }

		sentBytes = send(sockId, buf, strlen(buf), 0);
		if (sentBytes < 0) {
			close(sockId);
			printf("A conexao foi perdida\n");
			return NULL;
		}
		memset(buf,0,sizeof(buf)); 
    }
/*----------------------------------------------------------------------------*/
return NULL;
}
   
int main()
{
    pthread_t thread_id;
    printf("Before Thread\n");
    pthread_create(&thread_id, NULL, ThSendClient, NULL);
    printf("Meio da Thread\n");
    pthread_join(thread_id, NULL);
    printf("After Thread\n");
    exit(0);
}