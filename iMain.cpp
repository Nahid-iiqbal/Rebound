#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <windows.h>
#include "iGraphics.h"
#include "iSound.h"
// variables///////////////////////////////////////////////////////////
float pi = 3.14159;
float dx;
float dy;
int bgchk = 1, mbgchk = 1, mmchannel = -1, gamechannel = -1;
int chofmm, chofgame;
float ball_spd = 8.0;
int screen_width = 1000;
int screen_height = 750;
int paddle_width = 150;
int paddle_height = 20;
int paddle_x = screen_width / 2 - paddle_width / 2;
int paddle_y = 15;
int ball_radius = 10;
int lives = 3;
int score = 0;
float ball_x = paddle_x + paddle_width / 2;
float ball_y = paddle_height + paddle_y + ball_radius;
int dbx = 0;
bool isGameOver = false;
bool isFullscreen = false;
int offset_x = 0, offset_y = 0;
int gameState = 0;
char scoreText[10];
char lifeText[10];
int gomcheck = 0;
int max_menu_optn = 1;
int selected_menu_idx = 1;
int mainmenu_spacing = 50;
int prevGameState = 0;
bool isBallMoving = false;
bool mm_sound_check = true;
bool game_sound_check = true;
int level = 1;
bool loadingDone = false;

/// block variables///

float block_width = 1000.0 / 15;
float block_height = 30;
int block_padding = 3;
char block_path[5][100] = {
    "assets/images/explode_block.png",
    "assets/images/blocks/2.png",
    "assets/images/blocks/3.png",
    "assets/images/blocks/4.png",
    "assets/images/explode_block.png"};
int levelGrid[5][15][15] = {
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    },
    {
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 5, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 2, 5, 2, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 2, 2, 5, 2, 2, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 2, 2, 2, 5, 2, 2, 2, 1, 0, 0, 0, 0},
        {0, 0, 1, 2, 2, 2, 5, 2, 2, 2, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 2, 2, 5, 2, 2, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 2, 5, 2, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 5, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    },
    {
        {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1, 2, 2, 2},
        {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1, 2, 2, 2},
        {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1, 2, 2, 2},

        {2, 2, 2, 3, 3, 3, 1, 1, 1, 2, 2, 2, 3, 3, 3},
        {2, 2, 2, 3, 3, 3, 1, 1, 1, 2, 2, 2, 3, 3, 3},
        {2, 2, 2, 3, 3, 3, 1, 1, 1, 2, 2, 2, 3, 3, 3},

        {3, 3, 3, 1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1},
        {3, 3, 3, 1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1},
        {3, 3, 3, 1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1},

        {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1, 2, 2, 2},
        {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1, 2, 2, 2},
        {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1, 2, 2, 2},

        {2, 2, 2, 3, 3, 3, 1, 1, 1, 2, 2, 2, 3, 3, 3},
        {2, 2, 2, 3, 3, 3, 1, 1, 1, 2, 2, 2, 3, 3, 3},
        {2, 2, 2, 3, 3, 3, 1, 1, 1, 2, 2, 2, 3, 3, 3},
    },
    {
        {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3},
        {4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
        {3, 0, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 0, 3},
        {2, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 2},
        {1, 0, 3, 0, 1, 2, 3, 4, 1, 2, 3, 0, 3, 0, 1},
        {2, 0, 2, 0, 4, 0, 0, 0, 0, 0, 4, 0, 2, 0, 2},
        {3, 0, 1, 0, 3, 0, 1, 2, 3, 0, 3, 0, 1, 0, 3},
        {4, 0, 4, 0, 2, 0, 4, 0, 2, 0, 2, 0, 4, 0, 4},
        {1, 0, 3, 0, 1, 0, 3, 0, 1, 0, 1, 0, 3, 0, 1},
        {2, 0, 2, 0, 4, 0, 2, 0, 4, 0, 4, 0, 2, 0, 2},
        {3, 0, 1, 0, 3, 0, 1, 2, 3, 0, 3, 0, 1, 0, 3},
        {4, 0, 4, 0, 2, 0, 0, 0, 0, 0, 2, 0, 4, 0, 4},
        {1, 0, 3, 0, 1, 2, 3, 4, 1, 2, 3, 0, 3, 0, 1},
        {2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2},
        {3, 4, 3, 2, 1, 4, 3, 2, 1, 4, 3, 2, 1, 4, 1},
    },
    {{},
     {},
     {},
     {},
     {},
     {},
     {},
     {},
     {},
     {},
     {},
     {},
     {},
     {},
     {}}};
int blockGrid[15][15] = {0};

// block1 col = 00ffb5, 004d37
// block2 col = 00aaff, 00334d
// block3 col = ff4800, 4d1600

/*
gamestate:
0 = main menu
1 = game
2 = game over (i guess)
3 = Highscore
4 = Options
5 = Help
6 = Load Game

110 = <main_game><level 1><base>
100 = <main_game><paused>  [new experimental notation -rafid]
*/

///////////////////////////////////////////////////////////////
void resetGame(void);
void mainMenu(void);
void pauseMenu(void);
void drawBlocks(void);
void loadingScreen(void);
void displayOptions(void);
void displayHelp(void);
void displayHighscore(void);
void ballMotion(void);
void toggleFullscreen(void);
void toggleMenuMusic(void);
void toggleGameMusic(void);
void loadScreen(int gamestate);
void checkCollision(void);
int playOrResumeSound(int *channelVar, const char *filename, bool loop, int volume);
bool isLevelCleared();
void loadNextLevel();
void explode(int i, int j);
///////////////////////////////////////////////////////////////

/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{
    iClear();
    glPushMatrix();
    glTranslatef(offset_x, offset_y, 0);
    // main menu
    if (gameState == 0)
    {

        mainMenu();
        if (mbgchk && mm_sound_check)
        {
            playOrResumeSound(&mmchannel, "assets/sounds/mus_menu6.wav", true, 40);
            mbgchk = 0;
        }
        if (!mm_sound_check && mmchannel != -1)
        {
            iPauseSound(mmchannel);
        }

        iSetColor(255, 255, 255);

        if (selected_menu_idx == 1)
        {
            iShowImage(360, 370, "assets/images/mm_newgame_red.png");
        }

        else if (selected_menu_idx == 2)
        {
            iShowImage(360, 300, "assets/images/mm_loadgame_red.png");
        }

        else if (selected_menu_idx == 3)
        {
            iShowImage(360, 230, "assets/images/mm_highscore_red.png");
        }

        else if (selected_menu_idx == 4)
        {
            iShowImage(360, 160, "assets/images/mm_options_red.png");
        }

        else if (selected_menu_idx == 5)
        {
            iShowImage(360, 90, "assets/images/mm_help_red.png");
        }

        else if (selected_menu_idx == 6)
        {
            iShowImage(360, 20, "assets/images/mm_exit_red.png");
        }
        else if (gameState == 7 && !loadingDone)
        {
            iClear();
            iSetColor(0, 0, 0);
            iFilledRectangle(0, 0, screen_width, screen_height);

            iSetColor(255, 255, 255);
            iTextTTF(420, 380, "Loading Level...", "assets/fonts/RubikDoodleShadow-Regular.ttf", 30);

            char levelText[20];
            sprintf(levelText, "Level %d", level);
            iTextTTF(460, 330, levelText, "assets/fonts/RubikDoodleShadow-Regular.ttf", 28);
        }

        // if (gamechannel != -1)
        // {
        //     iStopSound(gamechannel);
        //     gamechannel = -1;
        // }
    }

    // main game (level 1)
    if (gameState == 101)
    {
        iClear();
        // if (mmchannel != -1)
        // {
        //     iStopSound(mmchannel);
        //     mmchannel = -1;
        // }
        iShowImage(0, 0, "assets/images/1.png");
        iShowImage(paddle_x + dbx, paddle_y, "assets/images/paddle2.png");
        iSetColor(213, 105, 43);
        iFilledCircle(ball_x, ball_y, ball_radius);
        drawBlocks();
        iSetColor(255, 0, 0);
        iShowImage(20, screen_height - 40, "assets/images/score.png");
        sprintf(scoreText, "%d", score);
        iTextBold(150, screen_height - 27, scoreText, GLUT_BITMAP_HELVETICA_18);
        iShowImage(850, screen_height - 40, "assets/images/lives.png");
        sprintf(lifeText, "%d", lives);
        iTextBold(950, screen_height - 27, lifeText, GLUT_BITMAP_HELVETICA_18);
        if (bgchk && game_sound_check)
        {
            playOrResumeSound(&gamechannel, "assets/sounds/gamebg1.wav", true, 40);
            bgchk = 0;
        }
        if (!game_sound_check && gamechannel != -1)
        {
            iPauseSound(gamechannel);
        }

        if (lives < 1 && !isGameOver)
        {
            iPlaySound("assets/sounds/mus_gameover.wav", false);
            isGameOver = true;
            level = 1;
            gameState = 2;
        }
    }

    // pause menu
    else if (gameState == 100)
    {
        pauseMenu();
        if (gamechannel != -1)
            iPauseSound(gamechannel);
        if (selected_menu_idx == 0)
        {
            iShowImage(50, 435, "assets/images/pm_resume_yellow.png");
        }
        else if (selected_menu_idx == 1)
        {
            iShowImage(50, 375, "assets/images/pm_option_yellow.png");
        }
        else if (selected_menu_idx == 2)
        {
            iShowImage(50, 315, "assets/images/pm_exittomm_yellow.png");
        }
        else if (selected_menu_idx == 3)
        {
            iShowImage(50, 255, "assets/images/pm_exittod_yellow.png");
        }
    }

    // game over
    else if (gameState == 2)
    {
        if (gamechannel != -1)
        {
            iStopSound(gamechannel);
            gamechannel = -1;
        }
        iShowImage(0, 0, "assets/images/gameover1.jpg");
        iSetTransparentColor(0, 0, 0, 0.7);
        iFilledRectangle(10, 10, 980, 70);
        iShowImage(63, 20, "assets/images/gom_mainmenu_blue.png");
        iShowImage(375, 20, "assets/images/gom_tryagain_blue.png");
        iShowImage(687, 20, "assets/images/gom_exit_blue.png");
        if (gomcheck == 0)
            iShowImage(63, 20, "assets/images/gom_mainmenu_red.png");
        if (gomcheck == 1)
            iShowImage(375, 20, "assets/images/gom_tryagain_red.png");
        if (gomcheck == 2)
            iShowImage(687, 20, "assets/images/gom_exit_red.png");

        iSetColor(0, 0, 0);
        iFilledRectangle(265, 150, 500, 70);
        iShowImage(345, 160, "assets/images/scoregom.png");
        iSetColor(255, 255, 255);
        iTextAdvanced(550, 167, scoreText, 0.3, 4);
    }

    // controls menu
    else if (gameState == 3)
    {
        // displayHighscore();
    }
    else if (gameState == 4)
    {
        displayOptions();
        if (selected_menu_idx == 0)
        {
            iShowImage(50, screen_height - 310, "assets/images/opn-opnbg1.png");
            iSetColor(255, 0, 0);
            iTextTTF(70, screen_height - 290, "FULLSCREEN", "assets/fonts/RubikDoodleShadow-Regular.ttf", 33);
        }
        else if (selected_menu_idx == 1)
        {
            if (mm_sound_check)
            {
                iShowImage(50, screen_height - 380, "assets/images/opn-opnbg1.png");
                iSetColor(255, 0, 0);
                iTextTTF(70, screen_height - 360, "MAIN MENU MUSIC : ON", "assets/fonts/RubikDoodleShadow-Regular.ttf", 33);
            }
            else
            {
                iShowImage(50, screen_height - 380, "assets/images/opn-opnbg1.png");
                iSetColor(255, 0, 0);
                iTextTTF(70, screen_height - 360, "MAIN MENU MUSIC : OFF", "assets/fonts/RubikDoodleShadow-Regular.ttf", 33);
            }
        }
        else if (selected_menu_idx == 2)
        {
            if (game_sound_check)
            {
                iShowImage(50, screen_height - 450, "assets/images/opn-opnbg1.png");
                iSetColor(255, 0, 0);
                iTextTTF(70, screen_height - 430, "GAME MUSIC : ON", "assets/fonts/RubikDoodleShadow-Regular.ttf", 33);
            }
            else
            {
                iShowImage(50, screen_height - 450, "assets/images/opn-opnbg1.png");
                iSetColor(255, 0, 0);
                iTextTTF(70, screen_height - 430, "GAME MUSIC : OFF", "assets/fonts/RubikDoodleShadow-Regular.ttf", 33);
            }
        }
        else if (selected_menu_idx == 3)
        {
            iShowImage(50, screen_height - 520, "assets/images/opn-opnbg1.png");
            iSetColor(255, 0, 0);
            iTextTTF(70, screen_height - 500, "BACK", "assets/fonts/RubikDoodleShadow-Regular.ttf", 33);
        }
    }
    else if (gameState == 5)
    {
        // displayHelp();
    }

    else if (gameState == 6)
    {
        // load game
    }
    glPopMatrix();
}

/*
function iMouseMove() is called when the user moves the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    mx -= offset_x;
    my -= offset_y;
    if (gameState == 101)
    {
        if (mx < paddle_width / 2)
            mx = paddle_width / 2;
        if (mx > screen_width - paddle_width / 2)
            mx = screen_width - paddle_width / 2;
        paddle_x = mx - paddle_width / 2;
        if (!isBallMoving)
            ball_x = paddle_x + dbx + paddle_width / 2;
    }

    if (gameState == 0)
    {

        if (my < 90 && my > 20)
        {
            selected_menu_idx = 6;
        }
        else if (my < 160 && my > 90)
        {
            selected_menu_idx = 5;
        }
        else if (my < 230 && my > 160)
        {
            selected_menu_idx = 4;
        }
        else if (my < 300 && my > 230)
        {
            selected_menu_idx = 3;
        }
        else if (my < 370 && my > 300)
        {
            selected_menu_idx = 2;
        }
        else if (my < 440 && my > 370)
        {
            selected_menu_idx = 1;
        }
    }
    if (gameState == 100)
    {
        if (my < 315 && my > 255)
        {
            selected_menu_idx = 3;
        }
        else if (my < 375 && my > 315)
        {
            selected_menu_idx = 2;
        }
        else if (my < 435 && my > 375)
        {
            selected_menu_idx = 1;
        }
        else if (my < 495 && my > 435)
        {
            selected_menu_idx = 0;
        }
    }
    if (gameState == 2)
    {
        if (mx >= 63 && mx <= 313)
            gomcheck = 0;
        if (mx >= 375 && mx <= 625)
            gomcheck = 1;
        if (mx >= 687 && mx <= 937)
            gomcheck = 2;
    }
    if (gameState == 3)
    {
    }
    if (gameState == 4)
    {
        if (my < screen_height - 240 && my > screen_height - 310)
        {
            selected_menu_idx = 0;
        }
        else if (my < screen_height - 310 && my > screen_height - 380)
        {
            selected_menu_idx = 1;
        }
        else if (my < screen_height - 380 && my > screen_height - 450)
        {
            selected_menu_idx = 2;
        }
        else if (my < screen_height - 450 && my > screen_height - 520)
        {
            selected_menu_idx = 3;
        }
    }
}

/*5unction iMouseDrag() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseDrag(int mx, int my)
{
    // place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    // Adjust for offset
    mx -= offset_x;
    my -= offset_y;
    if (gameState == 0)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (selected_menu_idx == 1)
            {
                // start game
                resetGame();
                gameState = 101;
                iResumeTimer(0);
                iStopAllSounds();
            }
            else if (selected_menu_idx == 2)
            {
                // load game
                // gameState = 6;
            }
            else if (selected_menu_idx == 3)
            {
                // high score
                displayHighscore();
            }
            else if (selected_menu_idx == 4)
            {
                // options
                prevGameState = gameState;
                displayOptions();
            }
            else if (selected_menu_idx == 5)
            {
                // help menu
                displayHelp();
            }
            else if (selected_menu_idx == 6)
            {
                exit(0);
            }
        }
    }
    if (gameState == 100)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (selected_menu_idx == 0)
            {
                gameState = 101;
                iResumeTimer(0);
                iResumeSound(gamechannel);
                bgchk = 1;
            }
            if (selected_menu_idx == 1)
            {
                prevGameState = gameState;
                displayOptions();
            }
            if (selected_menu_idx == 2)
            {
                resetGame();
                mbgchk = 1;
                iStopSound(gamechannel);
                gameState = 0;
            }
            if (selected_menu_idx == 3)
            {
                exit(0);
            }
        }
    }
    if (gameState == 101)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
        }
    }
    if (gameState == 2)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (gomcheck == 0)
            {
                iStopAllSounds();
                mbgchk = 1;
                gameState = 0;
            }
            else if (gomcheck == 1)
            {
                resetGame();
                isGameOver = false;
                iStopAllSounds();
            }
            else if (gomcheck == 2)
            {
                exit(0);
            }
        }
    }
    if (gameState == 4)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (selected_menu_idx == 0)
            {
                toggleFullscreen();
            }
            else if (selected_menu_idx == 1)
            {
                // toggle main menu music
                mm_sound_check = !mm_sound_check;
                toggleMenuMusic();
            }
            else if (selected_menu_idx == 2)
            {
                // toggle game music
                game_sound_check = !game_sound_check;
                toggleGameMusic();
            }
            else if (selected_menu_idx == 3)
            {
                gameState = prevGameState;
            }
        }
    }
}

/*
function iMouseWheel() is called when the user scrolls the mouse wheel.
dir = 1 for up, -1 for down.
*/
void iMouseWheel(int dir, int mx, int my)
{
    // place your code here
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if (gameState == 0) // main menu
    {

        switch (key)

        {

        case 'w':
        case 'W':
            selected_menu_idx = (selected_menu_idx + 6) % 7;
            if (selected_menu_idx == 0)
                selected_menu_idx = 1;
            break;

        case 's':
        case 'S':
            selected_menu_idx = (selected_menu_idx + 1) % 7;
            if (selected_menu_idx == 0)
                selected_menu_idx = 6;
            break;

        case '\r':
            if (selected_menu_idx == 1)
            {
                // main game
                resetGame();
                gameState = 101;
                iResumeTimer(0);
                iStopAllSounds();
            }

            else if (selected_menu_idx == 2)
            {
                // load game
                // gameState = 6;
            }

            else if (selected_menu_idx == 3)
            {
                // options
                prevGameState = gameState;
                displayOptions();
            }

            else if (selected_menu_idx == 4)
            {
                // high score
                displayHighscore();
            }
            else if (selected_menu_idx == 5)
            {
                // help menu
                displayHelp();
            }
            else if (selected_menu_idx == 6)
            {
                // exit
                exit(0);
            }
            selected_menu_idx = 0;
            break;
        default:
            break;
        }
    }

    if (gameState == 100) // paused
    {
        switch (key)
        {
        case 'w':
        case 'W':
            selected_menu_idx += 3;
            break;
        case 's':
        case 'S':
            selected_menu_idx++;
            break;
        default:
            break;
        }
        selected_menu_idx = selected_menu_idx % 4;

        switch (key)
        {
        case ' ':
        case '\r':

            if (selected_menu_idx == 0)
            {
                gameState = 101;
                iResumeTimer(0);
                iResumeSound(0);
            }
            if (selected_menu_idx == 1)
            {
                prevGameState = gameState;
                displayOptions();
            }
            if (selected_menu_idx == 2)
            {
                resetGame();
                iStopAllSounds();
                mbgchk = 1;
                gameState = 0;
            }
            if (selected_menu_idx == 3)
            {
                exit(0);
            }
        }
    }

    if (gameState == 101) // game
    {
        switch (key)
        {
        case 'd':
        case 'D':
            paddle_x += 20;
            if (paddle_x > screen_width - paddle_width)
                paddle_x = screen_width - paddle_width;
            if (!isBallMoving)
                ball_x = paddle_x + paddle_width / 2;
            break;
        case 'a':
        case 'A':
            paddle_x -= 20;
            if (paddle_x < 0)
                paddle_x = 0;
            if (!isBallMoving)
                ball_x = paddle_x + paddle_width / 2;
            break;
        case ' ':
        {
            if (!isBallMoving)
            {
                dx = ball_spd * cos(pi / 4);
                dy = ball_spd * sin(pi / 4);
                isBallMoving = true;
            }
            break;
        }
        case 27:
            gameState = 100;
            iPauseTimer(0);
            break;

        default:
            break;
        }
    }

    if (gameState == 2) // game over
    {
        switch (key)
        {
        case 'a':
        case 'A':
            gomcheck += 2;
            break;
        case 'd':
        case 'D':
            gomcheck += 1;
            break;
        default:
            break;
        }
        gomcheck = gomcheck % 3;

        switch (key)
        {
        case ' ':
        case '\r':

            if (gomcheck == 0)
            {
                iStopAllSounds();
                mbgchk = 1;
                gameState = 0;
            }
            else if (gomcheck == 1)
            {
                resetGame();
                gameState = 101;
                isGameOver = false;
                iStopAllSounds();
            }
            else if (gomcheck == 2)
            {
                exit(0);
            }
            break;

        default:
            break;
        }
    }

    if (gameState == 3) // high score
    {
        // displayHighscore();
        switch (key)
        {
        case 27:
            mbgchk = 1;
            gameState = 0;
            break;
        default:
            break;
        }
    }

    if (gameState == 4) // options menu
    {
        // displayOptions();
        switch (key)
        {
        case 'w':
        case 'W':
            selected_menu_idx = (selected_menu_idx + 3) % 4;
            break;
        case 's':
        case 'S':
            selected_menu_idx = (selected_menu_idx + 1) % 4;
            break;
        case 27:
            mbgchk = 1;
            gameState = prevGameState;
            break;
        case ' ':
        case '\r':
            if (selected_menu_idx == 0)
            {
                toggleFullscreen();
            }
            else if (selected_menu_idx == 1)
            {
                mm_sound_check = !mm_sound_check;
                toggleMenuMusic();
            }
            else if (selected_menu_idx == 2)
            {
                game_sound_check = !game_sound_check;
                toggleGameMusic();
            }
            else if (selected_menu_idx == 3)
            {
                gameState = prevGameState;
            }
            break;

        default:
            break;
        }
    }

    if (gameState == 5) // help menu
    {
        // displayHelp();
        switch (key)
        {
        case 27:
            mbgchk = 1;
            gameState = prevGameState;
            break;
        default:
            break;
        }
    }

    if (gameState == 6) // load game
    {
        // load game
        switch (key)
        {
        case 27:
            mbgchk = 1;
            gameState = 0;
            break;
        default:
            break;
        }
    }
}

/*
function iSpecialKeyboard() is called whenver user hits special keys likefunction
keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11,
GLUT_KEY_F12, GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN,
GLUT_KEY_PAGE_UP, GLUT_KEY_PAGE_DOWN, GLUT_KEY_HOME, GLUT_KEY_END,
GLUT_KEY_INSERT */

void iSpecialKeyboard(unsigned char key)
{
    switch (key)
    {
    case GLUT_KEY_END:
        // do something
        break;
    // place your codes for other keys here
    default:
        break;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    iSetTimer(15, ballMotion);
    // place your own initialization codes here.
    iInitializeSound();
    iInitialize(screen_width, screen_height, "Rebound by 2405051 and 2405042");
    return 0;
}

void resetGame(void)
{
    dx = 0;
    dy = 0;
    dbx = 0;
    isBallMoving = false;
    ball_x = paddle_x + dbx + paddle_width / 2;
    ball_y = paddle_height + paddle_y + ball_radius;
    lives = 3;
    score = 0;
    bgchk = 1;
    isGameOver = false;
    gameState = 101;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 15; j++)
            blockGrid[i][j] = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            blockGrid[i][j] = levelGrid[level - 1][i][j];
        }
    }
}

void pauseMenu(void)
{
    if (gamechannel != -1)
    {
        iStopSound(gamechannel);
        gamechannel = -1;
    }

    iShowImage(50, 255, "assets/images/pm_exittod_white.png");
    iShowImage(50, 315, "assets/images/pm_exittomm_white.png");
    iShowImage(50, 375, "assets/images/pm_option_white.png");
    iShowImage(50, 435, "assets/images/pm_resume_white.png");
}

void mainMenu(void)
{
    iShowImage(0, 0, "assets/images/mainmenubg2.png");
    iShowImage(360, 20, "assets/images/mm_exit_white.png");
    iShowImage(360, 90, "assets/images/mm_help_white.png");
    iShowImage(360, 160, "assets/images/mm_options_white.png");
    iShowImage(360, 230, "assets/images/mm_highscore_white.png");
    iShowImage(360, 300, "assets/images/mm_loadgame_white.png");
    iShowImage(360, 370, "assets/images/mm_newgame_white.png");
}

void drawBlocks(void)
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (blockGrid[i][j] == 1)
            {
                // iShowImage(j * block_width, screen_height - (i + 1) * block_height, block_path[blockGrid[i][j] - 1]);
                iSetColor(0, 77, 55);
                iFilledRectangle(j * block_width, screen_height - (i + 1) * block_height - 70, block_width, block_height);
                iSetColor(0, 255, 181);
                iFilledRectangle(j * block_width + block_padding, screen_height - (i + 1) * block_height + block_padding - 70, block_width - 2 * block_padding, block_height - 2 * block_padding);
            }

            else if (blockGrid[i][j] == 2)
            {
                // iShowImage(j * block_width, screen_height - (i + 1) * block_height, block_path[blockGrid[i][j] - 1]);
                iSetColor(0, 51, 77);
                iFilledRectangle(j * block_width, screen_height - (i + 1) * block_height - 70, block_width, block_height);
                iSetColor(0, 170, 255);
                iFilledRectangle(j * block_width + block_padding, screen_height - (i + 1) * block_height + block_padding - 70, block_width - 2 * block_padding, block_height - 2 * block_padding);
            }
            else if (blockGrid[i][j] == 3)
            {
                // iShowImage(j * block_width, screen_height - (i + 1) * block_height, block_path[blockGrid[i][j] - 1]);
                iSetColor(77, 22, 0);
                iFilledRectangle(j * block_width, screen_height - (i + 1) * block_height - 70, block_width, block_height);
                iSetColor(255, 72, 0);
                iFilledRectangle(j * block_width + block_padding, screen_height - (i + 1) * block_height + block_padding - 70, block_width - 2 * block_padding, block_height - 2 * block_padding);
            }
            else if (blockGrid[i][j] == 4)
            {
                // iShowImage(j * block_width, screen_height - (i + 1) * block_height, block_path[blockGrid[i][j] - 1]);
                iSetColor(128, 128, 128);
                iFilledRectangle(j * block_width, screen_height - (i + 1) * block_height - 70, block_width, block_height);
                iSetColor(192, 192, 192);
                iFilledRectangle(j * block_width + block_padding, screen_height - (i + 1) * block_height + block_padding - 70, block_width - 2 * block_padding, block_height - 2 * block_padding);
            }
            else if (blockGrid[i][j] == 5)
            {
                // iShowImage(j * block_width, screen_height - (i + 1) * block_height, block_path[blockGrid[i][j] - 1]);

                iSetColor(0, 0, 0);
                iFilledRectangle(j * block_width, screen_height - (i + 1) * block_height - 70, block_width, block_height);
                iSetColor(255, 0, 0);
                iFilledRectangle(j * block_width + block_padding, screen_height - (i + 1) * block_height + block_padding - 70, block_width - 2 * block_padding, block_height - 2 * block_padding);
                iSetColor(255, 0, 255);
                iFilledRectangle(j * block_width + 40.0 / 3, screen_height - (i + 1) * block_height + 10 - 70, block_width - 2 * 40.0 / 3, block_height - 2 * 10);
            }
        }
    }
}

void loadingScreen(void)
{
    iSetColor(255, 255, 255);
    iText(450, 100, "Loading...", GLUT_BITMAP_HELVETICA_18);
    Sleep(1000);
    iClear();
}

void displayOptions(void)
{
    gameState = 4;
    iShowImage(0, 0, "assets/images/background2.jpg");
    iShowImage(50, screen_height - 310, "assets/images/opn-opnbg1.png");
    iShowImage(50, screen_height - 380, "assets/images/opn-opnbg1.png");
    iShowImage(50, screen_height - 450, "assets/images/opn-opnbg1.png");
    iShowImage(50, screen_height - 520, "assets/images/opn-opnbg1.png");
    iSetColor(255, 255, 255);
    iTextTTF(70, screen_height - 290, "FULLSCREEN", "assets/fonts/RubikDoodleShadow-Regular.ttf", 31);
    if (mm_sound_check)
    {
        iTextTTF(70, screen_height - 360, "MAIN MENU MUSIC : ON", "assets/fonts/RubikDoodleShadow-Regular.ttf", 31);
    }
    else
    {
        iTextTTF(70, screen_height - 360, "MAIN MENU MUSIC : OFF", "assets/fonts/RubikDoodleShadow-Regular.ttf", 31);
    }
    if (game_sound_check)
    {
        iTextTTF(70, screen_height - 430, "GAME MUSIC : ON", "assets/fonts/RubikDoodleShadow-Regular.ttf", 31);
    }
    else
    {
        iTextTTF(70, screen_height - 430, "GAME MUSIC : OFF", "assets/fonts/RubikDoodleShadow-Regular.ttf", 31);
    }
    iTextTTF(70, screen_height - 500, "BACK", "assets/fonts/RubikDoodleShadow-Regular.ttf", 31);
}
void displayHelp(void)
{
    gameState = 5;
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 0, screen_width, screen_height);
}
void displayHighscore(void)
{
    gameState = 3;
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 0, screen_width, screen_height);
}
void ballMotion(void)
{
    checkCollision();
    if (!isBallMoving || gameState != 101)
    {
        return;
    }

    ball_x += dx;
    ball_y += dy;
    float position = ((paddle_x + dbx + paddle_width / 2) - ball_x) / (paddle_width / 2);
    float angle = (pi / 2) + position * (pi / 3);

    if (ball_x + ball_radius > screen_width || ball_x - ball_radius < 0)
    {
        dx *= (-1);
        iPlaySound("assets/sounds/bounce.wav");
    }

    if (ball_y + ball_radius > screen_height)
    {
        dy *= (-1);
        iPlaySound("assets/sounds/bounce.wav");
    }

    if (dx != 0 && dy != 0 && ball_x >= paddle_x + dbx && ball_x <= paddle_x + paddle_width + dbx && ball_y - ball_radius <= paddle_height + paddle_y && ball_y - ball_radius >= paddle_y)
    {
        score += 20;
        ball_y = paddle_y + paddle_height + ball_radius;
        if (dx != 0 && dy != 0)
            iPlaySound("assets/sounds/bounce.wav");
        dx = ball_spd * cos(angle);
        dy = ball_spd * sin(angle);
    }
    if (ball_y < paddle_y)
    {
        lives--;
        iPlaySound("assets/sounds/lifelost.wav");
        dbx = 0;
        dx = 0;
        dy = 0;

        isBallMoving = false;
        ball_x = paddle_x + dbx + paddle_width / 2;
        ball_y = paddle_height + paddle_y + ball_radius;
    }

    if (isLevelCleared())
    {
        level++;
        loadNextLevel();
    }
}
void toggleFullscreen(void)
{
    iToggleFullscreen();
    isFullscreen = !isFullscreen;
    if (isFullscreen)
    {
        int screen_w = GetSystemMetrics(SM_CXSCREEN);
        int screen_h = GetSystemMetrics(SM_CYSCREEN);
        offset_x = (screen_w - screen_width) / 2;
        offset_y = (screen_h - screen_height) / 2;
    }
    else
    {
        offset_x = 0;
        offset_y = 0;
    }
}
void toggleMenuMusic()
{
    if (mm_sound_check)
    {
        playOrResumeSound(&mmchannel, "assets/sounds/mus_menu6.wav", true, 40);
    }
    else
    {
        if (mmchannel != -1)
            iPauseSound(mmchannel);
    }
}

void toggleGameMusic()
{
    if (game_sound_check)
    {
        playOrResumeSound(&gamechannel, "assets/sounds/gamebg1.wav", true, 40);
    }
    else
    {
        if (gamechannel != -1)
            iPauseSound(gamechannel);
    }
}

void loadFinished(void)
{
    loadingDone = true;
}

void loadScreen(int gamestate)
{
    iSetColor(0, 0, 0);
    iFilledRectangle(0, 0, screen_width, screen_height);
    iSetColor(0, 255, 255);
    iTextTTF(450, 100, "Loading Level ", "assets/fonts/RubikDoodleShadow-Regular.ttf", 33);
    int level = gamestate / 100;
    sprintf(scoreText, "%d", level);
    iTextTTF(600, 100, scoreText, "assets/fonts/RubikDoodleShadow-Regular.ttf", 33);
    iTextTTF(450, 50, "Please wait...", "assets/fonts/RubikDoodleShadow-Regular.ttf", 33);
}
void checkCollision(void)
{
    if (ball_y > 280)
    {
        bool hit = false;
        for (int i = 0; i < 15 && !hit; i++)
        {
            for (int j = 0; j < 15 && !hit; j++)
            {
                if (blockGrid[i][j] > 0)
                {
                    int block_x = j * block_width;
                    int block_y = screen_height - (i + 1) * block_height - 70;

                    if ((ball_x >= block_x) && (ball_x <= block_x + block_width))
                    {
                        if ((ball_y + ball_radius >= block_y) && (ball_y - ball_radius <= block_y + block_height))
                        {
                            ball_x -= dx;
                            ball_y -= dy;
                            dy *= (-1);
                            if (blockGrid[i][j] < 4)
                            {
                                blockGrid[i][j] -= 1;
                                score += 50;
                            }
                            if (blockGrid[i][j] == 5)
                            {
                                explode(i, j);
                            }
                            iPlaySound("assets/sounds/bounce.wav");
                            hit = true;
                            break;
                        }
                    }
                    if ((ball_y >= block_y) && (ball_y <= block_y + block_height))
                    {
                        if ((ball_x + ball_radius >= block_x) && (ball_x - ball_radius <= block_x + block_width))
                        {
                            ball_x -= dx;
                            ball_y -= dy;
                            dx *= (-1);
                            if (blockGrid[i][j] != 4)
                            {
                                blockGrid[i][j] -= 1;
                                score += 50;
                            }
                            iPlaySound("assets/sounds/bounce.wav");
                            hit = true;
                            break;
                        }
                    }
                }
            }
        }
    }
}

int playOrResumeSound(int *channelVar, const char *filename, bool loop, int volume)
{
    if (*channelVar != -1 && Mix_Playing(*channelVar))
    {
        iResumeSound(*channelVar);
    }
    else
    {
        if (*channelVar != -1)
        {
            iStopSound(*channelVar); // Free previous chunk
        }
        *channelVar = iPlaySound(filename, loop, volume);
    }
    return *channelVar;
}
bool isLevelCleared()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (blockGrid[i][j] != 0)
                return false;
        }
    }
    return true;
}
void loadNextLevel()
{
    if (level >= 5)
        level = 1; // wrap around or stop here if you want game over

    gameState = 7; // 6 = loading state
    loadingDone = false;
    iPauseTimer(0); // pause movement
    iPauseSound(gamechannel);

    // Delay a bit and then load next level
    Sleep(1000); // simulate loading time
    resetGame(); // load level data and reset
    loadingDone = true;
    gameState = 101;
    iResumeTimer(0);
    bgchk = 1;
}

void explode(int i, int j)
{
    if (i < 0 || i >= 10 || j < 0 || j >= 15)
        return;

    if (blockGrid[i][j] == 0 || blockGrid[i][j] == 4)
        return; // Skip empty/unbreakable

    if (blockGrid[i][j] == 5) // Exploding block
    {
        blockGrid[i][j] = 0;
        score += 50;
        for (int di = -1; di <= 1; di++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                int ni = i + di;
                int nj = j + dj;
                explode(ni, nj); // Recursive explosion
            }
        }
    }
    else
    {
        blockGrid[i][j] = 0;
        score += 50;
    }
    iPlaySound("assets/sounds/explosion.mp3");
}