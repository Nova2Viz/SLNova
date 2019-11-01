#include<stdio.h>
#define IP "192.48.25.0"
int main()
{
int subnet,network,host,i,result = 0;
int networks = 1,hosts=1;
printf("IP address : %s \n",IP);
printf("enter the subnet:");
scanf("%d",&subnet);
network = subnet % 8;
host = 8 - network;
while(network != 0)
{
networks = networks * 2;
--network;
}
while(host != 0)
{
hosts = hosts * 2;
--host;
}
for(i=0;i<networks;i++)
{
result = result + hosts;
printf("starting address : %d\t ending address : %d\n",i+1,result-1);
}
return 0;
}



