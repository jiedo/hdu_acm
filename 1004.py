import random
import sys


number = 1000

def get_a_color():
    chars = "abcdefghijklmnopqrstuvwxyz"
    length = random.randint(1, 15)
    return "".join([chars[random.randint(0, 25)] for i in range(length)])


all_colors = []
for i in range(random.randint(1, number)):
    color = get_a_color()
    if color not in all_colors:
        all_colors += [color]


all_number = random.randint(len(all_colors), number)
while len(all_colors) < all_number:
    all_colors += [random.choice(all_colors)]

print all_number
for c in all_colors:
    print c


all_colors_dict = {}

for c in all_colors:
    if c not in all_colors_dict:
        all_colors_dict[c] = 1
    else:
        all_colors_dict[c] += 1

all_colors_pair = all_colors_dict.items()
all_colors_pair.sort(key=lambda x:x[1])

print 0

# for c in all_colors:
#     print >> sys.stderr, c

# for c in all_colors_pair:
#     print >> sys.stderr, c
print >> sys.stderr, all_colors_pair[-1]
