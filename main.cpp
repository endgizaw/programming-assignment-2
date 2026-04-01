#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>

#include "ArrayStack.h"

using namespace std;

// Token

struct Token {
    string value;   // number, operator, or parenthesis
    double number;

};

// Tokenizer

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;
    string item = "";
    for (char c: line) {
        if (c == ' ') {
            if (!item.empty()) {
                tokens.push_back(Token{item});
                item = "";
            }
        } else {
            item += c;
        }

    }
    if (!item.empty()) {
        tokens.push_back(Token{item});
    }
    // TODO
    return tokens;
}

// Helpers

bool isOperator(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

int precedence(const string& op) {
    if (op == "*" || op == "/") {
        return 2;
    }
    if (op == "+" || op == "-") {
        return 1;
    }
    // TODO
    return 0;
}

// Detection

bool isValidPostfix(const vector<Token>& tokens) {
    if (tokens.size() == 0) {
        return false;
    }
    int count = 0;
    for (int i = 0; i < tokens.size(); i++) {
        if (!isOperator(tokens[i].value)) {
            count++;
        } else {
            if (count < 2) {
                return false;
            }
            count--;
        }
    }
    // TODO
    return count == 1;
}

bool isValidInfix(const vector<Token>& tokens) {
    if (tokens.size() == 0) {
        return false;
    }
    for (int i = 0; i < tokens.size(); i++) {
        if (isOperator(tokens[i].value) && i % 2 == 0) {
            return false;
        }
        if (!isOperator(tokens[i].value) && i % 2 == 1) {
            return false;
        }
    }


    // TODO
    return true;
}

// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    ArrayStack<Token> temp;

    for (int i = 0; i < tokens.size(); i++) {
        if (precedence(tokens[i].value) == 0){
            output.push_back(tokens[i]);
        } else {
            while (!temp.empty() && precedence(temp.top().value) >= precedence(tokens[i].value)){
                output.push_back(temp.top());
                temp.pop();
            }
            temp.push(tokens[i]);
        }
    }

    while (!temp.empty()) {
        output.push_back(temp.top());
        temp.pop();
    }
    // TODO
    return output;
}

// Evaluation

double makeDouble(const string& s) {
    double result = 0.0;
    for (int i = 0; i < s.size(); i++) {
        double num = s[i] - '0';
        result = result * 10 +num;
    }

    return result;
}

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;
    for (int i = 0; i < tokens.size(); i++) {
        if (precedence(tokens[i].value) == 0) {
            stack.push(makeDouble(tokens[i].value));
        }else {
            double right = stack.top();
            stack.pop();
            double left = stack.top();
            stack.pop();

            if (tokens[i].value == "+") {
                stack.push(left + right);
            }
            if (tokens[i].value == "-") {
                stack.push(left - right);

            }
            if (tokens[i].value == "*") {
                stack.push(left * right);
            }
            if (tokens[i].value == "/") {
                if (right == 0) {
                    return 0.0;
                }
                stack.push(left / right);

            }
        }
    }
    // TODO
    return stack.top();
}

// Main

int main() {
    string line;
    getline(cin, line);

    vector<Token> tokens = tokenize(line);

    if (isValidPostfix(tokens)) {
        cout << "FORMAT: POSTFIX\n";
        cout << "RESULT: " << evalPostfix(tokens) << "\n";
    }
    else if (isValidInfix(tokens)) {
        vector<Token> postfix = infixToPostfix(tokens);
        cout << "FORMAT: INFIX\n";
        cout << "POSTFIX: ";
        for (const auto& t : postfix) {
            cout << t.value << " ";
        }
        cout << "\n";
        cout << "RESULT: " << evalPostfix(postfix) << "\n";
    }
    else {
        cout << "FORMAT: NEITHER\n";
        cout << "ERROR: invalid expression\n";
    }

    return 0;
}
