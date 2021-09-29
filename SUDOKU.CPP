#include<iostream.h>
#include<conio.h>
#include<process.h>
const int M=9;
const int N=9;
int b[M][N]=	{{0,0,2,0,8,0,6,9,3},{5,0,0,0,1,0,0,0,0},{0,0,3,0,0,0,0,8,1},{0,0,0,0,0,9,0,4,0},{3,0,6,0,0,0,8,0,9},{0,5,0,2,0,0,0,0,0},{2,1,0,0,0,0,3,0,0},{0,0,0,0,2,0,0,0,8},{4,8,5,0,3,0,2,0,0}};
int a[M][N][10];
void disp()
{
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		cout<<a[i][j][0]<<" ";
		cout<<"\n";
	}
}
void smart_transfer_row()
{
	for(int i=0;i<M;i++)
	for(int j=0;j<N;j++)
	{
		if(a[i][j][0]==0)
		{
			for(int l=1;l<10;l++)
			{
				int flag=0;
				for(int k=0;k<M;k++)
				{
					if((a[k][j][0]==0)&&(k!=i))
					{
						for(int m=1;m<10;m++)
						if(a[i][j][l]==a[k][j][m])flag=1;
					}
				}

			if(flag==0){a[i][j][0]=a[i][j][l];break;}
			}
		}
	}
}
void smart_transfer_col()
{
	for(int i=0;i<M;i++)
	for(int j=0;j<N;j++)
	{

		if(a[i][j][0]==0)
		{
			for(int l=1;l<10;l++)
			{
				int flag=0;
				for(int k=0;k<N;k++)
				{
					if((a[i][k][0]==0)&&(k!=j))
					{
						for(int m=1;m<10;m++)
						if(a[i][j][l]==a[i][k][m])flag=1;
					}
				}
			if(flag==0){a[i][j][0]=a[i][j][l];break;}
			}
		}
	}
}
void smart_transfer_box()
{
	for(int i=0;i<M;i++)
	for(int j=0;j<N;j++)
	{
		if(a[i][j][0]==0)
		{
			for(int l=1;l<10;l++)
			{
				int flag=0;
				int x=(i/3)*3,y=(j/3)*3;
				int v=x+3,w=y+3;
				for(x=(i/3)*3;x<v;x++)
				for(y=(j/3)*3;y<w;y++)
				{
					if((a[x][y][0]==0)&&((x!=i)||(y!=j)))
					{
						for(int m=1;m<10;m++)
						if(a[i][j][l]==a[x][y][m])flag=1;
					}
				}

			if(flag==0){a[i][j][0]=a[i][j][l];break;}
			}
		}
	}
}
void transfer()
{
	int count,t;
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
		{
			if(a[i][j][0]==0)
			{
				count=0;
				for(int k=1;k<10;k++)
				if(a[i][j][k]!=0)
				{
					count++;
					t=a[i][j][k];
				}

			if(count==1)a[i][j][0]=t;
			}
		}
}
void check()
{
	for(int i=0;i<M;i++)
    for(int j=0;j<N;j++)
    {
      if(a[i][j][0]==0)
      {
        for(int k=0;k<M;k++)
        {
          a[i][j][a[k][j][0]]=0;
        }
        for(k=0;k<N;k++)
        {
          a[i][j][a[i][k][0]]=0;
        }
        int l=i/3,m=j/3;
        l=l*3;
        m=m*3;
        int n=l+3,o=m+3;
        //if((i==1)&&(j==1))cout<<l<<" "<<m;
        for(;l<n;l++)
        for(m=(j/3)*3;m<o;m++)
        {
        int t=a[l][m][0];
        a[i][j][t]=0;
        }
        //transfer();
      }
    }
}
void solve()
{
	for(int i=0;i<40;i++)
	{
		check();
		transfer();
		check();
		smart_transfer_box();
		check();
		transfer();
		check();
		smart_transfer_row();
		check();
		transfer();
		check();
		smart_transfer_col();
		check();
		transfer();
	}
	/*disp();
	getch();
	clrscr();*/
	cout<<"\n\n";
	//disp();
	//getch();
}
void check_solve()
{
	for(int i=0;i<9;i++)
	{
		int rowc[10]={1};
		for(int j=0;j<9;j++)
		rowc[a[i][j][0]]=a[i][j][0];
		for(int t=0;t<10;t++)
		if(rowc[t]==0)return;
	}
	for(int j=0;j<9;j++)
	{
		int colc[10]={1};
		for(int i=0;i<9;i++)
		colc[a[i][j][0]]=a[i][j][0];
		for(int t=0;t<10;t++)
		if(colc[t]==0)return;
	}
	disp();
	getch();
	exit(0);
}
void init()
{
	 clrscr();
	/*for(int i=0;i<M;i++)
	for(int j=0;j<N;j++)
	cin>>a[i][j][0];
	*/
	for(int i=0;i<M;i++)
    for(int j=0;j<N;j++)
      a[i][j][0]=b[i][j];

	for(i=0;i<M;i++)
    for(j=0;j<N;j++)
      if(a[i][j][0]==0)
      {
        for(int k=1;k<10;k++)
        a[i][j][k]=k;
      }
}
void main()
{
	init();
	solve();

	int flag=0;
	for(int i=0;(i<M)&&(flag==0);i++)
    for(int j=0;(j<N)&&(flag==0);j++)
      if(a[i][j][0]==0)
        flag=1;
  i--;
	j--;
	if(flag==1)
	{
		for(int k=1;k<=9;k++)
		{
			a[i][j][0]=k;
			solve();
			check_solve();
			init();
			solve();
		}
	}
	disp();
	getch();
}