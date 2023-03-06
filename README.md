# How to play
## Description
You will lose health when moving and when fighting gyms. Health can be recovered in pokemon centers. Potions cost money, which can be gained by moving. The goal is to defeat all of the gyms on the map.
## Commands
m ID x y
  "move": command Trainer ID to move to location (x, y)
c ID1 ID2
 "move towards a PokemonCenter”: command Trainer ID1 to start heading to PokemonCenter ID2.
g ID1 ID2
  “move towards a PokemonGym”: command Trainer ID1 to start heading towards PokemonGym ID2.
s ID
  "stop": command Trainer ID to stop doing whatever it is doing
p ID potion_amount
  “buy potions”: command Trainer ID to buy potion_amount of potion at a PokemonCenter.
b ID battle_amount
  “complete battle_amount battles at a PokemonGym”: command Trainer ID to complete battle_amount of battles at a PokemonGym.
a
  "advance": advance one-time step by updating each object once.
r
  "run": advance one-time step and update each object, and repeat until either the update function returns true for at least one of the objects, or 5 time steps have been done.
q
  "quit": terminate the program
n TYPE ID X Y- create a new object with the specified TYPE, ID number, (X, Y) location. 
  TYPE is a one letter abbreviation for the type of object:
    c – PokemonCenter
    g – PokemonGYM
    t – Trainer
    w – WildPokemon
## How to win
There are two trainers that you control. The game ends when both of the trainers die or all of the gyms are beaten. 
## Pokemon
The two pokemon spawn and will remain in there spot until a trainer reaches a certain proximty. In this range, the pokemon will begin to follow the trainer. Pokemon are faster than trainers, so the trainer must either defeat it or hide in a gym/center. When a pokemon is following a trainer, a they will deal damage to each other. A trainers damage is based on their experience points. When a trainer kills a pokemon, they will gain experience. 
## How to run
Use make makefile4.txt to compile. Run with ./PA4
