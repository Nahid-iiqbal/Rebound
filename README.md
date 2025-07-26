<div align="center">
<h1>🎮 Rebound - Breakout Game</h1>
<h2>Built with Modern iGraphics Library</h2>
</div>

<p align="center">
    <a href="https://github.com/mahirlabibdihan/Modern-iGraphics">💻 iGraphics Library</a> •
    <a href="#-features">🎯 Features</a> •
    <a href="#-gameplay">🎮 Gameplay</a> •
    <a href="#-setup">⚙️ Setup</a>
</p>

---

## 🎯 About Rebound

**Rebound** is a modern breakout-style arcade game developed by **nahid 2405051** and **rafid 2405042** using the Modern iGraphics library. Experience classic brick-breaking action with modern features, multiple levels, power-ups, and explosive gameplay mechanics!

### 🎮 Game Features

- **🧱 Multiple Block Types**
  - **Standard Blocks** (Types 1-3): Different durability levels with color-coded difficulty
  - **Unbreakable Blocks** (Type 4): Indestructible gray barriers that add strategic challenge
  - **Explosive Blocks** (Type 5): Chain-reaction blocks that destroy surrounding blocks

- **⚡ Power-Up System**
  - **Multi-Ball**: Split your ball into multiple balls for chaos
  - **Paddle Expansion**: Increase paddle size for easier ball control
  - **Speed Boost**: Accelerate ball movement for faster gameplay
  - **Ball Size**: Modify ball radius for different challenges
  - **Score Multiplier**: Boost your scoring potential
  - **Extra Life**: Gain additional chances
  - **Slow Motion**: Reduce ball speed for precision control
  - **Fire Ball**: Penetrate through blocks without bouncing

- **🎵 Immersive Audio**
  - Dynamic background music that changes with game states
  - Sound effects for ball bounces, block destruction, and power-up collection
  - Explosive audio feedback for chain reactions
  - Victory and defeat musical themes

- **🎨 Visual Effects**
  - **Particle System**: Colorful explosion effects when blocks are destroyed
  - Block-specific particle colors and intensity
  - Smooth fade animations in menus and credits
  - Dynamic background graphics

- **📊 Game Progression**
  - **10 Unique Levels**: Each with distinct block patterns and challenges
  - **High Score System**: Track your best performances
  - **Save/Load System**: Continue your progress anytime
  - **Lives System**: Traditional 3-life arcade-style gameplay

- **🎯 Advanced Gameplay Mechanics**
  - **Physics-based Ball Movement**: Realistic collision detection and response
  - **Paddle Angle Control**: Ball direction changes based on paddle hit position
  - **Chain Explosions**: Strategic block placement for maximum destruction
  - **Level Completion**: Progress through increasingly difficult challenges

---

## 🎮 Gameplay

### 🕹️ Controls
- **Arrow Keys** / **A/D**: Move paddle left/right
- **Spacebar**: Launch ball / Pause game
- **Mouse**: Navigate menus and options
- **ESC**: Pause game / Return to menu

### 🎯 Objectives
1. **Destroy all breakable blocks** to advance to the next level
2. **Collect power-ups** to gain advantages and higher scores
3. **Survive all 10 levels** to complete the game
4. **Achieve high scores** and compete with previous records

### 💥 Special Mechanics
- **Explosive Blocks**: Destroy surrounding blocks in a 3x3 area
- **Chain Reactions**: Multiple explosive blocks can trigger cascading explosions
- **Power-Up Strategy**: Time your power-up collection for maximum benefit
- **Angle Physics**: Hit the ball with different parts of the paddle to control direction

---

## 🎨 Visual Showcase

### 🎮 Game Screenshots
```
🎯 Main Menu          🧱 Gameplay           🎆 Explosions
┌─────────────────┐   ┌─────────────────┐   ┌─────────────────┐
│     REBOUND     │   │ ████ ████ ████  │   │ ████ 💥💥 ████ │
│                 │   │  ████ ████ ████ │   │ ████ 💥💥 ████ │
│  ► Start Game   │   │                 │   │    ✨💥💥✨   │
│    High Scores  │   │      ●          │   │      ●          │
│    Options      │   │    ═══════      │   │    ═══════      │
│    Exit         │   └─────────────────┘   └─────────────────┘
└─────────────────┘   Score: 2,500         Score: 4,750
```

### 🎨 Block Types
- 🟢 **Type 1**: Green blocks (1 hit) - Basic blocks worth 50 points
- 🔵 **Type 2**: Blue blocks (2 hits) - Medium blocks worth 100 points  
- 🟠 **Type 3**: Orange blocks (3 hits) - Strong blocks worth 150 points
- ⬜ **Type 4**: Gray blocks (Unbreakable) - Strategic obstacles
- 🔴 **Type 5**: Red blocks (Explosive) - Chain reaction triggers worth 200 points

---

## ⚙️ Setup and Installation

### 📋 Prerequisites
- **Windows OS** (Primary support)
- **Code::Blocks IDE** or **g++ compiler**
- **Modern iGraphics Library** (included in project)

### 🚀 Quick Start

1. **Download the Game**
   ```bash
   git clone <your-repository-url>
   cd "iGraphics practice"
   ```

2. **Setup with Code::Blocks**
   - Open `iGraphics.cbp` in Code::Blocks
   - The project is pre-configured with all necessary settings
   - Press **F9** to build and run

3. **Manual Compilation** (Advanced)
   ```bash
   # Windows
   .\runner.bat iMain.cpp
   
   # Linux (if ported)
   sudo apt install libsdl2-dev libsdl2-mixer-dev
   ./runner.sh iMain.cpp
   ```

### 📁 Project Structure
```
📦 Rebound Game
 ┣ 📂 assets/
 ┃ ┣ 📂 images/
 ┃ ┃ ┣ 📂 blocks/     # Block sprites (1.png - 5.png)
 ┃ ┃ ┣ 📂 backgrounds/ # Game backgrounds
 ┃ ┃ ┗ 📂 ui/         # Menu and UI elements
 ┃ ┣ 📂 sounds/       # Audio files (.wav, .mp3)
 ┃ ┗ 📂 fonts/        # Custom fonts (.ttf)
 ┣ 📂 OpenGL/         # iGraphics library files
 ┣ 📜 iMain.cpp       # Main game source code
 ┣ 📜 iGraphics.h     # Graphics library header
 ┣ 📜 iSound.h        # Audio library header
 ┗ 📜 README.md       # This file
```

---

## 🎵 Audio System

### 🎶 Music Tracks
- **Main Menu**: Atmospheric menu music
- **Gameplay**: Dynamic background tracks
- **Level Complete**: Victory fanfare
- **Game Over**: Defeat theme
- **Credits**: Emotional farewell music

### 🔊 Sound Effects
- **Ball Bounce**: Satisfying collision sounds
- **Block Destruction**: Impact and destruction audio
- **Power-up Collection**: Reward sound effects
- **Explosions**: Dramatic blast audio
- **UI Navigation**: Menu interaction sounds

---

## 📊 Game Statistics & Features

### 🏆 Scoring System
| Action | Points |
|--------|--------|
| Block Type 1 Destroyed | 50 |
| Block Type 2 Destroyed | 100 |
| Block Type 3 Destroyed | 150 |
| Explosive Block | 200 |
| Paddle Bounce | 20 |
| Power-up Collection | 100 |
| Level Completion | 1000 |

### 🎮 Technical Features
- **60 FPS Gameplay** with smooth animation
- **Particle System** with 200+ simultaneous particles
- **10 Pre-designed Levels** with increasing difficulty
- **Save System** with 10 save slots
- **High Score Tracking** with player names
- **Collision Detection** with pixel-perfect accuracy
- **Dynamic Audio** with 8-channel mixing

---

## 👥 Development Team

### 🧑‍💻 Developers
- **Nahid Iqbal (2405051)** 
- **Rafid Muammar (2405042)**

### 🎨 Inspired By
- **Arkanoid** - Classic arcade brick-breaker gameplay
- **Undertale** - Audio design and emotional storytelling elements

### 🛠️ Built With
- **[Modern iGraphics](https://github.com/mahirlabibdihan/Modern-iGraphics)** - Cross-platform C++ graphics library
- **OpenGL** - Hardware-accelerated rendering
- **SDL2** - Audio processing and sound effects
- **C++** - Core programming language

---

## 🎮 How to Play

### 🎯 Basic Gameplay
1. **Start the Game** from the main menu
2. **Use arrow keys** to move your paddle
3. **Press spacebar** to launch the ball
4. **Break all colored blocks** to complete the level
5. **Collect power-ups** that fall from destroyed blocks
6. **Avoid losing the ball** below your paddle

### 💡 Pro Tips
- **Aim for explosive blocks** to trigger chain reactions
- **Use paddle edges** to control ball angle
- **Collect power-ups strategically** for maximum effect
- **Save your game** before challenging levels
- **Watch for unbreakable blocks** that affect ball trajectory

---

## 🏆 Achievements & Challenges

### 🎯 Level Progression
- **Levels 1-3**: Tutorial levels with basic block patterns
- **Levels 4-6**: Intermediate challenges with mixed block types
- **Levels 7-9**: Advanced levels with strategic explosive placement
- **Level 10**: Ultimate challenge with complex patterns

### 🎨 Visual Progression
Each level features unique:
- **Block Arrangements**: From simple patterns to complex mazes
- **Color Schemes**: Visually distinct themes per level
- **Difficulty Scaling**: Progressive challenge increase
- **Strategic Elements**: Unbreakable block placement for added complexity

---

## 📞 Support & Feedback

For bug reports, feature requests, or general feedback about **Rebound**, please contact the development team:

- **Game Issues**: Report gameplay bugs or suggestions
- **Technical Support**: Help with installation or compatibility
- **Feature Requests**: Ideas for future game improvements

---

## 📄 License

This game is developed for educational purposes as part of computer graphics coursework. Built using the Modern iGraphics library for academic and hobbyist OpenGL projects.

---

<div align="center">

**🎮 Thank You for Playing Rebound! 🎮**

*Built with ❤️ using Modern iGraphics*

</div>
