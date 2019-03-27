import math
import sys

n = int(raw_input())
lines = []

for i in range(n):
    lines.append(sys.stdin.readline().rstrip('\n'))

def choose(n, r):
    return math.factorial(n) // (math.factorial(r) * math.factorial(n - r))
def binomial(trials, successes, p):
    return choose(trials, successes) * math.pow(p, successes) * math.pow(1.0 - p, trials - successes)
    
def binom_p(trials, min_successes, p):
    total = 0
    for i in range(min_successes, trials + 1):
        total += binomial(trials, i, p)
    return total

for line in lines:
    a = [ int(x) for x in line.split(' ') ]
    p = (a[1] - a[0] + 1) / float(a[1])
    total_p = binom_p(a[3], a[2], p)

    print "yes" if a[4] > 1/total_p else "no"

