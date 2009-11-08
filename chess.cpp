#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void initialize_board(string board[8][8]);
void print_board(string board[8][8]);
void process_move(string move, string board[8][8], char &turn);

int main()
{
	system("clear");
	string move;
	string board[8][8];
	char turn = 'w';
	
	initialize_board(board);
	print_board(board);

	cout << endl << "White's move.\n: ";
	cin >> move;

	while (move != "quit")
	{
		system("clear");
		process_move(move, board, turn);

		cout << endl << ": ";
		cin >> move;
	}
	system("clear");
	return 0;
}

bool validate_move(string move)
{
	if (move.length() != 5) return false;
	if (move[0] >= 'a' && move[0] <= 'h'
		&& move[1] >= '1' && move[1] <= '8'
		&& (move[2] == '-' || move[2] == 'x')
		&& move[3] >= 'a' && move[3] <= 'h'
		&& move[4] >= '1' && move[4] <= '8')
	{
		return true;
	}
	else
		return false;
}

bool isChecked(char player, string board[8][8])
{
	return false;
}

bool perform_move(int startx, int starty, int newx, int newy, string board[8][8], string &msg)
{
	char player = board[starty][startx][0];
        switch(board[starty][startx][1])
        {
                case ('p'):

                        break;
                case ('n'):

                        break;
                case ('b'):

                        break;
                case ('r'):

                        break;
                case ('q'):

                        break;
                case ('k'):

                        break;
                default:
                        return false;
                        break;
        }


       	board[newy][newx] = board[starty][startx];
       	board[starty][startx] = "  ";

	return true;
}

bool perform_capture(int startx, int starty, int newx, int newy, string board[8][8])
{
	char player = board[starty][startx][0];
	switch(board[starty][startx][1])
	{
		case ('p'):
			
			break;
		case ('n'):
			
			break;
		case ('b'):

			break;
		case ('r'):

			break;
		case ('q'):

			break;
		case ('k'):

			break;
		default:
			return false;
			break;
	}
	return false;
}

void check_move(string move, string board[8][8], char &turn)
{
	bool legal_move = false;
	string msg = "";
	int startx = (int(move[0]) - 97);
	int starty = 8 - (int(move[1]) - 48);
	int newx = (int(move[3]) - 97);
	int newy = 8 - (int(move[4]) - 48);

	if (board[starty][startx] == "  ") msg = "No piece at " + move.substr(0,2);
	else if (move.substr(0,2) == move.substr(3,2)) msg = "Cannot move to the square your piece is currently occupying.";
	else if (board[starty][startx][0] != turn) msg = "Wrong player's piece.";
	else if (move[2] == '-')
	{
		if (board[newy][newx] == "  ")
		{
			if (perform_move(startx, starty, newx, newy, board, msg)) legal_move = true;
		}
		else msg = "Cannot move to occupied square. (Did you mean " + move.substr(0,2) + "x" + move.substr(3,2) + "?)";
	}
	else if (move[2] == 'x')
	{
		if (board[newy][newx] == "  ")
		{
			msg = "Nothing to capture";
			legal_move = false;
		}
		else if (board[newy][newx][0] == board[starty][startx][0])
			msg = "Cannot capture your own piece.";
		else if (perform_capture(startx, starty, newx, newy, board))
			legal_move = true;
		else msg = "Cannot capture piece at " + move.substr(3,2) + " with piece at " + move.substr(0,2);
	}
	else
		legal_move = false;

	print_board(board);
	cout << endl;
	if (!legal_move)
	{
		cout << "Illegal Move. " + msg;
		if (turn == 'w') cout << "\nWhite's Turn.";
		else cout << "\nBlack's Turn.";
	}
	else if (turn == 'w')
	{
		turn = 'b';
		cout << "Black\'s Turn.";
	}
	else if (turn == 'b')
	{
		turn = 'w';
		cout << "White\'s Turn.";
	}
}

void process_move(string move, string board[8][8], char &turn)
{
	if (move == "help")
	{
		cout << "Enter move using long algebraic notation:\n\n"
		     << "[start_x][start_y]-[new_x][new_y]\n"
		     << "Example: e2-e4\n\n"
		     << "Use an \'x\' instead of a \'-\' for captures.\n"
		     << "Example: f5xe4\n\n"
		     << "Type \'disp\' to show board again.\n"
		     << "Type \'quit\' to exit program.\n\n"
		     << "For an exhaustive list of commands type \'help-commands\'\n";
	}
	else if (move == "help-commands")
	{
		cout << "help: display general help\n"
			<< "help-commands: display list of commands with descriptions\n"
			<< "disp: displays the current game board\n"
			<< "restart: resets the board to the initial state\n"
			<< "quit: exits chess program\n";
	}
	else if (move == "disp")
	{
		print_board(board);
		if (turn == 'w') cout << "\nWhite\'s Turn.";
		else cout << "\nBlack\'s Turn.";
	}
	else if (move == "restart")
	{
		initialize_board(board);
		turn = 'w';
		print_board(board);
		cout << endl << "White's Turn.";
	}
	else if (validate_move(move))
	{
		check_move(move, board, turn);
	}
	else
	{
		print_board(board);
		cout << "\nInvalid Command.  Type \'help\' for help.";
	}
}

void initialize_board(string board[8][8])
{
	board[0][0] = "br";
	board[0][1] = "bn";
	board[0][2] = "bb";
	board[0][3] = "bq";
	board[0][4] = "bk";
	board[0][5] = "bb";
	board[0][6] = "bn";
	board[0][7] = "br";

	board[7][0] = "wr";
	board[7][1] = "wn";
	board[7][2] = "wb";
	board[7][3] = "wq";
	board[7][4] = "wk";
	board[7][5] = "wb";
	board[7][6] = "wn";
	board[7][7] = "wr";

	//make pawns
	for (int i=0; i<8; ++i)
	{
		board[1][i] = "bp";
		board[6][i] = "wp";
	}

	//make empty spaces
	for(int i=2; i<6; ++i)
	{
		for(int j=0; j<8; ++j)
		{
			board[i][j] = "  ";
		}
	}
}

void print_board(string board[8][8])
{
	cout << "\n   a  b  c  d  e  f  g  h" << endl;
	cout << "  -------------------------" << endl;
	for(int i=0; i<8; ++i)
	{
		cout << 8 - i << " |";
		for(int j=0; j<8; ++j)
		{
			cout << board[i][j] << "|";
		}
		cout << " " << 8 - i << endl;
		cout << "  -------------------------" << endl;
	}
	cout << "   a  b  c  d  e  f  g  h" << endl;

}
