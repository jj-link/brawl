#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_26050[];
extern char lbl_27_data_24450[];
extern char lbl_27_data_24540[];
extern char lbl_27_data_19558[];

void* getInstance__13soEventSystemFv();
void fn_27_EF114(void*);
void fn_27_84398(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int),
                       unsigned long, unsigned long);
}

struct EventManager {
    virtual s16 add(void*);
};

extern "C" EventManager* getManager__13soEventSystemFl(void*, long);

struct Sub {
    void* vtbl;
    u8 enabled;
    u8 pad5[3];
    void* v8;
    void* vC;
    void* v10;
    void* v14;
    u32 flags;
    u8 array[0x114];
    u8 end;
};

struct Object {
    void* vtbl;
    s16 id;
    s16 index;
    Sub* ptr;
    Sub sub;
};

extern "C" Object* fn_27_D6528(Object* self, s16 id, s16 index) {
    self->vtbl = lbl_27_data_26050;
    self->id = id;
    self->index = index;

    if (id != -1) {
        s16 result = getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->id)->add(self);
        if (result > -1) {
            self->index = result;
        }
    }

    Sub* sub = &self->sub;
    self->ptr = sub;
    self->vtbl = lbl_27_data_19558;
    sub->enabled = 0;
    sub->vtbl = lbl_27_data_24450;
    sub->v8 = lbl_27_data_24450 + 0x34;
    sub->vC = lbl_27_data_24450 + 0x40;
    sub->v10 = lbl_27_data_24540;
    sub->v14 = lbl_27_data_24540 + 0x48;
    sub->flags &= 0x1FFF;

    __construct_array(sub->array, fn_27_EF114, fn_27_84398, 0xC, 0x17);
    sub->end = 0;
    return self;
}
