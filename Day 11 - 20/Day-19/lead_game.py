# Number of Rounds
rounds = int(input())

# Initial Score of Both Player
player_1 = 0
player_2 = 0
lead = 0
diff = 0

for _ in range(rounds):
    score_1, score_2 = map(int, input().split())
    player_1 += score_1
    player_2 += score_2
    if(player_2 > player_1):
        diff = player_2 - player_1
        if diff > lead:
            lead = diff
            winner = 2
    elif(score_1 > score_2):
        diff = player_1 - player_2
        if diff > lead:
            lead = diff
            winner = 1
        
print("{} {}".format(winner, lead))