
#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


class Board
{
private:
  vector<vector<int>> matrix;

public:
	Board();
	bool const empty();
	void push(char val);
	char const peek();
	void pop(); 
  int getRow() {return matrix.size();}
  int getCol() {return matrix.size();}
  vector<vector<int>> getMatrix(){return matrix;}
  bool up();
  bool down();
  bool right();
  bool left();
  bool checkIfSolved();
  bool ImpToSolve();
  bool Possible();
  void play(int);
  void fillMatrix(ifstream&, int row, int col);
  string SolvingGame(int l, Board&, string seq, ofstream&);

	//void print(ofstream &ofs);

};