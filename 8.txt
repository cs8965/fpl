#include <iostream>
#include<queue>
using namespace std;
class obst
{
	public:
	int n,i,j,k,g;
    int p[50],q[50],w[50][50],c[50][50],r[50][50];
	string keys[10];
	void create();
	int mincost(int y,int z);
    void display();
};

void obst::create()
{
	cout<<"Enter total number of keys : ";
	cin>>n;
	for(i=0;i<=n;i++)
	{
		keys[i]=i;
	}			
	for(i=1;i<=n;i++)	
	{
		cout<<"Enter probability of successful search p"<<i<<" : ";
		cin>>p[i];
	}
	for(i=0;i<=n;i++)	
	{
		cout<<"Enter probability of unsuccessful search q"<<i<<": ";
		cin>>q[i];
	}
	

	for(i=0;i<=n;i++)
	{
		w[i][i]=q[i];
		c[i][i]=0;
		r[i][i]=0;
	}
	for(i=0;i<=n;i++)
	{
		j=i+1;
		w[i][j]=p[j]+q[j]+w[i][j-1];
		k=j;	
		c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
		r[i][j]=k;
	}
	for(g=2;g<=n;g++)
	{
		for(i=0;i<n;i++)
		{
			j=i+g;
			w[i][j]=p[j]+q[j]+w[i][j-1];
			k=mincost(i,j);
			c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
			r[i][j]=k;
		}
	}	
}

int obst::mincost(int y,int z)
{
	int k,m,cost,min=999;
	for(m=(y+1);m<=z;m++)	
	{
		cost=c[y][m-1]+c[m][z];
		if(cost<min)
		{
			min=cost;
			k=m;
		}
	}
	return k;
}

void obst::display()
{
	queue<int> que;
	cout<<"\n------------------------------------------\nNode\t\tLeft\t\tRight\n------------------------------------------"<<endl;
	que.push(0);
	que.push(n);
	while(!que.empty())
	{
		i=que.front();
		que.pop();
		j=que.front();
		que.pop();
		k=r[i][j];
		cout<<"\n"<<k;
		if(r[i][k-1]!=0)
		{
			cout<<"\t\t"<<r[i][k-1];
			que.push(i);
			que.push(k-1);			
		}
		else
			cout<<"\t\tNULL";
		if(r[k][j]!=0)
		{
			cout<<"\t\t"<<r[k][j];
			que.push(k);
			que.push(j);			
		}
		else
			cout<<"\t\tNULL";
	}
	cout<<"\n------------------------------------------"<<endl;
}

int main()
{
	obst o;
	o.create();
	o.display();
}
