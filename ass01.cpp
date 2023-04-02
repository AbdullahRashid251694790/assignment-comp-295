#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
int score=0;
int board[4][4];
void newgame();
void print_func();
void random_generator();
bool space_check();
bool addition_check();
bool winner_check();
void up_func();
void down_func();
void left_func();
void right_func();
void menu();
int main()
{
	srand(time(0));
	
	cout<<"*******  2048 game *****"<<endl;
	cout<<"press S to start"<<endl;
	cout<<"press I for instructions"<<endl;
	cout<<"press Q for quit "<<endl;
	for(;;){
	
	char key;
	cin>>key;
	if(key=='s')
	{
		
	
	newgame();
    
    int row1,column1,row2,column2,space,win,add;
     for(;;)
	 {
    	row1=rand()%4;
    	row2=rand()%4;
    	column1=rand()%4;
    	column2=rand()%4;
    	if(row1==row2 && column1==column2)
    	{
    		continue;
		}
		else
		break;
	 }
    board[row1][column1]=2*(rand()%2+1);
    board[row2][column2]=2*(rand()%2+1);
    print_func();
    char key;
	for(;;)
	{
		
		win=winner_check();
		if(win==1)
		{ 
		cout<<"You have won the game /n";
		return 0;
	    }
	    space=space_check();
		add=addition_check();
	    if(space==1 && add==1)
	    {
	    cout<<"You have lost the game \n";
			    return 0;
		}
			cout<<"score is:"<<score<<endl;
		cout<<"Press Button ";
		cin>>key;
	
		system("cls");
		if(key=='n' ||key=='q' ||key=='d' ||key=='u' ||key=='r' ||key=='l')
		{
		    win=winner_check();
		    if(win==1)
		    { 
			    cout<<"You have won the game /n";
			    return 0;
		    }
		    space=space_check();
		    add=addition_check();
		    if(space==1 && add==1)
		    {
			    cout<<"You have lost the game \n";
			    return 0;
		    }
		    if(key=='n')
		    {
			    newgame();
		    }
		    else if(key=='q')
		    {
			    cout<<"game end"<<endl;
			    	cout<<"score is:"<<score<<endl;
			    return 0;
		    }
            else if(key=='l')
            {
        	    left_func();
        	    score+=2;
		    }
		    else if(key=='r')
            {
        	    right_func();
        	    score+=2;
		    }
		    else if(key=='u')
            {
        	    up_func();
        	    score+=2;
		    }
		    else if(key=='d')
            {
        	    down_func();
        	    score+=2;
		    }
			random_generator();
			print_func();
		}
		else
		continue;
    }  }
    if(key=='i')
    {
    		cout<<"Press u to move up \n";
	cout<<"Press d to move down \n";
	cout<<"Press l to move left \n";
	cout<<"Press r to move right \n";
	}
	if(key=='q')
	{
		cout <<"game end"<<endl;
			cout<<"score is:"<<score<<endl;
		break;
	}}
	return 0;
}
void newgame()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			board[i][j]=0;
		}
	}
//	cout<<"Press n for new game \n";
	cout<<"Press u to move up \n";
	cout<<"Press d to move down \n";
	cout<<"Press l to move left \n";
	cout<<"Press r to move right \n";
	//cout<<"Press q to quit the game \n";
}
void print_func()
{
	cout<<"\t---------------------------------";
	cout<<endl;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(board[i][j]==0)
			{
			cout<<"\t|"<<board[i][j]; 
			}
			else
			{
			cout<<"\t|"<<board[i][j];
			}
	    }
	    cout<<"\t|";
	    cout<<endl;
	    cout<<"\t---------------------------------";
	    cout<<endl;
	    
	}
	cout<<endl;
}
void random_generator()
{
	int check2;
	srand(time(0));
	check2=space_check();
	if(check2==0)
	{
	    for(;;)
	    {
	 	int row,column;
	 	row=rand()%4;
	 	column=rand()%4;
	 	if(board[row][column]==0)
	 	{
	 		board[row][column]=2*(rand()%2+1);
	 		break;
	    }
	    else
	    continue;
	    }	
	}

}
void up_func()
{   int temp,temp2;
	for(int i=0;i<4;i++)
	{
		int temp=0,temp2=i;
		for (int j=1;j<4;j++)
		{
			if(board[j][i]!=0)
			{
				if(board[j-1][i]==0 || board[j-1][i]==board[j][i])
				{
					if(board[temp][temp2]==board[j][i])
					{
						board[temp][temp2]=2*board[temp][temp2];
						board[j][i]=0;
					}
					else
					{
						if(board[temp][temp2]==0)
						{
							board[temp][temp2]=board[j][i];
							board[j][i]=0;
						}
						else
						{
							board[temp=temp+1][temp2]=board[j][i];
							board[j][i]=0;
						}
					}
				}
				else
				{
					temp++;
				}
			}
		}
	}
}
void down_func()
{   int temp,temp2;
	for(int i=0;i<4;i++)
	{
		temp=3;temp2=i;
		for (int j=2;j>=0;j--)
		{
			if(board[j][i]!=0)
			{
				if(board[j+1][i]==0 || board[j+1][i]==board[j][i])
				{
					if(board[temp][temp2]==board[j][i])
					{
						board[temp][temp2]=2*board[temp][temp2];
						board[j][i]=0;
					}
					else
					{
						if(board[temp][temp2]==0)
						{
							board[temp][temp2]=board[j][i];
							board[j][i]=0;
						}
						else
						{
							board[temp=temp-1][temp2]=board[j][i];
							board[j][i]=0;
						}
					}
				}
				else
				{
					temp--;
				}
			}
	    }
	}
}
void left_func()
{
	int temp,temp2;
	for(int i=0;i<4;i++)
	{
		temp=i;temp2=0;
		for(int j=1;j<4;j++)
		{
			if(board[i][j]!=0)
			{
				if(board[i][j-1]==0 || board[i][j-1]==board[i][j])
				{
					if(board[temp][temp2]==board[i][j])
					{
						board[temp][temp2]=2*board[temp][temp2];
						board[i][j]=0;
					}
					else
					{
						if(board[temp][temp2]==0)
						{
							board[temp][temp2]=board[i][j];
							board[i][j]=0;
						}
						else
						{
							board[temp][temp2=temp2+1]=board[i][j];
							board[i][j]=0;
						}
					}
				}
				else
				{
					temp2++;
				}
			}
		}
	}
}
void right_func()
{
	int temp,temp2;
	for(int i=0;i<4;i++)
	{
		temp=i;temp2=3;
		for(int j=2;j>=0;j--)
		{
			if(board[i][j]!=0)
			{
				if(board[i][j+1]==0 || board[i][j+1]==board[i][j])
				{
					if(board[temp][temp2]==board[i][j])
					{
						board[temp][temp2]=2*board[temp][temp2];
						board[i][j]=0;
					}
					else
					{
						if(board[temp][temp2]==0)
						{
							board[temp][temp2]=board[i][j];
							board[i][j]=0;
						}
						else
						{
							board[temp][temp2=temp2-1]=board[i][j];
							board[i][j]=0;
						}
					}
				}
				else
				{
					temp2--;
				}
			}
		}
	}
}
bool winner_check()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
		    if(board[i][j]==1024)
		    {
		    	return true;
			}
		}
	}
	return false;
}
bool space_check()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(board[i][j]==0)
			{
				return false;
			}
		}
	}
	return true;
}
bool addition_check()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<=3;j++)
		{
			if(board[i][j]==board[i+1][j])
			{
				return false;
			}
		}
		
	}
	for(int i=0;i<=3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j]==board[i][j+1])
			{
				return false;
			}
		}
		
	}
	return true;
}
void menu()
{
	char key;
	cout<<"*******  2048 game *****"<<endl;
	cout<<"press S to start"<<endl;
	cout<<"press I for instructions"<<endl;
	cout<<"press Q for quit "<<endl;
	
	cin>>key;
	if(key=='s')
	{
		
	}
}

