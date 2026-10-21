#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_EF1BC(void*);
void fn_27_845D8(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
extern char lbl_27_data_25F88[];
extern char lbl_27_data_32EA0[];
extern char lbl_27_data_3FFF0[];
extern char lbl_27_data_400E8[];
}

struct Manager {
    virtual s16 add(void*);
};

struct Inner {
    void* table;
    u8 flag;
    u8 pad[3];
    void* table8;
    void* tableC;
    void* table10;
    void* table14;
    u32 flags;
    u8 entries[0x18];
    u8 done;
};

struct Object {
    void* table;
    s16 manager;
    s16 slot;
    Inner* inner;
    Inner storage;
};

extern "C" Object* fn_27_1AB238(Object* self, s16 manager, s16 slot) {
    self->manager = manager;
    self->table = lbl_27_data_25F88;
    self->slot = slot;

    if (manager != -1) {
        Manager* mgr = (Manager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->manager);
        s16 result = mgr->add(self);
        if (result > -1) {
            self->slot = result;
        }
    }

    Inner* inner = &self->storage;
    self->inner = inner;
    self->table = lbl_27_data_32EA0;
    inner->flag = 0;
    inner->table = lbl_27_data_3FFF0;
    inner->table8 = lbl_27_data_3FFF0 + 0x34;
    inner->tableC = lbl_27_data_3FFF0 + 0x40;
    inner->table10 = lbl_27_data_400E8;
    inner->table14 = lbl_27_data_400E8 + 0x48;
    inner->flags &= 0x3FFFFF;
    __construct_array(inner->entries, fn_27_EF1BC, fn_27_845D8, 0xC, 2);
    inner->done = 0;

    return self;
}
