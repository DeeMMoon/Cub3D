# Cub3D

## Rules
- Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside.
- Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.
- If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall , -Wextra and -Werror , and your Makefile must not relink.
- Your Makefile must at least contain the rules $(NAME), all , clean , fclean and re .
- To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file \_bonus.{c/h} . Mandatory and bonus part evaluation is done separately.
- If your project allows you to use your libft , you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile , then compile the project.
- We encourage you to create test programs for your project even though this work **won’t have to be submitted and won’t be graded** . It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git reposi- tory will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop.

**Mandatory part - cub3D**

|**Program name**|cub3D|
| - | - |
|**Turn in files**|All your files|
|**Makefile**|all, clean, fclean, re, bonus|
|**Arguments**|a map in format \*.cub|
|**External functs.**|<p>- open, close, read, write, malloc, free, perror, strerror, exit</p><p>- All functions of the math library (-lm man man 3 math)</p><p>- All functions of the MinilibX</p>|
|**Libft authorized**|Yes|
|**Description**|You must create a “realistic” 3D graphical representation of the inside of a maze from a first person perspective. You have to create this representation using the Ray-Casting principles mentioned earlier.|

The constraints are as follows:

- You must use the miniLibX. Either the version that is available on the operating system, or from its sources. If you choose to work with the sources, you will need to apply the same rules for your libft as those written above in Common Instructions part.
- The management of your window must remain smooth: changing to another win- dow, minimizing, etc.
- Display different wall textures (the choice is yours) that vary depending on which side the wall is facing (North, South, East, West).

cub3D My first RayCaster with miniLibX

- Your program must be able to display an item (sprite) instead of a wall.![ref1]
- Your program must be able to set the floor and ceilling colors to two different ones.
- In case the Deepthought has eyes one day to evaluate your project, your program must save the first rendered image in bmp format when its second argument is "––save" .
- If no second argument is supllied, the program displays the image in a window and respects the following rules:
- The left and right arrow keys of the keyboard must allow you to look left and right in the maze.
- The W, A, S and D keys must allow you to move the point of view through the maze.
- Pressing ESCmust close the window and quit the program cleanly.
- Clicking on the red cross on the window’s frame must close the window and quit the program cleanly.
- If the declared screen size in the map is greater than the display resolution, the window size will be set depending to the current display resolution.
- The use of images of the minilibX is strongly recommended.
- Your program must take as a first argument a scene description file with the .cub extension.
- The map must be composed of only 4 possible characters: **0** for an empty space, **1** for a wall, **2** for an item and **N**,**S**,**E** or **W** for the player’s start position and spawning orientation.

This is a simple valid map:



|111111|
| - |
|100101|
|102001|
|1100N1|
|111111|



- The map must be closed/surrounded by walls, if not the program must return an error.
- Except for the map content, each type of element can be separated by one or more empty line(s).
- Except for the map content which always has to be the last, each type of element can be set in any order in the file.
- Except for the map, each type of information from an element can be separated by one or more space(s).
- The map must be parsed as it looks like in the file. Spaces are a valid part of the map, and is up to you to handle. You must be able to parse any kind of map, as long as it respects the maps rules.
- Each element (except the map) firsts information is the type identifier (com- ![ref1]posed by one or two character(s)), followed by all specificinformations for each object in a strict order such as :

∗Resolution:

R 1920 1080

- identifier: **R**
- x render size
- y render size

∗North texture:

NO ./path\_to\_the\_north\_texture

- identifier: **NO**
- path to the north texure

∗South texture:

SO ./path\_to\_the\_south\_texture

- identifier: **SO**
- path to the south texure

∗West texture:

WE ./path\_to\_the\_west\_texture

- identifier: **WE**
- path to the west texure

∗East texture:

EA ./path\_to\_the\_east\_texture

- identifier: **EA**
- path to the east texure

∗Sprite texture:

S ./path\_to\_the\_sprite\_texture

- identifier: **S**
- path to the sprite texure

∗Floor color:

F 220,100,0

- identifier: **F**
- R,G,B colors in range [0,255]: **0, 255, 255**

∗Ceilling color:![ref1]

C 225,30,0

- identifier: **C**
- R,G,B colors in range [0,255]: **0, 255, 255**
- Example of the mandatory part with a minimalist **.cub** scene:



|R 1920 1080|
| - |
|NO ./path\_to\_the\_north\_texture|
|SO ./path\_to\_the\_south\_texture|
|WE ./path\_to\_the\_west\_texture|
|EA ./path\_to\_the\_east\_texture|
||
|S ./path\_to\_the\_sprite\_texture|
|F 220,100,0|
|C 225,30,0|
||
|1111111111111111111111111|
|1000000000110000000000001|
|1011000001110000002000001|
|1001000000000000000000001|
|111111111011000001110000000000001|
|100000000011000001110111111111111|
|11110111111111011100000010001|
|11110111111111011101010010001|
|11000000110101011100000010001|
|10002000000000001100000010001|
|10000000000000001101010010001|
|11000001110101011111011110N0111|
|11110111 1110101 101111010001|
|11111111 1111111 111111111111|
