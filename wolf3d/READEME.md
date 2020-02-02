# Wolf3D
	A Wolfenstein 3D gqme like. Project for [42 School Paris](https://www.42.fr/) project.

## Built with
	C Language, Racasting method, SDL2 graphic library.

## Features
*	3 game in 1. Lunch with 3rd argument {wolf | asylum | maze} for different texture and setup
*	Raycasting technique : Wall.
*	FloorCasting technique : Floor and Ceilling.
*	Move in any direction {arrow | WASD}
*	Rotation {Mouse | Q E}
*	Weapon {Button Left for Shoot | Button right for Switch gun}
*	Enemy with different sprite depending on the game
*	Shadow and Fog {F}
*	Minimap {M}

## How to use

<strong>Linux</strong>
$>apt-get install libsdl2 libsdl2_ttf libsdl2_mixer

<strong>MacOS</strong>
$>make SDL2

<strong>after SDL2 installed</strong>
$>make
$>./wolf3d map/name.wolf {wolf | asylum | maze}