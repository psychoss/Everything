#include <iostream>
#include <string>

class RecordSet {
public:
    bool getFieldVal(int i, std::string& s) const;
    // ...
};

bool RecordSet::getFieldVal(int i, std::string& s) const {
    // In here, you can't modify any nonmutable data
    // members (see discussion)
}

void displayRecords(const RecordSet& rs) {
    // Here, you can only invoke const member functions
    // on rs
}