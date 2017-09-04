/*
3
4 1 2 3 5 4 8 6 7
5 2 5 1 10 3 7 4 6 8 9
4 3 7 4 5 2 9 6 8
----------------------
2
4
3
*/
#include<stdio.h>
#include<stdlib.h>
const int max = 100000; //n {2, 3, . . . , 100000}
typedef struct Seg //結構名稱:Seg
{
	int left; //左端點
	int right; //右端點
	int overlap; //重疊數
	int color; // 第?th的顏色	
}seg; //結構變數名稱:seg 
int main()
{
	freopen("in.txt","r",stdin);
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int set;
		scanf("%d",&set);
		seg sg[max];
		for(int i=0;i<set;i++)
		{
			int left,right;
			scanf("%d %d",&left,&right);
			sg[i].left = left;
			sg[i].right = right;
			//printf("%d %d\n",sg[i].left,sg[i].right);
			//system("pause");
		}
		
		for(int j=0;j<set;j++)
		{
			sg[j].overlap = 0;
			for(int k=0;k<set;k++)
			{
				int flag = 0;
				if(sg[j].left>sg[k].right||sg[j].right<sg[k].left)//反向思考 
				{
						flag = 1;
				} 
				else if(j!=k&&flag!=1) 
				{
					sg[j].overlap++;
				} 
			}
		}
		
		//上色 //由重疊數最多(if 一樣 則 照順序)的依次排序上色
		// 排序部分 
		for(int i=0;i<set;i++)
		{
			for(int j=i+1;j<set;j++)
			{
				if(sg[j].overlap>sg[i].overlap)
				{
					int t_left,t_right,t_overlap;
					t_left = sg[j].left;
				   	t_right = sg[j].right;
				   	t_overlap = sg[j].overlap;
				   	
				    sg[j].left = sg[i].left;
				    sg[j].right = sg[i].right;
				    sg[j].overlap = sg[i].overlap;
				    
				    sg[i].left = t_left;
				    sg[i].right = t_right;
					sg[i].overlap = t_overlap;
				}
			}	
		}
		
		//for(int i=0;i<set;i++) printf("%d %d\n",sg[i].left,sg[i].right);//test
		// 上色囉~ 
		int count  = 1;
		for(int j=0;j<set;j++)
		{
			int flag;
			int mark=0;
			for(int k=j+1;k<set;k++)
			{
				flag = 0;
				if(sg[j].left>sg[k].right||sg[j].right<sg[k].left)//反向思考 
				{
						flag = 1;
				} 
				else if(j!=k&&flag!=1) 
				{
					sg[j].color = count;
					sg[k].color = sg[j].color+1;
					mark = 1; 	
				} 
			}
			if(mark==1) count++;
		}		
		printf("%d\n",count); 
	}
	return 0;
} 
