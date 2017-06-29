#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int number;
    string temp;
    getline(cin, temp);
    number = atoi(temp.c_str());
    vector<string> code;
    vector<char> character;
    string ss;
    char cc;

    for(int i=0;i<number;i++)
    {
        string piece;
        code.push_back(ss);
        character.push_back(cc);
        getline(cin, piece);
        character[i]=piece[0];
        size_t pos=2;
        code[i]=piece.substr(pos);
    }
    string encode_text;
    getline(cin,encode_text);
    int pos=0;
    int len=1;
    int flag=0;
    cout<<"\ndecoded_text:\n";
    for(int i=0;i<encode_text.size();i++)
    {
        for(int j=0;j<code.size();j++)
        {
            if(encode_text.substr(pos,len)==code[j])
            {
                //cout<<encode_text.size()<<" "<<character[j]<<" "<<pos<<" "<<len<<endl;
                cout<<character[j];
                flag=1;
                break;
            }
            else
            {
                //cout<<encode_text.size()<<" "<<" "<<" "<<pos<<" "<<len<<endl;
            }

        }
        if(flag==1)
        {
            pos=pos+len;
            len=1;
            flag=0;
        }
        else
        {
            len++;
        }
    }
}
