#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_21D78[];
extern char lbl_27_data_43C10[];
extern char lbl_27_data_43D08[];
extern char lbl_27_data_3F5F8[];

void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_EF1EC(void*);
void fn_27_84358(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
}

struct EventManager {
    virtual s16 addUnit(void*);
};

struct Work {
    void* vtable;
    u8 flag;
    u8 pad[3];
    void* table14;
    void* table18;
    void* table1c;
    void* table20;
    u32 flags;
    u8 array[48];
    u8 end;
};

class soCollisionShieldEventObserver;

template <typename T, int N>
struct soEventUnitWithWorkArea {
    void* vtable;
    s16 managerId;
    s16 eventId;
    Work* workPtr;
    Work work;

    soEventUnitWithWorkArea(s16, s16);
};

template <typename T, int N>
soEventUnitWithWorkArea<T, N>::soEventUnitWithWorkArea(s16 mgrId, s16 evtId) {
    managerId = mgrId;
    vtable = lbl_27_data_21D78;
    eventId = evtId;

    if (mgrId != -1) {
        s16 id = ((EventManager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), managerId))->addUnit(this);
        if (id > -1)
            eventId = id;
    }

    Work* w = &work;
    workPtr = w;
    vtable = lbl_27_data_3F5F8;
    w->flag = 0;
    w->vtable = lbl_27_data_43C10;
    w->table14 = lbl_27_data_43C10 + 0x34;
    w->table18 = lbl_27_data_43C10 + 0x40;
    w->table1c = lbl_27_data_43D08;
    w->table20 = lbl_27_data_43D08 + 0x48;
    w->flags &= 0x0007FFFF;
    __construct_array(w->array, fn_27_EF1EC, fn_27_84358, 12, 4);
    w->end = 0;
}

template struct soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>;
