#include <iostream>
using namespace std;

char pos[10] = {'o','1','2','3','4','5','6','7','8','9'};
int winStatus();
void playingBoard();

int main()
{
	int player = 1,i,choice;
	char mark;
	do
	{
		playingBoard();
		player=(player%2)?1:2;
		cout << "Player " << player << ", enter a number:  ";
		cin >> choice;
		mark=(player == 1) ? 'X' : 'O';
		if (choice == 1 && pos[1] == '1')
			pos[1] = mark;
		else if (choice == 2 && pos[2] == '2')
			pos[2] = mark;
		else if (choice == 3 && pos[3] == '3')
			pos[3] = mark;
		else if (choice == 4 && pos[4] == '4')
			pos[4] = mark;
		else if (choice == 5 && pos[5] == '5')
			pos[5] = mark;
		else if (choice == 6 && pos[6] == '6')
			pos[6] = mark;
		else if (choice == 7 && pos[7] == '7')
			pos[7] = mark;
		else if (choice == 8 && pos[8] == '8')
			pos[8] = mark;
		else if (choice == 9 && pos[9] == '9')
			pos[9] = mark;
		else
		{
			cout<<"Invalid move ";
			player--;
			cin.ignore();
			cin.get();
		}
		i=winStatus();
		player++;
	}while(i==-1);
	playingBoard();
	if(i==1)
		cout<<"==>\aPlayer "<<--player<<" win ";
	else
		cout<<"==>\aGame draw";
	cin.ignore();
	cin.get();
	return 0;
}
int winStatus()
{
	if (pos[1] == pos[2] && pos[2] == pos[3])
		return 1;
	else if (pos[4] == pos[5] && pos[5] == pos[6])
		return 1;
	else if (pos[7] == pos[8] && pos[8] == pos[9])
		return 1;
	else if (pos[1] == pos[4] && pos[4] == pos[7])
		return 1;
	else if (pos[2] == pos[5] && pos[5] == pos[8])
		return 1;
	else if (pos[3] == pos[6] && pos[6] == pos[9])
		return 1;
	else if (pos[1] == pos[5] && pos[5] == pos[9])
		return 1;
	else if (pos[3] == pos[5] && pos[5] == pos[7])
		return 1;
	else if (pos[1] != '1' && pos[2] != '2' && pos[3] != '3' && pos[4] != '4' && pos[5] != '5' && pos[6] != '6' && pos[7] != '7' && pos[8] != '8' && pos[9] != '9')
		return 0;
	else
		return -1;
}

void playingBoard()
{
	//system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";
	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;
	cout << "     |     |     " << endl;
	cout << "  " << pos[1] << "  |  " << pos[2] << "  |  " << pos[3] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << pos[4] << "  |  " << pos[5] << "  |  " << pos[6] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << pos[7] << "  |  " << pos[8] << "  |  " << pos[9] << endl;
	cout << "     |     |     " << endl << endl;
}
