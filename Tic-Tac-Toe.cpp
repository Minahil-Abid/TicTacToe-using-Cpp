#include <iostream>
using namespace std;
char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
char one, two;
int value;
int row, column;
bool tie=false;
void table(){
system("cls");
	
    cout<<"\t\t\t\t\t\t"<<"TIK TAK TOE"<<endl;
	cout<<"\t\t\t"<<"PLAYER:01 [X]"<<endl;
	cout<<"\t\t\t"<<"PLAYER:02 [O]"<<endl<<"\n";
	cout<<"\t\t\tENTER NUMBER BETWEEN 1-9"<<endl;
	cout<<endl;
	cout<<"\t\t\t"<<"\t"<<a[0][0]<<"\t"<<"|"<<"\t"<<a[0][1]<<"\t"<<"|"<<"\t"<<a[0][2]<<endl;
	cout<<"\t\t\t"<<"________________"<<"|"<<"_______________"<<"|"<<"________________"<<endl;
	cout<<"\t\t\t"<<"                "<<"|"<<"               "<<"|"<<"                "<<endl;
    cout<<"\t\t\t"<<"\t"<<a[1][0]<<"\t"<<"|"<<"\t"<<a[1][1]<<"\t"<<"|"<<"\t"<<a[1][2]<<endl;
    cout<<"\t\t\t"<<"________________"<<"|"<<"_______________"<<"|"<<"________________"<<endl;
	cout<<"\t\t\t"<<"                "<<"|"<<"               "<<"|"<<"                "<<endl;
    cout<<"\t\t\t"<<"\t"<<a[2][0]<<"\t"<<"|"<<"\t"<<a[2][1]<<"\t"<<"|"<<"\t"<<a[2][2]<<endl;
	cout<<"\t\t\t"<<"                "<<"|"<<"               "<<"|"<<"              "<<endl;
}

void player_turn(){
	if(turn=='X')
	{
		
		cout<<"\t\t\t"<<"PLAYER:01 [X]"<<"please enter:";
		cin>>value;
	}
	if(turn=='O')
	{
		cout<<"\t\t\t"<<"PLAYER:02 [O]"<<"please enter:";
		cin>>value;
	}
	switch(value){
		case 1:
			row=0;
			column=0;
			break;
			case 2:
			row=0;
			column=1;
			break;
			case 3:
			row=0;
			column=2;
			break;
			case 4:
			row=1;
			column=0;
			break;
			case 5:
			row=1;
			column=1;
			break;
			case 6:
			row=1;
			column=2;
			break;
			case 7:
			row=2;
			column=0;
			break;
			case 8:
			row=2;
			column=1;
			break;
			case 9:
			row=2;
			column=2;
			break;
			default:
		cout<<"invalid choice\n";
		cout<<"please enter numbers between 1-9";
		break;					

	}
	
	
	
	//avoid over-writing
if(turn=='X' && a[row][column]!='X' && a[row][column]!='O')
{
	a[row][column]='X';
	turn='O';
}
	else if(turn=='O' && a[row][column]!='X' && a[row][column]!='O')
{
	a[row][column]='O';
	turn='X';
}
else
{
	cout<<"invalid !!!"<<endl;

}
table();
	
}


bool game_over(){
	//horizontal game check
	if(a[0][0]==a[0][1] && a[0][1]==a[0][2] || a[1][0]==a[1][1] && a[1][1]==a[1][2] || a[2][0]==a[2][1] && a[2][1]==a[2][2])
	{
		return true;
	}
	//vertical game check
	if(a[0][0]==a[1][0] && a[1][0]==a[2][0] || a[0][1]==a[1][1] && a[1][1]==a[2][1] || a[0][2]==a[1][2] && a[1][2]==a[2][2])
	{
		return true;
	}
	//diagonal game check
	if(a[0][0]==a[1][1] && a[1][1]==a[2][2] || a[0][2]==a[1][1] && a[1][1]==a[2][0])
	{
		return true;
	}
	//game continue
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j]!='X' && a[i][j]!='O')
			{
				return false;
			}
			
		}
	}
	tie=true;
	return false;
}


int main(){


while(!game_over() && tie==false)
{
table();
player_turn();



}
if(turn=='X' && tie==false)
{
    cout<<"O IS WINNER.CONGRATULATIONS!!!"<<endl;
}
else if(turn=='O' && tie==false)
{
    cout<<"X IS WINNER.CONGRATULATIONS!!!"<<endl;	
}
else
{
	cout<<"GAME DRAW!!!"<<endl;
}
return 0;
}













