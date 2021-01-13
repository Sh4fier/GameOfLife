#include<iostream>
#include<string>
#include<fstream>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    int BLOCK = 8;
    string file;
    int size;
    int x,y ;
    cout << "how large field you want?"<< endl;
    cout << "for X :";
    cin >> size;
    //width=width+2;
    cout << "for Y :";
    cin >> size;
    //height=height+2;
    int width= size * BLOCK ;
    int height=size * BLOCK ; 
    bool net[width][height] = {}; 
    sf::Texture dead_img;
    sf::Texture alive_img;
    dead_img.loadFromFile("Dead.png"); 
    alive_img.loadFromFile("Alive.png");
    sf::Sprite dead_sprite(dead_img);
    sf::Sprite alive_sprite(alive_img);
     cout << "file name ";
    cin >> file ;
    cout << file <<endl ;
    int simCount;
    cout << "number of generations: " ;
    cin >> simCount ;
    ifstream readf(file);
        if (readf.is_open()){
            string line,firstint,secondint;
            while (getline(readf,line)){
                stringstream ss(line);
                getline(ss,firstint,' ');
                getline(ss,secondint,' ');
                x = stoi(firstint);
                y = stoi(secondint);
                net[x][y] = true ;
            }
        }
    sf::RenderWindow window(sf::VideoMode(width, height), "GameOfLife");
 for (int x=1 ; x < width ; x++ ){
            for (int y=1 ; y < height ; y++){
                if (net[x][y]){
                     alive_sprite.setPosition( x*BLOCK, y*BLOCK);
                    window.draw(alive_sprite);
                }
                else{
                   dead_sprite.setPosition( x*BLOCK, y*BLOCK);
                    window.draw(dead_sprite);
                }
            }         
        } 
        window.display();
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }
       
bool Nnet[width][height];
int liveCounter = 0 ;
//cout << "number of generations: " ;
//cin >> simCount ;
//for (int z=0 ; z<simCount ;z++ ){                   //count of simulations
    for (int x=1 ; x < width-1 ; x++ ){
        for (int y=1 ; y < height-1 ; y++){
            liveCounter=0;
            if (net[x][y+1]){
                liveCounter++;
            }
            if (net[x+1][y]){
                liveCounter++;
            }
            if (net[x][y-1]){
                liveCounter++;
            }
            if (net[x-1][y]){
                liveCounter++;
            }
            if (net[x-1][y+1]){
                liveCounter++;
            }
            if (net[x-1][y-1]){
                liveCounter++;
            }
            if (net[x+1][y+1]){
                liveCounter++;
            }
            if (net[x+1][y-1]){
                liveCounter++;
            }
            if ((liveCounter>=2) && (liveCounter<=4)){
                Nnet[x][y] = true;
            }
            else{
                Nnet[x][y] = false;
            if (liveCounter==3){
                Nnet[x][y] = true;
            }
            if (liveCounter>4)
            Nnet[x][y] = false;
            }
        }
    }
    for (int x=1 ; x < width-1 ; x++ ){
        for (int y=1 ; y < height-1 ; y++){
            net[x][y] =  Nnet[x][y];
        }
    }
    for (int x=1 ; x < width-1 ; x++ ){
        for (int y=1 ; y < height-1 ; y++){
            if (net[x][y]) {
                alive_sprite.setPosition( x*BLOCK, y*BLOCK);
                    window.draw(alive_sprite);
            }
            else{
                dead_sprite.setPosition( x*BLOCK, y*BLOCK);
                    window.draw(dead_sprite);
            } 
        }
        cout << endl;          
    } 
    cout << endl;
//}

        
//window.display();
}
  





       


/*bool Nnet[width][height];
int liveCounter = 0 ;
int simCount;
cout << "number of generations: " ;
cin >> simCount ;
for (int z=0 ; z<simCount ;z++ ){                   //count of simulations
    for (int x=1 ; x < width-1 ; x++ ){
        for (int y=1 ; y < height-1 ; y++){
            liveCounter=0;
            if (net[x][y+1]){
                liveCounter++;
            }
            if (net[x+1][y]){
                liveCounter++;
            }
            if (net[x][y-1]){
                liveCounter++;
            }
            if (net[x-1][y]){
                liveCounter++;
            }
            if (net[x-1][y+1]){
                liveCounter++;
            }
            if (net[x-1][y-1]){
                liveCounter++;
            }
            if (net[x+1][y+1]){
                liveCounter++;
            }
            if (net[x+1][y-1]){
                liveCounter++;
            }
            if ((liveCounter>=2) && (liveCounter<=4)){
                Nnet[x][y] = true;
            }
            else{
                Nnet[x][y] = false;
            if (liveCounter==3){
                Nnet[x][y] = true;
            }
            if (liveCounter>4)
            Nnet[x][y] = false;
            }
        }
    }
    for (int x=1 ; x < width-1 ; x++ ){
        for (int y=1 ; y < height-1 ; y++){
            net[x][y] =  Nnet[x][y];
        }
    }
    for (int x=1 ; x < width-1 ; x++ ){
        for (int y=1 ; y < height-1 ; y++){
            if (net[x][y]) {
                cout<< " O " ;
            }
            else{
                cout<< " X " ;
            } 
        }
        cout << endl;          
    } 
    cout << endl;*/

    return 0;
}
