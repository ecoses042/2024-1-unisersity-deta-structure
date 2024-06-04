#include "bt.h"

int main()
{
    cout << "20211530 Minsoo Song" << endl;
    typedef BinaryTree <char> chartree;
    typedef chartree* chartreeptr;
    
    chartreeptr bt1(new chartree);
    bt1->insert('A');
    chartreeptr bt2(new chartree);
    bt2->insert('B');
    chartreeptr bt3(new chartree);
    bt3->insert('E');
    bt3->makeleft(bt1);
    bt3->makeright(bt2);

    chartreeptr bt4(new chartree);
    bt4->insert('C');
    chartreeptr bt5(new chartree);
    bt5->insert('D');
    chartreeptr bt6(new chartree);
    bt6->insert('F');
    bt6->makeleft(bt4);
    bt6->makeright(bt5);
    
    chartreeptr bt7(new chartree);
    bt7->insert('G');
    bt7->makeleft(bt3);
    bt7->makeright(bt6);

    cout << "this is bottom top method" << endl;
    cout << "Root contains: " << bt7->getData() << endl;
    cout << "Left subtree root: " << bt7->left()->getData() << endl;
    cout << "Right subtree root: " << bt7->right()->getData() << endl;
    cout << "Leftmost child is: " << bt7->left()->left()->getData() << endl;
    cout << "Rightmost child is: " << bt7->right()->right()->getData() << endl;

    chartreeptr btTopbot(new chartree);
    btTopbot->insert('G');
    btTopbot->left()->insert('E');
    btTopbot->right()->insert('F');
    btTopbot->left()->left()->insert('A');
    btTopbot->left()->right()->insert('B');
    btTopbot->right()->left()->insert('C');
    btTopbot->right()->right()->insert('D');
    cout << "this is top bottom method" << endl;
    cout << "Root contains: " << btTopbot->getData() << endl;
    cout << "Left subtree root: " << btTopbot->left()->getData() << endl;
    cout << "Right subtree root: " << btTopbot->right()->getData() << endl;
    cout << "Leftmost child is: " << btTopbot->left()->left()->getData() << endl;
    cout << "rightmost child is: " << btTopbot->right()->right()->getData() << endl;
    return 0;
}