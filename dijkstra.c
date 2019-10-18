#include<stdio.h>
int main()
{
int cost[10][10],d[10],p[10];
int v[10],count,min,next,i,j;
int g[10][10],n,s;
printf("\ntotal no. of vertices:...\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("\ncost of vertices from to %d vertice to %d vertice \n",i+1,j+1);
scanf("%d",&g[i][j]);
}
}
printf("\nEnter the Source\n");
scanf("%d",&s);
s=s-1;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(g[i][j]==0)
cost[i][j]=9999;
else
cost[i][j]=g[i][j];
for(i=0;i<n;i++)
{
d[i]=cost[s][i];
p[i]=s;
v[i]=0;
}
d[s]=0;
v[s]=1;
count=1;
while(count<n-1)
{
min=9999;
for(i=0;i<n;i++)
if(d[i]<min&&!v[i])
{
min=d[i];
next=i;
}
v[next]=1;
for(i=0;i<n;i++)
if(!v[i])
if(min+cost[next][i]<d[i])
{
d[i]=min+cost[next][i];
p[i]=next;
}
count++;
}
for(i=0;i<n;i++)
if(i!=s)
{
printf("\nTotal cost to vertice %d from vertice %d =%d\n",i+1,s+1,d[i]);
printf("Path between the vertices are= %d-> ",i+1);
j=i;
do
{
j=p[j];
printf("%d",j+1);
}while(j!=s);
}
}
