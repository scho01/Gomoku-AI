#include "ai.h"
using namespace std;

int main(int argc, char** argv)
{
	int n = 11;
	bool l = true;
/*	if (argv[1] == "-n")
	{
		sscanf_s(argv[2], "%d", &n);
	}
	else if (argv[1] == "-l")
		l = false;
	if (argv[2] == "-n")
	{
		sscanf_s(argv[3], "%d", &n);
	}
	if (argv[3] == "-l")
		l = false;*/
	game start(n, !l);
	start.print_board(l);
	long win;
	while (1)
	{
		if (start.receive_move())
		{
//			start.reset();
			start.print_board(l); 
			win = start.find_move(1, 0, 0);
//			if (win >= 1000000)
//			{
//				cout << "CPU win.\n";
//				break;
//			}
//			else if (win <= -1000000)
//			{
//				cout << "Player win.\n";
//				break;
//			}
			start.send_move();
			start.print_board(l);
		}
	}
}