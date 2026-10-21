#pragma force_active on

extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" void* fn_27_840D8(void*, int);

template<class T>
class soEventUnitWrapper {
public:
    static char __vt[];
};

class EvMgr {
public:
    virtual void v0();
    virtual void remove(short);
};

class soTurnEventObserver;

template<class T, int N>
class soEventUnitWithWorkArea {
public:
    void* m_vptr;
    short m_id;
    short m_slot;
    unsigned char m_data[0x38];

    ~soEventUnitWithWorkArea();
};

template<class T, int N>
soEventUnitWithWorkArea<T, N>::~soEventUnitWithWorkArea() {
    if ((unsigned char*)this + 0xc) {
        if ((unsigned char*)this + 0x1c) {
            __destroy_arr((unsigned char*)this + 0x28,
                          (void (*)(void*, int))fn_27_840D8, 12, 2);
        }
    }
    if (this && this) {
        short id = m_id;
        m_vptr = soEventUnitWrapper<T>::__vt;
        if (id != -1) {
            ((EvMgr*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), m_id))->remove(m_slot);
        }
    }
}

template class soEventUnitWithWorkArea<soTurnEventObserver, 2>;
