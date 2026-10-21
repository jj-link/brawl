#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, s32);
void fn_27_EF15C(void*);
void fn_27_84418(void*, s32);
void __construct_array(void*, void (*)(void*), void (*)(void*, s32), u32, u32);
}

extern u8 lbl_27_data_26000[];
extern u8 lbl_27_data_3F690[];
extern u8 lbl_27_data_43E28[];
extern u8 lbl_27_data_43F18[];

struct EventManager {
    virtual s16 add(void*);
};

struct Work {
    void* vtable;
    u8 flag;
    u8 pad[3];
    void* a;
    void* b;
    void* c;
    void* d;
    u32 flags;
    u8 entry[48];
    u8 end;

    void init() {
        flag = 0;
        vtable = lbl_27_data_43E28;
        a = lbl_27_data_43E28 + 0x34;
        b = lbl_27_data_43E28 + 0x40;
        c = lbl_27_data_43F18;
        d = lbl_27_data_43F18 + 0x48;
        flags &= 0x0007FFFF;
        __construct_array(entry, fn_27_EF15C, fn_27_84418, 12, 4);
        end = 0;
    }
};

struct soCaptureEventObserver {};

template <class T, int N>
struct soEventUnitWithWorkArea {
    void* vtable;
    s16 manager;
    s16 id;
    Work* work;
    Work area;

    soEventUnitWithWorkArea(s16 manager, s16 id);
};

template <class T, int N>
soEventUnitWithWorkArea<T, N>::soEventUnitWithWorkArea(s16 manager, s16 id) {
    this->manager = manager;
    this->vtable = lbl_27_data_26000;
    this->id = id;

    if (manager != -1) {
        s16 result = ((EventManager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), this->manager))->add(this);
        if (result > -1)
            this->id = result;
    }

    Work* area = (Work*)((u32)this + 12);
    this->work = area;
    this->vtable = lbl_27_data_3F690;
    area->init();
}

template struct soEventUnitWithWorkArea<soCaptureEventObserver, 4>;
