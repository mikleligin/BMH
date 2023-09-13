
#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;
void offset(int *arr, string word) {

    for (size_t i = word.size()-1; i > 0; i--)
    {
       arr[word.size() - 1 - i] = i;
    }
    arr[word.size()-1] = word.size();
    for (size_t i = word.size() - 1; i > 0; i--)
    {
       // if (arr[i] == arr[word.size() - 1]) arr[word.size() - 1] = arr[i]; continue;
        for (size_t j = i; j > 0; j--)
        {
            if (word[i] == word[j] && i != j)
            {
                arr[j] = arr[i];
            }
        }
        
    }
}
int index_offset(int *arr, string word, char symbol) {
    for (size_t i = 0; i < word.size(); i++)
    {
        if (word[i] == symbol)
        {
            return arr[i];
        }
    }
    return arr[word.size()-1];
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string word = "World";
    int* array = new int[word.size()];
    //cout << array[0];
    offset(array, word);
    for (size_t i = 0; i < 5; i++)
    {
        cout << array[i];
    }
    cout << endl;
    string text = "Hello World!";
    ofstream txt;
    txt.open("file.txt");
    for (size_t i = 0; i < text.size()-word.size()+2; i++)
    {
        int temp = 0;
        for (size_t j = word.size(); j > 0; j--)
        {
            
            temp++;
            if (word[j-1]!=text[i+j-1])
            {
                i+= index_offset(array, word, text[i+j-1])-1;
                temp = 0;
                break;
            }
            
            if (temp==word.size()-1)
            {
                txt << i<<" < Номер с которого начинается совпадение";
               // cout << i;
            }
        }
        //cout << array[i];
    }
    txt.close();
}
