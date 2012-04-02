/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#define MAX 5000
struct info
{
int fd;
int mast_port;
int left_port;
char * ipadd;
};
int left_arr[MAX];
struct info Play_list[MAX];

void error(const char *msg)
{
    perror(msg);
    exit(1);
}
int make_socket(int a, struct sockaddr_in b);
int sockf;
struct sockaddr_in fserver;
int main(int argc, char *argv[])
{
setbuf(stdout,NULL);
     int sockfd, newsockfd,play_n,hops,i;
char ip_arr[MAX][255];
long int portno;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
struct hostent *out_h;
     if (argc < 4) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
play_n=atoi(argv[2]);
hops=atoi(argv[3]);

char hostn[255];
gethostname(hostn,sizeof(hostn));
printf("Potato Master on %s \nPlayers = %d\nHops = %d\n",hostn,play_n,hops);

if(play_n<=1)
{
printf("ERROR: Enter Valid values for Players \n");
if(hops<0)
printf("ERROR: Enter Valid values for hops \n");

exit(EXIT_SUCCESS);
}
if(hops<0)
{
printf("ERROR: Enter Valid values for hops \n");
exit(EXIT_SUCCESS);
}
    
///

 sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,play_n);
     clilen = sizeof(cli_addr);

int count=0;
while(count!=play_n)
{
count++;
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");
     bzero(buffer,256);
int port_n;
     n = recv(newsockfd,&port_n,sizeof(int),0);
     if (n < 0) error("ERROR reading from socket");
     


     n = send(newsockfd,"I got your message",18,0);
     if (n < 0) error("ERROR writing to socket");


    struct hostent *server;
int sockc;
    
   
        sockc = socket(AF_INET, SOCK_STREAM, 0);
    if (sockc < 0) 
        error("ERROR opening socket");
char *ip;
ip=inet_ntoa(cli_addr.sin_addr);

    server = gethostbyname(ip);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(port_n);
    while(connect(sockc,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0);
        
sockf = socket(AF_INET, SOCK_STREAM, 0);
     if (sockf< 0) 
        error("ERROR opening socket");
int cli_port;
Play_list[count].mast_port=make_socket(sockf,fserver);


    
   n = send(sockc,&Play_list[count].mast_port,sizeof(int),0);
    if (n < 0) 
         error("ERROR writing to socket");
    bzero(buffer,256);
    n = recv(sockc,buffer,255,0);
    if (n < 0) 
         error("ERROR reading from socket");
   
    close(sockc);
   // return 0;
listen(sockf,play_n);
     clilen = sizeof(cli_addr);
Play_list[count].fd = accept(sockf, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (Play_list[count].fd < 0) 
          error("ERROR on accept");


out_h = gethostbyaddr((char *)&cli_addr.sin_addr,sizeof(struct in_addr), AF_INET);

printf("player %d is on %s\n",count,out_h->h_name);

n = send(Play_list[count].fd,&count,sizeof(int),0);
    if (n < 0) 
         error("ERROR writing to socket");
int left;
n = recv(Play_list[count].fd,&Play_list[count].left_port,sizeof(int),0);
     if (n < 0) error("ERROR reading from socket");


char *ipcpy=(char *)malloc(255);
ipcpy=inet_ntoa(cli_addr.sin_addr);
strcpy(ip_arr[count],ipcpy);


n = send(Play_list[count].fd,&play_n,sizeof(int),0);
     if (n < 0) error("ERROR writing to socket");

n = send(Play_list[count].fd,&hops,sizeof(int),0);
     if (n < 0) error("ERROR writing to socket");
}

if(play_n==1)
exit(1);


//left port array creation

for(i=1;i<=play_n;i++)
{
left_arr[i]=Play_list[i].left_port;
}

for(i=1;i<=play_n;i++)
{
int j;
for(j=1;j<=play_n;j++)
n=send(Play_list[i].fd,&left_arr[j],sizeof(int),0);
if (n < 0) error("ERROR writing to socket");
}


for(i=1;i<=play_n;i++)
{
int j;
for(j=1;j<=play_n;j++)
n=send(Play_list[i].fd,&ip_arr[j],256*sizeof(char),0);
if (n < 0) error("ERROR writing to socket");
}
char check_ring;
n = recv(Play_list[1].fd,&check_ring,sizeof(char),0);

int rand_no;
time_t seco;
time(&seco);

srand(seco);
rand_no=rand();
i=(rand_no%play_n)+1;

if(hops==0)
{
printf("All players present, not sending potato\n");
for(i=1;i<=play_n;i++)
{
char last_m='f';
n=send(Play_list[i].fd,&last_m,sizeof(char),0);
if (n < 0) error("ERROR writing to socket");
}
for(i=1;i<=play_n;i++)
close(Play_list[i].fd);
exit(EXIT_SUCCESS);
}
char p='p';
printf("All players present, sending potato to player %d\n" ,i);
n=send(Play_list[i].fd,&p,sizeof(char),0);
if (n < 0) error("ERROR writing to socket");

//get potato from player....




while(1)
{
fd_set monito;
int readsock;
int highfd=0;
FD_ZERO(&monito);

for(i=1;i<=play_n;i++)
{
FD_SET(Play_list[i].fd,&monito);

if(Play_list[i].fd>highfd)
highfd=Play_list[i].fd;

}

struct timeval timeout;
timeout.tv_sec = 1;
timeout.tv_usec = 0;
readsock = select(highfd+1, &monito, (fd_set *) 0,(fd_set *) 0, &timeout);
if (readsock < 0) {
			perror("select");
			exit(EXIT_FAILURE);
		}
		 else if(readsock>0)
{
		
		
		for(i=1;i<=play_n;i++)
{
if (FD_ISSET(Play_list[i].fd,&monito))
			{
char fini;
int l,val;
n = recv(Play_list[i].fd,&fini,sizeof(char),0);
if (n < 0) error("ERROR writing to socket");
		if(n>0 && fini=='f')
		{
	n = recv(Play_list[i].fd,&l,sizeof(int),0);
if (n < 0) error("ERROR writing to socket");

if(n>0)
{
int j;
printf("Trace of potato:\n");
for(j=1;j<=l;j++)
		{
		n = recv(Play_list[i].fd,&val,sizeof(int),0);
     		if (n < 0) error("ERROR writing to socket");
		if(n>0)	
		{
		printf("%d",val);
			}
		if(j!=l)
		printf(",");
		else
		printf("\n");
		}
//sleep(1);
for(i=1;i<=play_n;i++)
{
char last_m='f';
n=send(Play_list[i].fd,&last_m,sizeof(char),0);
if (n < 0) error("ERROR writing to socket");
}
for(i=1;i<=play_n;i++)
close(Play_list[i].fd);
exit(EXIT_SUCCESS);
}
}
}
}	
}
}
}
int make_socket(int a, struct sockaddr_in b)
{
int i;

     bzero((char *) &b, sizeof(b));
b.sin_family = AF_INET;
b.sin_addr.s_addr = INADDR_ANY;

for(i=65400;i<=65500;i++)
{
     b.sin_port = htons(i);
     if (bind(a, (struct sockaddr *)&b,sizeof(b)) >= 0) 
     {return i;
printf("LISTENING...\n");
}
}
for(i=1025;i<=65535;i++)
{
     b.sin_port = htons(i);
     if (bind(a, (struct sockaddr *)&b,sizeof(b)) >= 0) 
     {return i;
printf("LISTENING...\n");
}
}
return 0;
}
