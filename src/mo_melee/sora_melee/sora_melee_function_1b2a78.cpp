#include <types.h>
#pragma force_active on

class soNullableInterface {
public:
    virtual bool isNull() const = 0;
};

template <class T>
class soArrayFixed : public soNullableInterface {
public:
    virtual bool isNull() const { return false; }
    virtual T& at(s32 index) = 0;
    virtual const T& at(s32 index) const = 0;
    virtual s32 size() const = 0;
    virtual bool isEmpty() const { return this->size() == 0; }
    virtual ~soArrayFixed() { };
};

template <class T>
class soArrayContractible : public soArrayFixed<T> {
public:
    virtual ~soArrayContractible() { }
    virtual void shift() = 0;
    virtual void pop() = 0;
    virtual void clear() = 0;
};

template <class T>
class soArray : public soArrayContractible<T> {
public:
    virtual ~soArray() {};
    virtual void unshift(const T&) = 0;
    virtual void push(const T&) = 0;
    virtual void insert(s32, const T&) = 0;
    virtual void erase(s32) = 0;
    virtual s32 capacity() const = 0;
    virtual bool isFull() const = 0;
    virtual void set(s32 startingIndex, const T& element, s32 numIndicesToSet) = 0;
};

class soArrayVectorCalcInterface {
public:
    virtual void substitution(s32, s32) = 0;
    virtual void onFull() = 0;
    virtual void offFull() = 0;
    virtual void setTopIndex(s32) = 0;
    virtual void setLastIndex(s32) = 0;
    virtual ~soArrayVectorCalcInterface() { }
};

template <class T>
class soArrayVectorAbstract : public soArray<T>, public soArrayVectorCalcInterface {
public:
    virtual bool isNull() const { return false; }
    virtual T& at(s32 index);
    virtual const T& at(s32 index) const { return this->atFastAbstractSub(index); }
    virtual ~soArrayVectorAbstract() { }
    virtual void shift() { }
    virtual void pop() { }
    virtual void clear() { }
    virtual void unshift(const T& newElement) { }
    virtual void push(const T& newElement) { }
    virtual void insert(s32 index, const T& newElement) { }
    virtual void erase(s32 index) { }
    virtual s32 capacity() const = 0;
    virtual void set(s32 start, const T& elm, s32 count) { }
    virtual T& atFastAbstractSub(s32 index) const = 0;
    virtual void substitution(s32 subIndex, s32 targetIndex) { }
    virtual T& getArrayValueConst(s32) = 0;
    virtual s32 getTopIndex() const = 0;
    virtual s32 getLastIndex() const = 0;
    virtual void setSize(s32) = 0;
};

class wnPikminPikmin;

template <class T>
T& soArrayVectorAbstract<T>::at(s32 index) {
    return this->atFastAbstractSub(index);
}

template class soArrayVectorAbstract<wnPikminPikmin*>;
