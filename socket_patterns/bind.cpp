#include <thread>
#include <iostream>
#include <functional>

class Foo {
public:
    void bar(const std::string& str) {
        std::cout << "foo() called with " << str << std::endl;
    }
};


int main() {
    Foo obj;
    std::string test = "test";
    
    std::thread(&Foo::bar, obj, std::ref(test)).join(); 

    auto bindFunction = std::bind(&Foo::bar, obj,std::ref(test)); 
    std::thread(bindFunction, std::ref(test)).join(); 
    test = "lol";
    std::thread(bindFunction, std::ref(test)).join();

    return 0;
}


