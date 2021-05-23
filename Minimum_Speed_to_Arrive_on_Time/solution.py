from math import ceil
class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        lowSpeed, highSpeed = 1, 10**9+1
        def check(speed):
            ## find the total minimum time taken to reach office
            ## if all trains travel at speed
            totalTimeTaken = 0
            for distance in dist[:-1]:
                ## we take ceil of time taken as 1.5 hours is same as 2 hours
                ## if you have to board another train as you need to wait for .5 hours
                curTrainTime = ceil(distance/speed)
                totalTimeTaken += curTrainTime

            ## On last train we don't ceil
            ## as we don't need to wait for any other train
            ## as we have already reached office
            totalTimeTaken += dist[-1]/speed
            ## returns true if travelling by speed on each train
            ## takes less time than hour(The time in which we have to reach office)
            return totalTimeTaken <= hour

        ## Guess a speed and binary search answer
        ## if takes 10^9 + 1 speed, it means no matter what you do
        ## u cannot reach office on time
        ## example  (hour = 1) trains needed to board >= 2
        ## first train itself takes 1 hour time in the minimum
        ## as you need to wait for second train
        while lowSpeed < highSpeed:
            midSpeed = (lowSpeed+highSpeed)//2
            if check(midSpeed):
                highSpeed = midSpeed
            else:
                lowSpeed = midSpeed+1
        if lowSpeed < 10**9 + 1:
            return lowSpeed ## lowest speed is needed
        return -1
