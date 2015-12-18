#include "game.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"
#include "king.h"
#include "apolo.h"
#include "square.h"
#include "board.h"
#include <stdlib.h>
#include <time.h>
#include<piece.h>
#include<fstream>


Game::Game()
{
}

Game::~Game()
{
    // Delete pieces
    for (vector<Piece*>::iterator itr = whitePieces.begin();
         itr != whitePieces.end(); ++itr)
    {
        delete *itr;
    }
    whitePieces.clear();
    for (vector<Piece*>::iterator itr = blackPieces.begin();
         itr != blackPieces.end(); ++itr)
    {
        delete *itr;
    }
    blackPieces.clear();

    // Delete players
    delete &player1;
    delete &player2;
}

void Game::initialize()
{
    Piece* aPiece;
    King* aKing;
    Square* aSquare;
    int numberofPieces, numberofPawns, numberofRandoms, kingsColumn;
    char kingsColumnchar;
    int selcc=0;

    do{

cout<<endl;
cout<<endl;
cout<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"----------CHOOSE GAME MODE---------"<<endl;
    cout<<"                                   "<<endl;
    cout<<"     1vs1, TYPE 1"<<endl;
    cout<<"     1vsPC, TYPE 2"<<endl;
    cout<<"                                   "<<endl;
    cout<<"-----------------------------------"<<endl;
    cin>>selcc;
    cout<<endl;
    cout<<endl;
    }while(selcc!=1 && selcc!=2);



    do{
        cout<<"Introduce the number of pieces per player (2 to 16)"<<endl;
        cin>>numberofPieces;

    }while(numberofPieces<2 || numberofPieces>16);




        if(numberofPieces%2==0){                             //Case number of pieces is even

            numberofPawns=numberofPieces/2;
            numberofRandoms=numberofPieces-1-numberofPawns;

        }else{                                               //Case number of pieces is odd
            numberofPawns=(numberofPieces-1)/2;
            numberofRandoms=numberofPieces-1-numberofPawns;

        }





    cout<<endl;
    cout<<"Number of pawns "<<numberofPawns<<endl;
    cout<<"Number of random pieces "<<numberofRandoms<<endl;
    cout<<endl;

    Board::getBoard()->displayBoard();  //We print the board so that the player knows which column to choose


    if(numberofRandoms==7 ){






            do{

                 cout<<"Choose a valid column to put the king (D or E)"<<endl;
                 cin>>kingsColumnchar;

                 switch(kingsColumnchar){

                 case 'A': kingsColumn =0;
                     break;
                 case 'a': kingsColumn =0;
                     break;
                 case 'B': kingsColumn =1;
                     break;
                 case 'b': kingsColumn =1;
                     break;
                 case 'C': kingsColumn =2;
                     break;
                 case 'c': kingsColumn =2;
                     break;
                 case 'D': kingsColumn =3;
                     break;
                 case 'd': kingsColumn =3;
                     break;
                 case 'E': kingsColumn =4;
                     break;
                 case 'e': kingsColumn =4;
                     break;
                 case 'F': kingsColumn =5;
                     break;
                 case 'f': kingsColumn =5;
                     break;
                 case 'G': kingsColumn =6;
                     break;
                 case 'g': kingsColumn =6;
                     break;
                 case 'H': kingsColumn =7;
                     break;
                 case 'h': kingsColumn =7;
                     break;
                 default: kingsColumn=100;
                     break;
                 }



             }while(kingsColumn>7 || kingsColumn<0);    // We want the king to be in one of the middle positions, either D or E, to maintain the max symmetry
                                      // However, as there is no perfect symmetry in this case, we could place it in any column erasing
                                      // the omission operands



    }else{

        do{

             cout<<"Choose a valid column to put the king"<<endl;
             cin>>kingsColumnchar;

             switch(kingsColumnchar){

             case 'A': kingsColumn =0;
                 break;
             case 'a': kingsColumn =0;
                 break;
             case 'B': kingsColumn =1;
                 break;
             case 'b': kingsColumn =1;
                 break;
             case 'C': kingsColumn =2;
                 break;
             case 'c': kingsColumn =2;
                 break;
             case 'D': kingsColumn =3;
                 break;
             case 'd': kingsColumn =3;
                 break;
             case 'E': kingsColumn =4;
                 break;
             case 'e': kingsColumn =4;
                 break;
             case 'F': kingsColumn =5;
                 break;
             case 'f': kingsColumn =5;
                 break;
             case 'G': kingsColumn =6;
                 break;
             case 'g': kingsColumn =6;
                 break;
             case 'H': kingsColumn =7;
                 break;
             case 'h': kingsColumn =7;
                 break;
             default: kingsColumn=100;
                 break;
             }



         }while(kingsColumn<numberofPawns/2 || 8-kingsColumn<numberofPawns/2);

    }


    // create piece sets

whitePieces.resize(numberofPieces);
blackPieces.resize(numberofPieces);

    // create the white king
    aKing = new King(true);
    aSquare = Board::getBoard()->squareAt(kingsColumn, 0);
    aSquare->setOccupier(aKing);
    aKing->setLocation(aSquare);
    whitePieces[0]=aKing;



    // create the black king
    aKing = new King(false);
    aSquare = Board::getBoard()->squareAt(kingsColumn, 7);
    aSquare->setOccupier(aKing);
    aKing->setLocation(aSquare);
    blackPieces[0]=aKing;

    // Create each piece
    // Set their locations
    // Put them in their respective collections

    if(numberofPawns==8){

        for (int i = 0; i < 8; i++)
        {

            aPiece = new Pawn(true);
            aSquare = Board::getBoard()->squareAt(i, 1);
            aSquare->setOccupier(aPiece);
            aPiece->setLocation(aSquare);
            whitePieces[i+1]=aPiece;

            aPiece = new Pawn(false);
            aSquare = Board::getBoard()->squareAt(i, 6);
            aSquare->setOccupier(aPiece);
            aPiece->setLocation(aSquare);
            blackPieces[i+1]=aPiece;

        }


    }else{


        if((numberofPawns%2)!=0 || numberofPawns==1){
                                                             //Number of pawns is odd. We put a pawn in front of the king

            aPiece = new Pawn(true);
            aSquare = Board::getBoard()->squareAt(kingsColumn, 1);
            aSquare->setOccupier(aPiece);
            aPiece->setLocation(aSquare);
            whitePieces[1]=aPiece;

            aPiece = new Pawn(false);
            aSquare = Board::getBoard()->squareAt(kingsColumn, 6);
            aSquare->setOccupier(aPiece);
            aPiece->setLocation(aSquare);
            blackPieces[1]=aPiece;

        }


            for(int x=1;x<=(numberofPawns/2);x++){                   //For, to put all pawns simmetrically around the king

               aPiece = new Pawn(true);
               aSquare = Board::getBoard()->squareAt(kingsColumn+x, 1);
               aSquare->setOccupier(aPiece);
               aPiece->setLocation(aSquare);
               whitePieces[2*x]=aPiece;

               aPiece = new Pawn(true);
               aSquare = Board::getBoard()->squareAt(kingsColumn-x, 1);
               aSquare->setOccupier(aPiece);
               aPiece->setLocation(aSquare);
               whitePieces[2*x+1]=aPiece;

               aPiece = new Pawn(false);
               aSquare = Board::getBoard()->squareAt(kingsColumn+x, 6);
               aSquare->setOccupier(aPiece);
               aPiece->setLocation(aSquare);
               blackPieces[2*x]=aPiece;

               aPiece = new Pawn(false);
               aSquare = Board::getBoard()->squareAt(kingsColumn-x, 6);
               aSquare->setOccupier(aPiece);
               aPiece->setLocation(aSquare);
               blackPieces[2*x+1]=aPiece;

           }

        }

    // ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

   // Board::getBoard()->displayBoard();   ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡COMPROBAR SI HAY QUE BORRARLO!!!!!!!!!!!!


    // Now we are going to generate the random pieces and put them simmetrically with respect to the king
    // We always start putting a piece by the right side (kings position +1) which may be a problem,


     srand(time(NULL));

     if(numberofRandoms!=7){

         for(int i=1; i<=numberofRandoms; i++){


             int random_1, random_2;

             random_1 = rand()%5 +1;   // For white pieces
             random_2 = rand()%5 +1;   // For black pieces

           //  cout<<"Random 1 "<<i<<" "<<random_1<<endl;
           //  cout<<"Random 2 "<<i<<" "<<random_2<<endl;


             switch(random_1){

             case 1: // White Rook

               //  cout<<"white rook"<<endl;
                 aPiece = new Rook(true);

                 if(i%2==0){
                     aSquare = Board::getBoard()->squareAt(kingsColumn-(i/2), 0);
                 }else{
                     aSquare = Board::getBoard()->squareAt(kingsColumn+(i/2)+1, 0);
                 }

                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 whitePieces[numberofPawns+i]=aPiece;
                 break;

             case 2: // White Knight

               //  cout<<"white knuight"<<endl;

                 aPiece = new Knight(true);

                 if(i%2==0){
                     aSquare = Board::getBoard()->squareAt(kingsColumn-(i/2), 0);
                 }else{
                     aSquare = Board::getBoard()->squareAt(kingsColumn+(i/2)+1, 0);
                 }

                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 whitePieces[numberofPawns+i]=aPiece;
                 break;

             case 3: // White Bishop

               //  cout<<"white bishop"<<endl;

                 aPiece = new Bishop(true);
                 if(i%2==0){
                     aSquare = Board::getBoard()->squareAt(kingsColumn-(i/2), 0);
                 }else{
                     aSquare = Board::getBoard()->squareAt(kingsColumn+(i/2)+1, 0);
                 }

                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 whitePieces[numberofPawns+i]=aPiece;
                 break;

             case 4: // White Queen

               //  cout<<"white queen"<<endl;

                 aPiece = new Queen(true);
                 if(i%2==0){
                     aSquare = Board::getBoard()->squareAt(kingsColumn-(i/2), 0);
                 }else{
                     aSquare = Board::getBoard()->squareAt(kingsColumn+(i/2)+1, 0);
                 }
                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 whitePieces[numberofPawns+i]=aPiece;
                 break;



             case 5: // White Apolo

               //  cout<<"white Apolo"<<endl;

                 aPiece = new Apolo(true);
                 if(i%2==0){
                     aSquare = Board::getBoard()->squareAt(kingsColumn-(i/2), 0);
                 }else{
                     aSquare = Board::getBoard()->squareAt(kingsColumn+(i/2)+1, 0);
                 }
                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 whitePieces[numberofPawns+i]=aPiece;
                 break;

             }


             switch(random_2){

             case 1: // Black Rook

               //  cout<<"black rook"<<endl;


                 aPiece = new Rook(false);

                 if(i%2==0){
                     aSquare = Board::getBoard()->squareAt(kingsColumn-(i/2), 7);
                 }else{
                     aSquare = Board::getBoard()->squareAt(kingsColumn+(i/2)+1, 7);
                 }

                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 blackPieces[numberofPawns+i]=aPiece;
                 break;

             case 2: // Black Knight

              //   cout<<"black knuight"<<endl;

                 aPiece = new Knight(false);

                 if(i%2==0){
                     aSquare = Board::getBoard()->squareAt(kingsColumn-(i/2), 7);
                 }else{
                     aSquare = Board::getBoard()->squareAt(kingsColumn+(i/2)+1, 7);
                 }

                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 blackPieces[numberofPawns+i]=aPiece;
                 break;

             case 3: // Black Bishop

               //  cout<<"black bishop"<<endl;

                 aPiece = new Bishop(false);
                 if(i%2==0){
                     aSquare = Board::getBoard()->squareAt(kingsColumn-(i/2), 7);
                 }else{
                     aSquare = Board::getBoard()->squareAt(kingsColumn+(i/2)+1, 7);
                 }

                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 blackPieces[numberofPawns+i]=aPiece;
                 break;


             case 4: // Black Queen

                 //cout<<"black queen"<<endl;

                 aPiece = new Queen(false);
                 if(i%2==0){
                     aSquare = Board::getBoard()->squareAt(kingsColumn-(i/2), 7);
                 }else{
                     aSquare = Board::getBoard()->squareAt(kingsColumn+(i/2)+1, 7);
                 }
                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 blackPieces[numberofPawns+i]=aPiece;
                 break;

             case 5: // Black Apolo

                 //cout<<"black Apolo"<<endl;

                 aPiece = new Apolo(false);
                 if(i%2==0){
                     aSquare = Board::getBoard()->squareAt(kingsColumn-(i/2), 7);
                 }else{
                     aSquare = Board::getBoard()->squareAt(kingsColumn+(i/2)+1, 7);
                 }
                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 blackPieces[numberofPawns+i]=aPiece;
                 break;


             }

         }

     }else{  // Case with 7 random pieces. The previous case is not valid due to some restrictions
             // We place all random pieces from 0 to 7. When we find king's column we jump one square

         for(int i=1; i<=numberofRandoms; i++){

             int random_1, random_2;

             random_1 = rand()%5 +1;   // For white pieces
             random_2 = rand()%5 +1;   // For black pieces

           //  cout<<"Random 1 "<<i<<" "<<random_1<<endl;
             //cout<<"Random 2 "<<i<<" "<<random_2<<endl;

             static int pos_white=0;
             static int pos_black=0;

             switch(random_1){

             case 1: // White Rook

               //  cout<<"white rook"<<endl;
                 aPiece = new Rook(true);

                 if(i-1==kingsColumn){
                     pos_white++;
                 }

                 aSquare = Board::getBoard()->squareAt(pos_white, 0);
                 pos_white++;

                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 whitePieces[numberofPawns+i]=aPiece;
                 break;

             case 2: // White Knight

                 //cout<<"white knuight"<<endl;

                 aPiece = new Knight(true);

                 if(i-1==kingsColumn){
                     pos_white++;
                 }

                 aSquare = Board::getBoard()->squareAt(pos_white, 0);
                 pos_white++;


                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 whitePieces[numberofPawns+i]=aPiece;
                 break;

             case 3: // White Bishop

                 //cout<<"white bishop"<<endl;

                 aPiece = new Bishop(true);

                 if(i-1==kingsColumn){
                     pos_white++;
                 }

                 aSquare = Board::getBoard()->squareAt(pos_white, 0);
                 pos_white++;

                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 whitePieces[numberofPawns+i]=aPiece;
                 break;

             case 4: // White Queen

                 //cout<<"white queen"<<endl;

                 aPiece = new Queen(true);

                 if(i-1==kingsColumn){
                     pos_white++;
                 }

                 aSquare = Board::getBoard()->squareAt(pos_white, 0);
                 pos_white++;

                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 whitePieces[numberofPawns+i]=aPiece;
                 break;

             case 5: // White Apolo

                 //cout<<"white Apolo"<<endl;

                 aPiece = new Apolo(true);

                 if(i-1==kingsColumn){
                     pos_white++;
                 }

                 aSquare = Board::getBoard()->squareAt(pos_white, 0);
                 pos_white++;

                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 whitePieces[numberofPawns+i]=aPiece;
                 break;

             }


             switch(random_2){

             case 1: // Black Rook

               //  cout<<"black rook"<<endl;


                 aPiece = new Rook(false);

                 if(i-1==kingsColumn){
                     pos_black++;
                 }



                 aSquare = Board::getBoard()->squareAt(pos_black, 7);
                 pos_black++;

                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 blackPieces[numberofPawns+i]=aPiece;
                 break;

             case 2: // Black Knight

              //   cout<<"black knuight"<<endl;

                 aPiece = new Knight(false);

                 if(i-1==kingsColumn){
                     pos_black++;
                 }

                 aSquare = Board::getBoard()->squareAt(pos_black, 7);
                 pos_black++;


                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 blackPieces[numberofPawns+i]=aPiece;
                 break;

             case 3: // Black Bishop

                // cout<<"black bishop"<<endl;

                 aPiece = new Bishop(false);

                 if(i-1==kingsColumn){
                     pos_black++;
                 }

                 aSquare = Board::getBoard()->squareAt(pos_black, 7);
                 pos_black++;

                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 blackPieces[numberofPawns+i]=aPiece;
                 break;


             case 4: // Black Queen

               //  cout<<"black queen"<<endl;

                 aPiece = new Queen(false);

                 if(i-1==kingsColumn){
                     pos_black++;
                 }

                 aSquare = Board::getBoard()->squareAt(pos_black, 7);
                 pos_black++;

                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 blackPieces[numberofPawns+i]=aPiece;
                 break;

             case 5: // Black Apolo

                // cout<<"black Apolo"<<endl;

                 aPiece = new Apolo(false);

                 if(i-1==kingsColumn){
                     pos_black++;
                 }

                 aSquare = Board::getBoard()->squareAt(pos_black, 7);
                 pos_black++;

                 aSquare->setOccupier(aPiece);
                 aPiece->setLocation(aSquare);
                 blackPieces[numberofPawns+i]=aPiece;
                 break;

             }

         }

     }



    // create White player and hand them their pieces
    player1 = new Player("White", true, *aKing, whitePieces, true);

    switch(selcc){

    case 1: player2 = new Player("Black", false, *aKing, blackPieces, true);
        break;
    case 2: player2 = new Player("Black", false, *aKing, blackPieces, false);
        break;


    }

    // create Black player and hand them their pieces


    nextPlayer = player2;   // We assigne it to the black player so that when we start we change to white player
}


void Game::saveGame(){

    cout<<"Introduce the name of the match"<<endl;
    string name;
    cin>>name;
    name+=".txt";
    char filename[100];
    for (int i=0;i<=name.size();i++){
        filename[i]=name[i];
    }



ofstream fichero(filename);

    for(unsigned int i=0;i<whitePieces.size();i++){
fichero<< whitePieces[i]->location()->occupiedBy()->displayName()<< "("<<whitePieces[i]->location()->getX() <<whitePieces[i]->location()->getY()<<")"<<endl;



    }
    for(unsigned int i=0;i<blackPieces.size();i++){

        fichero<< blackPieces[i]->location()->occupiedBy()->displayName()<< "("<<blackPieces[i]->location()->getX() <<blackPieces[i]->location()->getY()<<")"<<endl;

    }
cout<<"Game saved as "<<filename<<endl;

fichero.close();
}





Player* Game::getNextPlayer()
{
    nextPlayer = opponentOf(*nextPlayer);
    return nextPlayer;
}

Player* Game::opponentOf(Player& player)
{
    Player* opponent;

    if(player.getName() == player1->getName())
    {
        opponent = player2;
    }
    else
    {
        opponent = player1;
    }

    return opponent;
}

Player* Game::player1 = NULL;
Player* Game::player2 = NULL;
Player* Game::nextPlayer = NULL;
vector<Piece*> Game::whitePieces;
vector<Piece*> Game::blackPieces;
