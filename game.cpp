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

//filling in the matrix from inputFiles
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

void Board::play(int action){ //moves, 1 = up, 2 = right, 3 = down, 4 = left
  
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
//refered to code given by TA in lab to shift using a stack 

bool Board::up()
{ vector<vector<int>> NewMatrix = matrix;
  stack<int> Elements;
  int item;
  int iterator = 0;
  int temp;

  for(int j = 0; j < matrix.size(); j++) //iterating trough col
  {
    for(int i = 0; i < matrix.size(); i++)//iterating trough row
    {
      if(matrix[i][j] != 0 && matrix[i][j] != 2048) //while matrix has at least 1 ele and its is not 2048
      {
        if(!Elements.empty() && (matrix[i][j] == Elements.top()))//if the number is equal to the first (top) of stack
        {
          item = Elements.top();
          Elements.pop();
          Elements.push(item * 2);
          Elements.push(-1); //push in -1 so show that elements have merged 
          iterator++;//increment iterator to move to next
        }
        else
        {
          Elements.push(matrix[i][j]); //otherwise, just continue to push element in stack
        }
      }
      else if(matrix[i][j] == 2048) //if the element is the wall
      {
        while(Elements.size() < iterator)
        {
          Elements.push(0);
        }
        Elements.push(2048);
      }
      iterator++;//move iterator up by 1
    }
    while(Elements.size() < iterator)//now you are at the end of the col, push in zeros until the stack size is equal to iterator item
    {
      Elements.push(0);
    }
  }
  Elements.push(-1); //need to have code here to pass all cases (not included in code given by ta)
  iterator += 1;
  //after all elements have been push into the stack
  //start removing i.e popping them back into the matrix
  for(int j = matrix.size()-1; j >= 0; j--) 
  {
    for(int i = matrix.size()-1; i >= 0; i--)
    {
      temp = Elements.top();
      Elements.pop();
      if(temp == -1) //if the element being popped is -1, skip and move to next
      {
        matrix[i][j] = Elements.top();
        Elements.pop();
      }
      else
      {
        matrix[i][j] = temp; //else set element to temp
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
//similar functions refered to up function given by ta in lab
bool Board::left()
{ vector<vector<int>> NewMatrix = matrix;
  stack<int> Elements;
  int item;
  int iterator = 0;
  int temp;

  for(int i = 0; i < matrix.size(); i++)
  {
    for(int j = 0; j < matrix.size(); j++)
    {
      if(matrix[i][j] != 0 && matrix[i][j] != 2048)
      {
        if(!Elements.empty() && (matrix[i][j] == Elements.top()))
        {
          item = Elements.top();
          Elements.pop();
          Elements.push(item * 2);
          Elements.push(-1); 
          iterator++;
        }
        else
        {
          Elements.push(matrix[i][j]);
        }
      }
      else if(matrix[i][j] == 2048)
      {
        while(Elements.size() < iterator)
        {
          Elements.push(0);
        }
        Elements.push(2048);
      }
      iterator++;
    }
    while(Elements.size() < iterator)
    {
      Elements.push(0);
    }
    Elements.push(-1);
    iterator += 1;
  }

  for(int i = matrix.size()-1; i >= 0; i--)
  {
    for(int j = matrix.size()-1; j >= 0; j--)
    {
      temp = Elements.top();
      Elements.pop();
      if(temp == -1)
      {
        matrix[i][j] = Elements.top();
        Elements.pop();
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
//similar functions refered to up function given by ta in lab
bool Board::down()
{ vector<vector<int>> NewMatrix = matrix;
  stack<int> Elements;
  int item;
  int iterator = 0;
  int temp;

  for(int j = matrix.size() -1; j >= 0; j--)
  {
    for(int i = matrix.size() -1 ; i >= 0; i--)
    {
      if(matrix[i][j] != 0 && matrix[i][j] != 2048)
      {
        if(!Elements.empty() && (matrix[i][j] == Elements.top()))
        {
          item = Elements.top();
          Elements.pop();
          Elements.push(item * 2);
          Elements.push(-1); 
          iterator++;
        }
        else
        {
          Elements.push(matrix[i][j]);
        }
      }
      else if(matrix[i][j] == 2048)
      {
        while(Elements.size() < iterator)
        {
          Elements.push(0);
        }
        Elements.push(2048);
      }
      iterator++;
    }
    while(Elements.size() < iterator)
    {
      Elements.push(0);
    }
  }

  for(int j = 0; j < matrix.size(); j++)
  {
    for(int i = 0; i < matrix.size(); i++)
    {
      temp = Elements.top();
      Elements.pop();
      if(temp == -1)
      {
        matrix[i][j] = Elements.top();
        Elements.pop();
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
//similar functions refered to up function given by ta in lab
bool Board::right()
{ vector<vector<int>> NewMatrix = matrix;
  stack<int> Elements;
  int item;
  int iterator = 0;
  int temp;

  for(int i =  matrix.size() -1; i >= 0; i--)
  {
    for(int j =  matrix.size() -1 ; j >= 0; j--)
    {
      if(matrix[i][j] != 0 &&  matrix[i][j] != 2048)
      {
        if(!Elements.empty() && (matrix[i][j] == Elements.top()))
        {
          item = Elements.top();
          Elements.pop();
          Elements.push(item * 2);
          Elements.push(-1); 
          iterator++;
        }
        else
        {
          Elements.push(matrix[i][j]);
        }
      }
      else if(matrix[i][j] == 2048)
      {
        while(Elements.size() < iterator)
        {
          Elements.push(0);
        }
        Elements.push(2048);
      }
      iterator++;
    }
    while(Elements.size() < iterator)
    {
      Elements.push(0);
    }
  }

  for(int i = 0; i < matrix.size(); i++)
  {
    for(int j = 0; j < matrix.size(); j++)
    {
      temp = Elements.top();
      Elements.pop();
      if(temp == -1)
      {
        matrix[i][j] = Elements.top();
        Elements.pop();
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
bool Board::Possible(){ //checking if the matrix is solvable 
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
  while(total != 1 ){
    if(total % 2 != 0){
      return false;
    }
    total = total / 2;
  }
  return true;
}


bool Board::ImpToSolve(){ //similar to possible to solve, diff method

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
  
  int move = 0;
  for(int i = 0; i<matrix.size(); i++){
    for(int j = 0; j<matrix.size(); j++){
      if(matrix[i][j] != 0 && matrix[i][j] != 2048){
        move++;
        }
      }
    }
  
if(move == 1){
  return true; 
  }
else {
  return false;
}
}
 