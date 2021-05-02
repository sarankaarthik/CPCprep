#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> freq(vector<int> nums,int target)
{
    int low = 0;
        int high = nums.size() - 1;
        int index;
        vector<int> a;
        if(high < low)
        {
            a.push_back(-1);
            a.push_back(-1);
            return a;
        }
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] < target)
                low = mid + 1;
            else if(nums[mid] > target)
                high = mid - 1;
            else if(nums[mid] == target)
            {
                index = mid;
                break;
            }
            else
                index = -1;
                
        }
        if(index == -1)
        {
            a.push_back(-1);
            a.push_back(-1);
            return a;
        }
        int l = index;
        int r = index;
        int flag;
        while(nums[l] == target || nums[r] == target)
        {
            if(nums[l] == target && l > 0)
            {
                l--;
                flag = 1;
            }
            if(nums[r] == target && r < nums.size() - 1)
            {
                r++;
                flag = 1;
            }
            if(flag == 1)
                flag = 0;
            else
                break;
            
        }
        if(l == 0 && nums[l] == target)
            a.push_back(l);
        else
            a.push_back(l+1);
        if(r == nums.size() - 1 && nums[r] == target)
            a.push_back(r);
        else
            a.push_back(r-1);
        return a;
}

int main()
{
    vector<int> a{1,1,2,2,2,2,3,3,4};
    int x;
    cin>>x;
    vector<int> b = freq(a,x);
    cout<<b[1] - b[0] + 1<<" ";
}
