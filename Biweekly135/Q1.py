class Solution:
    def losingPlayer(self, x: int, y: int) -> str:
        cur = 0
        while x >= 1 and y >= 4:
            x-=1
            y-=4
            cur^=1
        return "Alice" if cur == 1 else "Bob"
