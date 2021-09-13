# SDLX

Provided here are source files that make working with SDL easier.

The header struct file defines some structs which routines are built around. These include the Sprite struct that can be sent to a RenderQueue struct to be rendered upon a flush of the queue. It also defines a big struct for gameinput that works as an address mapper when mapped keys have been pressed. This also includes places where curor velocity and position can be stored. There are also the things in order to make it would with Xbox controllers, and most controllers supported by SDL.

There is also a good portion for buttons to be used. These buttons are highly customizable allowing the developer to set function pointers that will have a standard way of triggering and activating that suit most needs. The buttons also have a few meta void pointers in case tou want to store extra or meta information wtih each button.

There is a very small rudimentary collision system. It is by no means optimized in any way. I have not ran into performance issuses but that is because the games I have made have been small in scope. The collision system provides detection and engagement function pointers that the user can provide to create thier own way to collide objects.
