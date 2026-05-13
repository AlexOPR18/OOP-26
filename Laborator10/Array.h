#pragma once
#include <iostream>
#include <exception>

using namespace std;

class OutOfBoundsException : public exception {
public:
    virtual const char* what() const throw() {
        return "Indexul este inafara domeniului";
    }
};

class InvalidCapacityException : public exception {
public:
    virtual const char* what() const throw() {
        return "Capacitatea alocata este invalida (mai mica decat 0)!";
    }
};

class Compare {
public:
    virtual int CompareElements(void* e1, void* e2)=0;
};

template<class T>
class Array;

template<class T>
class ArrayIterator {
private:
    int Current;
    T** ListRef;
    int Size;
public:
    ArrayIterator() : Current(0), ListRef(nullptr), Size(0) {}
    ArrayIterator(T** list, int start, int size) : Current(start), ListRef(list), Size(size) {} 
    
    ArrayIterator& operator++() {
        if (Current < Size) Current++;
        return *this;
    }

    ArrayIterator& operator--() {
        if(Current>0) Current--;
        return *this;
    }

    bool operator==(ArrayIterator<T>& other) {
        return Current==other.Current && ListRef==other.ListRef;
    }

    bool operator!=(ArrayIterator<T>& other) {
        return !(*this == other);
    }

    T* GetElement() {
        if(Current >= 0 && Current < Size) {
            return ListRef[Current];
        }
        return nullptr;
    }
};

template<class T>
class Array {
private:
    T** List;
    int Capacity;
    int Size;
    
    void resize(int newCapacity) {
        T** newList = new T*[newCapacity];
        for(int i=0; i<Size; i++) {
            newList[i] = List[i];
        }
        delete[] List;
        List = newList;
        Capacity = newCapacity;
    }
public:
    Array() : Capacity(0), Size(0), List(nullptr) {}
    Array(int capacity) {
        if(capacity<0) throw InvalidCapacityException();\
        Capacity = capacity;
        Size = 0;
        List = new T*[Capacity];
    }

    Array(const Array<T>& otherArray) {
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T*[Capacity];
        for(int i=0;i<Size;i++) {
            List[i]=new T(*(otherArray.List[i]));
        }
    }

    ~Array() {
        if(List != nullptr) {
            for(int i=0; i<Size; i++) {
                delete List[i];
            }
            delete[] List;
        }
    }

    T& operator[](int index) {
        if(index < 0 || index >= Size) {
            throw OutOfBoundsException();
        }
        return *(List[index]);
    }

    const Array<T>& operator+=(const T& newElem) {
        if(Capacity ==0) resize(1);
        else if(Size >= Capacity) resize(Capacity*2);

        List[Size]= new T(newElem);
        Size++;
        return *this;
    }

    const Array<T> Insert(int index, const T& newElem) {
        if(index < 0 || index > Size) throw OutOfBoundsException();
        if(Size >= Capacity) resize(Capacity == 0 ? 1 : Capacity *2);

        for(int i = Size; i>index; i--) {
            List[i] = List[i-1];
        }
        List[index]=new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray) {
        if(index<0 || index > Size) throw OutOfBoundsException();
        int newTotalSize = Size + otherArray.Size;
        if(newTotalSize > Capacity) resize(newTotalSize);

        for(int i=Size-1; i>= index; i--) {
            List[i+ otherArray.Size]= List[i];
        }

        for(int i=0;i<otherArray.Size; i++){
            List[index + i]= new T(*(otherArray.List[i]));
        }

        Size = newTotalSize;
        return *this;
    }

    const Array<T>& Delete(int index) {
        if(index<0 || index >=Size) throw OutOfBoundsException();
        delete List[index];

        for(int i =index; i<Size -1; i++) {
            List[i]= List[i+1];
        }
        Size--;
        return *this;
    }

    bool operator=(const Array<T>& otherArray) {
        if(this==&otherArray) return true;

        for(int i=0;i<Size;i++) delete List[i];
        delete[] List;

        Capacity = otherArray.Capacity;
        Size= otherArray.Size;
        List = new T*[Capacity];
        for(int i=0; i<Size; i++) {
            List[i] = new T(*(otherArray.List[i]));
        }
        return true;
    }

    void Sort() {
        for(int i=0;i<Size-1;i++) {
            for(int j=i+1; j<Size; j++) {
                if(*(List[j])< *(List[i])) {
                    T* temp = List[i];
                    List[i]=List[j];
                    List[j]=temp;
                }
            }
        }
    }

    void Sort(int(*compare)(const T&, const T&)) {
        for(int i=0;i<Size-1; i++) {
            for(int j=i+1; j<Size; j++) {
                if(compare(*(List[i]), *(List[j])) > 0) {
                    T* temp =List[i];
                    List[i]=List[j];
                    List[j]=temp;
                }
            }
        }
    }

    void Sort(Compare* comparator) {
        if(!comparator) return;
        for(int i=0;i<Size-1; i++) {
            for(int j=i+1; j<Size; j++) {
                if(comparator->CompareElements(List[i], List[j])>0) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    int BinarySearch(const T& elem) {
        int left =0, right = Size -1;
        while(left<=right) {
            int mid = left + (right-left) /2;
            if(*(List[mid])==elem) return mid;
            if(*(List[mid])<elem) left=mid+1;
            else right = mid -1;
        }
        return -1;
    }

    int Find(const T& elem) {
        for(int i=0;i<Size;i++) {
            if(*(List[i])==elem) return i;
        }
        return -1;
    }

    int GetSize() const {return Size;}
    int GetCapacity() const {return Capacity;}

    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(List,0, Size);
    }

    ArrayIterator<T> GetEndIterator() {
        return ArrayIterator<T>(List, Size, Size);
    }
};