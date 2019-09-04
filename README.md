#PONG GAME:

A classic Pong game built in C++ using SDL library.

#LIBRARY:

Install the SDL2 using `apt-get install libsdl2-dev`

#COMPILE AND RUN:

In src directory:

g++ -std="c++17" -o pong.out PongApp.cpp `pkg-config --cflags --libs sdl2`

Running the above line you will create `pong.out`.

#PONG COMMANDS

When the program is run, the ball will be automatically thrown.
Be ready!!

#CONTROLS

##Player 1

    W - Move up
    S - Move down

##Player 2

    u - Move up
    J - Move down

To pause the ball, use the SPACE button. It's the same for both players.

The score will be presented in the terminal.

To close the game, you need to close the window.

Enjoy!

#TECHNICAL INFORMATION:

##CLASS FILES:

###Ball.cpp/Ball.h	

The class responsible for defining the ball features, such as:
	- Changes direction when the ball hits something
	- Resets the ball`s position
	- Retrieves x and y position
	-Defines speed and position for the time elapsed

###Common_data.h

The class Responsible for set the changeable parameters of the game, such as:
	- sizes
	- speeds 
	- colors and constants parameters

###Control.cpp/Control.h

The class responsible for implementing the business layer of the game, connecting the other class and forming the functionalities, such as:
	-Set the Paddle limits in the window
	- Checks if the ball reach the limits or the paddles
	- Updates the game when a score occurs
	- Displays the score when a point occurs

###Design.cpp/Design.h

The class responsible for implementing the SDL features and capture the users' input:
	- Create the game initializing the SDL objects
	- Finishing the game, destroying the SDL objects
	- Define the user buttons and get its input
	- Pause the ball when a user press space

###IPONG.h

The abstract class responsible for the most important feature(play). It is implemented for the Control class

###Paddle.cpp/Paddle.h

The class responsible for define and set paddle features. Has some functionalities, such as:
	-Move the paddle up or down	
	-Get and set paddle position

###PongApp.cpp

The class is responsible for instantiating the main function. The control class is created and the play is called. The Quit is called when the game is finished.

#RUBRICS POINTS

point 1 :"The project demonstrates an understanding of C++ functions and control structures."
Answer: The project was split in files .cpp and .h , and there is a class only for common data called "Common_data.h"

point 2 "The project accepts user input and processes the input."
Answer : The class Design.cpp in controlLogics line 61, is preseted the manager of user`s input.

point 3 "The project uses Object Oriented Programming techniques."
Answer: All methods are wrapped by classes and has attributes(get and set as well) and different types of access

point 4 "Classes use appropriate access specifiers for class members."
Answer: All classes have explicitly defined the acess public, protected, or private.

point 5 "Classes abstract implementation details from their interfaces."
Answer:The methods have comment and the methods name help to understand the behavior

Point 6 "The project makes use of references in function declarations."
Answer: class Design.cpp in controlLogics(line 61) and pointPause(line 91), have parameters define as references.

Point 7 "Classes encapsulate behavior."
Answer: All Classes have get and set and only applicable functions can be accessed

Pointer 8 "The project uses destructors appropriately."
Answer: In class Control.cpp, the UI is created in Constructor(line 13) and the SDL is destroyed in destructor(line 19)



