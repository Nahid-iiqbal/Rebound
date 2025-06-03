#include <stdio.h>
#include <stdbool.h>
#include "iGraphics.h"
#include "iSound.h"
float dx;
float dy;
int paddle_x = 450;
int paddle_y = 15;
int paddle_height = 15;
int paddle_width = 100;
int ball_radius = 10;
int lives = 1;
int score = 0;
float ball_x = paddle_x + paddle_width / 2;
float ball_y = paddle_height + paddle_y + ball_radius;
int dbx = 0;
bool isGameOver = false;
int gameState = 1;
void gameOver(void);
/*
function iDraw() is called again and again by the system.
*/
void iDraw()
{
    // place your drawing codes here
    iClear();

    if (gameState == 1)
    {
        iSetColor(85, 115, 250);
        iFilledRectangle(paddle_x + dbx, paddle_y, paddle_width, paddle_height);
        iSetColor(213, 105, 43);
        iFilledCircle(ball_x, ball_y, ball_radius);
        iSetColor(255, 0, 0);
        iText(25, 730, "Lives: ", GLUT_BITMAP_HELVETICA_18);

        if (lives == 3)
        {
            iText(75, 730, "3", GLUT_BITMAP_HELVETICA_18);
        }
        else if (lives == 2)
        {
            iText(75, 730, "2", GLUT_BITMAP_HELVETICA_18);
        }
        else if (lives == 1)
        {
            iText(75, 730, "1", GLUT_BITMAP_HELVETICA_18);
        }
        iText(890, 730, "Score", GLUT_BITMAP_HELVETICA_18);
        iText(950, 730, "2000", GLUT_BITMAP_HELVETICA_18);
        if (lives < 1 && !isGameOver)
        {

            iPlaySound("assets/sounds/mus_gameover.wav", true);
            isGameOver = true;
            gameState = 2;
        }
    }
    else if (gameState == 2)
    {
        iShowImage(0, 0, "assets/images/gameover1.jpg");
    }
}

/*
function iMouseMove() is called when the user moves the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    // place your codes hfloat
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
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // place your codes here
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
    switch (key)
    {
    case 'd':
        dbx += 20;
        if ((450 + dbx) >= 900)
            dbx -= 20;
        if (dx == 0 && dy == 0)
        {
            ball_x += 20;
            if (ball_x >= (900 + paddle_width / 2))
            {
                ball_x -= 20;
            }
        }
        break;
    case 'a':
        dbx -= 20;
        if ((450 + dbx) <= 0)
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
        dx = 10;
        dy = 10;
    }
    default:
        break;
    }
}
void ballMotion()
{
    ball_x += dx;
    ball_y += dy;

    if (ball_x + ball_radius > 1000 || ball_x - ball_radius < 0)
    {
        dx *= (-1);
    }

    if (ball_y + ball_radius > 750)
    {
        dy *= (-1);
    }

    if (((ball_x > (450 + dbx)) && ball_x < (550 + dbx)) && ball_y < (paddle_height + paddle_y + ball_radius))
    {
        dy *= (-1);
    }
    if (ball_y < paddle_y)
    {
        lives--;
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
    iInitialize(1000, 750, "Breaking Ball");
    return 0;
}

void gameOver(void)
{
    iSetColor(255, 0, 0);
    iText(500, 350, "GAME OVER");
    iPlaySound("assets/sounds/mus_gameover.wav", true);
}