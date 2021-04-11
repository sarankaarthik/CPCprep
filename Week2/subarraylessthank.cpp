class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
    int n = a.size();
    long long p = 1;
    int res = 0;
    for (int start = 0, end = 0; end < n; end++)
    {
        p *= a[end];
        while (start < end && p >= k)
            p /= a[start++];
        if (p < k)
        {
            int len = end - start + 1;
            res += len;
        }
    }
 
    return res;
    }
};
