# PhysicsMovementBehaviors

This project was built with openFrameworks v0.10.1 and Visual Studio 2017.
To give it a try, place the contents of this repository under your myApps directory!

## Directory Outline

1. src/Behavior
   * basic-motion.h/.cpp
     * A class with the basic kinematic motion algorithm
   * Behavior.h/.cpp
     * A collection of structs and classes to represent behaviors
   * DynamicAlign.h/.cpp
     * A class with the dynamic align orientation algorithm
   * DynamicFace.h/.cpp
     * A class with the dynamic face orientation algorithm
   * DynamicLookWhereYouAreGoing.h/.cpp
     * A class with the dynamic look where you are going orientation algorithm
   * DynamicSeparation.h/.cpp
     * A class with the dynamic separation motion algorithm
   * seek-steering.h/.cpp
     * A class with the seek-steering motion algorithm
   * wander-steering.h/.cpp
     * A class with the wander-steering motion algorithm

2. src/Entity
   * Boid.h/.cpp
     * A class representing the entities that demonstrate behaviors
   * Breadcrumb.h/.cpp
     * A class representing the trails boids leave behind
   * Flock.h/.cpp
     * A class representing a collection a boids
   * Kinematic.cpp/.h
     * A structure representing a rigidbody for physics simulations
3. main.cpp
   * A file for the entry point into the program
4. ofApp.h/.cpp
   * A class that handles updating, drawing, and switching between scenes

## Running the Simulation

1. Open the physicsMovementBehaviors.sln
2. Build the project with Visual Studio with these settings:
   * Debug
   * Win32
3. Run the Local Windows Debugger

## Scene Selection

After the application loads you can press the numbers 1, 2, 3, or 4 to load different scenes

### Basic Kinematic Motion

Press 1 to load this demonstration where a boid makes its way around the edge of the screen using kinematic motion

The implementation of this behavior is found in basic-motion.cpp and DynamicLookWhereYouAreGoing.cpp

### Seek Steering Behavior

Press 2 to load this demonstration where a boid seeks a target you place with a left mouse click

The implementation of this behavior is found in seek-steering.cpp and DynamicLookWhereYouAreGoing.cpp

### Wander Steering Behavior

Press 3 to load this demonstration where a boid randomly wanders around the screen

The implementation of this behavior is found in wander-steering.cpp and DynamicLookWhereYouAreGoing.cpp

### Flocking Behavior
Press 4 to load this demonstration where several boids seek a single wandering boid

The implementation of this behavior is found in ofApp.cpp as a blending of wander, seek, separation, and look where you are going