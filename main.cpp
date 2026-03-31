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
};

// Tokenizer

vector<Token> tokenize(const string& line) {
    vector<Token> tokens;
    string item = "";
    for (char c: line) {
        if (c == ' ') {
            if (!item.empty()) {
                tokens.push_back(Token{"[" + item + "]"});
                item = "";
            }
        }
        if (!item.empty()) {
            tokens.push_back(Token{"[" + item + "]"});
        }
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
        if (precedence(tokens[i].value) == 0) {
            count++;
        } else {
            return false;
        }
    }
    // TODO
    return count;
}

bool isValidInfix(const vector<Token>& tokens) {
    if (tokens.size() == 0) {
        return false;
    }
    for (int i = 0; i < tokens.size(); i++) {
        if (precedence(tokens[i].value) > 0) {
            if (i == 0 || i == tokens.size() - 1) {
                return false;
            }
            if (precedence(tokens[i - 1].value) == 0) {
                return false;
            }
            if (precedence(tokens[i + 1].value) == 0) {
                return false;
            }
        }
    }

    // TODO
    return true;
}

// Conversion

vector<Token> infixToPostfix(const vector<Token>& tokens) {
    vector<Token> output;
    vector<Token> temp;

    for (int i = 0; i < tokens.size(); i++) {
        if (precedence(tokens[i].value == 0)){
            temp.push_back(tokens[i]);
        } else {
            while (temp.size() > 0) {
                output.push_back(tokens[i]);
                temp.pop_back();
            }
        }
    }

    // TODO
    return output;
}

// Evaluation

double evalPostfix(const vector<Token>& tokens) {
    ArrayStack<double> stack;
    // TODO
    return 0.0;
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
