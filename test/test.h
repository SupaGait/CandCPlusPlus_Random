//
// Created by Gerard on 27-2-2016.
//

#ifndef CANDCPLUSPLUS_RANDOM_TEST_H
#define CANDCPLUSPLUS_RANDOM_TEST_H

#include <iostream>
using namespace std;
class abc
{
private:
    struct n
    {
        int data;
    };
public:
    n print();
};

abc::n abc::print()
{
    abc::n* q = new abc::n;
    q->data = 7;
    return abc::n{6};
}

#endif //CANDCPLUSPLUS_RANDOM_TEST_H
