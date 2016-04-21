#include "fruit.h"

fruit::fruit(const string& n):name(n) {

}

fruit::fruit(const fruit& other):name(other.name) {

}

fruit& fruit::operator=(const fruit& other) {
    this->name = other.name;
    return *this;
}

bool fruit::operator<(const fruit& other) const {
    return this->name<other.name;
}

