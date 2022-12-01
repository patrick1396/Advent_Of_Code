#include <iostream>

int main()
{
  int l_mulp { 1 }, check_num{};
  //l_mulp is the lowst common multiple, check_num is the number used to check
  //l_mulp starts as 1 as all integers are multiples of 1
  
  check_num = l_mulp;
  //check_num initialised to be equal to l_mulp
  
  for (int count=2; count <= 20; ++count)
    //for loop from 2 to 20 to find lowest common multiple
    {
      
      do
	{
	if (check_num % count == 0)
	  //Check whether check_num is a multiple of the current count
	  {
	    //if true, set l_mulp to check_num and break from loop
	    l_mulp = check_num;
	    break;
	  }
	
	else
	  {
	    //if false then increment check_num by l_mulp
	    check_num = check_num + l_mulp;
	  }
	}
      while(true);
      
    }
  std::cout << l_mulp << "\n";
}
