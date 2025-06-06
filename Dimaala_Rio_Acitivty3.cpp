#include <iostream>

using namespace std;

char stack[20];
int top = -1;

string stackOutput = "";

void push(char val){
    stack[++top] = val;
    stackOutput +=val;
}

char pop(){
    stackOutput.erase(top, 1);
    char val = stack[top--];
    return val;
}

char peek(){
    return stack[top];
}

int checklevel(char operation){
    int level;
    
    if(operation == '(' || operation == ')'){
        level = 0;
    }else if(operation == '^'){
        level = 1;
    }else if(operation == '/' || operation == '*'){
        level = 2;
    }else if(operation == '+' || operation == '-'){
        level = 3;
    }else{
        level = 0;
    }
    
    return level;
}

void convertToPostfix(string input){
    string output ="";

    cout << "| input | Stack | Output |" <<endl;
    cout << "|------------------------|" <<endl;

    for(int i = 0; i < input.length(); i++){
        
        if (isdigit(input[i])){
            output += input[i];
            
        }else{
            
            if(top == -1){
                push(input[i]);
                
            }else{
                
                if(input[i] == '(' || peek() == '('){
                    push(input[i]);
                }else{
                    if (input[i] == ')'){
                        while(top >= 0 && peek() != '('){
                            output += pop();
                        }
                        
                        if(top >= 0 && peek() == '('){
                            pop();
                        }
                    }else{
                        
                        while(checklevel(peek()) <= checklevel(input[i])){
                            output += pop();
                        }
                        
                        push(input[i]);
                    }
                }
            }
        }

        cout << "| " << input[i] << " | " << stackOutput <<" | " << output << " |" <<endl;
        cout << "|------------------------|" <<endl;
    }
    
    while(top >= 0){
        output += pop();
    }
    
    cout << "The equivalent postfix is: " << output <<endl;
}

int main() {
    string input = "(5+6)*(2+1)";
    convertToPostfix(input);

    return 0;
}