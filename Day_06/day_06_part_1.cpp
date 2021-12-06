#include <iostream>
#include <fstream>
#include <list>
using namespace std;


int main()
{
  string line;
  int width, len, com_pos;
  
  int search_num;
  int i;
  list<int> gestation;
  list<int>::iterator iter;
  
  ifstream myfile;
  myfile.open("test_input.txt");
  
  getline(myfile, line);
  cout << line << "\n" << "\n";

  myfile.close();

  width = -1;
  len = line.length();
  while(width<len)
    {
      width++;
      com_pos = line.find(",", width+1);
      if (com_pos<0)
      	{
      	  search_num = stoi(line.substr(width, string::npos));
  	  width = len;
      	}
      else
      	{
  	  search_num  = stoi(line.substr(width, com_pos-width));
  	  width = com_pos;
  	}
      gestation.push_back(search_num);
    }

  for (i=0; i<80; i++)
    {
      for(iter=gestation.begin(); iter !=gestation.end(); ++iter)
	{
	  if (*iter==0)
	    {
	      *iter = 6;
	      gestation.push_back(9);
	    }
	  else
	    {
	      --*iter;
	    }
	}
    }

}





