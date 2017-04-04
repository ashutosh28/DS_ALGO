#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <climits>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
int rows, cols;
int HighestScore = 0;
map<string,int> mywords;
map<string,int>::iterator it;

bool isValidWord(string str) { // checking validity of word in dictionary
  string line;
  ifstream dictionary;
  dictionary.open("Dictionary.txt");
  if(dictionary.is_open()) {

    while(!dictionary.eof()) {
        getline(dictionary,line);
        if (line.find(str, 0) != string::npos) {
          //word found
          dictionary.close();
          return true;
        }
    }
    dictionary.close();
  }else {
      cout<<"Unable to open this file."<<endl;
  }
  return false;

}
void DisplayMaxPointAndWords() {
  printf("Max Points user can achieve with given grid are: %d and words are as follows:\n", HighestScore);

  for(it = mywords.begin(); it != mywords.end(); it++) {
    printf("%s\n", it->first.c_str());
  }
}

bool isSafeMovement(char **grid, int r, int c, bool **visited) {
  if(r < 0 && r >= rows && c < 0 && c >= cols && *((visited+r*rows) + c)) {
    return false;
  }
  return true;
}

void DFSTraversal(char **grid, int *gridvalue[], int i, int j, int maxscore, bool **visited, string str) {
  static int yaxis_move[] = {-1, -1, -1, 0, 0, 1, 1, 1}; //moving all 8 adjacent cells
  static int xaxis_move[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  visited[i][j] = 1;//visited
  str = str + *((grid+i*cols)+j);
  int *x = *((gridvalue+i*cols)+j);
  maxscore += *x;
  if(isValidWord(str)){ // checking word in dictonary
    it = mywords.find(str); // storing "unique"(no duplicate word) achieved words
    if(it != mywords.end()){
      //duplicate word found
    }else{
      HighestScore += maxscore;
      mywords.insert(pair<string,int>(str,1));
    }
  }
  for(int k = 0; k < 8; k++) {
    if(isSafeMovement(grid, i + yaxis_move[k], j + xaxis_move[k], (bool**)visited)) {
      DFSTraversal((char**)grid, (int**)gridvalue, i + yaxis_move[k], j + xaxis_move[k], maxscore, (bool**)visited, str);
    }
  }
  visited[i][j] = 0; // backtracking of visited nodes
  str.erase(str.begin() + str.length() - 1); // erasing character from string for backtracking
  maxscore -= *x;

}//*((arr+i*n) + j)
int main() {
  int i, j, maxscore = 0;
  printf("Enter numbers of rows and cols of the grid: ");
  scanf("%d%d", &rows, &cols);
  string  str = "";
  char grid[rows][cols];
  int gridvalue[rows][cols];
  bool visited[rows][cols];
  memset(visited, 0, sizeof(visited));

  printf("Enter characters in grid with values :");
  for(i = 0; i < rows; i++) {
    for(j = 0; j < cols; j++) {
      //scanf("%c%d", &grid[i][j], &gridvalue[i][j]);
      scanf("%c", &grid[i][j]);
      scanf("%d", &gridvalue[i][j]);
      printf("%c%d",grid[i][j],gridvalue[i][j]);
    }
  }

  for(i = 0; i < rows; i++) {
    for(j = 0; j < cols; j++) {
      DFSTraversal((char**)grid,(int**)gridvalue,i,j,maxscore,(bool**)visited,str);// DFS traversal
    }
  }
  // Display Max Points/words a user can achieve.
  DisplayMaxPointAndWords();


  return 0;
}
