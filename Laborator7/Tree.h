#pragma once

template <typename T>
bool cmp1(T a, T b)
{
    return a < b;
}

template <typename T>
class TreeNode {
public:
    T value;
    TreeNode<T>** children;
    int childrenCount;
    int capacity;
    TreeNode<T>* parent;
    
    TreeNode(T val, TreeNode<T>* p = nullptr) : value(val), parent(p) {
        childrenCount = 0;
        capacity = 2;
        children = new TreeNode<T>*[capacity];
    }

    ~TreeNode() {
        delete[] children;
    }

    void AddChild(TreeNode<T>* child) {
        if(childrenCount >= capacity) {
            capacity *= 2;
            TreeNode<T>** temp = new TreeNode<T>*[capacity];
            for(int i = 0; i<childrenCount; i++) temp[i] = children[i];
            delete[] children;
            children = temp;
        }
        children[childrenCount++] = child;
    } 

    void InsertChild(TreeNode<T>* child, int index) {
        if (index < 0 || index > childrenCount) return;
        if (childrenCount >= capacity) {
            capacity *= 2;
            TreeNode<T>** temp = new TreeNode<T>*[capacity];
            for(int i = 0; i<childrenCount; i++) temp[i]=children[i];
            delete[] children;
            children = temp;
        }
        for(int i = childrenCount; i>index; i--) {
            children[i] = children[i-1];
        }
        children[index] = child;
        childrenCount++;
    }
};

template <typename T>
class Tree {
private:
    TreeNode<T>* root;

    void delete_recursive(TreeNode<T>* node) {
        if (node == nullptr) return;
        for(int i=0;i<node->childrenCount;i++) {
            delete_recursive(node->children[i]);
        }
        delete node;
    }

    TreeNode<T>* find_recursive(TreeNode<T>* node, T val, bool (*cmp)(T, T)) {
        if(node == nullptr) return nullptr;
        bool isMatch= (cmp!=nullptr) ? cmp(val, node->value) : (val == node->value);
        if(isMatch) return node;

        for(int i=0;i<node->childrenCount;i++) {
            TreeNode<T>* found = find_recursive(node->children[i], val, cmp);
            if(found!=nullptr) return found;
        }
        return nullptr;
    
    }

    int count_recursive(TreeNode<T>* node) {
        if(node==nullptr) return 0;
        int total = node->childrenCount;
        for(int i=0;i<node->childrenCount;i++) {
            total+=count_recursive(node->children[i]);
        }
        return total;
    }

public:
    Tree() : root(nullptr) {}

    TreeNode<T>* add_node(TreeNode<T>* parent, T value) {
        TreeNode<T>* newNode = new TreeNode<T>(value, parent);
        if(parent==nullptr) {
            root=newNode;
        } else {
            parent->AddChild(newNode);
        }
        return newNode;
    }

    TreeNode<T>* get_node(TreeNode<T>* parent, int childIndex=0) {
        if(parent==nullptr) return root;
        if(childIndex>=0 && childIndex < parent->childrenCount) {
            return parent->children[childIndex];
        }
        return nullptr;
    }

    void delete_node(TreeNode<T>* node) {
        if(node==nullptr) return;
        if(node->parent!=nullptr) {
            TreeNode<T>* p = node->parent;
            for(int i=0;i<p->childrenCount;i++) {
                if(p->children[i]==node) {
                    for(int j=i;j<p->childrenCount-1;j++) {
                        p->children[j] = p->children[j+1];
                    }
                    p->childrenCount--;
                    break;
                }
            }
        } else if (node == root) {
            root = nullptr;
        }
        delete_recursive(node);
    }
    TreeNode<T>* find(T parameter, bool (*cmp)(T,T)=nullptr) {
        return find_recursive(root, parameter, cmp);
    }

    TreeNode<T>* insert(TreeNode<T>* parent, int index, T value) {
        if(parent == nullptr) return nullptr;
        TreeNode<T>* newNode = new TreeNode<T>(value, parent);
        parent->InsertChild(newNode, index);
        return newNode;
    }

    void sort(TreeNode<T>* node, bool (*cmp)(T,T) = nullptr) {
        if(node==nullptr) return;
        for(int i=0;i<node->childrenCount-1;i++) {
            for(int j=i+1;j<node->childrenCount;j++) {
                bool shouldSwap = false;
                if(cmp!=nullptr) {
                    shouldSwap=cmp(node->children[j]->value, node->children[i]->value);
                } else {
                    shouldSwap = node->children[j]->value < node->children[i]->value;
                }

                if(shouldSwap) {
                    TreeNode<T>* temp = node->children[i];
                    node->children[i] = node->children[j];
                    node->children[j] = temp;
                }
            }
        }
    }

    int count(TreeNode<T>* node = nullptr) {
        if(node == nullptr) {
            node = root;
        }
        return count_recursive(node);
    }
};