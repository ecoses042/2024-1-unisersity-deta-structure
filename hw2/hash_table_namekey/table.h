#pragma once

#include <iostream>
#include <assert.h>
using namespace std;
const int table_max_size = 11;

class Cphone
{
    public:
        Cphone();
        Cphone(string quota_name, int quota_birthday);
        print();
        friend ostream& operator<<(ostream& os, const Cphone& first);
    private:
        string name;
        int birthday;
};

Cphone::Cphone()
{
    name = "";
    birthday = 0;
}

Cphone::Cphone(string quota_name, int quota_birthday)
{
    name = quota_name;
    birthday = quota_birthday;
}

Cphone::print()
{
    cout << name << " " << birthday << endl;
}

template <class tablekeytype, class tabledatatype>
class table{
    public:
        table();
        bool lookup(const tablekeytype& key, tabledatatype& value);
        void insert(const tablekeytype& key, const tabledatatype& value);
        void deletekay(const tablekeytype& key);
        void dump();
    private:
        //empty for 0, deleted for 1 inuse for 2
        //if the slot has been deleted, it cannot end search
        enum slotType{empty, deleted, inuse};
        struct item{
            tablekeytype key;
            tabledatatype data;
            slotType status;
        };
        item t[table_max_size];
        int number_of_element;
        //sets slots hash value
        int hash(const tablekeytype& key);
        int next_slot(const int pos);
        //pos is the hash value of target.
        bool search(int& pos, const tablekeytype& target);
};

template <class tablekeytype, class tabledatatype>
table<tablekeytype, tabledatatype>::table()
{
    number_of_element = 0;
    for (int i = 0; i< table_max_size; i++)
    {
        t[i].status = empty;
    }
}

template <class tablekeytype, class tabledatatype>
int table<tablekeytype, tabledatatype>::hash(const tablekeytype& key)
{
    return (key % table_max_size);
}

template <class tablekeytype, class tabledatatype>
int table<tablekeytype, tabledatatype>::next_slot(const int pos)
{
    if (pos == table_max_size - 1)
        return 0;
    else
        return pos + 1;
}

template <class tablekeytype, class tabledatatype>
bool table<tablekeytype,tabledatatype>::search(int& pos, const tablekeytype& target)
{
    for (;t[pos].status != empty;pos = next_slot(pos))
    {
        if (t[pos].key == target)
            return true;
    }
    return false;
}

template <class tablekeytype, class tabledatatype>
bool table<tablekeytype, tabledatatype>::lookup(const tablekeytype& key, tabledatatype& value)
{
    int pos(hash(key));
    if (search(pos, key))
    {
        while (t[pos].key != key)
        {
            pos = next_slot(pos);
        }
        value = t[pos].data;
        return true;
    }
    else
        return false;
}

template <class tablekeytype, class tabledatatype>
void table<tablekeytype, tabledatatype>::insert(const tablekeytype& key, const tabledatatype& value)
{
    assert(number_of_element < table_max_size - 1);
    int pos = hash(key);
    if (!search(pos, key))
    {
        pos = hash(key);
        while (t[pos].status == inuse)
        {
            pos = next_slot(pos);
        }
        number_of_element++;
    }
    t[pos].status = inuse;
    t[pos].key = key;
    t[pos].data = value;
}

template <class tablekeytype, class tabledatatype>
void table<tablekeytype,tabledatatype>::deletekay(const tablekeytype& key)
{
    int pos(hash(key));
    if (search(pos, key))
    {
        t[pos].status = deleted;
        number_of_element--;
    }
}

template <class tablekeytype, class tabledatatype>
void table<tablekeytype, tabledatatype>::dump()
{
    for (int i = 0; i < table_max_size; i++)
    {
        cout << i  << ": ";
        switch(t[i].status)
        {
            case inuse:
                cout << "inuse:" << t[i].key << endl;
                break;
            case deleted:
                cout << "deleted:" << t[i].key << endl;
                break;
            case empty:
                cout << "empty"  << endl;
                break;
        }
    }
    cout << "number of elements: " << number_of_element << endl;
}