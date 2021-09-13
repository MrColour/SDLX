# SDLX

Provided here are source files that make working with SDL easier.

The header struct file defines some structs which routines are built around. These include the Sprite struct that can be sent to a RenderQueue struct to be rendered upon a flush of the queue. It also defines a big struct for gameinput that works as an address mapper when mapped keys have been pressed. This also includes places where curor velocity and position can be stored. There are also the things in order to make it would with Xbox controllers, and most controllers supported by SDL.
