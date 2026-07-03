#include<bits/stdc++.h>
using namespace std;
int main(){
    string inp;
    cin >> inp;
    int cnt1 = 0; //upper_case
    int cnt2 = 0; //lower_case
    string res = "";
    for (char ch : inp)
    {
        if(ch>='A' && ch<='Z')
            cnt1++;
        if(ch>='a' && ch<='z')
            cnt2++;
    }
    if(cnt1>cnt2){
        for(char ch: inp){
            res += toupper(ch);
        }
    }
    else{
        for(char ch: inp){
            res += tolower(ch);
        }
    }
    cout << res;
}

/*
Vasya is very upset that many people on the Net mix uppercase and lowercase letters in one word. That's why he decided to 
invent an extension for his favorite browser that would change the letters' register in every word so that it either only 
consisted of lowercase letters or, vice versa, only of uppercase ones. At that as little as possible letters should be changed 
in the word. For example, the word HoUse must be replaced with house, and the word ViP — with VIP. If a word contains an equal 
number of uppercase and lowercase letters, you should replace all the letters with lowercase ones. For example, maTRIx should 
be replaced by matrix. Your task is to use the given method on one given word.

Input
The first line contains a word s — it consists of uppercase and lowercase Latin letters and possesses the length from 1 to 100.

Output
Print the corrected word s. If the given word s has strictly more uppercase letters, make the word written in the uppercase register, otherwise - in the lowercase one.

Examples

Input
HoUse
Output
house

Input
ViP
Output
VIP

Input
maTRIx
Output
matrix

*/
