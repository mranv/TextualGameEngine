

# Textual Game Engine Documentation

## Table of Contents

1. [Overview of the Game Engine Architecture](#overview-of-the-game-engine-architecture)
2. [Project Structure](#project-structure)
3. [Detailed Structure Explanation](#detailed-structure-explanation)
    - [Engine](#engine)
    - [Game](#game)
4. [Compilation and Running Instructions](#compilation-and-running-instructions)
    - [Prerequisites](#prerequisites)
    - [Steps to Compile and Run](#steps-to-compile-and-run)
5. [User Guide for Playing the Game](#user-guide-for-playing-the-game)
    - [Starting the Game](#starting-the-game)
    - [Game Commands](#game-commands)
    - [Example Gameplay](#example-gameplay)
6. [System and Component Design](#system-and-component-design)
7. [Future Improvements](#future-improvements)
8. [References](#references)

## Overview of the Game Engine Architecture

The game engine is built using the Entity-Component-System (ECS) architecture, a design pattern widely used in game development for its flexibility and performance benefits. The ECS architecture decouples the data (components) from the behavior (systems) and the entities (game objects), allowing for a highly modular and scalable system.

### Key Components of ECS

1. **Entity Manager:** Handles the creation, storage, and destruction of entities. An entity is a unique identifier that represents a game object but does not hold any data or logic by itself.
   
2. **Component Manager:** Manages the components, which are data containers attached to entities. Components store the state and properties of entities, such as position, velocity, health, etc.

3. **System Manager:** Oversees the systems, which contain the game logic. Systems operate on entities that have specific components, processing and updating their states.

### Benefits of ECS Architecture

- **Modularity:** Components and systems can be developed, tested, and maintained independently.
- **Performance:** Efficiently processes entities in batches, reducing cache misses and improving performance.
- **Scalability:** Easily extend the game by adding new components and systems without affecting existing code.

## Project Structure

```
marioECS
└───ItalienQuiSaute
    ├───Engine
    │   ├───API
    │   │   └───nlohmann
    │   ├───Components
    │   ├───Entities
    │   └───System
    │       ├───Libraries
    │       │   └───Maths
    │       └───Managers
    └───Game
        ├───Assets
        │   ├───Fonts
        │   ├───Resources
        │   └───Sprites
        │       ├───Character
        │       ├───Enemies
        │       └───Map
        └───Source
```

## Detailed Structure Explanation

### Engine

The `Engine` directory contains the core components of the ECS architecture and supporting libraries.

#### API/nlohmann

This subdirectory includes the nlohmann JSON library, used for handling JSON data in the game. JSON is commonly used for configuration files, asset metadata, and save files.

#### Components

Contains definitions for various components used in the game. Examples include:

- **Position:** Stores the x and y coordinates of an entity.
- **Velocity:** Contains the velocity vector of an entity.
- **Health:** Holds the health value of an entity.
- **Name:** Stores the name of an entity.

Each component inherits from a base `Component` class.

#### Entities

Manages entity-related logic, such as creating and destroying entities. Entities are simply unique IDs that can have multiple components attached to them.

#### System

##### Libraries/Maths

Contains mathematical utilities and helper functions used by various systems for calculations and transformations.

##### Managers

Includes the System Manager and related logic. The System Manager is responsible for updating all systems each frame, ensuring they process the relevant entities.

### Game

The `Game` directory contains the game-specific assets and source code.

#### Assets

Stores all game assets, organized into subdirectories for different types:

- **Fonts:** Font files used for rendering text in the game.
- **Resources:** Additional resources such as sound files, textures, etc.
- **Sprites:** Images used for characters, enemies, and maps.
    - **Character:** Sprites for the main character.
    - **Enemies:** Sprites for enemy characters.
    - **Map:** Sprites for the game map and environment.

#### Source

Contains the source code for the game logic, including the main game loop and specific game systems.

## Compilation and Running Instructions

### Prerequisites

Before compiling and running the game, ensure you have the following tools installed:

- **C++ Compiler:** GCC, Clang, or MSVC.
- **CMake:** A build system generator used to configure and build the project.

### Steps to Compile and Run

1. **Clone the Repository:**

   Open a terminal and run the following command to clone the repository:

   ```sh
   git clone https://github.com/mranv/TextualGameEngine.git
   cd TextualGameEngine/marioECS/ItalienQuiSaute
   ```

2. **Create a Build Directory:**

   Create a directory for the build files and navigate into it:

   ```sh
   mkdir build
   cd build
   ```

3. **Run CMake to Configure the Project:**

   Generate the build files using CMake:

   ```sh
   cmake ..
   ```

   This command configures the project and generates the necessary makefiles.

4. **Compile the Project:**

   Build the project by running:

   ```sh
   make
   ```

   This compiles the source code and produces the executable.

5. **Run the Game:**

   Execute the compiled game binary:

   ```sh
   ./ItalienQuiSaute
   ```

   The game should now start, and you can interact with it via the command-line interface.

## User Guide for Playing the Game

### Starting the Game

After running the executable, the game will initialize and present a command-line interface for user interaction.

### Game Commands

The game supports a variety of commands that the player can use to interact with the game world. Below is a list of available commands:

- **move [direction]:** Moves the character in the specified direction (e.g., `move north`, `move south`, `move east`, `move west`).
- **attack [target]:** Attacks a specified target (e.g., `attack goblin`).
- **inventory:** Displays the current inventory of the player.
- **pickup [item]:** Picks up an item and adds it to the inventory (e.g., `pickup sword`).
- **use [item]:** Uses an item from the inventory (e.g., `use potion`).
- **status:** Displays the current status of the character, including health, position, and other relevant attributes.
- **exit:** Exits the game.

### Example Gameplay

Here is an example of what a gameplay session might look like:

```sh
Welcome to Italien Qui Saute!
Enter a command:
> move north
You move north.
> status
Position: (1, 0)
Health: 100
> pickup sword
You picked up a sword.
> inventory
Items: sword
> attack goblin
You attacked the goblin with your sword.
> exit
Thank you for playing!
```

## System and Component Design

### Systems

- **MovementSystem:** Handles the movement of entities based on their velocity components.
- **RenderSystem:** Renders entities to the screen.
- **InputSystem:** Processes player input and updates relevant components.
- **HealthSystem:** Manages the health of entities, applying damage or healing effects.
- **CollisionSystem:** Detects and resolves collisions between entities.

### Components

- **Position:** Represents the position of an entity in the game world.
- **Velocity:** Represents the speed and direction of an entity's movement.
- **Health:** Stores the health points of an entity.
- **Name:** Holds the name of an entity.
- **Sprite:** Contains the graphical representation of an entity.
- **Collider:** Defines the collision boundaries of an entity.
- **RigidBody:** Adds physical properties to an entity, like mass and drag.
- **Inventory:** Stores the items held by an entity.

## Future Improvements

While the current implementation provides a basic framework for a textual game engine, there are several areas for future improvement and enhancement:

- **Graphical User Interface (GUI):** Implement a graphical interface to provide a more immersive experience.
- **Networking:** Add networking capabilities to support multiplayer gameplay.
- **Advanced AI:** Develop more sophisticated AI behaviors for non-player characters (NPCs).
- **Save/Load System:** Implement functionality to save and load game progress.
- **Sound and Music:** Integrate audio for background music and sound effects.
- **More Systems and Components:** Expand the ECS with additional systems and components to support more complex game mechanics.

## References

- [C++ Reference](https://en.cppreference.com/)
- [ECS Articles and Tutorials](https://www.gamedev.net/articles/programming/general-and-gameplay-programming/)
- [nlohmann JSON Library](https://github.com/nlohmann/json)

