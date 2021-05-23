class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        length = len(s)
        queue1, queue2 = [], [length-1]
        if s[length - 1] == "1":
            return False
        for ind in range(length-2, -1, -1):
            while queue1 and queue1[0] > ind + maxJump:
                queue1.pop(0)
            while queue2 and queue2[0] >= ind + minJump:
                queue1.append(queue2[0])
                queue2.pop(0)
            if queue1 and s[ind] == "0":
                queue2.append(ind)
        return 0 in queue2
