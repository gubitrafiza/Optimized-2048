
#include "ArgumentManager.h"
#include "game.h"
#include <stack>
using namespace std;

//refered to some code from lab and some peers
string SolvingGame(int l, Board &gameBoard, string seq, ofstream& fileOut){

  
  if(l <= 0 || gameBoard.ImpToSolve())
  {
    return "Impossible";
  }
  else if(gameBoard.checkIfSolved()){
    return seq;
  }
  else{
  long long int maxSeq = 99999999999;
  int bestSeq = 0;
  string path = seq;
  for(int i = 1; i<=4; i++){
    Board Store(gameBoard);
    Store.play(i);
    if(gameBoard.getMatrix() != Store.getMatrix())
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
  
  path = path + to_string(bestSeq);
  return path;
  }
}

int main(int argc, char *argv[]){

  ArgumentManager am(argc, argv);
  string inputName = am.get("input");
  string outputName = am.get("output");
  ofstream fileOut(outputName);
  ifstream fileIn(inputName);
  fileOut << "";
   
    int size; //height, width of matrix
  
    string inp;
    getline(fileIn,inp);
    size = stoi(inp); //getting the first line of the input file 
    int row = size; 
    int col = size;
 
  

    Board gameBoard;
    string seq;
    gameBoard.fillMatrix(fileIn, row, col);

   
    if(gameBoard.checkIfSolved())
    {
      fileOut <<"0"; 
    }
    else{
     seq = SolvingGame(10, gameBoard,"", fileOut);

      if(seq == "Impossible")
      {
        fileOut << seq;
      }
      else
      {
        stack<char> myS;
        
          for(int i = 0; i<seq.size(); i++)
          {
            myS.push(seq.at(i));
          }
          for(int i = 0; i<seq.size(); i++)
          {
            seq.at(i) = myS.top();
            myS.pop();
          }
    
        fileOut << seq;
      }
      
    }



}