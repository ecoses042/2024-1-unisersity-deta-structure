#pragma once

#include <iostream>
#include <assert.h>
using namespace std;
const int table_max_size = 100;

template <class tablekeytype, class tabledatatype>
class table{
    public:
        table();
        bool lookup(const tablekeytype& key, tabledatatype& value);
        void insert(const tablekeytype& key, const tabledatatype& value);
        void deletekay(tablekeytype key);
    private:
        struct item{
            tablekeytype key;
            tabledatatype data;
        };
        item t[table_max_size];
        int number_of_element;
        int search(const tablekeytype& key);
};


template <class tablekeytype, class tabledatatype>
table<tablekeytype, tabledatatype>::table(){
    number_of_element = 0;
}

template <class tablekeytype, class tabledatatype>
bool table<tablekeytype, tabledatatype>::lookup(const tablekeytype& key, tabledatatype& value)
{
    int index = search(key);
    if (index == number_of_element)
        return false;
    else{
        value = t[index].data;
        return true;
    }
}

template <class tablekeytype, class tabledatatype>
void table<tablekeytype, tabledatatype>::insert(const tablekeytype& key, const tabledatatype& value)
{
    assert(number_of_element < table_max_size);
    int index = search(key);
    if (index == number_of_element)
        number_of_element++;
    t[index].key = key;
    t[index].data = value;
}


template <class tablekeytype, class tabledatatype>
void table<tablekeytype, tabledatatype>::deletekay(tablekeytype key)
{
    int index = search(key);
    if (index < number_of_element)
    {
        number_of_element--;
    }
    t[index] = t[number_of_element];
}

template <class tablekeytype, class tabledatatype>
int table<tablekeytype, tabledatatype>::search(const tablekeytype& key)
{
    int i;
    for (i = 0; i < number_of_element && t[i].key != key; i++);
    return i;
}