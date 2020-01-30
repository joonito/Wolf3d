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
<pre>
            initialize connection (<b>mlx_init()</b> will do this, and return a identifier for further calls.)
(software) <----------------------> (display)
</pre>
Second, send graphical orders
<pre>
           draw yellow pixel in this window
(software) --------------------------------> (display)
</pre>

#### LINKING MiniLibX on MACOSX
To use MiniLibX functions, you'll need to link your software with the MiniLibX library, and several system frameworks:
```
-lmlx -framework OpenGL -framework AppKit
```
You may also need to specify the path to these libraries, using the -L flag.__

### man1/mlx_loop.1

mlx_loop() is..
- for receive events
- Infinite loop that waits for an event
- Calls a user-defined function associated with this event.
- Need single parameter **mlx_ptr**

Assign a function to each three follwing events:
- mlx_key_hook(A key is pressed)
- mlx_mouse_hook(The mouse button is pressed)
- mlx_expose_hook(A part of the window should be re-drawn)
The three functions work exactly the same way.__
**funct_ptr** is a pointer to the function you want to be called when an event occurs.__
This assignment is specific to the window defined by the **win_ptr** identifier.__
**param** address will be passed to the function to store parameters it might need.__
**mlx_loop_hook** function is dentical to the previous ones, but the given function will be called when no event occurs.__
param is the address specified in the mlx_\*_hook calls. This address is never used nor modified by the MiniLibX. On key and mouse events, additional infor-mation  is  passed:  keycode tells you which key is pressed


## Things to know
* Cocoa programming
* keyborad & mouse entries
* linking
