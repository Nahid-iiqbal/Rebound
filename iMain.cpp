#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "iGraphics.h"
#include "iSound.h"

// variables///////////////////////////////////////////////////////////
float pi = 3.14159;
float dx;
float dy;
int bgchk = 1;
float ball_spd = 10;
int screen_width = 1000;
int screen_height = 750;
int paddle_width = 100;
int paddle_height = 10;
int paddle_x = screen_width / 2 - paddle_width / 2;
int paddle_y = 15;
int ball_radius = 6;
int lives = 1;
int score = 0;
float ball_x = paddle_x + paddle_width / 2;
float ball_y = paddle_height + paddle_y + ball_radius;
int dbx = 0;
bool isGameOver = false;
int gameState = 1;
char scoreText[10];
char lifeText[10];
int gomcheck = 0;

///////////////////////////////////////////////////////////////
/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{
    iClear();

    if (gameState == 1)
    {
        iShowImage(0, 0, "assets/images/1.png");
        iShowImage(paddle_x + dbx, paddle_y, "assets/images/paddle_n.png");
        iSetColor(213, 105, 43);
        iFilledCircle(ball_x, ball_y, ball_radius);
        iSetColor(255, 0, 0);
        iShowImage(20, screen_height - 40, "assets/images/score.png");
        sprintf(scoreText, "%d", score);
        iTextBold(150, screen_height - 27, scoreText, GLUT_BITMAP_HELVETICA_18);
        iShowImage(850, screen_height - 40, "assets/images/lives.png");
        sprintf(lifeText, "%d", lives);
        iTextBold(950, screen_height - 27, lifeText, GLUT_BITMAP_HELVETICA_18);
        if (bgchk)
        {
            iPlaySound("assets/sounds/gamebg1.wav", true, 40);
            bgchk = 0;
        }
        if (lives < 1 && !isGameOver)
        {

            iPlaySound("assets/sounds/mus_gameover.wav", false);
            isGameOver = true;
            gameState = 2;
        }
    }
    else if (gameState == 2)
    {
        iStopSound(0);
        iShowImage(0, 0, "assets/images/gameover1.jpg");
        iSetTransparentColor(0, 0, 0, 0.7);
        iFilledRectangle(10, 10, 980, 70);
        iShowImage(63, 20, "assets/images/mainmenublue.png");
        iShowImage(375, 20, "assets/images/tryagainblue.png");
        iShowImage(687, 20, "assets/images/exitblue.png");
        if (gomcheck == 0)
            iShowImage(63, 20, "assets/images/mainmenured.png");
        if (gomcheck == 1)
            iShowImage(375, 20, "assets/images/tryagainred.png");
        if (gomcheck == 2)
            iShowImage(687, 20, "assets/images/exitred.png");

        iSetColor(0, 0, 0);
        iFilledRectangle(265, 150, 500, 70);
        iShowImage(345, 160, "assets/images/scoregom.png");
        iSetColor(255, 255, 255);
        iTextAdvanced(550, 167, scoreText, 0.3, 4);
    }
}

/*
function iMouseMove() is called when the user moves the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    // if (mx > paddle_width / 2 && mx < screen_width - paddle_width / 2)
    // {
    //     dbx = (mx - paddle_width / 2);
    //     if (dx == 0 && dy == 0)
    //     {
    //         ball_x = mx;
    //     }
    // }
    if (gameState == 2)
    {
        if (mx >= 63 && mx <= 313)
            gomcheck = 0;
        if (mx >= 375 && mx <= 625)
            gomcheck = 1;
        if (mx >= 687 && mx <= 937)
            gomcheck = 2;
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
    if (gameState == 1)
    {
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        {
            if (dx == 0 && dy == 0)
            {

                dx = ball_spd * cos(pi / 4);
                dy = ball_spd * sin(pi / 4);
            }
        }
    }

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        // place your codes here
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
    if (gameState == 1)
    {

        if (gameState == 1)
        {

            switch (key)
            {
            case 'd':
            case 'D':
                dbx += 20;
                if ((paddle_x + dbx) >= screen_width - paddle_width)
                    dbx -= 20;
                if (dx == 0 && dy == 0)
                {
                    ball_x += 20;
                    if (ball_x >= (screen_width - paddle_width / 2))
                    {
                        ball_x -= 20;
                    }
                }
                break;
            case 'a':
            case 'A':
                dbx -= 20;
                if ((paddle_x + dbx) <= 0)
                    dbx += 20;
                if (dx == 0 && dy == 0)
                {
                    ball_x -= 20;
                    if (ball_x <= paddle_width / 2)
                    {
                        ball_x += 20;
                    }
                }

                break;
            // place your codes for other keys here
            case ' ':
            {
                if (dx == 0 && dy == 0)
                {

                    dx = ball_spd * cos(pi / 4);
                    dy = ball_spd * sin(pi / 4);
                }
            }
            default:
                break;
            }
        }
    }
    if (gameState == 2)
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
    }
}
void ballMotion()
{
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
        dx = dy = 0;
        ball_x = paddle_x + dbx + paddle_width / 2;
        ball_y = paddle_height + paddle_y + ball_radius;
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
    iInitialize(screen_width, screen_height, "Breaking Ball");
    return 0;
}
