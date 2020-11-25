#include<iostream>
#include<string>
#include<fstream>
#include <sstream>

using namespace std;

int main()
{
    string file;
    int width = 8;
    int height = 8; 
    int x,y ;
    bool net[width][height] = {}; 
    cout << "file name ";
    cin >> file ;
    cout << file <<endl ;
    ifstream readf(file);
        if (readf.is_open())
        {
         string line,firstint,secondint;
         while (getline(readf,line))
            {
            stringstream ss(line);
            getline(ss,firstint,' ');
            getline(ss,secondint,' ');
            x = stoi(firstint);
            y = stoi(secondint);
            net[x][y] = true ;
            }

        }
            else 
            {
             cout<< "No such file" <<endl;
            }
    for (int x=0 ; x < width ; x++ )
        {
        for (int y=0 ; y < height ; y++)
        {
            if (net[x][y]) 
            {
            cout<< " O " ;
            }
            else 
            {
            cout<< " X " ;
            } 
        }         
        cout << endl;
        }
bool Nnet[width][height];
int liveCounter = 0 ;
int pocetSimulacii;
cout << "zadaj pocet opakovani: " ;
cin >> pocetSimulacii ;
for (int z=0 ; z<pocetSimulacii ; z++) //count of simulations
    {
    for (int x=0 ; x < width ; x++ )
        {
        for (int y=0 ; y < height ; y++)
            {
            
               if (net[x][y+1])
               {
                  liveCounter++;
               }
               if (net[x+1][y])
               {
                   liveCounter++;
               }
               if (net[x][y-1])
               {
                liveCounter++;
               }
               if (net[x-1][y])
               {
                liveCounter++;
               }
               if (net[x-1][y+1])
               {
                liveCounter++;
               }
               if (net[x-1][y-1])
               {
                liveCounter++;
               }
               if (net[x+1][y+1])
               {
                liveCounter++;
               }
               if (net[x+1][y-1])
               {
                liveCounter++;
               }
               if ((liveCounter>3) && (liveCounter<6))
               {
                   Nnet[x][y] = true;
               }
               else
               {
                   Nnet[x][y] = false;
               }
               
            }
        }
     //net[x][y] =  Nnet[x][y];
    Nnet[x][y] = net[x][y];
    liveCounter=0;
    for (int x=0 ; x < width ; x++ )
        {
        for (int y=0 ; y < height ; y++)
        {
            if (net[x][y]) 
            {
            cout<< " O " ;
            }
            else 
            {
            cout<< " X " ;
            } 
        }
        cout << endl;          
    } 
    cout << endl;
    }
    return 0;
}