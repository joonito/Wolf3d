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
You may also need to specify the path to these libraries, using the -L flag.<br>

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
<br>
The three functions work exactly the same way.<br>
- <b>funct_ptr</b> is a pointer to the function you want to be called when an event occurs.
- This assignment is specific to the window defined by the <b>win_ptr</b> identifier.
- param address will be passed to the function to store parameters it might need
- mlx_loop_hook function is dentical to the previous ones, but the given function will be called when no event occurs.
- param is the address specified in the mlx_*_hook calls. This address is never used nor modified by the MiniLibX.
- On key and mouse events, additional infor-mation  is  passed:  keycode tells you which key is pressed.
- In MacOS, ( x , y ) are the coordinates of the mouse click in the window, and button tells you which mouse button was pressed.
- See source code of mlx_int_param_event.c to find out how the MiniLibX will call your own function for a specific event.

### man1/mlx_new_image.1
mlx_new_image() :
- Creates a new image in memory.
- Returns a void * identifier needed to manipulate this image later.
- Needs the size(width, height) of the image, mlx_ptr to be created
- User can draw inside the image.
- Dump the image into specified window at any time to display it.(**mlx_put_image_to_window()**)



## Things to know
* Cocoa programming
* keyborad & mouse entries
* linking
