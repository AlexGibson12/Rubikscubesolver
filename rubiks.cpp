#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef enum {
    WHITE,
    BLUE,
    RED,
    GREEN,
    ORANGE,
    YELLOW
} Colour;
typedef struct {
    vector<vector<Colour>> colours;
    
} Face;         


class Cube {
    public:
        int size;
        vector<Face> faces;
        map<pair<int,int>,int> cyclenum;
        map<int,pair<int,int>>  reversecycle;
  
        
        
        Cube(int size_){
            faces = {};
            size = size_;
            cyclenum = {};
            reversecycle ={};
            for(int colour=WHITE;colour <= YELLOW;colour+=1){
                faces.push_back({});
                for(int i = 0;i<size;i++){
                    faces[colour].colours.push_back({});
                    for(int j = 0;j<size;j++){
                        faces[colour].colours[i].push_back(static_cast<Colour>(colour));
                    }
                }
            }
            for(int i = 0;i<size;i++){
                cyclenum.insert({{i,0},i});
                reversecycle.insert({i,{i,0}});
            }
            for(int i = 0;i<size;i++){
                cyclenum.insert({{size-1,i},size-1+i});
                reversecycle.insert({size-1+i,{size-1,i}});
            }
            for(int i = 0;i<size;i++){
                cyclenum.insert({{size-1-i,size-1},2*size-2+i});
                reversecycle.insert({2*size-2+i,{size-1-i,size-1}});
            }
            for(int i = 0;i<size-1;i++){
                cyclenum.insert({{0,size-1-i},3*size-3+i});
                reversecycle.insert({3*size-3+i,{0,size-1-i}});
            }
            
            
        }  
      

        void MakeRMove(int reverse){
            vector<Face> newfaces = faces;
            vector<Colour> cyclefaces = {BLUE,YELLOW,GREEN,WHITE};
            vector<vector<pair<int,int>>> transitions={{{2,2},{2,2},{2,2},{2,2}},
            {{2,1},{2,1},{2,1},{2,1}},
           {{2,0},{2,0},{2,0},{2,0}}};
            for(auto transition:transitions){
                for(int i =0;i<cyclefaces.size();i++){
                    int next = (i+cyclefaces.size()+reverse)%cyclefaces.size();
                    newfaces[cyclefaces[next]].colours[transition[next].second][transition[next].first] = faces[cyclefaces[i]].colours[transition[i].second][transition[i].first] ;
                }
            }
            faces = newfaces;
            rotateFace(RED,-1*reverse);
        }

        void MakeFMove(int reverse){

            vector<Face> newfaces = faces;
            vector<Colour> cyclefaces = {YELLOW,RED,WHITE,ORANGE};
            vector<vector<pair<int,int>>> transitions={{{0,2},{0,0},{2,0},{2,2}},
            {{1,2},{0,1},{1,0},{2,1}},
           {{2,2},{0,2},{0,0},{2,0}}};
            for(auto transition:transitions){
                for(int i =0;i<cyclefaces.size();i++){
                    int next = (i+cyclefaces.size()+reverse)%cyclefaces.size();
                    newfaces[cyclefaces[next]].colours[transition[next].second][transition[next].first] = faces[cyclefaces[i]].colours[transition[i].second][transition[i].first] ;
                }
            }
            faces = newfaces;
            rotateFace(BLUE,-1*reverse);
        }
        void MakeUMove(int reverse){
            vector<Face> newfaces = faces;
            vector<Colour> cyclefaces = {BLUE,ORANGE,GREEN,RED};
            vector<vector<pair<int,int>>> transitions={{{0,0},{0,0},{2,2},{0,0}},
            {{1,0},{1,0},{1,2},{1,0}},
           {{2,0},{2,0},{0,2},{2,0}}};
            for(auto transition:transitions){
                for(int i =0;i<cyclefaces.size();i++){
                    int next = (i+cyclefaces.size()+reverse)%cyclefaces.size();
                    newfaces[cyclefaces[next]].colours[transition[next].second][transition[next].first] = faces[cyclefaces[i]].colours[transition[i].second][transition[i].first] ;
                }
            }
            faces = newfaces;
            rotateFace(YELLOW,-1*reverse);
        }
        void MakeDMove(int reverse){
            vector<Face> newfaces = faces;
            vector<Colour> cyclefaces = {BLUE,RED,GREEN,ORANGE};
            vector<vector<pair<int,int>>> transitions={{{0,2},{0,2},{2,0},{0,2}},
            {{1,2},{1,2},{1,0},{1,2}},
           {{2,2},{2,2},{0,0},{2,2}}};
            for(auto transition:transitions){
                for(int i =0;i<cyclefaces.size();i++){
                    int next = (i+cyclefaces.size()+reverse)%cyclefaces.size();
                    newfaces[cyclefaces[next]].colours[transition[next].second][transition[next].first] = faces[cyclefaces[i]].colours[transition[i].second][transition[i].first] ;
                }
            }
            faces = newfaces;
            rotateFace(WHITE,-1*reverse);
        }
        void MakeBMove(int reverse){
            vector<Face> newfaces = faces;
            vector<Colour> cyclefaces = {YELLOW,ORANGE,WHITE,RED};
            vector<vector<pair<int,int>>> transitions={{{2,0},{0,0},{0,2},{2,2}},
            {{1,0},{0,1},{1,2},{2,1}},
           {{0,0},{0,2},{2,2},{2,0}}};
            for(auto transition:transitions){
                for(int i =0;i<cyclefaces.size();i++){
                    int next = (i+cyclefaces.size()+reverse)%cyclefaces.size();
                    newfaces[cyclefaces[next]].colours[transition[next].second][transition[next].first] = faces[cyclefaces[i]].colours[transition[i].second][transition[i].first] ;
                }
            }
            faces = newfaces;
            rotateFace(GREEN,-1*reverse);
        }
        void MakeLMove(int reverse){
            vector<Face> newfaces = faces;
            vector<Colour> cyclefaces = {BLUE,WHITE,GREEN,YELLOW};
            vector<vector<pair<int,int>>> transitions={{{0,0},{0,0},{0,0},{0,0}},
            {{0,1},{0,1},{0,1},{0,1}},
           {{0,2},{0,2},{0,2},{0,2}}};
            for(auto transition:transitions){
                for(int i =0;i<cyclefaces.size();i++){
                    int next = (i+cyclefaces.size()+reverse)%cyclefaces.size();
                    newfaces[cyclefaces[next]].colours[transition[next].second][transition[next].first] = faces[cyclefaces[i]].colours[transition[i].second][transition[i].first] ;
                }
            }
            faces = newfaces;
          
            rotateFace(ORANGE,-1*reverse);
            
        }
        void rotateFace(Colour facetorotate,int clockwise){
            vector<Face> newfaces = faces;
    
            for(int i = 0;i<4*size-4;i++){
                pair<int,int> coords = reversecycle[i];
                pair<int,int> previouscoords = reversecycle[(i+4*size-4+2*clockwise)%(4*size-4)];
                newfaces[facetorotate].colours[coords.second][coords.first] = faces[facetorotate].colours[previouscoords.second][previouscoords.first];
            }
            faces = newfaces;
        }
        
        void permuteFaces(vector<int> permutation){
            vector<Face> newfaces = {};
            for(int i = 0;i<faces.size();i++){
                newfaces.push_back(faces[permutation[i]]);
            }
            faces = newfaces;
        }
        static char colourtext(Colour colour){
            int i = static_cast<int>(colour);
            vector<char> codes = {'W','B','R','G','O','Y'};
            return codes[i];
        }
        void printFaces() const{
            for(auto face:faces){
                for(auto x: face.colours){
                    for(auto y:x){
                        cout << colourtext(y);
                    }
                    cout << endl;                
                }
                cout << endl;
            }
        }
};

