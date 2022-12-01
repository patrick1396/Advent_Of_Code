#include <iostream>
#include <fstream>
using namespace std;



int main()
{
  string line;
  int file_length = 2000;
  int increase = 0;

  int a, b, c;
  int curr_sum, prev_sum;
  int i;


  ifstream myfile;
  myfile.open("input.txt");
  
  getline(myfile, line);
  a = stoi(line);

  getline(myfile, line);
  b = stoi(line);

  getline(myfile, line);
  c = stoi(line);

  curr_sum = a+b+c;
  
  for (i=1; i<file_length-2; i++)
    {
      prev_sum = curr_sum;
      a = b;
      b = c;
      getline(myfile, line);
      c = stoi(line);
      curr_sum = a+b+c;
      
      if (curr_sum>prev_sum)
	{
	  increase++;
	}
    }
  myfile.close();
  printf("%d\n", increase);
}
