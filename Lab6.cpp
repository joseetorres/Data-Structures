#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

#define until(x) while(!(x))
#define unless(x) if(!(x))

struct Coord {
	int x, y;
	Coord(int _x, int _y) : x(_x), y(_y) {}
	bool operator == (const Coord &c) { return x== c.x and y == c.y;}
};

template <typename Iter, typename T>
bool check_conflict(Iter begin, Iter end, const T &val) {
	int x, y, other_x, other_y;
	x = val.x;
	y = val.y;
	while (begin != end) {
		other_x = begin->x;
		other_y = begin->y;
		if (other_x == x) return true;
		if (other_y == y) return true;
		if (other_y == y + abs(x - other_x)) return true;
		if (other_y == y - abs(x - other_x)) return true;
		++begin;
	}
	return false;
}

int main () 
{
 	int n;
	bool success;
	vector <Coord> board;

	cout << "Enter board size: ";
	cin >> n; 

	board.push_back(Coord(1, 1));
	until (success or board.empty()) {
		if (check_conflict(board.begin(), board.end() -1, board.back()))
	{
		until (board.empty() or board.back().y !=n) board.pop_back();
		unless (board.empty()) ++board.back().y;
	}
		else if (board.size() == n) success = true;
		else board.push_back(Coord(board.size() +1, 1));
}
	for (vector<Coord>::iterator it= board.begin(); it !=board.end(); ++it)
{ 
	cout << '{' << it->x << ',' << it->y << '}' <<endl;
	}	
}
 

