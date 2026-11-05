#pragma force_active on

#include <types.h>

struct soTransitionTermPack {
    s32 m_a;
    s32 m_b;
    s32 m_c;
    s32 m_d;
    s32 m_e;

    soTransitionTermPack& operator=(const soTransitionTermPack& src) {
        m_a = src.m_a;
        if (&m_b != &src.m_b) {
            if (&m_b != &src.m_b) {
                if (&m_c != &src.m_c)
                    m_c = src.m_c;
                s32 d = src.m_d;
                m_d = d;
                m_e = src.m_e;
                if (d == 0)
                    m_e = 0;
            }
        }
        return *this;
    }
};

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
    virtual ~soArrayFixed() { }
};

template <class T>
class soArrayVectorAbstract : public soArrayFixed<T> {
public:
    virtual ~soArrayVectorAbstract() { }
    virtual void set(s32 start, const T& elm, s32 count);
};

template <class T>
void soArrayVectorAbstract<T>::set(s32 start, const T& elm, s32 count) {
    int c = count;
    if (c + start >= this->size())
        c = this->size() - start;
    for (s32 i = 0; i < c; i++) {
        this->at(start + i) = elm;
    }
}

template class soArrayVectorAbstract<soTransitionTermPack>;
