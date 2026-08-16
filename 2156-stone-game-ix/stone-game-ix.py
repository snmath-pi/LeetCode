class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        cnt0, cnt1, cnt2 = 0, 0, 0
        for x in stones:
            if x % 3 == 0:
                cnt0 += 1
            elif x % 3 == 1:
                cnt1 += 1
            else:
                cnt2 += 1
        
        if cnt0 & 1:
            return cnt1 - cnt2 > 2 or cnt2 - cnt1 > 2
        
        return cnt1 >= 1 and cnt2 >= 1
                