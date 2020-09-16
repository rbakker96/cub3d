<p align="center">
  <img src="https://github.com/rbakker96/images/blob/master/codam_logo.png">
</p>

# cub3D
***This project is inspired by the world-famous eponymous 90’s game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way***

---

### Project summary
> 2th ring Codam project

This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use of basic algorithms, information research etc. As a graphic design project, cub3D will enable you to improve your skills in these areas: windows, colors, events, fill shapes, etc. To conclude cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics. With the help of the numerous documents available on the internet, you will use mathematics as a tool to create elegant and efficient algorithms

---

### Technical considerations
> The project needs to comply with the following rules/functionalities.

- You must use the miniLibX. Either the version that is available on the operating system, or from its sources. If you choose to work with the sources, you will need to apply the same rules for your libft as those written above in Common
- The management of your window must remain smooth: changing to another window, minimizing, etc.
- Display different wall textures (the choice is yours) that vary depending on which side the wall is facing (North, South, East, West).
- Your program must be able to display an item (sprite) instead of a wall.
- Your program must be able to set the floor and ceilling colors to two different ones.
- In case the Deepthought has eyes one day to evaluate your project, your program must save the first rendered image in bmp format when its second argument is "––save".
- If no second argument is supllied, the program displays the image in a window and respects the following rules:
  - The left and right arrow keys of the keyboard must allow you to look left and right in the maze.
  - The W, A, S and D keys must allow you to move the point of view through the maze.
  - Pressing ESC must close the window and quit the program cleanly.
  - Clicking on the red cross on the window’s frame must close the window and quit the program cleanly.
  - If the declared screen size in the map is greater than the display resolution, the window size will be set depending to the current display resolution.
  - The use of images of the minilibX is strongly recommended.
- Your program must take as a first argument a scene description file with the .cub extension.
  - The map must be composed of only 4 possible characters: 0 for an empty space, 1 for a wall, 2 for an item and N,S,E or W for the player’s start position and spawning orientation.
  - The map must be closed/surrounded by walls, if not the program must return an error.
  - Except for the map content, each type of element can be separated by one or more empty line(s).
  - Except for the map content which always has to be the last, each type of element can be set in any order in the file.
  - Except for the map, each type of information from an element can be separated by one or more space(s).
  - The map must be parsed as it looks like in the file. Spaces are a valid part of the map, and is up to you to handle. You must be able to parse any kind of map, as long as it respects the maps rules.
  - Each element (except the map) firsts information is the type identifier (composed by one or two character(s)), followed by all specific informations for each object in a strict order.
  - If any misconfiguration of any kind is encountered in the file, the program must exit properly and return "Error\n" followed by an explicit error message of your choice.

---

### Usage
> A variety of maps (correct and incorrect) are provided in the folder "maps"

> Run the following commands in the terminal

```shell
$ git clone https://github.com/rbakker96/cub3d.git cub3d
$ cd cube3d
$ make
-> To play the game
$ ./cub3D maps/correct_one.cub
-> To make an bmp image of the players view (folder "screenshot")
$ ./cub3D maps/correct_one.cub ––save 
```

---

### Used resources
> Most noteworthy resources used during this project

- <a href="https://lodev.org/cgtutor/raycasting.html" target="_blank">Lode's Computer Graphics Tutorial</a>
- <a href="https://www.geeksforgeeks.org/enumeration-enum-c/" target="_blank">Enumeration</a>
- <a href="https://www.geeksforgeeks.org/union-c/?ref=lbp" target="_blank">Union</a>
- <a href="https://www.geeksforgeeks.org/structures-c/?ref=lbp" target="_blank">Structures</a>


