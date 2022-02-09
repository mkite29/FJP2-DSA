
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        //size kitna hoga resultant ka 
        int size = nums.size() - k + 1;
         int idx = 0;
        
        vector<int> res(size);
        deque<int> dq;
        
        for(int i = 0;i<nums.size();i++){
            
            //jab window exceed ker jaye to front se hata do
            if(dq.size() > 0 && dq.front() <= i - k){
                dq.pop_front();
            }
            
            //jab current element deque ke peeche element se bade ho to hosakta hai
            //ek ho ya  jyada ho to sabko remove kerna hai to while loop chalaya
            while(dq.size() > 0 && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            
            //current element ko push back kerdo
            dq.push_back(i);
            
            
            //and result mei deque ke front ko jabhi add karo jab window size ke barabar 
            //ho jaye.
            if(i + 1 >= k){
                res[idx++] = nums[dq.front()];
            }
            
        }
        
        return res;
    }
};
