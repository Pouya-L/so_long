# Project Overview
This project presents a compact 2D game that focuses on integrating textures, sprites, and fundamental gameplay elements. The primary goal is to provide hands-on experience with these graphical aspects.

# Storyline
Awakening in a dungeon with only a katana and a faint memory of a loved one's request for sentient eggplants, you encounter tranquilized zombies. Although non-aggressive, these zombies pose a threat if you collide with them, you'll get hurt and might die. Eliminate them using your katana. Collect all eggplants and find the exit to escape the dungeon.

https://github.com/Pouya-L/so_long/assets/119332828/adaa2968-e182-4bb4-bc68-7f3f0c70db32

# Minilibx
## Graphic Library: Minilibx
This project exclusively utilizes the Minilibx (MLX), a simplistic graphic library supplied with the project specifications. You can locate it on [GitHub](https://github.com/42Paris/minilibx-linux) 

# Map Composition
## Map Specifications
- The map is confined to specific characters:
  - Empty space: 0
  - Wall: 1
  - Player: P
  - Exit: E
  - Collectible: C
- The map, stored as a .ber file, must be rectangular and enclosed by walls.
- Each map must feature precisely one player, one exit, and at least one collectible. For bonus maps, an enemy is also required.
- A valid path must exist in the map. If the exit or any collectible is obstructed by walls, rendering the map invalid.

# How to Play
## Controls
- Move using W, A, S, D, or arrow keys.
- Attack right with E and left with Q.
- Health points (3 in total) are displayed on the right; losing all leads to death. Although, try to die once, it might be intresting!
- Discover an Easter egg to transform zombies into Barbie zombies.

https://github.com/Pouya-L/so_long/assets/119332828/d1d2523c-bf9d-42fd-87ba-55ac6e979468\

# What I Learned
## Key Takeaways
In the course of this project, I acquired valuable insights into:
- Utilizing a simple graphic interface (MLX).
- Managing events through hook functions.
- Employing the random number generation function from the math library.
- Enhancing variable definitions and error messages for code readability.
- Using Procreate to edit and make new sprites.
- Improving skills in creating effective tests and seeking assistance from peers.

## Challenges Faced
Encountering dynamic random enemies posed a significant challenge. Avoiding the common representation of zombies (Z) on the map led to the need for random enemy spawns post-game initiation. Overcoming complexities in generating random enemy movements, considering their coordinates to prevent overlap, required extensive trial and error. Ultimately, the outcome was satisfactory, and while potential improvements may be considered in the future, the current focus remains on other ongoing projects.

# Personal Reflection
## Favorite Project Experience
Among my various projects, this stands out as a favorite. Witnessing tangible progress with each code addition was gratifying. While not as formidable as previous projects, the creative enjoyment derived from developing this small game was immensely rewarding. Looking forward, I may revisit and refine aspects when time permits, but for now, attention is directed towards other project commitments. 😊

###Special thanks to ashuuya on [OpenGameArt](https://opengameart.org/users/ashuuya), I used their spirits, added shadows, and made a few new frames when needed.
