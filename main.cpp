#include <iostream>
#include <cstring>


//Напишите функцию, которая обрезает пробелы в конце переданной ей строки. 
//Функция должна быть написана в расчёте на работу с очень длинными строками 
//с очень большим количеством пробелов, оптимизирована по количеству обращений к памяти. 

void TrimRight( char *s )
{
    //Определяем длину строки без пробелов
    int length = 0;
    int length2 = 0; 
    int length3 = 0; 

   /*  while (s[length] != '\0') 
        ++length;
   // while (s[length-1] == ' ')
    //    --length;

    //Второй вариант поиска длины строки
    const char *cTemp(s);
    while (*cTemp++);
    length2 = static_cast<int>(cTemp - s - 1); */

    //Оптимизированный по обращению к памяти вариант поиска длины строки
    int index = -1;
    bool isSpaceLine = false;
    while (s[length3] != '\0')
    {
        while (s[length3] != '\0' && s[length3] != ' ')
            ++length3;
        if (s[length3] == '\0')
            break;
        if (s[length3] == ' ') 
        {
            index = length3;
            isSpaceLine = true;
            ++length3;
            while (s[length3] != '\0' && s[length3] == ' ')
                ++length3;
            if (s[length3] == '\0')
                break;
            if (s[length3] != ' ')
                isSpaceLine = false;
        }
    }
    if (isSpaceLine == true)
        s[index] = '\0';
           
     // Вспомогательный вывод результата:
    std::cout << "Optimal solution length: " << length3 << '\n';
    std::cout << "string s: \"" << s << "\"" << '\n';

    // Вспомогательный вывод результата:
    std::cout << "First solution length: " << length << '\n';
    std::cout << "string s: \"" << s << "\"" << '\n';
    //s[length] = '\0';

    std::cout << "Second solution length: " << length2 << '\n';
    std::cout << "string s: \"" << s << "\"" << '\n';
    //s[length] = '\0';


   /*  // Выделяем память для вспомогательной строки
    char *newString;
    newString = new char[length+1];

    // Копируем фактическое значение s в newChar без пробелов 
    for (int count=0; count < length; ++count) 
        newString[count] = s[count];
    newString[length] = '\0';
     
    
    s = newString;
    //delete[] newString; */


};

void BuildString(char *mystring, int count)
{
    //int count = 100;
    int askiiZeroCode = 48;
    int wordLength = 70;
    //char *mystring;
    //mystring = new char[count];
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
    int count = 100;
    char *teststring;
    teststring = new char[count];
    BuildString(teststring, count);
    std::cout << "Start teststring: \"" << teststring << "\"" << '\n';
    std::cout << "Start teststring has " << strlen(teststring) << " letters.\n";
    TrimRight(teststring);
    std::cout << "Finish teststring: \"" << teststring << "\"" << '\n';
    std::cout << "Finish teststring has " << strlen(teststring) << " letters.\n"; 

    return 0;
}
