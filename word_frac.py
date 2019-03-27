import string
from string import ascii_lowercase

word = input('Word: ')
letters = {}
for c in ascii_lowercase:
	letters[c] = (ord(c) - 87)
print('(')
for i in range(len(word)):
	print(letters.get(word[i]), '*36^', len(word)-1-i)
	if i < len(word) - 1:
	    print('+')
print(')/(36^', len(word), '- 1) in base 36')





	
	
