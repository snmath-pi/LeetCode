class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        
        m = Counter()
        for x in power:
            m[x]+=1
        power.sort()
        s = list(dict.fromkeys(power))
        n = len(s)
        f = [0]*n
        mx = [0]*n
        f[0] = s[0]*m[s[0]]
        mx[0] = s[0]*m[s[0]]
        for i in range(1, n): 
            f[i] = s[i]*m[s[i]]
            mx[i] = mx[i-1]
            if s[i-1] < s[i]-2:
                f[i] = max(f[i], f[i-1] + m[s[i]]*s[i])
            if i-2 >= 0:
                if s[i-2] < s[i]-2:
                    f[i] = max(f[i], f[i-2]+s[i]*m[s[i]])
            if i-3 >= 0:
                f[i] = max(f[i], mx[i-3] + s[i]*m[s[i]])
            mx[i] = max(mx[i], f[i])
        return max(f)
