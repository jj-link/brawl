#pragma force_active on
class wnPikminPikmin {
public:
    wnPikminPikmin() {}
};

class soArrayVectorCalcInterface {
public:
    virtual void substitution(long, long) = 0;
    virtual void onFull() = 0;
    virtual void offFull() = 0;
    virtual void setTopIndex(long) = 0;
    virtual void setLastIndex(long) = 0;
    virtual ~soArrayVectorCalcInterface() {}
};

template <class T>
class soArray {
public:
    virtual ~soArray() {}
    virtual T& at(long) = 0;
    virtual const T& at(long) const = 0;
    virtual long size() const = 0;
    virtual bool isEmpty() const { return this->size() == 0; }
    virtual void clear() = 0;
};

template <class T>
class soArrayVectorAbstract : public soArray<T>, public soArrayVectorCalcInterface {
public:
    virtual T& at(long index) { return this->atFastAbstractSub(index); }
    virtual const T& at(long index) const { return this->atFastAbstractSub(index); }
    virtual T& atFastAbstractSub(long) const = 0;
    virtual T& getArrayValueConst(long) = 0;
    virtual long getTopIndex() const = 0;
    virtual long getLastIndex() const = 0;
    virtual void setSize(long) = 0;
};

template <class T, int C>
class soArrayVector : public soArrayVectorAbstract<T> {
    long m_topIndex : 5;
    long m_lastIndex : 5;
    long m_size : 5;
    unsigned long m_isFull : 1;
    T m_elements[C];
public:
    virtual long size() const { return m_size; }
    virtual void setSize(long size);
    virtual void clear() {}
    virtual void substitution(long, long) {}
    virtual void onFull() { m_isFull = 1; }
    virtual void offFull() { m_isFull = 0; }
    virtual void setTopIndex(long i) { m_topIndex = i; }
    virtual void setLastIndex(long i) { m_lastIndex = i; }
    virtual T& atFastAbstractSub(long i) const { return const_cast<T&>(m_elements[i]); }
    virtual T& getArrayValueConst(long i) { return m_elements[i]; }
    virtual long getTopIndex() const { return m_topIndex; }
    virtual long getLastIndex() const { return m_lastIndex; }
};

template <class T, int C>
void soArrayVector<T, C>::setSize(long size) {
    m_size = size;
}

template void soArrayVector<wnPikminPikmin*, 10>::setSize(long);
