#include <types.h>
#pragma force_active on

extern "C" void fn_27_84598(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" char lbl_27_data_25FB0[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

class soCollisionHitEventObserver;

class soEventManagerIface {
public:
    virtual void f0();
    virtual void f1(s16 x);
};

template <class T, int N>
class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};

template <class T, int N>
soEventUnitWithWorkArea<T, N>::~soEventUnitWithWorkArea() {
    u8* self = (u8*)this;
    if (self + 0xc != 0 && self + 0x1c != 0) {
        __destroy_arr(self + 0x28, fn_27_84598, 0xc, 4);
    }
    if (this != 0) {
        if (this != 0) {
            s16 id = *(s16*)(self + 4);
            *(char**)this = lbl_27_data_25FB0;
            if (id != -1) {
                soEventManagerIface* mgr =
                    (soEventManagerIface*)getManager__13soEventSystemFl(
                        getInstance__13soEventSystemFv(), *(s16*)(self + 4));
                mgr->f1(*(s16*)(self + 6));
            }
        }
    }
}

template class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>;
