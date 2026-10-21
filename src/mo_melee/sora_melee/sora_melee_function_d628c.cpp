#include <types.h>
#pragma force_active on

extern "C" void* fn_27_84298(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);
extern "C" char lbl_27_data_24DB8[];

struct EventManager {
    virtual void fn0();
    virtual void fn1(s16);
};

class soMotionEventObserver {};

template <class T, int N>
class soEventUnitWithWorkArea {
public:
    ~soEventUnitWithWorkArea();
};

template <class T, int N>
soEventUnitWithWorkArea<T, N>::~soEventUnitWithWorkArea() {
    unsigned char* self = (unsigned char*)this;
    if (self + 0xc != 0 && self + 0x1c != 0) {
        __destroy_arr(self + 0x28, (void (*)(void*, int))fn_27_84298, 0xc, 1);
    }
    if (self != 0) {
        if (self != 0) {
            s16 id = *(s16*)(self + 4);
            *(void**)self = (void*)lbl_27_data_24DB8;
            if (id != -1) {
                void* instance = getInstance__13soEventSystemFv();
                ((EventManager*)getManager__13soEventSystemFl(
                    instance, *(s16*)(self + 4)))->fn1(*(s16*)(self + 6));
            }
        }
    }
}

template class soEventUnitWithWorkArea<soMotionEventObserver, 1>;
