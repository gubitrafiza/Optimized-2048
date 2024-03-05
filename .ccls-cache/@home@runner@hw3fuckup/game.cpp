#include<stdio.h>
#include<iostream>
#include<algorithm>
#include "game.h"
using namespace std;

Board::Board() //initilizaing game board
 {
  
   for(int i = 0;i < getRow(); i++)
    {
        for(int j = 0; j < getCol(); j++)
        {
            matrix[i][j] = 0;
        }
    }
}


void Board::play(int action){
  
  if(action == 1){
    up();
  }
  else if(action == 2){
    right();
  }
  else if(action == 3){
    down();
  }
  else if(action == 4){
    left();
  }
  }

bool Board::up()
{ vector<vector<int>> NewMatrix = matrix;
  stack<int> theStack;
  int val;
  int counter = 0;
  int temp;

  for(int j = 0; j < matrix.size(); j++)
  {
    for(int i = 0; i < matrix.size(); i++)
    {
      if(matrix[i][j] != 0 && matrix[i][j] != 2048)
      {
        if(!theStack.empty() && (matrix[i][j] == theStack.top()))
        {
          val = theStack.top();
          theStack.pop();
          theStack.push(val * 2);
          theStack.push(-1); 
          counter++;
        }
        else
        {
          theStack.push(matrix[i][j]);
        }
      }
      else if(matrix[i][j] == 2048)
      {
        while(theStack.size() < counter)
        {
          theStack.push(0);
        }
        theStack.push(2048);
      }
      counter++;
    }
    while(theStack.size() < counter)
    {
      theStack.push(0);
    }
  }

  for(int j = matrix.size()-1; j >= 0; j--)
  {
    for(int i = matrix.size()-1; i >= 0; i--)
    {
      temp = theStack.top();
      theStack.pop();
      if(temp == -1)
      {
        matrix[i][j] = theStack.top();
        theStack.pop();
      }
      else
      {
        matrix[i][j] = temp;
      }
    }
  }
  if(NewMatrix != matrix)
     {
      return true;
     }
     else
     {
      return false;
     }  
}

bool Board::left()
{ vector<vector<int>> NewMatrix = matrix;
  stack<int> theStack;
  int val;
  int counter = 0;
  int temp;

  for(int i = 0; i < matrix.size(); i++)
  {
    for(int j = 0; j < matrix.size(); j++)
    {
      if(matrix[i][j] != 0 && matrix[i][j] != 2048)
      {
        if(!theStack.empty() && (matrix[i][j] == theStack.top()))
        {
          val = theStack.top();
          theStack.pop();
          theStack.push(val * 2);
          theStack.push(-1); 
          counter++;
        }
        else
        {
          theStack.push(matrix[i][j]);
        }
      }
      else if(matrix[i][j] == 2048)
      {
        while(theStack.size() < counter)
        {
          theStack.push(0);
        }
        theStack.push(2048);
      }
      counter++;
    }
    while(theStack.size() < counter)
    {
      theStack.push(0);
    }
  }

  for(int i = matrix.size()-1; i >= 0; i--)
  {
    for(int j = matrix.size()-1; j >= 0; j--)
    {
      temp = theStack.top();
      theStack.pop();
      if(temp == -1)
      {
        matrix[i][j] = theStack.top();
        theStack.pop();
      }
      else
      {
        matrix[i][j] = temp;
      }
    }
  }
  if(NewMatrix != matrix)
     {
      return true;
     }
     else
     {
      return false;
     }  
}

bool Board::down()
{ vector<vector<int>> NewMatrix = matrix;
  stack<int> theStack;
  int val;
  int counter = 0;
  int temp;

  for(int j = matrix.size() -1; j >= 0; j--)
  {
    for(int i = matrix.size() -1 ; i >= 0; i--)
    {
      if(matrix[i][j] != 0 && matrix[i][j] != 2048)
      {
        if(!theStack.empty() && (matrix[i][j] == theStack.top()))
        {
          val = theStack.top();
          theStack.pop();
          theStack.push(val * 2);
          theStack.push(-1); 
          counter++;
        }
        else
        {
          theStack.push(matrix[i][j]);
        }
      }
      else if(matrix[i][j] == 2048)
      {
        while(theStack.size() < counter)
        {
          theStack.push(0);
        }
        theStack.push(2048);
      }
      counter++;
    }
    while(theStack.size() < counter)
    {
      theStack.push(0);
    }
  }

  for(int j = 0; j < matrix.size(); j++)
  {
    for(int i = 0; i < matrix.size(); i++)
    {
      temp = theStack.top();
      theStack.pop();
      if(temp == -1)
      {
        matrix[i][j] = theStack.top();
        theStack.pop();
      }
      else
      {
        matrix[i][j] = temp;
      }
    }
  }
  if(NewMatrix != matrix)
     {
      return true;
     }
     else
     {
      return false;
     }  
}

bool Board::right()
{ vector<vector<int>> NewMatrix = matrix;
  stack<int> theStack;
  int val;
  int counter = 0;
  int temp;

  for(int i =  matrix.size() -1; i >= 0; i--)
  {
    for(int j =  matrix.size() -1 ; j >= 0; j--)
    {
      if(matrix[i][j] != 0 &&  matrix[i][j] != 2048)
      {
        if(!theStack.empty() && (matrix[i][j] == theStack.top()))
        {
          val = theStack.top();
          theStack.pop();
          theStack.push(val * 2);
          theStack.push(-1); 
          counter++;
        }
        else
        {
          theStack.push(matrix[i][j]);
        }
      }
      else if(matrix[i][j] == 2048)
      {
        while(theStack.size() < counter)
        {
          theStack.push(0);
        }
        theStack.push(2048);
      }
      counter++;
    }
    while(theStack.size() < counter)
    {
      theStack.push(0);
    }
  }

  for(int i = 0; i < matrix.size(); i++)
  {
    for(int j = 0; j < matrix.size(); j++)
    {
      temp = theStack.top();
      theStack.pop();
      if(temp == -1)
      {
        matrix[i][j] = theStack.top();
        theStack.pop();
      }
      else
      {
        matrix[i][j] = temp;
      }
    }
  }
}

bool Board::Possible(){
  int total = 0;
  for(int i = 0; i<matrix.size(); i++){
    
    for(int j = 0; j<matrix.size(); j++){

      if(matrix[i][j] != 2048){
        
        total += matrix[i][j];
      }
    }
  }
  
  if(total == 0){
    return false;
  }
  while(total != 1 && total > 0){
    if(total % 2 != 0){
      return false;
    }
    total = total / 2;
  }
  return true;
}




bool Board::ImpToSolve(){

  int total = 0;
  for(int a = 0; a<matrix.size(); a++){
    for(int b = 0; b<matrix.size();b++){
      if(matrix[a][b] != 0 && matrix[a][b] != 2048)
      {
        total += matrix[a][b];        
      }    
  }
}

  if(total ==0){
    return true;
  }
  while(total != 1 && total > 0){
    if(total % 2 != 0){
      return true;
    }
    total = total / 2;
  }
  return false;
}


 

bool Board::checkIfSolved(){
  
  int counter = 0;
  for(int i = 0; i<matrix.size(); i++){
    for(int j = 0; j<matrix.size(); j++){
      if(matrix[i][j] != 0 && matrix[i][j] != 2048){
        counter++;
        if(counter >= 2){
          return false;
        }
      }
    }
  }
  return true; 
}



void Board::fillMatrix(ifstream& fileIn, int row, int col){
  int value;
  for(int i = 0; i<row; i++) //row
     { 
         vector<int> temp;
         for(int j = 0; j<col; j++) //col
         { 
             fileIn >> value;
             temp.push_back(value); 
         }
          matrix.push_back(temp); //filling in the matrix 
     }
}

