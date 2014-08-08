//converts regular English to l33t
#include <iostream>
#include <fstream>

using namespace std;
string gameAlpha[] = {"4","8","(","|)","3","|=","6","#","1","J","|<","|_","|V|","/V","0","|>","(,)","|2","5","7","(_)","\/","VV","><","Y","2"}; //l33t alphabet

string convert(char a){ //function converts letters to corresponding l33t symbol
    return gameAlpha[((int) tolower(a)) - 97]; //finds index and returns corresponding l33t symbol
}

int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");
    char ch; // variable for each letter of input
    while (fin >> noskipws >> ch) { //doesn't skip spaces
        if(isalpha(ch)){ //if it is a letter, convert to l33t
            fout<<convert(ch);
            cout<<convert(ch);
        }else{ //otherwise, keep as is
            fout<<ch;
            cout<<ch;
        }
    }
    fin.close();
    fout.close();

    return 0;
}
