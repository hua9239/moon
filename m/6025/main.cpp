#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;
//?T?w?ܼƭ? 
const int rows = 8;
const int columns = 4;
/*
const double horizontal = 1.5;
const double vertical = 2.0;
const double diagonally = 2.5;
enum Shape_Set { point = 1, line, triangle, square, rectangle, parallelogram, pentagon };
*/

//?P?_???ʨ?? 
void move(int* record, const int x, const int y){
  //double stamina[columns][rows] = {};
  
  // ?j??|?@??????A???쪱?a???ʨ?y???I???۾F?@??d??
  while (!(abs(record[0] - x) <= 1 && abs(record[1] - y) <= 1)) {
    if(record[0] == x || record[0]+1 == x && record[0]+1 < 4 || record[0]-1 == x && record[0]-1 >= 0){
      if(y > record[1]) {
        record[1] = y-1;
        break;
      } 
      else if(y < record[1]){
        record[1] = y+1;
        break;
      }
    }
    else if(record[1] ==  y || record[1]+1 == y && record[1]+1 < 8 || record[1]-1 == y && record[1]-1 >= 0){
      if(x > record[0]){
        record[0] = x-1;
        break;
      }
      else if(x < record[0]){
        record[0] = x+1;
        break;
      }
    }
    else{
      if(x > record[0] && y > record[1]){
        record[0]++ ;
        record[1]++ ;
      }
      else if(x > record[0] && y < record[1]){
        record[0]++ ;
        record[1]-- ;
      }
      else if(x < record[0] && y > record[1]){
        record[0]-- ;
        record[1]++ ;
      }
      else{
        record[0]-- ;
        record[1]-- ;
      }
    }
  }
  
}

// ?ˬd?O?_?T???I?bx?b?By?b?αײv??+1??-1???P?@???u?W
bool same_line(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x1 == x2 && x2 == x3) || // ?P?@x?b
           (y1 == y2 && y2 == y3) || // ?P?@y?b
           ((y2 - y1 == x2 - x1) && (y3 - y2 == x3 - x2)) || // ?ײv+1
           ((y2 - y1 == -(x2 - x1)) && (y3 - y2 == -(x3 - x2))); // ?ײv-1
}

void Eliminate_Points(vector<vector<int> >& locate) {
    vector<pair<int, int> > points;

    // ?M???}?C?A?N?Ȭ?1???I?O???U??
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            if (locate[i][j] == 1) {
                points.push_back({i, j});
            }
        }
    }

    // ?ˬd?T???I?O?_?b?P?@???u?W
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = i + 1; j < points.size(); j++) {
            for (size_t k = j + 1; k < points.size(); k++) {
                if (same_line(points[i].first, points[i].second, points[j].first, points[j].second, points[k].first, points[k].second)) {
                    // ?]?m??쪺?I??0
                    locate[points[j].first][points[j].second] = 0;
                    //cout << "Removed point (" << points[j].first << "," << points[j].second << ")" << endl;
                }
            }
        }
    }
}

//?P?_?O????Ϊ? 
string shape(vector<vector<int> >& locate){
    
  //?R???@?u?I 
  Eliminate_Points(locate);
  
  //?p?⦳?X???I    
  int Landing_Point = 0;
  for(int i = 0; i < columns ; i++)
    for(int j = 0; j < rows ; j++)
      if(locate[i][j] == 1)
        Landing_Point++;
  
  //?P?_?Ϊ?
  if(Landing_Point == 1)  return "point";
  else if(Landing_Point == 2) return "line";
  else if(Landing_Point == 3)  return "triangle";
  else if(Landing_Point == 4) return "parallelogram";
  else return "pentagon";
}

int main(){
  //??l?ȳ]?w 
  int record[2] = {};
  vector<vector<int> > locate(columns, vector<int>(rows, 0));
  int input[2][2];
  //??J?_?I
  cin >> record[0] >> record[1]; 
  locate[record[0]][record[1]] = 1;
  
  //??J?вy???I 
  for(int i = 0; i < 2 ; i++){
    for(int j = 0; j < 2 ; j++){
      cin >> input[i][j];
    }
    //?p?Ⲿ???I 
    move(record,input[i][0],input[i][1]);
    
    // ?p?G?????I?M???I???P?A?~???O????
      if (record[0] != input[i][0] || record[1] != input[i][1]) {
          locate[record[0]][record[1]] = 1;
      }
    //?????вy???I
    locate[input[i][0]][input[i][1]] = 1;
    
  }
  
  //?N???G?s?_?? 
  string res = shape(locate);
  
  //??X???G 
  cout << res << endl;
}