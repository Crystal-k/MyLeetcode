class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
            sum.push_back(nums[i]);
    }
    
    int sumRange(int i, int j) {
        int res=0;
        for(int k=i;k<=j;k++){
            res+=sum[k];
        }

        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
 
// 方法二：优化 
 class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        sum.push_back(0);
        for(int i=0;i<nums.size();i++)
            sum.push_back(sum.back()+nums[i]);
    }
    
    int sumRange(int i, int j) {
        int res=sum[j+1]-sum[i];

        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
