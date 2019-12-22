/*
Alexander Zhang
Yasuhiro Yamada
22C Manish Goel

This program demonstrates the Calculator class which can turn an infix equation into its
postfix and prefix forms.


Flexibility in the parenthesis has been implemented. Parenthesis are not ambiguous with/without
spaces, so they are implemented in a way which reflects their consistency.

Negative values are not allowed, as per instructions. Every equation is validated.

The infix to postfix uses a stack of operators and a queue to parse through the equation.
The infix to prefix uses the method taught in class: reverse infix, find postfix, reverse postfix
Therefore, this part can reuse the code from the infix to postfix function for code efficiency.

The evaluating postfix function uses a stack to hold the operands, passing values and calculations to the stack.
The final answer remains in the stack.
The evaluating prefix function uses a stack to hold the operands. It does a similar process to the above except it goes from the back to the front.
There was a mental challenge in making the reversed string give the correct number values for numbers with two digits and up. I found a creative way to fix this.


The user can loop this program as long as they want. They simply press Enter afterwards to
continue.
If the user wishes to end, type anything then press Enter.
*/
#include <iostream>
#include <string>
#include "Calculator.h" //includes Stack and Queue ADT
using namespace std;

void getInfixPrompt(Calculator &);

void clarityLine();





int main()
{
    Calculator calc;

    char choice = '\n'; //choice = newline

    while (choice == '\n') // while choice == newline
    {

        getInfixPrompt(calc); //get the equation and convert them

                              //output the equation in infix, postfix, and prefix form
        cout << "Infix: " << calc.getInfixEquation() << endl;
        cout << "Postfix: " << calc.getPostfixEquation() << endl;
        cout << "Evaluated Result Postfix: " << calc.getPostResult() << endl;

        cout << "Prefix: " << calc.getPrefixEquation() << endl;
        cout << "Evaluated Result Prefix: " << calc.getPreResult() << endl;
        clarityLine();

        //allows user to repeat
        cout << "Only press Enter to repeat. Type anything else, then enter, to end. ";
        cin.get(choice);
        clarityLine();
    }

    system("pause");
    return 0;
}



/* outputs a line for visual clarity
Pre:
Post:
Return:
*/
void clarityLine()
{
    cout << string(30, '=') << endl;
}


/* gets the equation from the user. checks if valid.
Pre: &calc - Calculator object by reference.
Post: Equation is entered into the calculator object, which stores it
Return:
*/
void getInfixPrompt(Calculator &calc)
{
    string eqn; //holds the user input

                //checks if the input is invalid. Will be invalid first run to start the loop
    while (!calc.checkValidEqn(eqn))
    {
        cout << "Enter an Infix equation (No Negative Numbers)." << endl;
        cout << "(Separate Operands and Operators by a space): ";
        getline(cin, eqn);

        if (!calc.checkValidEqn(eqn)) //if invalid, report to user. will repeat loop
        {
            cout << "Invalid Equation!" << endl;
        }
    } //exits once equation is valid.
      //sets the equation in the calculator object, which immediately finds the post and prefix form
    calc.setEquation(eqn);
}
