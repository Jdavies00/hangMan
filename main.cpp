#include <iostream>
using namespace std;

void PrintMessage(string message, bool printTop = true, bool printBottom = true)

{
    if (printTop)
    {
        cout << "+---------------------------------+" << endl;
        cout << "|";
    }
    else
    {
        cout << "|";
    }
    bool front = true;
    for (int i = message.length(); i < 33; i++)
    {
        if (front)
        {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }
        front = !front;
    }
    cout << message.c_str();


    if (printBottom)
    {
        cout << "|" << endl;
        cout << "+---------------------------------+" << endl;
    }
     else
    {
        cout << "|" << endl;
    }
}
void DrawHangman(int guessCount = 0)
{
    if (guessCount >= 1)
    {
        PrintMessage("|", false, false);
    }
    else
    {
        PrintMessage("", false, false);
    }
     if (guessCount >= 2)
    {
        PrintMessage("|", false, false);
    }
    else
    {
        PrintMessage("", false, false);
    }
}

int main()
{
    PrintMessage("HANGMAN");
    DrawHangman(2);
    getchar();
    return 0;
}