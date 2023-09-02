# Cub3D

![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.001.png)

cub3D![ref1]

My first RayCaster with miniLibX

*Summary: This project is inspired by the world-famous eponymous 90’s game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to*

*make a dynamic view inside a maze, in which you’ll have to find your way.*

![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.003.png)

**Contents![ref1]**

[**I Foreword](#_page2_x72.00_y72.00) **2 [II Goals](#_page3_x72.00_y72.00) 3 [III Common Instructions](#_page4_x72.00_y72.00) 4 [IV Mandatory part - cub3D](#_page5_x72.00_y72.00) 5**

[**V Bonus part](#_page9_x72.00_y72.00) **9 [VI Examples](#_page11_x72.00_y72.00) 11**

![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.004.png)

<a name="_page2_x72.00_y72.00"></a>**Chapter I Foreword![ref1]**

Developed by Id Software by the über famous John Carmack and John Romero, pub- lished in 1992 by Apogee Software , Wolfenstein 3D is the first true “First Person Shooter” in the history of video games.

![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.005.png)

Figure I.1: John Romero (left) and John Carmack (right) posing for posterity.

Wolfenstein 3D is the ancestor of games like Doom(Id Software , 1993), Doom II (Id Software , 1994), Duke Nukem 3D(3D Realm, 1996) and Quake(Id Software , 1996), that are additional eternal milestones in the world of video games.

Now, it’s your turn to relive History...

<a name="_page3_x72.00_y72.00"></a>**Chapter II ![ref1]Goals**

This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use of basic algorithms, information research etc.

As a graphic design project, cub3D will enable you to improve your skills in these areas: windows, colors, events, fill shapes, etc.

To conclude cub3D is a remarkable playground to explore the playful practical appli- cations of mathematics without having to understand the specifics.

With the help of the numerous documents available on the internet, you will use mathematics as a tool to create elegant and efficient algorithms.

![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.006.png)

We recommend that you test the original game before starting this project:

<http://users.atw.hu/wolf3d/>

<a name="_page4_x72.00_y72.00"></a>**Chapter III ![ref1]Common Instructions**

- Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside.
- Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation.
- All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated.
- If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall , -Wextra and -Werror , and your Makefile must not relink.
- Your Makefile must at least contain the rules $(NAME), all , clean , fclean and re .
- To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file \_bonus.{c/h} . Mandatory and bonus part evaluation is done separately.
- If your project allows you to use your libft , you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile , then compile the project.
- We encourage you to create test programs for your project even though this work **won’t have to be submitted and won’t be graded** . It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating.
- Submit your work to your assigned git repository. Only the work in the git reposi- tory will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop.

<a name="_page5_x72.00_y72.00"></a>**Chapter IV![ref1]**

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

5
cub3D My first RayCaster with miniLibX![ref2]

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

R 1920 1080![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.008.png)

- identifier: **R**
- x render size
- y render size

∗North texture:

NO ./path\_to\_the\_north\_texture![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.009.png)

- identifier: **NO**
- path to the north texure

∗South texture:

SO ./path\_to\_the\_south\_texture![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.010.png)

- identifier: **SO**
- path to the south texure

∗West texture:

WE ./path\_to\_the\_west\_texture![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.011.png)

- identifier: **WE**
- path to the west texure

∗East texture:

EA ./path\_to\_the\_east\_texture![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.012.png)

- identifier: **EA**
- path to the east texure

∗Sprite texture:

S ./path\_to\_the\_sprite\_texture![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.013.png)

- identifier: **S**
- path to the sprite texure

∗Floor color:

F 220,100,0![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.014.png)

- identifier: **F**
- R,G,B colors in range [0,255]: **0, 255, 255**

∗Ceilling color:![ref1]

C 225,30,0![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.015.png)

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

- If any misconfiguration of any kind is encountered in the file, the program must exit properly and return "Error\n" followed by an explicit error message of your choice.

8

<a name="_page9_x72.00_y72.00"></a>**Chapter V Bonus![ref1] part**

Bonuses will be evaluated only if your mandatory part is PERFECT.![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.016.png)

By PERFECT we naturally mean that it needs to be complete, that it cannot fail, even in cases of nasty mistakes like wrong uses etc. Basically, it means that if your mandatory part does not obtain ALL the points during the grading, your bonuses will be entirely IGNORED.

Bonus list:

- Wall collisions.
- A skybox.
- Floor and/or ceiling texture.
- An HUD.
- Ability to look up and down.
- Jump or crouch.
- A distance related shadow effect.
- Life bar.
- More items in the maze.
- Object collisions.
- Earning points and/or losing life by picking up objects/traps.
- Doors which can open and close.
- Secret doors.
- Animations of a gun shot or animated sprite.
- Several levels.
- Sounds and music.
- Rotate the point of view with the mouse.

9
cub3D My first RayCaster with miniLibX![ref2]

- Weapons and bad guys to fight!![ref1]

To earn all bonus points you need to validate at least 14 of them, so choose![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.017.png) wisely but be careful to not waste your time!

You are allowed to use other functions to complete the bonus part as long![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.018.png) as their use is justified during your evaluation. You are also allowed to modify the expected scene file format to fit your needs. Be smart!

10

<a name="_page11_x72.00_y72.00"></a>**Chapter VI Examples![ref1]**

![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.019.png) ![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.020.png) ![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.021.png)

Figure VI.1: Wolfeinstein3D original game usinfg RayCasting.

![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.022.jpeg)

Figure VI.2: Example of what your project could look like as per the mandatory part.

11
cub3D My first RayCaster with miniLibX![ref2]

![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.023.jpeg)![ref1]

Figure VI.3: Example of the bonus part with a minimap, floor and ceilling textures and an animated

famous hedgehog sprite.

![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.024.jpeg)

Figure VI.4: Another example of the bonus part with an HUD, a life bar, sounds and music, a shadow effect and a gun which can shoot.

![](Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.025.jpeg)![ref1]

Figure VI.5: Another example of the bonus part with another weapon choice and with the player

looking at the ceilling.
13

[ref1]: Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.002.jpeg
[ref2]: Aspose.Words.6b2d879e-a948-4162-aa42-ffbe2d0af55a.007.png
