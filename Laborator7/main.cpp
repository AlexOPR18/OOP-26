#include <iostream>
#include "Tree.h"

using namespace std;

constexpr float operator""_Kelvin(unsigned long long k) {
    return static_cast<float>(k) - 273.15f;
}

constexpr float operator""_Fahrenheit(unsigned long long f) {
    return (static_cast<float>(f) - 32.0f)* 5.0f / 9.0f;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    cout<<"300 Kelvin in Celsius: " << a << endl;
    cout<<"120 Fahrenheit in Celsius: " << b << endl;

    Tree<int> myTree;
    TreeNode<int>* root = myTree.add_node(nullptr, 1);
    TreeNode<int>* c1 = myTree.add_node(root, 10);
    TreeNode<int>* c2 = myTree.add_node(root, 5);
    myTree.insert(root, 0, 20);
    myTree.sort(root, cmp1);
    cout<<"Nr copii sub radacina: " << myTree.count(root) << endl;
    TreeNode<int>* gasit = myTree.find(10, nullptr);
    if(gasit!=nullptr) { cout<<"Am gasit nodul: " << gasit->value << endl;
    } else cout<<"Nu am gasit nodul";

    TreeNode<int>* nod = myTree.get_node(root, 1);
    if(nod!=nullptr) {
        myTree.delete_node(nod);
    }

    return 0;
}