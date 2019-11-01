#include<stdio.h>
#include<string.h>
//#include<conio.h>
void main()
{
char ip[10][20]={"192.168.0.64","192.168.0.60","192.168.0.68","132.147.3.3"};
char et[10][20]={"00:A8:00:40:8E:FS","00:16:17:31:8e:22","00:16:17:31:8E:F7","00:16:17:31:8E:08"};
char ipaddr[20],etaddr[20];
int i,j,op;
int x=0,y=0;
printf("\nThe ARP table is:");
for(i=0;i<4;i++)
    printf("\n%s is %s",ip[i],et[i]);
//clrscr();
while(1)
{
printf("\n\n 1.ARP 2.RARP 3.EXIT");
printf("\n enter the choice");
scanf("%d",&op);
switch(op)
{
case 1:
printf("\n enter ip address");
scanf("%s",ipaddr);
for(i=0;i<=20;i++)
{
if(strcmp(ipaddr,ip[i])==0)
{
printf("Ethernet address is%s",et[i]);
x=1;
} }
if(x==0)
printf("invalid ip address");
x=0;
break;
case 2:
printf("enter ethernet address");
scanf("%s",etaddr);
for(i=0;i<=20;i++)
{
if(strcmp(etaddr,et[i])==0)
{
printf("IP address is %s",ip[i]);
y=1;
} }
if(y==0)
printf("Invalid ethernet address");
y=0;
break;
case 3:
exit(0);
} } }

