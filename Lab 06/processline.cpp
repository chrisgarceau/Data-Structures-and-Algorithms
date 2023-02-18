#include <iostream>
#include <cctype>
#include "mystack.h"

double process_line(std::istream &f) {
    DS::mystack<double> stack;  //DECLARATION OF NEW STACK.
    std::string line;  //CONTAINS EACH LINE OF INPUT FROM FILE.
    while (getline(f, line)) {  //WHILE THERE ARE STILL LINES TO READ.
        int j = 0;  //KEEPS TRACK OF AND UPDATES INDEX ACCORDINGLY.
        for (j = 0; j < line.size(); j++) {
            //IF THERE IS A SINGLE DIGIT OR DOUBLE DIGIT WITHIN THE LINE, PUSH ONTO STACK.
            if (isdigit(line[j]) || ((isdigit(line[j])) && isdigit(line[j + 1]))) {
                //DOUBLE DIGIT PUSH.
                if (isdigit(line[j]) && isdigit(line[j + 1])) {
                    double a = (line[j] - 48) * 10;
                    double b = (line[j + 1]) - 48;
                    double num = a + b;
                    stack.push(num);
                    j++; //UPDATES INDEX THE NUMBER IN THE ONES PLACE WILL NOT BE PUSHED.
                }
                //SINGLE DIGIT PUSH.
                else if (isdigit(line[j])) {
                    double num = line[j] - 48;
                    stack.push(num);
                }
            }
            //IF THERE IS A SPACE BEFORE A DIGIT, PUSH ONTO STACK.
            else if (isdigit(line[j]) && isspace(line[j - 1])) {
                double num = line[j + 1] - 48;
                stack.push(num);
            }
            //IF THERE IS A NEGATIVE SIGN DIRECTLY BEFORE A DIGIT, MULTPLY BY -1 AND PUSH ONTO STACK.
            else if((line[j] == '-') && isdigit(line[j + 1])) {
                double num = (line[j + 1] - 48) * -1;
                stack.push(num);
                j = j + 2;  //UPDATE INDEX SO POSITIVE VERSION OF THE NUMBER IS NOT PUSHED.
            }
            //IF CHARACTER IN LINE IS AN OPERATOR, CALCULATE USING THE TOP 2 NUMBERS, THEN PUSH RESULT ONTO STACK.
            else if (!isspace(line[j])){
                char operate = line[j];
                double val1 = stack.top();
                stack.pop();
                double val2 = stack.top();
                stack.pop();
                int num1 = val1;
                int num2 = val2;
                switch(operate) {
                    case '+':
                        stack.push(val2 + val1);
                        break;
                    case '-':
                        stack.push(val2 - val1);
                        break;
                    case '*':
                        stack.push(val2 * val1);
                        break;
                    case '/':
                        if (val1 == 0 || val2 == 0) {
                            val1 = 0;
                            val2 = 0;
                        }
                        stack.push(val2 / val1);
                        break;
                    case '%':
                        stack.push(num2 % num1);
                        break;
                }
            }
        }
        //IF THERE IS ONLY ONE NUMBER ON THE STACK, RETURN THE TOP VALUE.
        if (stack.size() == 1) {
            return stack.top();
        }
        //THERE IS MORE THAN ONE NUMBER ON THE STACK, SO RETURN nan("Invalid").
        else {
            double invalid1 = 0;
            double invalid2 = 0;
            return invalid2 / invalid1;
        }
    }
}