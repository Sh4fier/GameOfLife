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
    cout << "for Y :";
    cin >> size;
    int width= size * BLOCK ;
    int height=size * BLOCK ; 
    bool net[width][height] = {}; 
    sf::Texture dead_img;
    sf::Texture alive_img;
    dead_img.loadFromFile("Dead.png"); 
    alive_img.loadFromFile("Alive.png");
    sf::Sprite dead_sprite(dead_img);
    sf::Sprite alive_sprite(alive_img);
    bool simulation_on = false;
    // cout << "file name ";
   // cin >> file ;
    //cout << file <<endl ;
    int simCount;
    //cout << "number of generations: " ;
    //cin >> simCount ;
    /*ifstream readf(file);
        if (readf.is_open()){
            string line,firstint,secondint;
            while (getline(readf,line)){
                stringstream ss(line);
                getline(ss,firstint,' ');
                getline(ss,secondint,' ');
                x = stoi(firstint);
                y = stoi(secondint);
                net[x][y] = 1 ;
            }
        }*/

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
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
            sf::Vector2i pos = sf::Mouse::getPosition(window);
		int i = pos.x / BLOCK;
		int j = pos.y / BLOCK;
            if(e.type==sf::Event::MouseButtonPressed){
                if(e.key.code==sf::Mouse::Left){
                    if(net[i][j]==0){
                        net[i][j]=1;
                    }
                    else{
                        net[i][j]=0;
                    }
                }
            }
            if (e.type == sf::Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::Enter) {
					if (simulation_on) {
						simulation_on = false;
					}
					else {
						simulation_on = true;
					}
			
				}
			}
        }
window.clear();
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
while (simulation_on){
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
            sf::Vector2i pos = sf::Mouse::getPosition(window);
		int i = pos.x / BLOCK;
		int j = pos.y / BLOCK;
            if(e.type==sf::Event::MouseButtonPressed){
                if(e.key.code==sf::Mouse::Left){
                    if(net[i][j]==0){
                        net[i][j]=1;
                    }
                    else{
                        net[i][j]=0;
                    }
                }
            }
            if (e.type == sf::Event::KeyPressed) {
				if (e.key.code == sf::Keyboard::Enter) {
					if (simulation_on) {
						simulation_on = false;
					}
					else {
						simulation_on = true;
					}
			
				}
			}
        }
bool Nnet[width][height];
int liveCounter = 0 ;
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
                Nnet[x][y] = 1;
            }
            else{
                Nnet[x][y] = 0;
            if (liveCounter==3){
                Nnet[x][y] = 1;
            }
            if (liveCounter>4)
            Nnet[x][y] = 0;
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

        
window.display();
}
}
    return 0;
}