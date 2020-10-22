# PTT_Groupproject

# Explanation about the game (Goal of the game):
The ultimate goal of this game is to kill different monsters. The user can damage the monster’s HP by playing a number game. In each round, the user and the monster have to select a number from the three numbers given to beat the monster. If the user’s number is greater than the monster the user wins and damages the monster’s HP, otherwise the user receives the damage. The round ends until the user or the monster dies or all of the numbers in the deck are used. After each round the user can purchase different items. With a limited number of rounds, the game ends when the user or the monster dies, or at the last round.

At round 1, the user and the monster are assigned 3 numbers each. The numbers are randomly selected by the  from the integer range of 1 <= number <= 20. The user and the monster do not know the others’ number. The user and the monster will select one number from the three given

# Rules:
A user can choose the difficulty level. Easy game has 4 stages, intermediate  has 6 stages and Hard has 9 stages. 

 	Each stage user and monster are assigned three random cards from the deck which are composed of the number from 1 to 20 without repetition. At each stage, the user can decide a card for the battle. If the user picks a card which is higher than that of the monster picked, the user damages the monster’s HP, vise versa. Then the user and the monster pick one card each from the remaining deck and start round 2. If the user gives a damage over the total HP of the monster 1 the user can move on to defeat the next monster 2.  
If the user does not kill the monster until exhausting all cards from the deck, the system would judge by comparing the HP of the user and the monster. Whoever has the higher HP at the end would survive. Every end of the stage, the user can buy one of the three items before entering the next stage. The money to purchase the item will be the sum of the remaining cards that the user has not selected to battle. A weapon that will increase the certain damage of the card. An armor will reduce the damage that the user received. A potion will increase certain HP. All abilities of times will be decided randomly while reflecting the difficulties.

Users can save and load the file anytime they want at each round. 

# Control:
choosing the card from one’s options: Users can choose a card which he owns. One can only choose from the cards he got. If one choose the card not on one’s options, one should choose again.
After each stage, users can choose an item by typing (w= weapon, a= armor, p= potion) after examining the ability of the game. For the confirmation, one should type Y/N after selecting the item. If users type ‘N,’ users can see the item options again.
At each round, users can type ‘save’ instead of typing a card option. If so, users can save the current status, and leave the game. Users can load the file before starting the game from the main screen.
Users can exit the game by typing ‘terminate.’ Unsave files will not be saved. 

# List of features that we plan to implement:
Generation of random game sets or events
A HP of monster will be randomly generated. Its HP will be same or greater than that of the previous monster ( Stage 1 monster HP is fixed as 100). 
At every stage 3 cards will be randomly given to a user and monster. Also after every round one random card will be given to the user and the monster.
An option of every item will be randomly selected. 
 
# Data structures for storing game status
Individual users’ profiles will be created. To distinguish each user, the user will input the name and age data of the file.
 
 
# Dynamic memory management
HP Data: Before the start of the game, an integer value for the monster’s and the user’s HP will be set. After each stage the monster’s or the user’s HP will be deducted by the amount of damage. 
Item inventory Data: When the user purchases an item, the item earned will be stored in the item inventory data. When the user uses an item, the used item will be deleted from the inventory
 
 
# File input/output (e.g., for loading/saving game status)
The user can create their own profile. The game will save the game progress to a file according to the user’s name. When the user wishes to save and exit, and when re-entering the game, by typing the same name the user can continue from the previous end section. 
 
# Program codes in multiple files
Each stage, item store will be generated in different files.
