#include <string>
using std::string;
class fruit {
    public:
        string name;
        fruit(const string &n);
        fruit& operator=(const fruit& other);
        fruit(const fruit& other);
        bool operator<(const fruit& o) const;
};
