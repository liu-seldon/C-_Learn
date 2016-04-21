#include <iostream>
#include "fruit.h"
#include <set>

//using namespace::std;
using std::set;
int main() {
    set<fruit> fruits;
    fruit apple("apple");
    fruits.insert(apple);
    apple.name = "orangle";

    set<fruit>::iterator itr = fruits.begin();
    std::cout << apple.name << " " << itr->name << std::endl;
    return 0;
}
