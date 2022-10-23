import itertools

word = input()
all_combinations = list(map(''.join, itertools.product(*zip(word.upper(), word.lower()))))

all_combinations.sort(reverse=True)
print((all_combinations))
print(len(all_combinations))