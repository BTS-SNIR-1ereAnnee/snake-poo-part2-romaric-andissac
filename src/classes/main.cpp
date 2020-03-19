/*
 Projet: snake
 Auteur: Sylvain Guilbert
*/
#include <iostream>
#include "Point.h"
#include "Board.h"
#include "snake.h"
#include <unistd.h>

int usleep(useconds_t usec);

using namespace std;

//https://github.com/ajpaulson/learning-ncurses/blob/master/kbhit.c

#define  TOUCHE_KEY_UP 1 // sert a définir les touche de mouvement
#define  TOUCHE_KEY_DOWN 2
#define  TOUCHE_KEY_LEFT 3
#define  TOUCHE_KEY_RIGHT 4

/** Cette fonction retourne si une touche est appuyé par l'utilisateur
*   https://github.com/ajpaulson/learning-ncurses/blob/master/kbhit.c
*/
int kbhit(void);

int main()
{
    int directionEnCours=TOUCHE_KEY_DOWN;

    // pointeurs sur l'unique instance de la classe fenetre
    Board *fenetre;
    // initialisation des pointeurs
    fenetre = Board::getInstance ();

    snake serpent(10,4);

    keypad (stdscr,true);
    noecho();

    bool collision = FALSE;
    while (!collision)
    {
        if(kbhit())
        {   
            //Permet d'utiliser de voir quand on appuis sur le clavier
            
            switch (getch())
            {
            
            //259 est la fleche du haut
            
            case 259:
                directionEnCours = TOUCHE_KEY_UP;   
                break;
                
            //260 est la fleche de gauche
            
            case 260:
                directionEnCours = TOUCHE_KEY_LEFT;
                break;
                
            //258 est la fleche du bas
            
            case 258:
                directionEnCours = TOUCHE_KEY_DOWN;
                break;
                
            //261 est la fleche de droite
            
            case 261:
                directionEnCours = TOUCHE_KEY_RIGHT;

                break;
            }

        }
        serpent.move(directionEnCours);
        collision = serpent.checkColisionWithBoard();
        serpent.affichSerpent();
        usleep (150000);

    }
    //getchar();
    fenetre->kill();
    return 0;
};

int kbhit(void)    /* Cette fonction retourne si une touche est appuyé par l'utilisateur https://github.com/ajpaulson/learning-ncurses/blob/master/kbhit.c */
{
    int ch, r;
    nodelay(stdscr, TRUE);
    ch = getch();
    if( ch == ERR)
        r = FALSE;
    else
    {
        r = TRUE;
        ungetch(ch);
    }
    echo();
    nodelay(stdscr, FALSE);
    return(r);
}
