#include "headers.h"

class A
{
    public:
    int value() { return 1;}
};
class B : public A
{
    public:
    int value() { return 2;}
};

int main()
{
    std::string s = "Hello\nWorld";
    std::cout << s << std::endl;

    s = 
R"(
Hello
World)";
    std::cout << s <<std::endl;

    std::vector<std::string> words = {"ab", "cd", "ef", "gh", "ij"};
    std::string result = "";
    char nl = char(10);
    for(std::string& word : words)
    {
        result += word + nl;
    }
    std::cout <<"result: " <<std::endl <<result << std::endl;

    A* obj = new B();
    int val = obj->value();

    return 0;
}