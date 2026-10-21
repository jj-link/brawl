#pragma force_active on
#include <types.h>

extern "C" void* fn_27_84218(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_27_data_25F60[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

class soCollisionSearchEventObserver;

class soEvManagerBase {
public:
    virtual void f0();
    virtual void f1(long);
};

template <class T, int N>
class soEventUnitWithWorkArea {
public:
    void* m_vtbl;
    s16 m_4;
    s16 m_6;
    u8 m_pad8[0xc - 0x8];
    u8 m_arrA[0x1c - 0xc];
    u8 m_arrB[0x28 - 0x1c];
    u8 m_arrC[0x40];

    ~soEventUnitWithWorkArea();
};

template <class T, int N>
soEventUnitWithWorkArea<T, N>::~soEventUnitWithWorkArea() {
    if ((u8*)this + 0xc != 0 && (u8*)this + 0x1c != 0) {
        __destroy_arr((u8*)this + 0x28,
                      (void (*)(void*, int))fn_27_84218, 0xc, 4);
    }
    if ((u8*)this != 0) {
        if (this != 0) {
            m_vtbl = lbl_27_data_25F60;
            if (m_4 != -1) {
                soEvManagerBase* mgr =
                    (soEvManagerBase*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(),
                        *(s16*)((u8*)this + 4));
                mgr->f1(*(s16*)((u8*)this + 6));
            }
        }
    }
}

template class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>;
