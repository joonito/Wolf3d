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
**X-Window** has tow main parts<br>
1. Draw something on the screen and/or get keboard entries.
2. The X-Server manages the screen, keboard and mouse (It is often refered to as a "display")
<pre>                                  network connection  
drawing orders       : (software) -----------------> (X-Server)  
keboard/mouse events : (X-Server) -----------------> (software)  
</pre>
#### MACOSX CONCEPT
The MacOSX operating system handle graphical access to the screen (or "display")<br>

<pre>           draw<br>
(software) -----> (screen)<br>
            get<br>
(software) <----- (keyboard & mouse entries)<br>
</pre>
#### INCLUDE FILE
mlx.h should be included for a correct use of the MiniLibX API. It only contains function proto types, no structure is needed.

#### LIBRARY FUNCTIONS

First, we need to initialize the connection between the software and display.<br>
<pre>            initialize connection<br>
(software) <----------------------> (display)<br>
</pre>
Second, send graphical orders
<pre>
           draw yellow pixel in this window<br>
(software) --------------------------------> (display)<br>
</pre>

## Things to know
* Cocoa programming
* keyborad & mouse entries
