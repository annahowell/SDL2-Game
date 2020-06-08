# SDL2_Game

Simple SDL2 asteroids type top-down 2D game, created to learn C++, SDL2 and more maths. Currently lacks asteroids and guns on the spaceship but these are planned at some point.


## Compiling and Running

### Linux

1. Use your distros package manager to install sdl2, sdl2_gfx and sdl2_image and required build tools e.g.:  `sudo apt install libsdl2-dev libsdl2-gfx-dev libsdl2-image-dev cmake build_essential` (The FindSDL2* files in the included cmake folder should find the sdl2 files in the associated folders).

2. Run the following commands at the commandline:  
`mkdir build `   
`cd build`  
`cmake ../`  
`cmake --build ./`

3. From the root / dir (containing the game folder) run the game:  
`./game/SDL2_Game`

### MacOS

1. Install brew and then run `brew install sdl2 sdl2_gfx sdl2_image` (The FindSDL2* files in the included cmake folder should find the sdl2 files in the /usr/local/Cellar/ folders).

2. Run the following commands at the commandline:  
`mkdir build `   
`cd build`  
`cmake ../`  
`cmake --build ./`

3. From the root / dir (containing the game folder) run the game:  
`./game/SDL2_Game`  


## Shoutouts

Thanks to [webtreats](https://www.flickr.com/photos/webtreatsetc/) for the [nebula images](https://www.flickr.com/photos/webtreatsetc/4081217254/) used for the layers and modified to add transparency under the [CC BY 2.0](https://creativecommons.org/licenses/by/2.0/) licence. More thanks to [Rawdanitsu](https://opengameart.org/users/rawdanitsu) for the [spaceship image](https://opengameart.org/content/some-top-down-spaceships) used under the [CC0 1.0](https://creativecommons.org/publicdomain/zero/1.0/) licence.

Additional thanks to [aminosbh](https://github.com/aminosbh) for their sdl2 cmake [modules](https://github.com/aminosbh/sdl2-cmake-modules).


## Screenshots

![GameMov](https://github.com/annahowell/SDL2_Game/blob/master/screenshots/SDL2_Game.webp)

![GameStill](https://github.com/annahowell/SDL2_Game/blob/master/screenshots/SDL2_Game.jpg)
