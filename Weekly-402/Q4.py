class Solution:
    
    def countOfPeaks(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums)
        u = 1
        while u <= n: 
            u *= 2
        seg = [0] * (u * 2)
        
        def build(v, tl, tr):
            if tl == tr:
                if tl - 1 >= 0 and tl + 1 < n:
                    seg[v] = 1 if nums[tl] > nums[tl - 1] and nums[tl] > nums[tl + 1] else 0
                else:
                    seg[v] = 0
            else:
                tm = (tl + tr) // 2
                build(2 * v, tl, tm)
                build(2 * v + 1, tm + 1, tr)
                seg[v] = seg[2 * v] + seg[2 * v + 1]
        
        def get(v, tl, tr, l, r):
            if l > r:
                return 0
            if tl == l and tr == r:
                return seg[v]
            tm = (tl + tr) // 2
            return get(2 * v, tl, tm, l, min(tm, r)) + get(2 * v + 1, tm + 1, tr, max(tm + 1, l), r)
        
        def update(v, tl, tr, pos, val):
            if tl == tr:
                nums[tl] = val
                if tl - 1 >= 0 and tl + 1 < n:
                    seg[v] = 1 if nums[tl] > nums[tl - 1] and nums[tl] > nums[tl + 1] else 0
                else:
                    seg[v] = 0
                
            else:
                tm = (tl + tr) // 2
                if pos <= tm:
                    update(2 * v, tl, tm, pos, val)
                else:
                    update(2 * v + 1, tm + 1, tr, pos, val)
                seg[v] = seg[2 * v] + seg[2 * v + 1]
        
        
        build(1, 0, n - 1)
        ans = []
        for x in queries:
            if x[0] == 1:
                ans.append(get(1, 0, n - 1, x[1]+1, x[2]-1))
            else:
                update(1, 0, n - 1, x[1], x[2])
                if x[1]-1>=0:
                    update(1, 0, n-1, x[1]-1, nums[x[1]-1])
                if x[1]+1<n:
                    update(1, 0, n-1, x[1]+1, nums[x[1]+1])
        
        return ans
