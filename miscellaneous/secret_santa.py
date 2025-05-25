#!/usr/bin/env python3

from copy import deepcopy
from random import randint

# Build sibling list and copy of it for "drawing names out of hat"
sibling_list = ["Caitlin", "Casarah", "Zach", "Willy", "Audrey", "Grace", "Leah"]
hat = deepcopy(sibling_list)
# Dictionary to hold matched pairs
secret_santa_pairs = {}

# Each sibling draws a name from the hat
for sibling in sibling_list:
    # Keep drawing names until you get one that is not your own
    sibling_match = sibling
    while sibling == sibling_match:
        pick_name_index = randint(0, len(hat)-1)
        sibling_match = hat[pick_name_index]
    # Record match
    secret_santa_pairs.update({sibling: sibling_match})
    # Remove name from hat
    hat.remove(sibling_match)

# print the names
for name1,name2 in secret_santa_pairs.items():
    print(f"{name1} picked {name2}")
