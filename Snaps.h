//
// Created by beauc on 10/26/2022.
//

#ifndef GAMEOFSNAPS_H
#define GAMEOFSNAPS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Snaps {
private:
    // A method below will call to a database outside of C++
    // and there will be getters and setters for this string
    string codeWord;
    int numberOfWords;
    int wordIndex = 0;
public:
    Snaps() {
        openingLine();
        setup();
    }

    void openingLine(){
        cout<<"Welcome to the game of SNAPS where you either understand or you dont!"<<endl;
        cout<<"It is asked that if you know the rules you dont expose them!"<<endl;
        cout<<"Allow others the opportunity to struggle!"<<endl;
        cout<<"The game will begin when I say 'This is the game of SNAPS, now pay attention!'"<<endl;
        cout<<"You may only type 'Continue...', 'SNAP!' (To Answer), or 'i feel stupid i give up!'"<<endl;
        cout<<"Nothing in parenthesis is a hint ;) !"<<endl;
        cout<<endl;
    }

    void setup(){
        cout<<"Lets Begin!"<<endl;
        setCodeWord(sourceCodeWord());
        setNumberWords(getNumberWords(codeWord));
        game();
    }

    void game(){
        if (numberOfWords==1){
            cout<<"There is "<<numberOfWords<<" word to guess!"<<endl;
        }
        else{
            cout<<"There are "<<numberOfWords<<" words to guess!"<<endl;
        }
        cout<<"This is the game of SNAPS, now pay attention!"<<endl;

    }

    int processWord(string word, int index, int numChars){
        if (index == word.size()-1){
            cout<<"(...It would be way to easy if I gave you the last letter dont you think?)"<<endl;
            return index;
        }
        char toIdentify = tolower(word[index]);
        if (toIdentify == 'a'){
            cout<<"*SNAP!*"<<endl;
            return index++;
        }
        if (toIdentify == 'e'){
            cout<<"*SNAP!* *SNAP!*"<<endl;
            return index++;
        }
        if (toIdentify == 'i'){
            cout<<"*SNAP!* *SNAP!* *SNAP!*"<<endl;
            return index++;
        }
        if (toIdentify == 'o'){
            cout<<"*SNAP!* *SNAP!* *SNAP!* *SNAP!*"<<endl;
            return index++;
        }
        if (toIdentify == 'u'){
            cout<<"*SNAP!* *SNAP!* *SNAP!* *SNAP!* *SNAP!*"<<endl;
            return index++;
        }

    }

    string sourceCodeWord(){
        system("python ../sourceCodeWord.py");
        ifstream wordFile;
        wordFile.open("../randomWord.txt");
        string randomWord;
        if (wordFile.is_open()){
            getline(wordFile, randomWord);
        }
        else{
            cout<<"There was a critical error. Scold the coder!"<<endl;
        }
        return randomWord;
    }

    string getCodeWord(){
        return codeWord;
    }
    void setCodeWord(string randomWord){
        codeWord = randomWord;
    }

    int getNumberWords(string word){
        //there will always be at least one word
        int numWords = 1;
        for (int i = 0; i < word.size(); i++){
            if (word[i] == ' '){
                numWords= numWords+1;
            }
        }
        return numWords;
    }
    void setNumberWords(int numWords){
        numberOfWords = numWords;
    }


};
#endif //GAMEOFSNAPS_H
