class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        res = 0
        for s in operations:
            if '+' in s:
                res += 1
            else: res -= 1
        return res
