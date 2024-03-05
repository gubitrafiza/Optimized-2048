
#include "ArgumentManager.h"
#include "game.h"
#include <stack>
using namespace std;

//refered to some code from lab and some peers
string SolvingGame(int l, Board &gameBoard, string seq, ofstream& fileOut){

  
  if(gameBoard.checkIfSolved()){ //if the board is solevd return the path used to solve it 
    return seq;
  }
  else if(l <= 0 || gameBoard.Possible() == false) //if the board is not possible to solve, outfile "Impossible"
  {
    return "Impossible";
  }
  
  long int maxSeq = 99999999999; //constant for longest sequence possible
  int bestSeq = 0;
  string path = seq;
  for(int i = 1; i<=4; i++){
    Board Store(gameBoard); //create temp matrix 
    Store.play(i); //run all the moves, up, roght, down, left in this order
        
    if(gameBoard.getMatrix() != Store.getMatrix()) //if moved matrix is not as temp matrix 
    {
      string cur = SolvingGame(l-1, Store, seq, fileOut);
      if(cur.length() < maxSeq)
      {
        maxSeq = cur.length();
        bestSeq = i;
        path = cur;
      }
    }
  }
  
  path += to_string(bestSeq);
  return path; //return best path to solve the game
 
}

int main(int argc, char *argv[]){

  ArgumentManager am(argc, argv); //argument manager implementation from dr.rizk ppts 
  string inputName = am.get("input");
  string outputName = am.get("output");
  ofstream fileOut(outputName);
  ifstream fileIn(inputName);
  fileOut << "";
   
    int size; //height, width of matrix
  
    string inp; //storing first line of file as string
    getline(fileIn,inp);
    size = stoi(inp); //getting the first line of the input file 
    int row = size; //size = height = width thus = row = col of matrix
    int col = size;
 
    Board gameBoard; //obj of Board class to make gameBoard
    string path = "";
   gameBoard.fillMatrix(fileIn, row, col); //fill in the empty/new matrix with input file values 
  
  if(gameBoard.checkIfSolved()) //if the matrix is solved 
  {
      fileOut << "0"; //if the matrix is possible
      return 0;
  }
  else if(gameBoard.checkIfSolved() && gameBoard.Possible() == false)
  {
     fileOut << "Impossible";  
     return 0;
  }
  else 
  {
    path = SolvingGame(12,gameBoard,"",fileOut); //12 because the posisbel moves are only 12
    if(path.substr(0, 10) == "Impossible" || path == "0")
    fileOut << "Impossible"; //the game is impossible to solve because more than 1 ele left over
    else
    {
      stack<char>Revstk; //create a stack to reverse all the elemets since it was put in the stack in LIFO order
      for(int i = 0; i < path.length(); i++)
      {
        Revstk.push(path.at(i));
      }
      for(int i = 0; i < path.length(); i++)
      {
        path.at(i) = Revstk.top();
        
        Revstk.pop();
      }
      fileOut << path;
    }
  }

 
}