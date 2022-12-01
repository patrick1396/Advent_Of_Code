#include <iostream>
#include <fstream>
using namespace std;



int main()
{
  string line;
  int file_length = 2000;
  int increase = 0;

  int prev_in, curr_in;
  int i;


  ifstream myfile;
  myfile.open("input.txt");
  
  getline(myfile, line);
  curr_in = stoi(line);
  
  for (i=1; i<file_length; i++)
    {
      prev_in = curr_in;
      getline(myfile, line);
      curr_in = stoi(line);
      if (curr_in>prev_in)
	{
	  increase++;
	}
    }
  myfile.close();
  printf("%d\n", increase);
}
