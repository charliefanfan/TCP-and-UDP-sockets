// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cstring>
#include<sstream>
#include <time.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <algorithm>
#include <memory.h>
#include<functional>
#include <netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<fstream>
#define PORT 6334
#define UDPPORT 21734

using namespace std;

bool check( int num,int num1,int num2)
{
return(num1<=num&&num<=num2);

}
char Ha[1024];
void Remove(char *s, char m)
{ int w=0, r=0;
	while(s[r]){
	if(s[r]!=m)
	{s[w++]=s[r];}
	r++;
	}
	s[w]=0;}
string first;

void store(char* buffer,int *number,int num1,int num2,char*name){
string f=string(buffer);
int s=f.find('#');
first=f.substr(0,s);
char *back=strstr(buffer,"#");
Remove(back,'#');
string m=string(back);
int a=m.find(',');
string second=m.substr(0,a);
char *last=strstr(back,",");
Remove(last,',');
string last1= string(last);
stringstream k(last1);
stringstream g(second);
int x,y;
k>>x;
g>>y;
number[num1]=y;
number[num2]=x;
strcpy(name, first.c_str());
} 

	

int main(int argc, char const *argv[])
{
ofstream myfile("result.txt");
int server_fd, new_socket, valread;
int read1=0,read2=0,read3=0,read4=0,read5=0,read6=0,read7=0;
struct sockaddr_in address;
int opt = 1;
int addrlen = sizeof(address);
char buffer[1024] = {0};
char buffer1[1024] = {0};
char buffer0[1024]={0};
char buffer2[1024]={0};
char buffer3[1024]={0};
char buffer5[1024]={0};
char buffer4[1024]={0};
int number[1024];
int number1[1024];
int number2[1024];
char ip[100]={0};
int count=0;
char d[2]={0};
string buff;
string trans_id;
int once=0;
int once1=0;
int once2=0;

// Creating socket file descriptor
if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
{
perror("socket failed");
exit(EXIT_FAILURE);
}

// Forcefully attaching socket to the port 8080
if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR,&opt, sizeof(opt)))
{
perror("setsockopt");
exit(EXIT_FAILURE);
}
address.sin_family = AF_INET;
address.sin_addr.s_addr = INADDR_ANY;
address.sin_port = htons( PORT );

if (bind(server_fd, (struct sockaddr *)&address,
sizeof(address))<0)
{
perror("bind failed");
exit(EXIT_FAILURE);
}
if (listen(server_fd, 3) < 0)
{
perror("listen");
exit(EXIT_FAILURE);
}


for(int c=0;c<3;c++){
if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
(socklen_t*)&addrlen))<0)
{
perror("accept");
exit(EXIT_FAILURE);
}
if(once==0){
socklen_t serv_len=sizeof(address);
if(getsockname(new_socket, (struct sockaddr *)&address ,&serv_len)==-1){
perror("getsockname");}
inet_ntop(AF_INET, &address.sin_addr,ip,sizeof(ip));
cout<<"The health center has TCP port "<<PORT<<" and IP address "<<ip<<endl;
once=3;
}


int pid;
pid=fork();
if( pid<0) perror("error fork");
if(pid==0){
close(server_fd);
if(read1 = read( new_socket , buffer, 1024)>0){
//cout<<"Received the following Transaction ID from client: "<<buffer<<endl;
count++;
}

if(read2 = read( new_socket , buffer1, 1024)>0){
//cout<<"Received the following Transaction ID from client: "<<buffer1<<endl;
count++;
}

if(read3 = read( new_socket , buffer0, 1024)>0){
//cout<<"Received the following Transaction ID from client: "<<buffer0<<endl;
count++;
}

if(count>2){
read( new_socket , d, 1024);
cout<<"Received the department list from <Hospital "<<d<<">"<<endl;

}

char name[1024];
if(d[0]=='A'){
store(buffer,number,0,1,name);
store(buffer1,number,2,3,name);
store(buffer0,number,4,5,name);
myfile<<number[0]<<" "<<number[1]<<" "<<number[2]<<" "<<number[3]<<" "<<number[4]<<" "<<number[5]<<endl;
}
if(d[0]=='B'){
char name1[1024];
store(buffer,number1,0,1,name1);
store(buffer1,number1,2,3,name1);
store(buffer0,number1,4,5,name1);
myfile<<number1[0]<<" "<<number1[1]<<" "<<number1[2]<<" "<<number1[3]<<" "<<number1[4]<<" "<<number1[5]<<endl;
}
if(d[0]=='C'){
char name2[1024];
store(buffer,number2,0,1,name2);
store(buffer1,number2,2,3,name2);
store(buffer0,number2,4,5,name2);
myfile<<number2[0]<<" "<<number2[1]<<" "<<number2[2]<<" "<<number2[3]<<" "<<number2[4]<<" "<<number2[5]<<endl;
}
close(new_socket);
exit(EXIT_SUCCESS);
}
else close(new_socket);
}
sleep(1);
cout<<"End of Phase 1 for the health center"<<endl;
myfile.close();


ifstream file("result.txt");
file>>number[0]>>number[1]>>number[2]>>number[3]>>number[4]>>number[5]>>number1[0]>>number1[1]>>number1[2]>>number1[3]>>number1[4]>>number1[5]
>>number2[0]>>number2[1]>>number2[2]>>number2[3]>>number2[4]>>number2[5];

for(int qw=0;qw<5;qw++){
if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
(socklen_t*)&addrlen))<0)
{
perror("accept");
exit(EXIT_FAILURE);
}
if(once1==0)
{
socklen_t serv_len=sizeof(address);
if(getsockname(new_socket, (struct sockaddr *)&address ,&serv_len)==-1){
perror("getsockname");}
inet_ntop(AF_INET, &address.sin_addr,ip,sizeof(ip));
cout<<"The health center has TCP port "<<PORT<<" and IP address "<<ip<<endl;
once1=3;
}
string i1;
string i2;
string i;
int pid_1;
pid_1=fork();
if( pid_1<0) perror("error fork");
if(pid_1==0){

read4 = read( new_socket , buffer2, 1024);
char *sys=strstr(buffer2,":");
Remove(sys,':');
int num1=atoi(sys);


read5 = read( new_socket , buffer3, 1024);
if(strlen(buffer3)!=0){
i1=strstr(buffer3,":");
i1.erase(0,1);}

read6 = read( new_socket , buffer4, 1024);
if(strlen(buffer4)!=0){
i2=strstr(buffer4,":");
i2.erase(0,1);}

read7 = read( new_socket , buffer5, 1024);
//e3=buffer5.empty()
if(strlen(buffer5)!=0){
i=strstr(buffer5,":");
i.erase(0,1);}
if(read5>0&&read6>0&&read7>0&&read4>0)
{
read( new_socket , d, 1024);
cout<<"health center receive the application from <Student"<<d<<">"<<endl;
}
int yes=0;
string w;
if(i1=="A1"){
	if(check(num1,number[0],number[1])==true)
	{w="A1";
	yes=1;}
}
if(i1=="A2"){
	if(check(num1,number[2],number[3])==true)
	{w="A2";
	yes=1;}
}if(i1=="A3"){
	if(check(num1,number[3],number[4])==true)
	{w="A3";
	yes=1;}
}if(i1=="B1"){
	if(check(num1,number1[0],number1[1])==true)
	{w="B1";
	yes=1;}
}if(i1=="B2"){
	if(check(num1,number1[2],number1[3])==true)
	{w="B2";
	yes=1;}
}if(i1=="B3"){
	if(check(num1,number1[4],number1[5])==true)
	{w="B3";
	yes=1;}
}if(i1=="C1"){
	if(check(num1,number2[0],number2[1])==true)
	w="C1";
	yes=1;
}if(i1=="C2"){
	if(check(num1,number2[2],number2[3])==true)
	{w="C2";
	yes=1;}
}if(i1=="C3"){
	if(check(num1,number2[4],number2[5])==true)
	{w="C3";
	yes=1;}
}
if(yes==0)
{
if(i2=="A1"){
	if(check(num1,number[0],number[1])==true)
	{w="A1";
	yes=1;}
}if(i2=="A2"){
	if(check(num1,number[2],number[3])==true)
	{w="A2";
	yes=1;}
}if(i2=="A3"){
	if(check(num1,number[3],number[4])==true)
	{w="A3";
	yes=1;}
}if(i2=="B1"){
	if(check(num1,number1[0],number1[1])==true)
	{w="B1";
	yes=1;}
}if(i2=="B2"){
	if(check(num1,number1[2],number1[3])==true)
	{w="B2";
	yes=1;}
}if(i2=="B3"){
	if(check(num1,number1[4],number1[5])==true)
	{w="B3";
	yes=1;}
}if(i2=="C1"){
	if(check(num1,number2[0],number2[1])==true)
	w="C1";
	yes=1;
}if(i2=="C2"){
	if(check(num1,number2[2],number2[3])==true)
	{w="C2";
	yes=1;}
}if(i2=="C3"){
	if(check(num1,number2[4],number2[5])==true)
	{w="C3";
	yes=1;}
}
}


if(yes==0)
{
if(i=="A1"){
	if(check(num1,number[0],number[1])==true)
	{w="A1";
	yes=1;}
}if(i=="A2"){
	if(check(num1,number[2],number[3])==true)
	{w="A2";
	yes=1;}
}if(i=="A3"){
	if(check(num1,number[3],number[4])==true)
	{w="A3";
	yes=1;}
}if(i=="B1"){
	if(check(num1,number1[0],number1[1])==true)
	{w="B1";
	yes=1;}
}if(i=="B2"){
	if(check(num1,number1[2],number1[3])==true)
	{w="B2";
	yes=1;}
}if(i=="B3"){
	if(check(num1,number1[4],number1[5])==true)
	{w="B3";
	yes=1;}
}if(i=="C1"){
	if(check(num1,number2[0],number2[1])==true)
	w="C1";
	yes=1;
}if(i=="C2"){
	if(check(num1,number2[2],number2[3])==true)
	{w="C2";
	yes=1;}
}if(i=="C3"){
	if(check(num1,number2[4],number2[5])==true)
	{w="C3";
	yes=1;}
}
}
string o,n,y;
if(w.empty()){
o="Reject";
y=o;
}
else
{
o="Accept#";
if(w=="A1"||w=="A2"||w=="A3")
{n="#hospitalA";
y=o+w+n;
}
else if(w=="B1"||w=="B2"||w=="B3")
{n="#hospitalB";
y=o+w+n;
}
else if(w=="C1"||w=="C2"||w=="C3")
{n="#hospitalC";
y=o+w+n;
}
}


close(new_socket);
close(server_fd);
const char *b;
int s, t;
b=y.c_str();
int udp_sock;
udp_sock = socket(AF_INET, SOCK_DGRAM, 0);
if ( udp_sock< 0) 
perror("udp socket");
struct sockaddr_in udp_server;
memset(&udp_server, 0, sizeof(udp_server));
udp_server.sin_family = AF_INET;

int x;
if(d[0]=='1')
{x=21734;}
else if(d[0]=='2')
{x=21834;}
else if(d[0]=='3')
{x=21934;}
else if(d[0]=='4')
{x=22034;}
else if(d[0]=='5')
{x=22134;}


udp_server.sin_port = htons(x);
udp_server.sin_addr.s_addr = INADDR_ANY;
//connect(udp_sock, (struct sockaddr *)&udp_server, sizeof(udp_server));
sleep(1);
t=sendto(udp_sock, b, 50, 0, (struct sockaddr *)&udp_server, sizeof(udp_server));



struct sockaddr_in serv;
if(inet_pton(AF_INET, "127.0.0.1", &udp_server.sin_addr)<=0)
{
printf("\nInvalid address/ Address not supported \n");
return -1;
}
if(once2==0){
char ip2[100];
serv.sin_port=0;
serv.sin_addr.s_addr='0.0.0.0';
socklen_t servlen=sizeof(serv);
bind(udp_sock,(struct sockaddr *)&serv ,servlen);
getsockname(udp_sock, (struct sockaddr *)&serv,&servlen);
inet_ntop(AF_INET,"127.0.0.1",ip, sizeof(ip2));
char *some_addr;
inet_aton(  *argv ,&udp_server.sin_addr);
some_addr=inet_ntoa(udp_server.sin_addr);
cout<<"<The health center has UDP port "<<ntohs(serv.sin_port)<<" and IP address 127.0.0.1 for the Phase 2"<<endl;
once2=3;
}
cout<<"The health center has send the application result to <Student"<<d<<">"<<endl;


if(w=="A1"||w=="A2"||w=="A3")
{
udp_server.sin_port = htons(21434);
sleep(1);
sendto(udp_sock,d, 50, 0, (struct sockaddr *)&udp_server, sizeof(udp_server));
if(t>0)
cout<<"The health center has send one admitted student to <HospitalA>"<<endl;
}else if(w=="B1"||w=="B2"||w=="B3"){
udp_server.sin_port = htons(21534);
sleep(1);
sendto(udp_sock,d, 50, 0, (struct sockaddr *)&udp_server, sizeof(udp_server));
if(t>0)
cout<<"The health center has send one admitted student to <HospitalB>"<<endl;
}else if(w=="C1"||w=="C2"||w=="C3"){
udp_server.sin_port = htons(21634);
sleep(1);
sendto(udp_sock,d, 50, 0, (struct sockaddr *)&udp_server, sizeof(udp_server));
if(t>0)
cout<<"The health center has send one admitted student to <HospitalC>"<<endl;
}
close(new_socket);
exit(EXIT_SUCCESS);
}else close(new_socket);
}
sleep(1);
return 0;
}
