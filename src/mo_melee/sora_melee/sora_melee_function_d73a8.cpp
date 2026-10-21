#include <types.h>
#pragma force_active on

extern "C" {
char lbl_27_data_22D70[];
char lbl_27_data_22990[];
char lbl_27_data_22A88[];
char lbl_27_data_18ED0[];

void* getInstance__13soEventSystemFv();
void fn_27_EF1A4(void*);
void fn_27_84558(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
}

struct EventManager {
    virtual short add(void*);
};

extern "C" EventManager* getManager__13soEventSystemFl(void*, long);

class soCollisionCatchEventObserver {
    u8 data[0xC];
};

template <class T, int N>
class soEventUnitWithWorkArea {
public:
    u8 data[0x38];
    soEventUnitWithWorkArea(short, short);
};

template <class T, int N>
soEventUnitWithWorkArea<T, N>::soEventUnitWithWorkArea(short a, short b) {
    u8* self = (u8*)this;
    *(short*)(self + 4) = a;
    *(void**)self = lbl_27_data_22D70;
    *(short*)(self + 6) = b;

    if (a != -1) {
        short id = getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), *(short*)(self + 4))->add(this);
        if (id > -1)
            *(short*)(self + 6) = id;
    }

    u8* work = self + 0xC;
    *(void**)(self + 8) = work;
    *(void**)self = lbl_27_data_18ED0;
    *(u8*)(work + 4) = 0;
    *(void**)(work + 0) = lbl_27_data_22990;
    *(void**)(work + 8) = lbl_27_data_22990 + 0x34;
    *(void**)(work + 0xC) = lbl_27_data_22990 + 0x40;
    *(void**)(work + 0x10) = lbl_27_data_22A88;
    *(void**)(work + 0x14) = lbl_27_data_22A88 + 0x48;
    *(u32*)(work + 0x18) &= 0x01FFFFFF;
    __construct_array(work + 0x1C, fn_27_EF1A4, fn_27_84558, 0xC, 1);
    *(u8*)(work + 0x28) = 0;
}

template class soEventUnitWithWorkArea<soCollisionCatchEventObserver, 1>;
