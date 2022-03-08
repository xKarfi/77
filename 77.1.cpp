#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "string"

using namespace std;
class task 
{
	public:
	
    ifstream FileIn1;
    ifstream FileIn2;
    ofstream FileOut;
    
    int repentence = 0;
    
    task();
    ~task();
    
    string cd(string key, string text);
    string decd(string key, string text);
    void count(string text);
};

task::task() 
{
    FileIn1.open("dokad.txt");
    FileIn2.open("szyfr.txt");
    FileOut.open("wyniki.txt");
}

task::~task() 
{
    FileIn1.close();
    FileIn2.close();
    FileOut.close();
}

string task::cd(string key, string text)
 {
    string nT = "";
    int wC = 0;
    for (int i = 0; i < text.length(); i++) 
	{
        if (text[i] == ' ') 
		{
            nT += ' ';
            wC++;
        }
        else if (text[i] == '.') 
		{
            nT += '.';
            wC++;
        }
        else if (text[i] == ',') 
		{
            nT += ',';
            wC++;
        }
        else {
            int x = i - wC;
            int k = int(text[i] - 'A') + int(key[x % key.length()] - 'A');
            nT += char((k % 26) + 'A');
        }
    }

    repentence = ceil(float(text.length() - wC) / key.length());
    return nT;
}

string task::decd(string key, string text) 
{
    string nT = "";
    int wC = 0;
    for (int i = 0; i < text.length(); i++) 
	{
        if (text[i] == ' ') 
		{
            nT += ' ';
            wC++;
        }
        else if (text[i] == '.') 
		{
            nT += '.';
            wC++;
        }
        else if (text[i] == ',') 
		{
            nT += ',';
            wC++;
        }
        else {
            int x = i - wC;
            int k = int(text[i] - 'A') - int(key[x % key.length()] - 'A');
            while(k < 0) {
                k += 26;
            }
            
            nT += char(k + 'A');
        }
    }

    return nT;
}

void task::count(string text) 
{
    int t[26];
    for (int i = 0; i < 26; i++) 
	{
        t[i] = 0;
    }
    for (int i = 0; i < text.length(); i++) 
	{
        t[text[i] - 'A' ]++;
    }
    for (int i = 0; i < 26; i++) 
	{
        FileOut<<char(i+'A')<<":"<<t[i]<<endl;
}
    double k = 0;
    for (int i = 0; i < 26; i++)
	 {
        int l = 0;
        l += (t[i] - 1) * t[i];
        k += l;
    }
    int sum = 0;
    for (int i = 0; i < 26; i++) 
	{
        sum += t[i];
    }
    int n = (sum - 1) * sum;
    k = k / n;
    double d;
    double ko = k;
    ko = ko - 0.0385;
    d = 0.0285 / ko;
    d += 0.005;
    d = 0.01 * int(100 * d);
    FileOut << "wyniki" << endl;
    FileOut << d<<endl;
    FileOut << round(d);
}

int main()
{
    task t1;
    string f1;

    getline(t1.FileIn1, f1);
    
    t1.FileOut << "77.1" << endl;
    t1.FileOut << t1.cd("LUBIMYCZYTAC", f1) << endl;
    t1.FileOut << "liczba powtorzen: " << t1.repentence << endl;
    
    string f2, c2;
    
    t1.FileOut << "77.2" << endl;
    getline(t1.FileIn2, f2);
    getline(t1.FileIn2, c2);
    
    t1.FileOut << t1.decd(c2, f2)<<endl;
    t1.FileOut << "77.3" << endl;
    t1.count(f2);

}
