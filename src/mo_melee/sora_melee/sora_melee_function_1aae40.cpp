#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, s32);
void fn_27_EF174(void*);
void fn_27_84258(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);

extern unsigned char lbl_27_data_25FD8[];
extern unsigned char lbl_27_data_3F848[];
extern unsigned char lbl_27_data_44450[];
extern unsigned char lbl_27_data_44540[];
}

struct Manager {
    virtual s16 add(void*);
};

struct Work {
    void* vtable;
    u8 state;
    u8 pad[3];
    void* vtable8;
    void* vtableC;
    void* vtable10;
    void* vtable14;
    u32 flags;
    u8 array[48];
    u8 state4C;
};

class soSituationEventObserver;

template <class T, int N>
struct soEventUnitWithWorkArea {
    void* vtable;
    s16 managerID;
    s16 eventID;
    Work* work;
    Work data;

    soEventUnitWithWorkArea(s16, s16);
};

template <class T, int N>
soEventUnitWithWorkArea<T, N>::soEventUnitWithWorkArea(s16 managerID, s16 eventID) {
    this->managerID = managerID;
    this->vtable = lbl_27_data_25FD8;
    this->eventID = eventID;

    if (managerID != -1) {
        s16 id = ((Manager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), this->managerID))->add(this);
        if (id > -1) {
            this->eventID = id;
        }
    }

    Work* work = &this->data;
    this->work = work;
    this->vtable = lbl_27_data_3F848;
    work->state = 0;
    work->vtable = lbl_27_data_44450;
    work->vtable8 = lbl_27_data_44450 + 0x34;
    work->vtableC = lbl_27_data_44450 + 0x40;
    work->vtable10 = lbl_27_data_44540;
    work->vtable14 = lbl_27_data_44540 + 0x48;
    work->flags &= 0x7FFFF;
    __construct_array(work->array, fn_27_EF174, fn_27_84258, 12, 4);
    work->state4C = 0;
}

template class soEventUnitWithWorkArea<soSituationEventObserver, 4>;
