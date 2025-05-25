def get_game_id(line):
    game_id = line.split(":")[0].split(" ")[1]
    return game_id

def set_valid(incoming_set):
    ref_dict = {"red": 12, "green": 13, "blue": 14}
    for elements in incoming_set:
        color = elements.split(" ")[2]
        number = int(elements.split(" ")[1])
        # import pdb; pdb.set_trace()
        if (number > ref_dict[color]):
            return 0 # invalid set
    return 1

def determine_if_game_valid(line):
    sets = line.split(":")[1].split(";")
    for single_set in sets:
        single_set_split = single_set.split(",")
        if(set_valid(single_set_split) == 0):
            return 0 # invalid set
    return 1

def main():
    FILENAME = "puzzle_input"
    game_id_sum = 0
    with open(FILENAME, 'r') as filename:
        for line in filename:
            line = line.rstrip()
            game_id = get_game_id(line)
            if(determine_if_game_valid(line) == 1):
                game_id_sum = int(game_id_sum) + int(game_id)
                print(game_id)
    
    print("Game sum is {}".format(game_id_sum))


if __name__ == "__main__":
    main()