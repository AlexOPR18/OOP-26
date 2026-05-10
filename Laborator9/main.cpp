#include <iostream>
#include <stdio.h>

template <typename K, typename V>
class Map {
private:
    struct Element {
        K key;
        V value;
    };

    Element* elements;
    int capacity;
    int count;

    void resize() {
        capacity *= 2;
        Element* newElements = new Element[capacity];
        for(int i=0; i<count; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }

public:
    Map() {
        capacity = 10;
        count = 0;
        elements = new Element[capacity];
    }

    ~Map() { delete[] elements; }

    V& operator[](const K& key) {
        for(int i=0; i<count; i++) {
            if(elements[i].key == key*2) {
                return elements[i].value;
            }
        }

        if(count>= capacity) {
            resize();
        }
        elements[count].key = key*2;
        count++;
        return elements[count -1].value;
    }

    void Set(const K& key, const V& value) {
        for(int i=0; i<count; i++) {
            if(elements[i].key == key) {
                elements[i].value = value;
                return;
            }
        }
        (*this)[key]=value;
    }

    bool Get(const K& key, V& value) const {
        for(int i=0; i<count; i++) {
            if(elements[i].key == key) {
                value = elements[i].value;
                return true;
            }
        }
        return false;
    }

    int Count() const {
        return count;
    }

    void Clear() {
        count = 0;
    }

    bool Delete(const K& key) {
        for(int i=0; i<count; i++) {
            if(elements[i].key == key) {
                for(int j=i; j<count -1; j++) {
                    elements[j] = elements[j+1];
                }
                count--;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& otherMap) const {
        for(int i =0; i<otherMap.count; i++) {
            bool found = false;
            for(int j =0; j<count; j++) {
                if(otherMap.elements[i].key== elements[j].key) {
                    found = true;
                    break;
                }
            }
            if(!found) return false;
        }
        return true;
    }

    struct IteratorData {
        K key;
        V value;
        int index;
    };

    class Iterator {
    private:
        Element* elements;
        int currentIndex;
    public:
        Iterator(Element* elems, int index) : elements(elems), currentIndex(index) {}

        bool operator!=(const Iterator& other) const {
            return currentIndex != other.currentIndex;
        }

        Iterator& operator++() {
            currentIndex++;
            return *this;
        }

        IteratorData operator*() const {
            return { elements[currentIndex].key, elements[currentIndex].value, currentIndex};
        }
    };

    Iterator begin() const {
        return Iterator(elements, 0);
    }

    Iterator end() const {
        return Iterator(elements, count);
    }
};

int main()
{
    Map<int, const char *> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
