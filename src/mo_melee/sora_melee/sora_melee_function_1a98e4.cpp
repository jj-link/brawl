#include <types.h>
#pragma force_active on

struct EventManager {
    virtual s16 add(void*);
};

extern "C" {
void* getInstance__13soEventSystemFv();
EventManager* getManager__13soEventSystemFl(void*, s32);
extern char lbl_27_data_26050[];
extern char lbl_27_data_429E0[];
extern char lbl_27_data_42AD0[];
extern char lbl_27_data_3DB78[];
void fn_27_EF114(void*);
void fn_27_84398(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
}

struct Sub {
    void* vptr;
    u8 byte4;
    u8 pad5[3];
    void* ptr8;
    void* ptrC;
    void* ptr10;
    void* ptr14;
    u32 flags;
    u8 array[0x180];
    u8 end;
};

class soStatusEventObserver;

template <class T, int N>
struct soEventUnitWithWorkArea {
    void* vptr;
    s16 manager;
    s16 id;
    Sub* list;
    Sub sub;

    soEventUnitWithWorkArea(s16, s16);
};

template <>
soEventUnitWithWorkArea<soStatusEventObserver, 32>::soEventUnitWithWorkArea(
    s16 manager, s16 id) {
    this->manager = manager;
    this->vptr = lbl_27_data_26050;
    this->id = id;

    if (manager != -1) {
        s16 value = getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), this->manager)->add(this);
        if (value > -1) {
            this->id = value;
        }
    }

    Sub* sub = &this->sub;
    this->list = sub;
    this->vptr = lbl_27_data_3DB78;
    sub->byte4 = 0;
    sub->vptr = lbl_27_data_429E0;
    sub->ptr8 = lbl_27_data_429E0 + 0x34;
    sub->ptrC = lbl_27_data_429E0 + 0x40;
    sub->ptr10 = lbl_27_data_42AD0;
    sub->ptr14 = lbl_27_data_42AD0 + 0x48;
    sub->flags &= 0x3FF;
    __construct_array(sub->array, fn_27_EF114, fn_27_84398, 0xC, 0x20);
    sub->end = 0;
}
