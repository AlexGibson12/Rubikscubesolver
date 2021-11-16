#include "rubiks.cpp"


class Parser{
public:
    string input;
    Cube cube {3};
    int pointer;
    int val;
    char code;
    Parser(string input_,Cube cube_ ){
        vector<char> codes = {'R','F','U','B','D','L'};
        cube = cube_;
        set<char> validchars = {'R','F','U','B','D','L','x','y','z','0','1','2',
        '3','4','5','6','7','8','9','\''};
        input = "";
        for(auto x: input_){
            if(validchars.find(x) != validchars.end()){
                input+=x;
            }
        }
        
    }
    Cube parse(){
        pointer = 0;
        while(pointer<input.size()){
            consumeterm();
        }
        return cube;
    }
    void consumenum(){
        val = 0;
        while(pointer<input.size() and '0'<=input[pointer] and input[pointer]<='9'){
            val = 10*val + input[pointer]-'0';
            pointer +=1;
        }
        cout << val <<endl;
    }
    void executeterm(){
        switch(code){
            case 'R':{
                cube.MakeRMove(val);
                break;
            }
            case 'U':{
                cube.MakeUMove(val);
                break;
            }
            case 'F':{
                cube.MakeFMove(val);
                break;
            }
            case 'D':{
                cube.MakeDMove(val);
                break;
            }
            case 'B':{
                cube.MakeBMove(val);
                break;
            }
            case 'L':{
                cube.MakeLMove(val);
                break;
            }
        }
    }
    void consumeterm(){
        code = input[pointer];
        pointer+=1;
        val = 1;
        if('0'<=input[pointer] and input[pointer]<='9'){
            consumenum();
        }
        if(input[pointer] == '\''){
            val = -1;
            pointer+=1;
        }
        executeterm();
    }
    

};
