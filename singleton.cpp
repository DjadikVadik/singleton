#include <iostream>
#include <string>
using namespace std;

class Logger
{
    static Logger* instance;

    string path;

    Logger(string path)
    {
        this->path = path;
    }

public:
    static Logger* GetInstance(string path)
    {
        return instance == nullptr ? instance = new Logger(path) : instance;
    }

    void WriteStringToFile(string text)
    {
        FILE* file = nullptr; 
      
        fopen_s(&file, path.c_str(), "a+");

        if (file != nullptr)
        {
            fputs(text.c_str(), file);
            fclose(file);
        }
    }

    void WriteIntegerToFile(int number)
    {
        FILE* file = nullptr;
        fopen_s(&file, path.c_str(), "a+");
        
        if (file != nullptr)
        {
            string str = to_string(number) + "\n";
            fputs(str.c_str(), file);
            fclose(file);
        }
    }

};

Logger* Logger::instance = nullptr;

int main()
{
    Logger* logger = Logger::GetInstance("file.txt");
    
    logger->WriteStringToFile("hello!!!\nit's me!!!\n");
    logger->WriteIntegerToFile(777);

}