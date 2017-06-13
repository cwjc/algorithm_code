#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

long long n;
int Ans[15];
char myLeft[6],myRight[6],myState[6];
int leng;

void MarkRest(char* s1,char* s2,int len)
{
	int i;
	int temp[15];
	for(int i=0;i<len;i++)
	{
		temp[s1[i]-'A']=1;
		temp[s2[i]-'A']=1;
	}
	for(int i=0;i<12;i++)
	{
		if(temp[i]!=1)
		{
			Ans[i]=0;
		}
	}
}

int main ()
{
	scanf("%d",&n);
	while(n--)
	{
		memset(Ans,-1,sizeof(Ans));
		for(int i=0;i<3;i++)
		{
			memset(myLeft,'\0',sizeof(myLeft));
   	    		memset(myRight,'\0',sizeof(myRight));
   	    		memset(myState,'\0',sizeof(myState));
			scanf("%s%s%s",myLeft,myRight,myState);
			if(myState[0]=='u')
			{
				leng=strlen(myLeft);
				for(int i=0;i<leng;i++)
				{
					if(Ans[myLeft[i]-'A']==-1)
					{	
						Ans[myLeft[i]-'A']=2;
					}
					if(Ans[myLeft[i]-'A']==1)
					{
						Ans[myLeft[i]-'A']=0;
					}
				}
				leng=strlen(myRight);
				for(int i=0;i<leng;i++)
				{
					if(Ans[myRight[i]-'A']==-1)
					{
						Ans[myRight[i]-'A']=1;
					}
					if(Ans[myRight[i]-'A']==2)
					{
						Ans[myRight[i]-'A']=0;
					}
				}
				MarkRest(myLeft,myRight,leng);
			}
			if(myState[0]=='d')
			{
				leng=strlen(myLeft);
				for(int i=0;i<leng;i++)
				{
					if(Ans[myLeft[i]-'A']==-1)
					{
						Ans[myLeft[i]-'A']=1;
					}
					if(Ans[myLeft[i]-'A']==2)
					{
						Ans[myLeft[i]-'A']=0;
					}
				}
				leng=strlen(myRight);
				for(int i=0;i<leng;i++)
				{
					if(Ans[myRight[i]-'A']==-1)
					{
						Ans[myRight[i]-'A']=2;
					}
					if(Ans[myRight[i]-'A']==1)
					{
						Ans[myRight[i]-'A']=0;
					}
				}
				MarkRest(myLeft,myRight,leng);
			}
			if(myState[0]=='e')
			{
				leng=strlen(myLeft);
				for(int i=0;i<leng;i++)
				{
					Ans[myLeft[i]-'A']=0;
				}
				leng=strlen(myRight);
				for(int i=0;i<leng;i++)
				{
					Ans[myRight[i]-'A']=0;
				}
			}
		}
		
		for(int i=0;i<12;i++)
		{
			if(Ans[i]!=0)
			{
				if(Ans[i]==1)
				{
					printf("%c is the counterfeit coin and it is light.\n",i+'A');
				}
				if(Ans[i]==2)
				{
					printf("%c is the counterfeit coin and it is heavy.\n",i+'A');
				}
				break;
			}
		}
	}
    return 0; 
}
