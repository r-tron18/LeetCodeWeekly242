class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        one, zero = 0, 0
        charFreq = 0
        prevChar = s[0]
        for char in s:
            if char == prevChar:
                charFreq+=1
            else:
                if prevChar == '0': zero = max(zero, c)
                else              : one = max(one, c)
                charFreq = 1
            prevChar = char
        if prevChar == '0': zero = max(zero, c)
        else              : one = max(one, c)

        return one > zero
