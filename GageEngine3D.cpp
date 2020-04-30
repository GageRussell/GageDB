// GageEngine3D.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


enum PrepareResult {PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT};
enum StatementType { STATEMENT_INSERT, STATEMENT_SELECT };
enum MetaCommandResult {META_COMMAND_SUCCESS, META_COMMAND_UNRECOGNIZED};

struct Statement{
    StatementType type;
};

void print_prompt() { cout << "Gagedb>"; }

MetaCommandResult do_meta_command(string input_from_usr) {
    if (input_from_usr == ".exit") {
        exit(EXIT_SUCCESS);
    }
    else {
        return META_COMMAND_UNRECOGNIZED;
    }
}

PrepareResult prepare_statement(string input_from_usr, Statement &statement) {
    string statement_type = input_from_usr.substr(0, 6);
    if (statement_type == "insert")
    {
        statement.type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }
    if (statement_type == "select")
    {
        statement.type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }
    return PREPARE_UNRECOGNIZED_STATEMENT;
}

void execute_statement(Statement& statement) {
    switch (statement.type) {
    case (STATEMENT_INSERT):
        cout << "Here is a insert statment" << endl;
        break;
    case(STATEMENT_SELECT):
        cout << "Here is a select statment" << endl;
        break;
    }
}
int main()
{
    cout << "Welcome to GageDB" << endl;
    cout << "GageDB version 0.1 2020-04-29" << endl;
    while (true) {
        
        print_prompt();
        string usr_input;
        getline(cin, usr_input);

        string first_char;
        first_char = usr_input.at(0);
        if (first_char == ".") {
            //cout << first_char << endl;
            switch (do_meta_command(usr_input)) {
            case (META_COMMAND_SUCCESS):
                continue;
                break;
            case (META_COMMAND_UNRECOGNIZED):
                cout << "Unrecognized command '" << usr_input << "'" << endl;
                break;
            }
        }
                
        Statement statement;
        switch (prepare_statement(usr_input, statement)) {
        case(PREPARE_SUCCESS):
            break;
        case(PREPARE_UNRECOGNIZED_STATEMENT):
            cout << "Unrecognized keyword at start of '" << usr_input << "'" << endl;
            continue;
        }
        
        execute_statement(statement);
     
        
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
