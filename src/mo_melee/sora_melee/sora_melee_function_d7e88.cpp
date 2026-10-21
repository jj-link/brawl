#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_25F38[];
extern char lbl_27_data_189E0[];
extern char lbl_27_data_215A8[];
extern char lbl_27_data_216A0[];

void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_EF204(void*);
void fn_27_842D8(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
}

struct Manager {
    virtual s16 attach(void*);
};

struct Inner {
    void* vtable;
    u8 enabled;
    u8 pad[3];
    void* v14;
    void* v18;
    void* v1c;
    void* v20;
    u32 flags;
    u8 array[12];
    u8 tail;
};

struct Object {
    void* vtable;
    s16 id;
    s16 index;
    Inner* ptr;
    Inner inner;
};

extern "C" Object* fn_27_D7E88(Object* self, s16 id, s16 index) {
    self->id = id;
    self->vtable = lbl_27_data_25F38;
    self->index = index;

    if (id != -1) {
        Manager* manager = (Manager*)getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->id);
        s16 result = manager->attach(self);
        if (result > -1) {
            self->index = result;
        }
    }

    Inner* inner = &self->inner;
    self->ptr = inner;
    self->vtable = lbl_27_data_189E0;
    inner->enabled = 0;
    inner->vtable = lbl_27_data_215A8;
    inner->v14 = lbl_27_data_215A8 + 0x34;
    inner->v18 = lbl_27_data_215A8 + 0x40;
    inner->v1c = lbl_27_data_216A0;
    inner->v20 = lbl_27_data_216A0 + 0x48;
    inner->flags &= 0x01FFFFFF;
    __construct_array(inner->array, fn_27_EF204, fn_27_842D8, 12, 1);
    inner->tail = 0;
    return self;
}
