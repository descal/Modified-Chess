#include <iostream>
#include "player.h"
#include "board.h"
#include "game.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include<sstream>

using namespace std;

#define X_MIN 'a'
#define X_MAX 'h'
#define Y_MIN '1'
#define Y_MAX '8'

Player::Player(string name, bool isWhite, King& myKing, vector<Piece*>& myPieces, bool humanity) :
    _name(name), _isWhite(isWhite), _myPieces(myPieces), _myKing(myKing), _human(humanity)
{
}

Player::~Player()
{
}

bool Player::makeMove()
{
    string badInput; // string for throwing away invalid input
    string fromSquare =  "  ";
    string toSquare = "  ";
    int fromX;
    int fromY;
    int toX;
    int toY;

    /*

    // check/announce if player is in check
    if(inCheck())
    {
        cout << _name << " is in check!" << endl;
    }

*/

    ////////////////////////////////////////////////////////////
    // HE MODIFICADO DESDE AQUÍ
    ////////////////////////////////////////////////////////////

    // AHORA EL JUGADOR NEGRO SIEMPRE LO USA EL PC. SIMPLEMENTE PARA VER SI FUNCIONA
    // GENERO 4 RANDOMS ENTRE 1 Y 8. CONVIERTO LAS COORDENADAS 'y' INICIAL Y FINAL A LETRAS
    // Y LOS CONVIERTO A STRING PARA QUE LOS LEA EL PROGRAMA CON EL FORMATO QUE PIDE a1 a3
    // NO CREO QUE FUNCIONE, PERO PRUEBALO A VER
    // DEL IF NO ESTOY SEGURO SI PONE Black o black o como lo pone. Cambialo tu si puedes verlo

    //repeat:

    do{
    // get move from player input




      if(_name=="Black" && _human==false){   //In case the game is 1vsPC, generate random movements for the PC





        int random_initial_x, random_initial_y, random_final_x, random_final_y ;
        string srandom_initial_x, srandom_initial_y, srandom_final_x, srandom_final_y ;

        random_initial_x = rand()%8 +1;   // Initial x position
        random_initial_y = rand()%8 +1;   // Initial y position
        random_final_x = rand()%8 +1;     // Final x position
        random_final_y = rand()%8 +1;     // Final y position




        //solucionado de esta manera
       stringstream srandom_initial_y1;
       srandom_initial_y1<<random_initial_y;
       srandom_initial_y =srandom_initial_y1.str() ;


        stringstream srandom_final_y1;
        srandom_final_y1<<random_final_y;
        srandom_final_y =srandom_final_y1.str() ;


        switch(random_initial_x){

        case 1: srandom_initial_x="a";
            break;
        case 2: srandom_initial_x="b";
            break;
        case 3: srandom_initial_x="c";
            break;
        case 4: srandom_initial_x="d";
            break;
        case 5: srandom_initial_x="e";
            break;
        case 6: srandom_initial_x="f";
            break;
        case 7: srandom_initial_x="g";
            break;
        case 8: srandom_initial_x="h";
            break;

}

        switch(random_final_x){

        case 1: srandom_final_x="a";
            break;
        case 2: srandom_final_x="b";
            break;
        case 3: srandom_final_x="c";
            break;
        case 4: srandom_final_x="d";
            break;
        case 5: srandom_final_x="e";
            break;
        case 6: srandom_final_x="f";
            break;
        case 7: srandom_final_x="g";
            break;
        case 8: srandom_final_x="h";
            break;



}

        fromSquare=srandom_initial_x+srandom_initial_y;
        toSquare=srandom_final_x+srandom_final_y;
     //   cout<<"from "<<fromSquare<<" to "<<toSquare<<endl;

}else{   //


        cout << _name << " player enter move (e.g. a2 a4): ";
        cin >> fromSquare >> toSquare;
        if(fromSquare=="show" && toSquare=="score"){

            cout<<score()<<endl;
        }else if(fromSquare=="save" && toSquare=="game"){

            Game::saveGame();
        }
}


    // move must be in algebraic notation
    // (start and end squares denoted by 2 characters, a1-h8,
    // and separated from each other by whitespace)
    // move cannot start from an empty square

    }while(fromSquare.length() != 2 ||
          toSquare.length() != 2 ||
          tolower(fromSquare.at(0)) < X_MIN ||
          tolower(fromSquare.at(0)) > X_MAX ||
          tolower(toSquare.at(0)) < X_MIN ||
          tolower(toSquare.at(0)) > X_MAX ||
          tolower(fromSquare.at(1)) < Y_MIN ||
          tolower(fromSquare.at(1)) > Y_MAX ||
          tolower(toSquare.at(1)) < Y_MIN ||
          tolower(toSquare.at(1)) > Y_MAX ||
          !(Board::getBoard()->squareAt(tolower(fromSquare.at(0)) - X_MIN,
                                      tolower(fromSquare.at(1)) - Y_MIN)->occupied())
          );


    // translate input (algebraic notation) into board coordinates
    fromX = tolower(fromSquare.at(0)) - X_MIN;
    fromY = tolower(fromSquare.at(1)) - Y_MIN;
    toX = tolower(toSquare.at(0)) - X_MIN;
    toY = tolower(toSquare.at(1)) - Y_MIN;

    // move the piece on fromSquare to toSquare
    return Board::getBoard()->squareAt(fromX, fromY)->occupiedBy()->moveTo(*this,
                                                                  *(Board::getBoard()->squareAt(toX, toY)));
}

/*bool Player::inCheck()     // Check if our king is in check. Returns true if we are in check
{


    bool check = false;

    // for each piece in the opponent's set of pieces
    for (set<Piece*>::iterator itr = Game::opponentOf(*this)->myPieces()->begin();
         itr != Game::opponentOf(*this)->myPieces()->end(); ++itr)
    {
        // if a piece that is still located on the board
        // can move to my king's square
        if (((Piece*)*itr)->location() &&
            ((Piece*)*itr)->checkMove(*(myKing()->location())))
        {
            // I am in check
            check = true;
        }
    }

    return check;
}*/

void Player::capture(Piece* aPiece)
{
    // unset the piece's location on the board
    aPiece->setLocation(NULL);

    // put the piece into this player's set of captured pieces
    _capturedPieces.insert(aPiece);
}

string Player::getName() const
{
    return _name;
}

bool Player::isWhite() const
{
    return _isWhite;
}

int Player::score() const
{

   // cout<<"daddsd"<<endl;
    int score = 0;

    // add up the points of all captured pieces
    for (set<Piece*>::iterator itr = _capturedPieces.begin(); itr != _capturedPieces.end(); ++itr)
    {
        score += ((Piece*)*itr)->value();
    }

    return score;
}

vector<Piece*>* Player::myPieces() const
{
    return &_myPieces;
}

King* Player::myKing() const
{
    return &_myKing;
}
