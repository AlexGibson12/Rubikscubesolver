#include "rubiks.cpp"
#include "parse.cpp"
string OrientEdges(Cube& cube){
    
}
int main(){
    ifstream fin;
    fin.open("moves.txt",ios::in);
    string input = "";
    string x = "";
    while(fin >> x){
        input+=x;
    }
    Cube cubes =Cube(3);
    Parser parse = Parser(input,cubes);
    cubes = parse.parse();
    OrientEdges(cubes);
}