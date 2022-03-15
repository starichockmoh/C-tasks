#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str, slovo;
    char symbol;
    int s=0;
    string::size_type k=0, pos=0;
    string razdel=" ,.;:!?";
    cout<<"Enter string: "<<endl;
    getline(cin, str);
    cout<<"Enter symbol: "<<endl; cin>>symbol;
    k=str.find_first_of (razdel, pos);
    while(k!=string::npos)
    {
        slovo= str.substr(pos, k-pos);
        if (ispunct (str[k]))
            pos=k+2;
        else pos = k+1;
        if(tolower(slovo[0])== tolower(symbol))
            cout<<slovo<<" ";
        k= str.find_first_of(razdel, pos);
    }
    return 0;
}

