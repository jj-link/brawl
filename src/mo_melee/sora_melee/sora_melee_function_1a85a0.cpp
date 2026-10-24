#pragma force_active on
#include <types.h>

extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

class soLinkEventObserver;

template<class T>
struct soInstanceUnitFullProperty {
    char d[0xC];
    ~soInstanceUnitFullProperty();
};

template<class T>
struct soEventUnitWrapper {
    static char __vt[];
};

struct EventManager {
    virtual void f0();
    virtual void f1(long);
};

struct H2 {
    char pad[0xC];
    soInstanceUnitFullProperty<soLinkEventObserver*> arr[4];
    inline ~H2() {}
};

struct H1 {
    char pad[0x10];
    H2 h2;
    inline ~H1() {}
};

struct Outer {
    char pad[0xC];
    H1 h1;
};

template<class T, int N>
class soEventUnitWithWorkArea {
public:
    void* m_vtbl;
    s16 m_4;
    s16 m_6;
    u8 m_pad8[4];
    u8 m_arrA[0x10];
    u8 m_arrB[0xC];
    u8 m_arrC[0x30];

    ~soEventUnitWithWorkArea();
};

template<class T, int N>
soEventUnitWithWorkArea<T, N>::~soEventUnitWithWorkArea() {
    ((Outer*)this)->h1.~H1();
    if ((u8*)this != 0) {
        if ((u8*)this != 0) {
            s16 id = m_4;
            m_vtbl = soEventUnitWrapper<soLinkEventObserver>::__vt;
            if (id != -1) {
                EventManager* mgr =
                    (EventManager*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), m_4);
                mgr->f1(m_6);
            }
        }
    }
}

template class soEventUnitWithWorkArea<soLinkEventObserver, 4>;
