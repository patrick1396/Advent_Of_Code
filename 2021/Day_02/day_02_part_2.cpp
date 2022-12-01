#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
  string line;
  string in_str;
  int file_length = 1000;
  int in_int;
  int space_pos;

  int horiz_pos = 0;
  int verti_pos = 0;
  int aim = 0;
  int i;
  
  ifstream myfile;
  myfile.open("input.txt");
  
  
  for (i=0; i<file_length; i++)
    {
      getline(myfile, line);
      space_pos = line.find(" ");
      in_str = line.substr(0, space_pos);
      in_int = stoi(line.substr(space_pos+1, string::npos));

      if (in_str=="forward"){
	horiz_pos+=in_int;
	verti_pos+=in_int*aim;
      }
      else if (in_str=="down"){
	aim+=in_int;
      }
      else if (in_str=="up"){
	aim-=in_int;
      }
    }
  myfile.close();
  printf("%d, %d, %d\n", horiz_pos, verti_pos, horiz_pos*verti_pos);
}
