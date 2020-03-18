#include "Board.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


// Initialisation du singleton à NULL
Board *Board::_singleton = NULL;


Board *Board::getInstance ()
  {
    if (NULL == _singleton)
      {
        _singleton =  new Board;
      }

    return _singleton;
  }

  void Board::kill ()
  {
    if (NULL != _singleton)
    {
        delete _singleton;
        _singleton = NULL;
      }
  }


Board::Board()
{
    initscr();
    clear();

    this->dessinerPlateau();
}

Board::~Board()
{
    endwin();//RAZ du curseur
    cout<<"Destruction du plateau"<<endl;
}

void Board::dessinerPlateau()
{
    m_sizeX = 20;
    m_sizeY = 30;
    this->m_boite = subwin(stdscr, m_sizeX, m_sizeY, 0, 0);

    box(this->m_boite, ACS_VLINE, ACS_HLINE); // ACS_VLINE et ACS_HLINE sont des constantes qui génèrent des bordures par défaut
    wrefresh(m_boite);
}


void Board::dessinerPoint(Point &p){
    wmove(m_boite, p.getX(), p.getY());
    waddch(m_boite,'*');
    wrefresh(m_boite);

}

void Board::effacerPoint(Point &p){
    wmove(m_boite, p.getX(), p.getY());
    waddch(m_boite,' ');
    wrefresh(m_boite);

}

int Board::getXSize(){
    return m_sizeX;
}
int Board::getYSize(){
    return m_sizeY;
}
