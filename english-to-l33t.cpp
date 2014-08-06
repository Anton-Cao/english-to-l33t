//converts regular English to l33t
//Anton Cao 8/4/14
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;
string input;
string snewLineSignal = "*";
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
string gameAlpha[] = {"4","|8","(","|)","3","|=","6","#","1","J","|<","|_","|V|","/V","0","|>","(,)","|2","5","7","(_)","\/","VV","><","Y","2"};

string convert(char a){
    string b;
    int index = 0;
    for(int i = 0; i < 52; i++){
        if(a==alpha[i]){
            index = (i)%26;
        }
    }
    b = gameAlpha[index];
    return b;
}

int main()
{
    bool file = true;
    //reads in input
    if(file){
        //from file
        ifstream fin("input.in");

        string inputLine;

        fin>>inputLine;
        input=inputLine;

        while(getline(fin,inputLine)){
            istringstream iss(inputLine);
            input.append(inputLine);
            input.append(snewLineSignal);
        }
        fin.close();
    }else{
        //from input
        getline(cin,input);
    }

    //processes input
    ofstream fout("output.out");

    int i = 0;
    while(input[i]){
        if(input[i]=='*'){
            fout<<endl;
            cout<<endl;
        }else if(isalpha(input[i])){
            fout<<convert(input[i]);
            cout<<convert(input[i]);
        }else{
            fout<<input[i];
            cout<<input[i];
        }
        i++;
    }

    fout.close();

    return 0;
}
