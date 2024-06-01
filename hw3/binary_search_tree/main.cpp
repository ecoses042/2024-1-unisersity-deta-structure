#include "bst.h"

int main()
{
    typedef bst<int> intBST;
    typedef intBST* intBSTPtr;
    intBSTPtr b(new intBST);
    b->insert(17);
    b->insert(10);
    b->insert(26);
    b->insert(6);
    b->insert(14);
    b->insert(20);
    b->insert(28);
    b->insert(31);
    b->insert(11);
    b->insert(37);
    b->insert(12);
    // is 11 in the tree?
    intBSTPtr get11((bst<int>*)b->retrieve(11));
    if (get11->isempty())
        cout << "11 not found.\n";
    else
        cout << "11 found.\n";
    // is 13 in the tree?
    intBSTPtr get13((bst<int>*)b->retrieve(13));
    if (get13->isempty())
        cout << "13 not found.\n";
    else
        cout << "13 found.\n";
    return 0;
}