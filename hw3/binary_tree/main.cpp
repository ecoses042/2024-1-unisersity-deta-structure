#include "bt.h"

int main()
{
    cout << "20211530 Minsoo Song" << endl;
    typedef BinaryTree <char> chartree;
    typedef chartree* chartreeptr;
    /*
    chartreeptr bt1(new chartree);
    bt1->insert('1');
    chartreeptr bt2(new chartree);
    bt2->insert('2');
    chartreeptr bt3(new chartree);
    bt3->insert('3');
    bt3->makeleft(bt1);
    bt3->makeright(bt2);
    chartreeptr bt4(new chartree);
    bt4->insert('4');
    chartreeptr bt5(new chartree);
    bt5->insert('5');
    bt5->makeright(bt4);
    chartreeptr bt6(new chartree);
    bt6->insert('6');
    bt6->makeright(bt5);
    bt6->makeleft(bt3);
    cout << "this is bottom top method" << endl;
    cout << "Root contains: " << bt6->getData() << endl;
    cout << "Left subtree root: " << bt6->left()->getData() << endl;
    cout << "Right subtree root: " << bt6->right()->getData() << endl;
    cout << "Leftmost child is: " << bt6->left()->left()->getData() << endl;
    cout << "Rightmost child is: " << bt6->right()->right()->getData() << endl;*/

    chartreeptr btTopbot(new chartree);
    btTopbot->insert('1');
    btTopbot->left()->insert('2');
    btTopbot->right()->insert('3');
    btTopbot->left()->left()->insert('4');
    btTopbot->left()->right()->insert('5');
    btTopbot->right()->right()->insert('6');
    cout << "this is top bottom method" << endl;
    cout << "Root contains: " << btTopbot->getData() << endl;
    cout << "Left subtree root: " << btTopbot->left()->getData() << endl;
    cout << "Right subtree root: " << btTopbot->right()->getData() << endl;
    cout << "Leftmost child is: " << btTopbot->right()->left()->getData() << endl;
    cout << "rightmost child is: " << btTopbot->right()->right()->getData() << endl;
    return 0;
}