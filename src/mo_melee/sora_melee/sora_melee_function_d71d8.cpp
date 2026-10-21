#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_25FB0[];
extern char lbl_27_data_22D98[];
extern char lbl_27_data_22E90[];
extern char lbl_27_data_18FC0[];

void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_EF18C(void*);
void fn_27_84598(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
}

class EventManager {
public:
    virtual short add(void*);
};

class soCollisionHitEventObserver;

template<class T, int N>
class soEventUnitWithWorkArea {
public:
    soEventUnitWithWorkArea(short, short);
};

template<class T, int N>
soEventUnitWithWorkArea<T, N>::soEventUnitWithWorkArea(short manager, short event) {
    char* self = (char*)this;
    *(short*)(self + 4) = manager;
    *(char**)self = lbl_27_data_25FB0;
    *(short*)(self + 6) = event;

    if (manager != -1) {
        EventManager* mgr = (EventManager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), *(short*)(self + 4));
        short id = mgr->add(this);
        if (id > -1) {
            *(short*)(self + 6) = id;
        }
    }

    char* work = self + 0xc;
    *(char**)(self + 8) = work;
    *(char**)self = lbl_27_data_18FC0;
    work[4] = 0;
    *(char**)(work + 0) = lbl_27_data_22D98;
    *(char**)(work + 8) = lbl_27_data_22D98 + 0x34;
    *(char**)(work + 0xc) = lbl_27_data_22D98 + 0x40;
    *(char**)(work + 0x10) = lbl_27_data_22E90;
    *(char**)(work + 0x14) = lbl_27_data_22E90 + 0x48;
    *(u32*)(work + 0x18) &= 0x7ffff;

    __construct_array(work + 0x1c, fn_27_EF18C, fn_27_84598, 0xc, N);
    work[0x4c] = 0;
}

template class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>;
