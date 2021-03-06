#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h> // time libaray
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

    if (guessCount >= 3)
    {
        PrintMessage("O", false, false);
    }
    else
    {
        PrintMessage("", false, false);
    }

    if (guessCount == 4)
    {
        PrintMessage("/", false, false);
    }

    if (guessCount == 5)
    {
        PrintMessage("/|", false, false);
    }

    if (guessCount >= 6)
    {
        PrintMessage("/|\\", false, false); //escape the escape char
    }
    else
    {
        PrintMessage("", false, false);
    }

    if (guessCount >= 7)
    {
        PrintMessage("|", false, false);
    }
    else
    {
        PrintMessage("", false, false);
    }
    if (guessCount == 8)
    {
        PrintMessage("/", false, false);
    }
    if (guessCount >= 9)
    {
        PrintMessage("/ \\", false, false);
    }
    else
    {
        PrintMessage("", false, false);
    }
}

void PrintLetters(string input, char from, char to)
{
    string s;
    for (char i = from; i <= to; i++)
    //loop through char
    {
        if (input.find(i) == string::npos)
        {
            s += i;
            s += " ";
        }
        //if input contains the current char == if input dose not contain it then the string returns npos
        //npos returns the char as it exists
        else
        {
            s += "";
        }
    }
    PrintMessage(s, false, false);
}

void PrintAvailableLetters(string taken)
{
    PrintMessage("Available Letters");
    PrintLetters(taken, 'A', 'M');
    PrintLetters(taken, 'N', 'Z');
}

bool PrintWordAndCheckWin(string word, string guessed)
{
    bool won = true;
    string s;
    for (int i = 0; i < word.length(); i++)
    {
        if (guessed.find(word[i]) == string::npos)
        {
            won = false;
            s += "_ ";
        }
        else
        {
            s += word[i];
            s += " ";
        }
    }
    PrintMessage(s, false);
    return won;
}

string LoadRandomWord(string path)
{
    int lineCount = 0;
    string word;

    //vertor is special type of array that can be sized and resized
    // in order to use it I need to include it up top
    //basically a dynamic array
    //call vector <what type of array> what to call this vector
    vector<string> v;
    //ifstream is called up top and is the txt file where my words are being pulled from
    ifstream reader(path);
    //renaming it as readerwith access to the path
    if (reader.is_open())
    //if the file is succesfully opened
    //is_open method used my reader= ifstream that can access the path
    {
        while (std::getline(reader, word)) //reader is the files it gets the word from and 'word' is where its storing it
        {
            v.push_back(word); //as it reads the file and brings the word to this file, then using push_back function it stores it
            int randomLine = rand() % v.size();

            word = v.at(randomLine);
            reader.close();
        }
        return word;
    }
}
int TriesLeft(string word, string guessed)
{
    int error = 0;
    for (int i = 0; i < guessed.length(); i++)
    {
        if (word.find(guessed[i]) == string::npos)
            error++;
    }
    return error;
}
int main()
{
    srand(time(0)); //return the standard time in unix
    string guesses = "ABHJIKKLL";
    string wordToGuess;
    wordToGuess = LoadRandomWord("words.txt");
    cout << wordToGuess << endl
         << endl;
    PrintMessage("HANG MAN");
    int tries = 0;
    bool win = false;
    do
    {
        system("clear"); // clears the screem
        PrintMessage("HANGMAN");
        DrawHangman(tries);
        PrintAvailableLetters(guesses);
        PrintMessage("Guess the Word");
        PrintWordAndCheckWin("ALEXES", guesses);

        if (win)
            break;

        char x;
        cout << ">"; cin >> x;
        if (guesses.find(x)==string ::npos)
            guesses+= x;
        
        tries = TriesLeft(wordToGuess,guesses);

    } 
    while (tries < 10);

    getchar();
    return 0;
}