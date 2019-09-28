#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
int main()
{
	int data1,data2,max=0;
	fstream file;
	file.open("network.txt",ios::in);
	while(!file.eof())
	{
		file>>data1;
	if(max<(data1))
		max=data1;
	}
	max++;
	int adj[max][max];
	for(int i=0;i<max;i++)
		for(int j=0;j<max;j++)
			adj[i][j]=0;
	file.seekg(0);
	while(!file.eof())
	{
	file>>data1;
	file>>data2;
	if(!file.eof())
	{
		adj[data1][data2]=adj[data2][data1]=1;
	}
	}
	cout<<"The adjaency matrix is: \n";
	for(int i=0;i<max;i++)
	{
		for(int j=0;j<max;j++)
			cout<<adj[i][j]<<" ";
		cout<<"\n";
	}
	file.close();
	return 0;
}
