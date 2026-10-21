#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_21D78[];
extern char lbl_27_data_21998[];
extern char lbl_27_data_21A90[];
extern char lbl_27_data_18AD0[];

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
    u8 array[12];
    u8 end;
};

struct Object {
    void* vtable;
    s16 managerId;
    s16 eventId;
    Work* workPtr;
    Work work;
};

extern "C" Object* fn_27_D7CB8(Object* self, s16 managerId, s16 eventId) {
    self->managerId = managerId;
    self->vtable = lbl_27_data_21D78;
    self->eventId = eventId;

    if (managerId != -1) {
        s16 id = ((EventManager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->managerId))->addUnit(self);
        if (id > -1)
            self->eventId = id;
    }

    Work* work = &self->work;
    self->workPtr = work;
    self->vtable = lbl_27_data_18AD0;
    work->flag = 0;
    work->vtable = lbl_27_data_21998;
    work->table14 = lbl_27_data_21998 + 0x34;
    work->table18 = lbl_27_data_21998 + 0x40;
    work->table1c = lbl_27_data_21A90;
    work->table20 = lbl_27_data_21A90 + 0x48;
    work->flags &= 0x01FFFFFF;
    __construct_array(work->array, fn_27_EF1EC, fn_27_84358, 12, 1);
    work->end = 0;
    return self;
}
