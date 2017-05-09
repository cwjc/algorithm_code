#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

char map[45][45][45];
bool vis_map[45][45][45];
int dir[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int l,r,c;
int l1,r1,c1,l2,r2,c2;
int ok,ans;

struct node
{
	int l,r,c;
	int time;
};

void bfs()
{
	memset(vis_map,false,sizeof(vis_map));
	queue<node> q;
	node st,ed;
	st.l=l1;
	st.r=r1;
	st.c=c1;
	st.time=0;
	vis_map[l1][r1][c1]=true;
	q.push(st);
	
	while(!q.empty())
	{
		st=q.front();
		q.pop();
		if(st.l==l2&&st.r==r2&&st.c==c2)
		{
			ok=1;
			ans=st.time;
			return;
		}
		for(int i=0;i<6;i++)
		{
			ed.l=st.l+dir[i][0];
			ed.r=st.r+dir[i][1];
			ed.c=st.c+dir[i][2];
			if(vis_map[ed.l][ed.r][ed.c]||map[ed.l][ed.r][ed.c]=='#'||ed.l<=0||ed.l>l||ed.r<=0||ed.r>r||ed.c<=0||ed.c>c)
			{
				continue;
			}
			ed.time=st.time+1;
			vis_map[ed.l][ed.r][ed.c]=true;
			q.push(ed);
		}
	}
	return;
	
}

int main()
{
	char ch;
	while(cin>>l>>r>>c)
	{
		if(l==0&&r==0&&c==0)
		{
			break;
		}
		
		ok=0;
		
		for(int i=1;i<=l;i++)
		{
			for(int j=1;j<=r;j++)
			{
				for(int k=1;k<=c;k++)
				{
					cin>>map[i][j][k];
					if(map[i][j][k]=='S')
					{
						l1=i;r1=j;c1=k;
					}
					if(map[i][j][k]=='E')
					{
						l2=i;r2=j;c2=k;
					}
					
				}
			}
			getchar();
		}
		bfs();
		
		if(ok==0)
		{
			cout<<"Trapped!"<<endl;
		}
		else
		{
			cout<<"Escaped in "<<ans<<" minute(s)."<<endl;
		}
	}
} 
