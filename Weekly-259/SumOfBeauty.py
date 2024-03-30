class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        n = len(nums)
        mn = [int(1e18) for _ in range(n)]
        mn[-1] = nums[-1]
        for i in range(n-2, -1, -1):
            mn[i] = min(mn[i+1], nums[i])
        
        res = 0
        
        mx = int(-1e18)
        for i in range(n):
            if i == 0 or i == n-1:
                mx = max(nums[i], mx)
                continue
                
            else:
                if mx < nums[i] < mn[i+1]:
                    res += 2
                    mx = max(nums[i], mx)
                    continue
                elif nums[i-1] < nums[i] < nums[i+1]:
                    res += 1
                    mx = max(nums[i], mx)
                else:
                    mx = max(nums[i], mx)
        return res
                    
                
            
