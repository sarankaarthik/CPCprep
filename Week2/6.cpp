#include <bits/stdc++.h>
using namespace std;
 
void find(vector<int> nums)
{
  int seq = 1;       
   
  int min_num = nums[0]; 
   
  int max_seq = INT_MIN;     
   
  int store_min = min_num;  
   
  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i] == min_num)
      continue;
     
    else if (nums[i] < min_num)
    {
      min_num = nums[i];
      continue;
    }
     
    else if (nums[i] < max_seq) {   
      max_seq = nums[i];      
      store_min = min_num;           
    }
    else if (nums[i] > max_seq)
    {   
      seq++;
      if (seq == 3)
      {           
        cout << store_min << " " << max_seq << " " << nums[i] << endl;
        return;
      }
      max_seq = nums[i];
    }
  }
  cout << "No such triplet found";
}
 
int main()
{
  vector<int> nums {5,6,2,1,3,4,-1};
  find(nums);
}
