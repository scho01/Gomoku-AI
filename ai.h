#ifndef AI_H
#define AI_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdarg.h>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
using namespace std;

extern unordered_map <int, int> heuristic;

class game
{
	public:
		game(int n, bool l);
		bool receive_move();
		int find_move(int p, int depth, int ta); //, int prev);
		void send_move();
		void print_board(bool l);
private:
		int dim;
		vector<vector<int>> pboard;
		vector<vector<int>> oboard;
		unordered_set <int> available;
		pair<int, int> best_move;
		unordered_set <int> tavailset;
		stack<int> tavailstack;
		unordered_map <int, int>::iterator it;
//		int alpha, beta;

		int coordtonum(int x, int y);
		pair<int, int> numtocoord(int num);
		void update_board(int x, int y, int p);
		bool within_board(int x, int y);
		void update_available(int x, int y);
		int update_tempavail(int x, int y);
		void revert_board(int x, int y);

		int score(int x, int y, int p);
		int score_row(int x, int y, int p);
		int score_col(int x, int y, int p);
		int score_ldiag(int x, int y, int p);
		int score_rdiag(int x, int y, int p);
		int heuristic_search(int keyp, int keyo, int p, int cscore);
};


#endif