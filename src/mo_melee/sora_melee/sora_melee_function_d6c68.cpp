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
extern u8 lbl_27_data_19228[];
extern u8 lbl_27_data_23738[];
extern u8 lbl_27_data_23828[];

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
    u8 entry[12];
    u8 end;

    void init() {
        flag = 0;
        vtable = lbl_27_data_23738;
        a = lbl_27_data_23738 + 0x34;
        b = lbl_27_data_23738 + 0x40;
        c = lbl_27_data_23828;
        d = lbl_27_data_23828 + 0x48;
        flags &= 0x01FFFFFF;
        __construct_array(entry, fn_27_EF15C, fn_27_84418, 12, 1);
        end = 0;
    }
};

struct Object {
    void* vtable;
    s16 manager;
    s16 id;
    Work* work;
    Work area;
};

extern "C" Object* fn_27_D6C68(Object* self, s16 manager, s16 id) {
    self->manager = manager;
    self->vtable = lbl_27_data_26000;
    self->id = id;

    if (manager != -1) {
        s16 result = ((EventManager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->manager))->add(self);
        if (result > -1)
            self->id = result;
    }

    Work* area = (Work*)((u32)self + 12);
    self->work = area;
    self->vtable = lbl_27_data_19228;
    area->init();
    return self;
}
