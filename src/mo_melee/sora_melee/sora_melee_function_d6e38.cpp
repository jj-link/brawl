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
extern unsigned char lbl_27_data_19148[];
extern unsigned char lbl_27_data_23378[];
extern unsigned char lbl_27_data_23468[];
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
    u8 array[24];
    u8 state34;
};

struct Unit {
    void* vtable;
    s16 managerID;
    s16 eventID;
    Work* work;
    Work data;
};

extern "C" Unit* fn_27_D6E38(Unit* self, s16 managerID, s16 eventID) {
    self->managerID = managerID;
    self->vtable = lbl_27_data_25FD8;
    self->eventID = eventID;

    if (managerID != -1) {
        s16 id = ((Manager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->managerID))->add(self);
        if (id > -1) {
            self->eventID = id;
        }
    }

    Work* work = &self->data;
    self->work = work;
    self->vtable = lbl_27_data_19148;
    work->state = 0;
    work->vtable = lbl_27_data_23378;
    work->vtable8 = lbl_27_data_23378 + 0x34;
    work->vtableC = lbl_27_data_23378 + 0x40;
    work->vtable10 = lbl_27_data_23468;
    work->vtable14 = lbl_27_data_23468 + 0x48;
    work->flags &= 0x3FFFFF;
    __construct_array(work->array, fn_27_EF174, fn_27_84258, 12, 2);
    work->state34 = 0;

    return self;
}
