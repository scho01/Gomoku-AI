#include "ai.h"
using namespace std;

/*
Priorities:							Weights:
1. Made 5						10000000
2. guaranteed & 1 to win		1000000
3. 1 to win						100000
4. 1 to guarantee & 2 to win	10000
5. 2 to win						1000
6. 2 to guarantee, 3 to win		100
7. 3 to win						10
*/
	
unordered_map <int, int> heuristic = {
/* 
Manually wrote out all combinations in google sheet here:
https://docs.google.com/spreadsheets/d/1wyPO3BosZo8A6r7s1XJ5ZhKLDqvBuoCzwra-iT-oZaw/edit?usp=sharing
Then copy pasted second column as input in the following function and used find & replace to change "	" to "	" (used onlineGDB text input):

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	bool end = false;
	string input;
	int weight = 10000000;
	while (!end)
	{
		int output = 0;
		getline (cin, input);
		if (input == "end")
			end = true;
		else if (input == "skip")
			{
				cout << endl;
				weight = weight / 10;
			}
		else
		{
			cout << "	{";
			for (auto x: input)
			{
				if (x != ' ')
				{
					output = output << 2;
					if (x == '1')
						output += 1;
					else if (x == '2')
						output += 2;
					else if (x == '3')
						output += 3;
				}
			}
		cout << output << ", " << weight << "},	//" << input << endl;
		}
	}
}
*/
	{341, 10000000},	//_ 1 1 1 1 1
	{1364, 10000000},	//1 1 1 1 1 _
	{1365, 10000000},	//1 1 1 1 1 1
	{1366, 10000000},	//1 1 1 1 1 2
	{1367, 10000000},	//1 1 1 1 1 3
	{2389, 10000000},	//2 1 1 1 1 1
	{3413, 10000000},	//3 1 1 1 1 1

	{340, 1000000},	//_ 1 1 1 1 _

	{85, 100000},	//_ _ 1 1 1 1
	{277, 100000},	//_ 1 _ 1 1 1
	{325, 100000},	//_ 1 1 _ 1 1
	{337, 100000},	//_ 1 1 1 _ 1
	{1108, 100000},	//1 _ 1 1 1 _
	{1109, 100000},	//1 _ 1 1 1 1
	{1110, 100000},	//1 _ 1 1 1 2
	{1111, 100000},	//1 _ 1 1 1 3
	{1300, 100000},	//1 1 _ 1 1 _
	{1301, 100000},	//1 1 _ 1 1 1
	{1302, 100000},	//1 1 _ 1 1 2
	{1303, 100000},	//1 1 _ 1 1 3
	{1348, 100000},	//1 1 1 _ 1 _
	{1349, 100000},	//1 1 1 _ 1 1
	{1350, 100000},	//1 1 1 _ 1 2
	{1351, 100000},	//1 1 1 _ 1 3
	{1360, 100000},	//1 1 1 1 _ _
	{1361, 100000},	//1 1 1 1 _ 1
	{1362, 100000},	//1 1 1 1 _ 2
	{1363, 100000},	//1 1 1 1 _ 3
	{2133, 100000},	//2 _ 1 1 1 1
	{2325, 100000},	//2 1 _ 1 1 1
	{2373, 100000},	//2 1 1 _ 1 1
	{2385, 100000},	//2 1 1 1 _ 1
	{2388, 100000},	//2 1 1 1 1 _
	{3157, 100000},	//3 _ 1 1 1 1
	{3349, 100000},	//3 1 _ 1 1 1
	{3397, 100000},	//3 1 1 _ 1 1
	{3409, 100000},	//3 1 1 1 _ 1
	{3412, 100000},	//3 1 1 1 1 _

	{84, 10000},	//_ _ 1 1 1 _
	{276, 10000},	//_ 1 _ 1 1 _
	{324, 10000},	//_ 1 1 _ 1 _
	{336, 10000},	//_ 1 1 1 _ _
	{338, 10000},	//_ 1 1 1 _ 2
	{339, 10000},	//_ 1 1 1 _ 3
	{2132, 10000},	//2 _ 1 1 1 _
	{3156, 10000},	//3 _ 1 1 1 _

	{21, 1000},		//_ _ _ 1 1 1
	{69, 1000},		//_ _ 1 _ 1 1
	{81, 1000},		//_ _ 1 1 _ 1
	{261, 1000},	//_ 1 _ _ 1 1
	{273, 1000},	//_ 1 _ 1 _ 1
	{321, 1000},	//_ 1 1 _ _ 1
	{1044, 1000},	//1 _ _ 1 1 _
	{1045, 1000},	//1 _ _ 1 1 1
	{1046, 1000},	//1 _ _ 1 1 2
	{1047, 1000},	//1 _ _ 1 1 3
	{1092, 1000},	//1 _ 1 _ 1 _
	{1093, 1000},	//1 _ 1 _ 1 1
	{1094, 1000},	//1 _ 1 _ 1 2
	{1095, 1000},	//1 _ 1 _ 1 3
	{1104, 1000},	//1 _ 1 1 _ _
	{1105, 1000},	//1 _ 1 1 _ 1
	{1106, 1000},	//1 _ 1 1 _ 2
	{1107, 1000},	//1 _ 1 1 _ 3
	{1284, 1000},	//1 1 _ _ 1 _
	{1285, 1000},	//1 1 _ _ 1 1
	{1286, 1000},	//1 1 _ _ 1 2
	{1287, 1000},	//1 1 _ _ 1 3
	{1296, 1000},	//1 1 _ 1 _ _
	{1297, 1000},	//1 1 _ 1 _ 1
	{1298, 1000},	//1 1 _ 1 _ 2
	{1299, 1000},	//1 1 _ 1 _ 3
	{1344, 1000},	//1 1 1 _ _ _
	{1345, 1000},	//1 1 1 _ _ 1
	{1346, 1000},	//1 1 1 _ _ 2
	{1347, 1000},	//1 1 1 _ _ 3
	{2069, 1000},	//2 _ _ 1 1 1
	{2117, 1000},	//2 _ 1 _ 1 1
	{2129, 1000},	//2 _ 1 1 _ 1
	{2309, 1000},	//2 1 _ _ 1 1
	{2321, 1000},	//2 1 _ 1 _ 1
	{2324, 1000},	//2 1 _ 1 1 _
	{2369, 1000},	//2 1 1 _ _ 1
	{2372, 1000},	//2 1 1 _ 1 _
	{2384, 1000},	//2 1 1 1 _ _
	{3093, 1000},	//3 _ _ 1 1 1
	{3141, 1000},	//3 _ 1 _ 1 1
	{3153, 1000},	//3 _ 1 1 _ 1
	{3333, 1000},	//3 1 _ _ 1 1
	{3345, 1000},	//3 1 _ 1 _ 1
	{3348, 1000},	//3 1 _ 1 1 _
	{3393, 1000},	//3 1 1 _ _ 1
	{3396, 1000},	//3 1 1 _ 1 _
	{3408, 1000},	//3 1 1 1 _ _

	{20, 100},		//_ _ _ 1 1 _
	{68, 100},		//_ _ 1 _ 1 _
	{80, 100},		//_ _ 1 1 _ _
	{82, 100},		//_ _ 1 1 _ 2
	{83, 100},		//_ _ 1 1 _ 3
	{260, 100},		//_ 1 _ _ 1 _
	{272, 100},		//_ 1 _ 1 _ _
	{274, 100},		//_ 1 _ 1 _ 2
	{275, 100},		//_ 1 _ 1 _ 3
	{320, 100},		//_ 1 1 _ _ _
	{322, 100},		//_ 1 1 _ _ 2
	{323, 100},		//_ 1 1 _ _ 3
	{2068, 100},	//2 _ _ 1 1 _
	{2116, 100},	//2 _ 1 _ 1 _
	{2128, 100},	//2 _ 1 1 _ _
	{3092, 100},	//3 _ _ 1 1 _
	{3140, 100},	//3 _ 1 _ 1 _
	{3152, 100},	//3 _ 1 1 _ _

	{5, 10},	//_ _ _ _ 1 1
	{17, 10},	//_ _ _ 1 _ 1
	{65, 10},	//_ _ 1 _ _ 1
	{257, 10},	//_ 1 _ _ _ 1
	{1028, 10},	//1 _ _ _ 1 _
	{1029, 10},	//1 _ _ _ 1 1
	{1030, 10},	//1 _ _ _ 1 2
	{1031, 10},	//1 _ _ _ 1 3
	{1040, 10},	//1 _ _ 1 _ _
	{1041, 10},	//1 _ _ 1 _ 1
	{1042, 10},	//1 _ _ 1 _ 2
	{1043, 10},	//1 _ _ 1 _ 3
	{1088, 10},	//1 _ 1 _ _ _
	{1089, 10},	//1 _ 1 _ _ 1
	{1090, 10},	//1 _ 1 _ _ 2
	{1091, 10},	//1 _ 1 _ _ 3
	{1280, 10},	//1 1 _ _ _ _
	{1281, 10},	//1 1 _ _ _ 1
	{1282, 10},	//1 1 _ _ _ 2
	{1283, 10},	//1 1 _ _ _ 3
	{2053, 10},	//2 _ _ _ 1 1
	{2065, 10},	//2 _ _ 1 _ 1
	{2113, 10},	//2 _ 1 _ _ 1
	{2305, 10},	//2 1 _ _ _ 1
	{2308, 10},	//2 1 _ _ 1 _
	{2320, 10},	//2 1 _ 1 _ _
	{2368, 10},	//2 1 1 _ _ _
	{3077, 10},	//3 _ _ _ 1 1
	{3089, 10},	//3 _ _ 1 _ 1
	{3137, 10},	//3 _ 1 _ _ 1
	{3329, 10},	//3 1 _ _ _ 1
	{3332, 10},	//3 1 _ _ 1 _
	{3344, 10},	//3 1 _ 1 _ _
	{3392, 10},	//3 1 1 _ _ _
};

game::game(int n, bool l)
{
	this->dim = n;
//	this->alpha = -100000000;
//	this->beta = 100000000;
	vector<int> wall(n + 2, 3);
	vector<int> empty_row(n + 1, 0);
	empty_row.push_back(3);
	empty_row.front() = 3;
	vector<vector<int>> empty_board(n + 1, empty_row);
	empty_board.push_back(wall);
	empty_board.front() = wall;
	this->pboard = empty_board;
	this->oboard = empty_board;
	if (!l)
	{
		this->best_move = make_pair((n + 1) / 2, (n + 1) / 2);
		send_move();
	}
}
/*
void game::reset()
{
	this->alpha = -100000000;
	this->beta = 100000000;
}*/

void game::send_move()
{
	char col = 'a' + this->best_move.first - 1;
	update_board(this->best_move.first, this->best_move.second, 1);
	update_available(this->best_move.first, this->best_move.second);
//	cout << this->best_move.first << endl << this->best_move.second << endl;
	cout << "Move played: " << col << this->best_move.second << endl;
}

bool game::receive_move()
{
	char ccol = getchar();
	int col = ccol - 96;
	int row;
	cin >> row;
	cin.clear();
	cin.ignore(10, '\n');
	if (within_board(col, row))
	{
		if (this->pboard[col][row] == 0)
		{
			update_board(col, row, 2);
			update_available(col, row);
			cout << "Move played: " << ccol << row << endl;
			return true;
		}
	}
	cout << "Invalid move entered; please enter a new move.\n";
	return false;
}

void game::print_board(bool l)
{
	cout << "   a b c d e f g h i j k" << endl;
	if (!l)
	{
		for (int i = 1; i < this->dim + 1; i++)
		{
			cout << i << " ";
			if (i < 10)
				cout << " ";
			for (int j = 1; j < this->dim + 1; j++)
			{
				if (this->pboard[j][i] == 1)
					cout << "X ";
				else if (this->pboard[j][i] == 2)
					cout << "O ";
				else
					cout << ". ";
			}
			cout << i << endl;
		}
	}
	else
	{
		for (int i = 1; i < this->dim + 1; i++)
		{
			cout << i << " ";
			if (i < 10)
				cout << " ";
			for (int j = 1; j < this->dim + 1; j++)
			{
				if (this->oboard[j][i] == 1)
					cout << "X ";
				else if (this->oboard[j][i] == 2)
					cout << "O ";
				else
					cout << ". ";
			}
			cout << i << endl;
		}
	}
	cout << "   a b c d e f g h i j k" << endl;
	cout << endl;
}

void game::update_board(int x, int y, int p)
{
	if (p == 1)
	{
		this->pboard[x][y] = 1;
		this->oboard[x][y] = 2;
	}
	else
	{
		this->pboard[x][y] = 2;
		this->oboard[x][y] = 1;
	}
}

bool game::within_board(int x, int y)
{
	if ((x < 1) || (x > this->dim))
		return false;
	if ((y < 1) || (y > this->dim))
		return false;
	return true;
}

void game::update_available(int x, int y)
{
//	this->available.erase(coordtonum(x, y));
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			if (within_board(x + i, y + j))
			{
				if (this->pboard[x + i][y + j] == 0)
					this->available.insert(coordtonum(x + i, y + j));
			}
		}
	}
	this->available.erase(coordtonum(x, y));
}

int game::update_tempavail(int x, int y)
{
	int count = 0;
	int cxy = coordtonum(x, y);
	int coord = cxy;
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			coord = coordtonum(x + i, y + j);
			if (within_board(x + i, y + j) && (coord != cxy))
			{
				if ((this->pboard[x + i][y + j] == 0)
					&& (this->available.count(coord) == 0)
					&& (this->tavailset.count(coord) == 0))
				{
					this->tavailset.insert(coord);
					this->tavailstack.push(coord);
					count++;
				}
			}
		}
	}
	return count;
}

void game::revert_board(int x, int y)
{
	this->pboard[x][y] = 0;
	this->oboard[x][y] = 0;
}

int game::coordtonum(int x, int y)
{
	return x * 100 + y;
}

pair<int, int> game::numtocoord(int num)
{
	return make_pair(num / 100, num % 100);
}

/*
Implemented slightly differently from what might be expected due to my board evaluation function only
calculating change in score per move made. It is still a minimax tree at its core, just implemented by
making the score of the boards 1 depth above or below the current depth negative. Since every other 
depth operates in the negative, I was able to just use a maximum function at every level. Basically 
the theory behind this method was to reduce the number of evaluations I needed to make per board 
evaluation by evaluating the change in the score in each board at each depth.
*/
int game::find_move(int p, int depth, int ta)	//, int prev)
{
	if (depth == 2)
		return 0;
//	cout << endl << "depth = " << depth << " begin." << endl;
	int cmaxscore = -1000000000;
	int cmaxcoord = *this->available.begin();
	int tscore = 0;
	int nscore = 0;
	for (const auto& x : this->available)
	{
		this->pboard[x / 100][x % 100] = 1;
		this->oboard[x / 100][x % 100] = 1;
		pair<int, int> z = numtocoord(x);
		char c = 'a' + z.first - 1;
//		cout << c << z.second << ": " << endl;
		tscore = score(x / 100, x % 100, p);
//		cout << c << z.second << ": " << tscore << endl << endl;
		update_board(x / 100, x % 100, p);
		/*		if (tscore > 999999)
		{
			if (depth == 0)
				this->best_move = numtocoord(x);
			return tscore;
		}*/
		if (p == 1)
		{
			nscore = find_move(2, depth + 1, update_tempavail(x / 100, x % 100));	//, tscore);
//			if ((nscore < -999999) && (depth != 0))
//				return -1*nscore;
			tscore -= nscore;
		}
		else
		{
			nscore = find_move(1, depth + 1, update_tempavail(x / 100, x % 100));	// , tscore);
//			if ((nscore < -999999) && (depth != 0))
//				return -1 * nscore;
			tscore -= nscore;
		}
		if (tscore > cmaxscore)
		{
			this->best_move = numtocoord(x);
			cmaxscore = tscore;
//			cmaxcoord = x;
		}
		revert_board(x / 100, x % 100);
	}
	for (int i = ta; i > 0; i--)
	{
		int x = this->tavailstack.top();
		this->tavailstack.pop();
		this->tavailset.erase(x);
		update_board(x / 100, x % 100, p);
		int tscore = score(x / 100, x % 100, p);
		pair<int, int> z = numtocoord(x);
		char c = 'a' + z.first - 1;
//		cout << c << z.second << ": " << tscore << endl;
		/*		if (tscore > 999999)
		{
			if (depth == 0)
				this->best_move = numtocoord(x);
			return tscore;
		}*/
		if (p == 1)
		{
			nscore = find_move(2, depth + 1, update_tempavail(x / 100, x % 100));	// , tscore);
//			if ((nscore < -999999) && (depth != 0))
//				return -1 * nscore;
			tscore -= nscore;
		}
		else
		{
			nscore = find_move(1, depth + 1, update_tempavail(x / 100, x % 100));	// , tscore);
//			if ((nscore < -999999) && (depth != 0))
//				return -1 * nscore;
			tscore -= nscore;
		}
		if (tscore > cmaxscore)
		{
//			cout << tscore << endl << cmaxscore << endl;
			cmaxscore = tscore;
			this->best_move = numtocoord(x);
//			cmaxcoord = x;
		}
		revert_board(x / 100, x % 100);
	}
	char c = 'a' + this->best_move.first - 1;
//	cout << "best move in depth = " << depth << ": " << c << this->best_move.second << ": " << cmaxscore << endl;
//	if (depth == 0)
//		this->best_move = numtocoord(cmaxcoord);
	return cmaxscore;
}

int game::score(int x, int y, int p)
{
//	cout << "row:\n";
	int row = score_row(x, y, p);
//	cout << "row score: " << row << endl << endl << "column:\n";
	int col = score_col(x, y, p);
//	cout << "col score: " << col << endl << "\nleft diagonal:\n";
	int ldia = score_ldiag(x, y, p);
//	cout << "ldi score: " << ldia << endl << "\nright diagonal:\n";
	int rdia = score_rdiag(x, y, p);
//	cout << "rdi score: "<< rdia << endl;
	return row + col + ldia + rdia;
//	return (score_row(x, y, p) + score_col(x, y, p) + score_ldiag(x, y, p) + score_rdiag(x, y, p));
}
int game::score_row(int x, int y, int p)
{
	bool init = false;
	int cscore = 0;
	int keyp = -1;
	int keyo = -1;
	for (int i = x - 4; (i < x) && (i + 5 < this->dim + 1); i++)
	{
		if (i < 0) {}
		else if (init)
		{
			keyp = (keyp << 2) - (this->pboard[i - 1][y] << 12) + (this->pboard[i + 5][y]);
			keyo = (keyo << 2) - (this->oboard[i - 1][y] << 12) + (this->oboard[i + 5][y]);
			cscore = heuristic_search(keyp, keyo, p, cscore);
		}
		else
		{
			keyp = (this->pboard[i][y] << 10) + (this->pboard[i + 1][y] << 8) + (this->pboard[i + 2][y] << 6) + (this->pboard[i + 3][y] << 4) + (this->pboard[i + 4][y] << 2) + (this->pboard[i + 5][y]);
			keyo = (this->oboard[i][y] << 10) + (this->oboard[i + 1][y] << 8) + (this->oboard[i + 2][y] << 6) + (this->oboard[i + 3][y] << 4) + (this->oboard[i + 4][y] << 2) + (this->oboard[i + 5][y]);
			cscore = heuristic_search(keyp, keyo, p, cscore);
			init = true;
		}
	}
	return cscore;
}

int game::score_col(int x, int y, int p)
{
	bool init = false;
	int cscore = 0;
	int keyp = -1;
	int keyo = -1;
	for (int i = y - 4; i < y && i + 5 < this->dim + 1; i++)
	{
		if (i < 0) {}
		else if (init)
		{
			keyp = (keyp << 2) - (this->pboard[x][i - 1] << 12) + (this->pboard[x][i + 5]);
			keyo = (keyo << 2) - (this->oboard[x][i - 1] << 12) + (this->oboard[x][i + 5]);
			cscore = heuristic_search(keyp, keyo, p, cscore);
		}
		else
		{
			keyp = (this->pboard[x][i] << 10) + (this->pboard[x][i + 1] << 8) + (this->pboard[x][i + 2] << 6) + (this->pboard[x][i + 3] << 4) + (this->pboard[x][i + 4] << 2) + (this->pboard[x][i + 5]);
			keyo = (this->oboard[x][i] << 10) + (this->oboard[x][i + 1] << 8) + (this->oboard[x][i + 2] << 6) + (this->oboard[x][i + 3] << 4) + (this->oboard[x][i + 4] << 2) + (this->oboard[x][i + 5]);
			cscore = heuristic_search(keyp, keyo, p, cscore);
			init = true;
		}
	}
	return cscore;
}

int game::score_ldiag(int x, int y, int p)
{
	if ((x + this->dim - y < 6) || (this->dim - x + y < 6))
		return 0;
	bool init = false;
	int cscore = 0;
	int keyp = -1;
	int keyo = -1;
	for (int i = -4; i < 0 && x + i + 5 < this->dim + 1 && y + i + 5 < this->dim + 1; i++)
	{
		if (x + i < 0 || y + i < 0) {}
		else if (init)
		{
			keyp = (keyp << 2) - (this->pboard[x + i - 1][y + i - 1] << 12) + (this->pboard[x + i + 5][y + i + 5]);
			keyo = (keyo << 2) - (this->oboard[x + i - 1][y + i - 1] << 12) + this->oboard[x + i + 5][y + i + 5];
			cscore = heuristic_search(keyp, keyo, p, cscore);
		}
		else
		{
			keyp = (this->pboard[x + i][y + i] << 10) + (this->pboard[x + i + 1][y + i + 1] << 8) + (this->pboard[x + i + 2][y + i + 2] << 6) + (this->pboard[x + i + 3][y + i + 3] << 4) + (this->pboard[x + i + 4][y + i + 4] << 2) + (this->pboard[x + i + 5][y + i + 5]);
			keyo = (this->oboard[x + i][y + i] << 10) + (this->oboard[x + i + 1][y + i + 1] << 8) + (this->oboard[x + i + 2][y + i + 2] << 6) + (this->oboard[x + i + 3][y + i + 3] << 4) + (this->oboard[x + i + 4][y + i + 4] << 2) + (this->oboard[x + i + 5][y + i + 5]);
			cscore = heuristic_search(keyp, keyo, p, cscore);
			init = true;
		}
	}
	return cscore;
}

int game::score_rdiag(int x, int y, int p)
{
	if ((x + y < 7) || (2 * this->dim - x - y < 5))
		return 0;
	bool init = false;
	int cscore = 0;
	int keyp = -1;
	int keyo = -1;
	for (int i = -4; i < 0 && x + i + 5 < this->dim + 1 && y - i - 5 >= 0; i++)
	{
		if (x + i < 0 || y - i > this->dim + 1) {}
		else if (init)
		{
			keyp = (keyp << 2) - (this->pboard[x + i - 1][y - i + 1] << 12) + (this->pboard[x + i + 5][y - i - 5]);
			keyo = (keyo << 2) - (this->oboard[x + i - 1][y - i + 1] << 12) + (this->oboard[x + i + 5][y - i - 5]);
			cscore = heuristic_search(keyp, keyo, p, cscore);
		}
			else
		{
			keyp = (this->pboard[x + i][y - i] << 10) + (this->pboard[x + i + 1][y - i - 1] << 8) + (this->pboard[x + i + 2][y - i - 2] << 6) + (this->pboard[x + i + 3][y - i - 3] << 4) + (this->pboard[x + i + 4][y - i - 4] << 2) + (this->pboard[x + i + 5][y - i - 5]);
			keyo = (this->oboard[x + i][y - i] << 10) + (this->oboard[x + i + 1][y - i - 1] << 8) + (this->oboard[x + i + 2][y - i - 2] << 6) + (this->oboard[x + i + 3][y - i - 3] << 4) + (this->oboard[x + i + 4][y - i - 4] << 2) + (this->oboard[x + i + 5][y - i - 5]);
			cscore = heuristic_search(keyp, keyo, p, cscore);
			init = true;
		}
	}
	return cscore;
}

int game::heuristic_search(int keyp, int keyo, int p, int cscore)
{
	int pscore = 0;
	int oscore = 0;
//	cout << "keyp: " << keyp;
	this->it = heuristic.find(keyp);
	if (this->it != heuristic.end())
		pscore = this->it->second;
//	cout << ", " << pscore << endl;
//	cout << "keyo: " << keyo;
	this->it = heuristic.find(keyo);
	if (this->it != heuristic.end())
		oscore = this->it->second;
//	cout << ", " << oscore << endl;
	if (p == 1)
	{
		pscore += pscore / 5;
		if (oscore < 9999)
			return max(cscore, pscore);
	}
	else
	{
		oscore += oscore / 5;
		if (pscore < 9999)
			return max(cscore, oscore);
	}
	return max({cscore, pscore, oscore});
}
/*int game::score_row(int x, int y, int p)
{
	unordered_map <int, int>::iterator it;
	bool init = false;
	int cscore = 0;
	int key = -1;
	if (p == 1)
	{
		for (int i = x - 4; (i < x) && (i + 5 < this->dim); i++)
		{
			if (i < 0) {}
			else if (init)
			{
				key = key - (this->pboard[i - 1][y] << 10);
				key = (key << 2) + this->pboard[i + 5][y];
				it = heuristic.find(key);
				if (it != heuristic.end())
					cscore = max(cscore, it->second);
			}
			else
			{
				key = this->pboard[i][y];
				for (int j = i + 1; j < i + 6; j++)
					key = (key << 2) + this->pboard[j][y];
				it = heuristic.find(key);
				if (it != heuristic.end())
					cscore = max(cscore, it->second);
				init = true;
			}
		}
	}
	else
	{
		for (int i = x - 4; (i < x) && (i + 5 < this->dim); i++)
		{
			if (i < 0) {}
			else if (init)
			{
				key = key - (this->oboard[i - 1][y] << 10);
				key = (key << 2) + this->oboard[i + 5][y];
				it = heuristic.find(key);
				if (it != heuristic.end())
					cscore = max(cscore, it->second);
			}
			else
			{
				key = this->oboard[i][y];
				for (int j = i + 1; j < i + 6; j++)
					key = (key << 2) + this->oboard[j][y];
				it = heuristic.find(key);
				if (it != heuristic.end())
					cscore = max(cscore, it->second);
				init = true;
			}
		}
	}
	return cscore;
}

int game::score_col(int x, int y, int p)
{
	unordered_map <int, int>::iterator it;
	bool init = false;
	int cscore = 0;
	int key = -1;
	if (p == 1)
	{
		for (int i = y - 4; i < y && i + 5 < this->dim; i++)
		{
			if (i < 0) {}
			else if (init)
			{
				key = key - (this->pboard[x][i - 1] << 10);
				key = (key << 2) + this->pboard[x][i + 5];
				it = heuristic.find(key);
				if (it != heuristic.end())
					cscore = max(cscore, it->second);
			}
			else
			{
				key = this->pboard[x][i];
				for (int j = i + 1; j < i + 6; j++)
					key = (key << 2) + this->pboard[x][j];
				it = heuristic.find(key);
				if (it != heuristic.end())
					cscore = max(cscore, it->second);
				init = true;
			}
		}
	}
	else
	{
		for (int i = y - 4; i < y && i + 5 < this->dim; i++)
		{
			if (i < 0) {}
			else if (init)
			{
				key = key - (this->oboard[x][i - 1] << 10);
				key = (key << 2) + this->oboard[x][i + 5];
				it = heuristic.find(key);
				if (it != heuristic.end())
					cscore = max(cscore, it->second);
			}
			else
			{
				key = this->oboard[x][i];
				for (int j = i + 1; j < i + 6; j++)
					key = (key << 2) + this->oboard[x][j];
				it = heuristic.find(key);
				if (it != heuristic.end())
					cscore = max(cscore, it->second);
				init = true;
			}
		}
	}
	return cscore;
}

int game::score_ldiag(int x, int y, int p)
{
	unordered_map <int, int>::iterator it;
	if ((x + this->dim - y < 6) || (this->dim - x + y < 6))
		return 0;
	bool init = false;
	int cscore = 0;
	int key = -1;
	if (p == 1)
	{
		for (int i = -4; i < 0 && x + i + 5 < this->dim && y + i + 5 < this->dim; i++)
		{
			if (x + i < 0 || y + i < 0) {}
			else if (init)
			{
				key = key - (this->pboard[x + i - 1][y + i - 1] << 10);
				key = (key << 2) + this->pboard[x + i + 5][y + i + 5];
				it = heuristic.find(key);
				if (it != heuristic.end())
					cscore = max(cscore, it->second);
			}
			else
			{
				key = this->pboard[x + i][y + i];
				for (int j = 1; j < 6; j++)
					key = (key << 2) + this->pboard[x + i + j][y + i + j];
				it = heuristic.find(key);
				if (it != heuristic.end())
					cscore = max(cscore, it->second);
				init = true;
			}
		}
	}
	else
	{
		for (int i = -4; i < 0 && x + i + 5 < this->dim && y + i + 5 < this->dim; i++)
		{
			if (x + i < 0 || y + i < 0) {}
			else if (init)
			{
				key = key - (this->oboard[x + i - 1][y + i - 1] << 10);
				key = (key << 2) + this->oboard[x + i + 5][y + i + 5];
				it = heuristic.find(key);
				if (it != heuristic.end())
					cscore = max(cscore, it->second);
			}
			else
			{
				key = this->oboard[x + i][y + i];
				for (int j = 1; j < 6; j++)
					key = (key << 2) + this->oboard[x + i + j][y + i + j];
				it = heuristic.find(key);
				if (it != heuristic.end())
					cscore = max(cscore, it->second);
				init = true;
			}
		}
	}
	return cscore;
}

int game::score_rdiag(int x, int y, int p)
{
	unordered_map <int, int>::iterator it;
	if ((x + y < 5) || (2*this->dim - x - y < 7))
		return 0;
	bool init = false;
	int cscore = 0;
	int key = -1;
	if (p == 1)
	{
		for (int i = -4; i < 0 && x + i + 5 < this->dim && y - i - 5 >= 0; i++)
		{
			if (x + i < 0 || y - i > this->dim - 1) {}
			else if (init)
			{
				key = key - (this->pboard[x + i - 1][y - i + 1] << 10);
				key = (key << 2) + this->pboard[x + i + 5][y - i - 5];
				it = heuristic.find(key);
				if (it != heuristic.end())
					cscore = max(cscore, it->second);
			}
			else
			{
				key = this->pboard[x + i][y - i];
				for (int j = 1; j < 6; j++)
					key = (key << 2) + this->pboard[x + i + j][y - i - j];
				it = heuristic.find(key);
				if (it != heuristic.end())
					cscore = max(cscore, it->second);
				init = true;
			}
		}
	}
	else
	{
		for (int i = -4; i < 0 && x + i + 5 < this->dim && y - i - 5 >= 0; i++)
		{
			if (x + i < 0 || y - i > this->dim - 1) {}
			else if (init)
			{
				key = key - (this->oboard[x + i - 1][y - i + 1] << 10);
				key = (key << 2) + this->oboard[x + i + 5][y - i - 5];
				it = heuristic.find(key);
				if (it != heuristic.end())
					cscore = max(cscore, it->second);
			}
			else
			{
				key = this->oboard[x + i][y - i];
				for (int j = 1; j < 6; j++)
					key = (key << 2) + this->oboard[x + i + j][y - i - j];
				it = heuristic.find(key);
				if (it != heuristic.end())
					cscore = max(cscore, it->second);
				init = true;
			}
		}
	}
	return cscore;
}*/