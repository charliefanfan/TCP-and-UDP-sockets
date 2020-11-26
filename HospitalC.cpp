#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include<string>
#include<cstring>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include<functional>
#include <netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<fstream>
#define PORT 6334
#define DPORT 21634
using namespace std;



char local_adrress;

int main(int argc, char const *argv[])
{
int sock = 0, valread,valread1;
struct sockaddr_in serv_addr;
char buffer[1024] = {0};
char buffer2[1024]= {0};
char buffer3[1024]={0};
char ip[100];
if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
{
printf("\n Socket creation error \n");
return -1;
}


serv_addr.sin_family = AF_INET;
serv_addr.sin_port = htons(PORT);

// Convert IPv4 and IPv6 addresses from text to binary form
if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
{
printf("\nInvalid address/ Address not supported \n");
return -1;
}

if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
{
printf("\nConnection Failed \n");
return -1;
}
struct sockaddr_in serv;
serv.sin_port=0;
serv.sin_addr.s_addr='0.0.0.0';
socklen_t servlen=sizeof(serv);
bind(sock,(struct sockaddr *)&serv ,servlen);
getsockname(sock, (struct sockaddr *)&serv,&servlen);
inet_ntop(AF_INET,&serv_addr.sin_addr,ip, sizeof(ip));
char *some_addr;
inet_aton(  *argv ,&serv_addr.sin_addr);
some_addr=inet_ntoa(serv_addr.sin_addr);
cout<<"<HospitalC> has TCP port "<<ntohs(serv.sin_port)<<" and IP address "<<ip<<" for the Phase 1"<<endl;
cout<<"<Hospital C> is now connected to the health center"<<endl;
//discover
char line[50],line1[50],line2[50];  
ifstream file("HospitalC.txt");   //read the text
file>>line>>line1>>line2;      //store the data in the text
int a,b,c;
char which[2]="C";


if(a=(send(sock,line,50,0))>0){
cout<<"<Hospital C> has sent <C1> to the health center"<<endl;}
if(b=(send(sock,line1,50,0))>0){
cout<<"<Hospital C> has sent <C2> to the health center"<<endl;}
if(c=(send(sock,line2,50,0))>0){
cout<<"<Hospital C> has sent <C3> to the health center"<<endl;}
if(a>0&&b>0&&c>0){
send(sock,which,strlen(which),0);
cout<<"Updating the health center is done for <Hospital C>"<<endl;}

close(sock);
cout<<"End of Phase 1 for <Hospital C>"<<endl;
int sock1;
if ((sock1 = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
perror("udp socket");
struct sockaddr_in clientudp;
memset(&clientudp, 0, sizeof(clientudp));
clientudp.sin_family = AF_INET;
clientudp.sin_port = htons(21634);
clientudp.sin_addr.s_addr = htons(INADDR_ANY);
if (bind(sock1, (struct sockaddr *)&clientudp, sizeof(clientudp)) < 0)
perror("udp bind");
char rec[1024] = {0};
struct sockaddr_in peer;
socklen_t peerlen;
int n,t;
peerlen = sizeof(peer);
t=recvfrom(sock1, rec, 1024, 0, (struct sockaddr *)&peer, &peerlen);
cout<<"<HospitalC> has UDP port " <<DPORT<<" and IP address "<< ip<<" for Phase 2"<<endl;
cout<<"<Student"<<rec<<">"<<" has been admitted to <HospitalC>"<<endl;
t=recvfrom(sock1, rec, 1024, 0, (struct sockaddr *)&peer, &peerlen);
cout<<"<Student"<<rec<<">"<<" has been admitted to <HospitalC>"<<endl;
t=recvfrom(sock1, rec, 1024, 0, (struct sockaddr *)&peer, &peerlen);
cout<<"<Student"<<rec<<">"<<" has been admitted to <HospitalC>"<<endl;

return 0;
}
