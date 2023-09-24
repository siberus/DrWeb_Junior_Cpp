#include <iostream>
#include <cstring>


//Напишите функцию, которая обрезает пробелы в конце переданной ей строки. 
//Функция должна быть написана в расчёте на работу с очень длинными строками 
//с очень большим количеством пробелов, оптимизирована по количеству обращений к памяти. 

void TrimRight( char *s )
{
    //Определяем длину строки без пробелов
    int length = 0;
    int index = 0;
    bool isSpaceLine = false;
    while (s[length] != '\0')
    {
        while (s[length] != '\0' && s[length] != ' ')
            ++length;
        if (s[length] == '\0')
            break;
        if (s[length] == ' ') 
        {
            index = length;
            isSpaceLine = true;
            ++length;
            while (s[length] != '\0' && s[length] == ' ')
                ++length;
            if (s[length] == '\0')
                break; 
            if (s[length] != ' ')
                isSpaceLine = false;
        }
    }
    if (isSpaceLine == true)
        s[index] = '\0';
};

void BuildString(char *mystring, int count)
{
    int askiiZeroCode = 48;
    int wordLength = 700;
    int index = 0;
    for (int i = 0; i < wordLength/10; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if(j != 0) 
                mystring[i*10+j] = askiiZeroCode + j;
            else
                mystring[i*10+j] = ' ';
            index++;
        }      
    }        
    for (int i = index; i < count-1; i++)
    {
        mystring[i] = ' ';
    }
    mystring[count - 1] = '\0';

};

int main()
{
    int count = 1000;
    char *teststring1;
    //Случай 1 
    teststring1 = new char[count];
    BuildString(teststring1, count);
    std::cout << "Start teststring1: \"" << teststring1 << "\"" << '\n';
    std::cout << "Start teststring1 has " << strlen(teststring1) << " letters.\n";
    TrimRight(teststring1);
    std::cout << "Finish teststring1: \"" << teststring1 << "\"" << '\n';
    std::cout << "Finish teststring1 has " << strlen(teststring1) << " letters.\n"; 
    delete[] teststring1;

    //Случай 2
    char teststring2[] = "";
    std::cout << "Start teststring2: \"" << teststring2 << "\"" << '\n';
    std::cout << "Start teststring2 has " << strlen(teststring2) << " letters.\n";
    TrimRight(teststring2);
    std::cout << "Finish teststring2: \"" << teststring2 << "\"" << '\n';
    std::cout << "Finish teststring2 has " << strlen(teststring2) << " letters.\n";

    //Случай 3
    char teststring3[] = "MonolitString";
    std::cout << "Start teststring3: \"" << teststring3 << "\"" << '\n';
    std::cout << "Start teststring3 has " << strlen(teststring3) << " letters.\n";
    TrimRight(teststring3);
    std::cout << "Finish teststring3: \"" << teststring3 << "\"" << '\n';
    std::cout << "Finish teststring3 has " << strlen(teststring3) << " letters.\n";

    //Случай 4
    char teststring4[] = "                                                          ";
    std::cout << "Start teststring4: \"" << teststring4 << "\"" << '\n';
    std::cout << "Start teststring4 has " << strlen(teststring4) << " letters.\n";
    TrimRight(teststring4);
    std::cout << "Finish teststring4: \"" << teststring4 << "\"" << '\n';
    std::cout << "Finish teststring4 has " << strlen(teststring4) << " letters.\n";

     //Случай 5
    char teststring5[] = "                                                          End";
    std::cout << "Start teststring5: \"" << teststring5 << "\"" << '\n';
    std::cout << "Start teststring5 has " << strlen(teststring5) << " letters.\n";
    TrimRight(teststring5);
    std::cout << "Finish teststring5: \"" << teststring5 << "\"" << '\n';
    std::cout << "Finish teststring5 has " << strlen(teststring5) << " letters.\n";

    return 0;
}
