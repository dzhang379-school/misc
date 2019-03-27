import sys

n = int(raw_input())
lines = [""] * n

for i in range(n):
  lines[i] = raw_input().rstrip()

def qbf(lines):
    for line in lines:
        print(pangram(line))

def pangram(line):
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    missing = ""
    for i in range(26):
        if alphabet[i] not in line:
            missing += alphabet[i]
    return "pangram" if missing == "" else "missing {}".format(missing)

qbf(lines)
