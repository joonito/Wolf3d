# Wolf3d

## MiniLibX is...
- Library including the minimum necessary to open a window, light a pixel and deal with events linked to this window: keyboard and mouse. 

** Don't forget man mlx! **  

### man1/mlx.1
```c
void *mlx_int();
```
#### What can be done with MiniLibX?
1. Dimple window creation
2. Drawing
3. Image management
4. Events management (such as mouse, keboard..)

#### BSD/LINUX X-Window
Network-oriented graphical system for Unix.<br>
**X-Window** has tow main parts
1. Draw something on the screen and/or get keboard entries.
2. The X-Server manages the screen, keboard and mouse (It is often refered to as a "display")
                                  network connection  
drawing orders       : (software) -----------------> (X-Server)  
keboard/mouse events : (X-Server) -----------------> (software)  

#### MACOSX CONCEPT
The MacOSX operating system handle graphical access to the screen (or "display")<br>

<pre>           draw<br>
(software) -----> (screen)<br>
<pre>            get<br>
(software) <----- (keyboard & mouse entries)<br>

#### INCLUDE FILE
mlx.h should be included for a correct use of the MiniLibX API. It only contains function proto types, no structure is needed.

#### LIBRARY FUNCTIONS

First, we need to initialize the connection between the software and display.<br>
            initialize connection<br>
(software) <----------------------> (display)<br>
Second, send graphical orders
           draw yellow pixel in this window<br>
(software) --------------------------------> (display)<br>


## Things to know
* Cocoa programming
* keyborad & mouse entries
