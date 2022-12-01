#include <iostream>
#include <fstream>
using namespace std;


int main()
{
  string line;
  int file_length = ;
  int in_int
  
  ifstream myfile;
  myfile.open("input.txt");
  
  getline(myfile, line);
  in_int = stoi(line);
  
  for (i=1; i<file_length; i++)
    {
      getline(myfile, line);
      in_int = stoi(line);
    }
  myfile.close();
  printf("%d\n", in_int);
}
