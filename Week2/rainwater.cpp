class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        int res = 0;
        for (int i = 1; i < n-1; i++)
        {
            int left = a[i];
            for (int j=0; j<i; j++)
               left = max(left, a[j]);
            int right = a[i];
            for (int j=i+1; j<n; j++)
               right = max(right, a[j]);
           res = res + (min(left, right) - a[i]);  
        }
        return res;
    }
};
