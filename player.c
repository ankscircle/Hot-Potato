#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#define MAX 5000
int left_arr[MAX];

int make_socket(int a, struct sockaddr_in b);

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int sockf;
struct sockaddr_in fserver;
int main(int argc, char *argv[])
{
    int sockfd, portno, n,play_n,hops,i;
    struct sockaddr_in serv_addr;
    struct hostent *server,*my;
int rand_no;
char ip_arr[MAX][255];

my=gethostent();
 
    char buffer[256];
sockf = socket(AF_INET, SOCK_STREAM, 0);
     if (sockf< 0) 
        error("ERROR opening socket");
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port = htons(portno);
    while(connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) ;



portno=make_socket(sockf,fserver);

    n = send(sockfd,&portno,sizeof(int),0);
    if (n < 0) 
         error("ERROR writing to socket");
    bzero(buffer,256);
    n = recv(sockfd,buffer,255,0);
    if (n < 0) 
         error("ERROR reading from socket");
    
    close(sockfd);
 ////////////////////
     int  newsockfd;
     socklen_t clilen;
     struct sockaddr_in  cli_addr;
     listen(sockf,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockf,(struct sockaddr *) &cli_addr,&clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");
     bzero(buffer,256);
int mast_port;
     n = recv(newsockfd,&mast_port,sizeof(int),0);
     if (n < 0) error("ERROR reading from socket");
    

     n = send(newsockfd,"I got your message",18,0);
     if (n < 0) error("ERROR writing to socket");
     close(newsockfd);
     close(sockf);
int mast_sock;
int play;
struct sockaddr_in mast_str;
mast_sock = socket(AF_INET, SOCK_STREAM, 0);
     if (mast_sock< 0) 
        error("ERROR opening socket");
 bzero((char *) &mast_str, sizeof(mast_str));
    mast_str.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&mast_str.sin_addr.s_addr,
         server->h_length);
    mast_str.sin_port = htons(mast_port);
    while(connect(mast_sock,(struct sockaddr *) &mast_str,sizeof(mast_str)) < 0);

n = recv(mast_sock,&play,sizeof(int),0);
     if (n < 0) error("ERROR reading from socket");
printf("Connected as player %d\n",play);

int left_port,left_s;
struct sockaddr_in leftsock;
left_s = socket(AF_INET, SOCK_STREAM, 0);
if (left_s< 0) 
        error("ERROR opening socket");

left_port=make_socket(left_s,leftsock);



n = send(mast_sock,&left_port,sizeof(int),0);
     if (n < 0) error("ERROR writing to socket");

n = recv(mast_sock,&play_n,sizeof(int),0);
     if (n < 0) error("ERROR writing to socket");

n = recv(mast_sock,&hops,sizeof(int),0);
     if (n < 0) error("ERROR writing to socket");


int j;
for(j=1;j<=play_n;j++)
n = recv(mast_sock,&left_arr[j],sizeof(int),0);
     if (n < 0) error("ERROR writing to socket");


for(j=1;j<=play_n;j++)
n = recv(mast_sock,&ip_arr[j],256*sizeof(char),0);
     if (n < 0) error("ERROR writing to socket");

if(play_n==1 && hops==1)
{
/*char k='r';
n = send(mast_sock,&k,sizeof(char),0);
     if (n < 0) error("ERROR writing to socket");
printf("I'm it\n");
		char fini='f';
		l=l+1;
		n = send(mast_sock,&fini,sizeof(char),0);
		if (n < 0) error("ERROR writing to socket");
		n = send(mast_sock,&l,sizeof(int),0);
		if (n < 0) error("ERROR writing to socket");
		for(i=0;i<l+1;i++)
		{
		n = send(mast_sock,&potato[i],sizeof(int),0);
     		if (n < 0) error("ERROR writing to socket");
		//if(n>0) printf("data\n");
	
*/
exit(1);
}
/////*starts...........ring 

int right_sock,left_sock;
struct sockaddr_in righ,lef;
struct hostent *right_ent;

if(play==1)
{
if(play!=play_n)
{
      right_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (right_sock< 0) 
        error("ERROR opening socket");
     right_ent= gethostbyname(ip_arr[play+1]);
    if (right_ent == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &righ, sizeof(righ));
    righ.sin_family = AF_INET;
    bcopy((char *)right_ent->h_addr,(char *)&righ.sin_addr.s_addr,right_ent->h_length);
    righ.sin_port = htons(left_arr[play+1]);
    while(connect(right_sock,(struct sockaddr *) &righ,sizeof(righ)) < 0) ;
       
}
else if(play==play_n)
{
      right_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (right_sock< 0) 
        error("ERROR opening socket");
     right_ent= gethostbyname(ip_arr[1]);
    if (right_ent == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &righ, sizeof(righ));
    righ.sin_family = AF_INET;
    bcopy((char *)right_ent->h_addr, 
         (char *)&righ.sin_addr.s_addr,right_ent->h_length);
    righ.sin_port = htons(left_arr[1]);
    while(connect(right_sock,(struct sockaddr *) &righ,sizeof(righ)) < 0); 
        


}

listen(left_s,3);
clilen = sizeof(lef);

     left_sock = accept(left_s,(struct sockaddr *) &lef,&clilen);
     if (left_sock < 0) 
          error("ERROR on accept");
else
{

if(play==1)
{
char k='r';
n = send(mast_sock,&k,sizeof(char),0);
     if (n < 0) error("ERROR writing to socket");
}}

}
else
{
listen(left_s,3);
clilen = sizeof(lef);

     left_sock = accept(left_s,(struct sockaddr *) &lef,&clilen);
     if (left_sock < 0) 
          error("ERROR on accept");


if(play!=play_n)
{
      right_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (right_sock< 0) 
        error("ERROR opening socket");
     right_ent= gethostbyname(ip_arr[play+1]);
    if (right_ent == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &righ, sizeof(righ));
    righ.sin_family = AF_INET;
    bcopy((char *)right_ent->h_addr, 
         (char *)&righ.sin_addr.s_addr,right_ent->h_length);
    righ.sin_port = htons(left_arr[play+1]);
    while(connect(right_sock,(struct sockaddr *) &righ,sizeof(righ)) < 0); 
        

}
else if(play==play_n)
{
      right_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (right_sock< 0) 
        error("ERROR opening socket");
     right_ent= gethostbyname(ip_arr[1]);
    if (right_ent == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &righ, sizeof(righ));
    righ.sin_family = AF_INET;
    bcopy((char *)right_ent->h_addr, 
         (char *)&righ.sin_addr.s_addr,right_ent->h_length);
    righ.sin_port = htons(left_arr[1]);
   while(connect(right_sock,(struct sockaddr *) &righ,sizeof(righ)) < 0);

}
}

//Acknowledgement of ring completed 



//receive potato from left, right players or master


while(1)
{
fd_set monito;
int readsock;
int highfd;
FD_ZERO(&monito);

highfd=mast_sock;
FD_SET(mast_sock,&monito);

if(left_sock>highfd)
highfd=left_sock;
FD_SET(left_sock,&monito);

if(right_sock>highfd)
highfd=right_sock;
FD_SET(right_sock,&monito);


struct timeval timeout;
timeout.tv_sec = 1;
timeout.tv_usec = 0;
readsock = select(highfd+1, &monito, (fd_set *) 0,(fd_set *) 0, &timeout);
if (readsock < 0) {
			perror("select");
			exit(EXIT_FAILURE);
		}
		 else if(readsock >0)
{
		if (FD_ISSET(mast_sock,&monito))
			{
		char p;
		n = recv(mast_sock,&p,sizeof(char),0);
     		
		if (n < 0) error("ERROR writing to socket");
		if(n>0 && p=='p')
		{
if(hops==1)
		{
int potato[1],l;
		printf("I'm it\n");
		char fini='f';
		l=1;
		potato[0]=play;
		n = send(mast_sock,&fini,sizeof(char),0);
		if (n < 0) error("ERROR writing to socket");
		n = send(mast_sock,&l,sizeof(int),0);
		if (n < 0) error("ERROR writing to socket");
		for(i=0;i<l;i++)
		{
		n = send(mast_sock,&potato[i],sizeof(int),0);
     		if (n < 0) error("ERROR writing to socket");
//		if(n>0) printf("data\n");
		}
}
else
{
		

time_t seco;
time(&seco);

srand(seco);
rand_no=rand();
i=(rand_no%(play*2))+1;
if(i<=play)
{
if(play!=1)
printf("Sending potato to %d\n",play-1);
else
printf("Sending potato to %d\n",play_n);
int k=play,no=1;
n = send(left_sock,&no,sizeof(int),0);
     if (n < 0) error("ERROR writing to socket");
n = send(left_sock,&k,sizeof(int),0);
     if (n < 0) error("ERROR writing to socket");
}
if(i>play)
{
if(play!=play_n)
printf("Sending potato to %d\n",play+1);
else
printf("Sending potato to 1\n");

int k=play,no=1;
n = send(right_sock,&no,sizeof(int),0);
     if (n < 0) error("ERROR writing to socket");
n = send(right_sock,&k,sizeof(int),0);
     if (n < 0) error("ERROR writing to socket");
}
}
		}
if(n>0 && p=='f')
{

close(mast_sock);
close(right_sock);
close(left_sock);
exit(EXIT_SUCCESS);

}			}
		if (FD_ISSET(left_sock,&monito))
			{
		
		int l,val;
		n = recv(left_sock,&l,sizeof(int),0);
		
     		if (n < 0) error("ERROR writing to socket");
		if(n>0)
		{	

		
		int potato[l+1];
		for(i=0;i<l;i++)
		{
		n = recv(left_sock,&val,sizeof(int),0);
     		if (n < 0) error("ERROR writing to socket");
		
		potato[i]=val;
		}
int ran_play;
potato[l]=play;
if(l==hops-1)
		{
printf("I'm it\n");
		char fini='f';
		l=l+1;
		n = send(mast_sock,&fini,sizeof(char),0);
		if (n < 0) error("ERROR writing to socket");
		n = send(mast_sock,&l,sizeof(int),0);
		if (n < 0) error("ERROR writing to socket");
		for(i=0;i<l+1;i++)
		{
		n = send(mast_sock,&potato[i],sizeof(int),0);
     		if (n < 0) error("ERROR writing to socket");
		//if(n>0) printf("data\n");
		}
				}
else
{
time_t seco;
time(&seco);
srand(seco);
rand_no=rand();
ran_play=(rand_no%(play*2))+1;
//printf("Random play: %d\n",ran_play);
if(ran_play<=play)
{
if(play!=1)
printf("Sending potato to %d\n",play-1);
else
printf("Sending potato to %d\n",play_n);

int k=play,no=l+1;
n = send(left_sock,&no,sizeof(int),0);
     if (n < 0) error("ERROR writing to socket");
for(i=0;i<l+1;i++)
		{
		n = send(left_sock,&potato[i],sizeof(int),0);
     		if (n < 0) error("ERROR writing to socket");
		}
}
if(ran_play>play)
{
if(play!=play_n)
printf("Sending potato to %d\n",play+1);
else
printf("Sending potato to 1\n");

int k=play,no=l+1;
n = send(right_sock,&no,sizeof(int),0);
     if (n < 0) error("ERROR writing to socket");
for(i=0;i<l+1;i++)
		{
		n = send(right_sock,&potato[i],sizeof(int),0);
     		if (n < 0) error("ERROR writing to socket");
		}
}		
		}
		
}			}
		if (FD_ISSET(right_sock,&monito))
			{
		
		int l,val;
		n = recv(right_sock,&l,sizeof(int),0);
     		if (n < 0) error("ERROR writing to socket");
		if(n>0)
		{

		
		int potato[l+1];
		for(i=0;i<l;i++)
		{
		n = recv(right_sock,&val,sizeof(int),0);
     		if (n < 0) error("ERROR writing to socket");
		//printf("%d : %d\n",i,val);
		potato[i]=val;
		}
int ran_play;
potato[l]=play;
if(l==hops-1)
		{
		printf("I'm it\n");
		char fini='f';
		l=l+1;
		n = send(mast_sock,&fini,sizeof(char),0);
		if (n < 0) error("ERROR writing to socket");
		n = send(mast_sock,&l,sizeof(int),0);
		if (n < 0) error("ERROR writing to socket");
		for(i=0;i<l+1;i++)
		{
		n = send(mast_sock,&potato[i],sizeof(int),0);
     		if (n < 0) error("ERROR writing to socket");
		//if(n>0) printf("data\n");
		}
		
		}
else
{
time_t seco;
time(&seco);
srand(seco);
rand_no=rand();
ran_play=(rand_no%(play*2))+1;
//printf("Random play: %d\n",ran_play);
if(ran_play<=play)
{
if(play!=1)
printf("Sending potato to %d\n",play-1);
else
printf("Sending potato to %d\n",play_n);

int k=play,no=l+1;
n = send(left_sock,&no,sizeof(int),0);
     if (n < 0) error("ERROR writing to socket");
for(i=0;i<l+1;i++)
		{
		n = send(left_sock,&potato[i],sizeof(int),0);
     		if (n < 0) error("ERROR writing to socket");
		}
}
if(ran_play>play)
{
if(play!=play_n)
printf("Sending potato to %d\n",play+1);
else
printf("Sending potato to 1\n");


int k=play,no=l+1;
n = send(right_sock,&no,sizeof(int),0);
     if (n < 0) error("ERROR writing to socket");
for(i=0;i<l+1;i++)
		{
		n = send(right_sock,&potato[i],sizeof(int),0);
     		if (n < 0) error("ERROR writing to socket");
		}
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

}
}
return 0;
}
