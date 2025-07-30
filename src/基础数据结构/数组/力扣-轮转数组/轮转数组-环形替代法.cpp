class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         k %= nums.size(); //避免多转好几圈
        int count = gcd(int(nums.size()),k);

        for(int start=0; start < count; start++)
        {
            int prve = nums[start];
            int current = start;

            do
            {
                int next = (current+k) % int(nums.size());
                swap(nums[next],prve);
                current = next;

            }while(current != start);
        }
         

    }
};