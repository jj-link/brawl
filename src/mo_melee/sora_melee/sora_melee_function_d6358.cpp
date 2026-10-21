#include <types.h>
#pragma force_active on

struct EventManager {
    virtual s16 add(void*);
};

extern "C" {
void* getInstance__13soEventSystemFv();
EventManager* getManager__13soEventSystemFl(void*, s32);
extern char lbl_27_data_26050[];
extern char lbl_27_data_195E8[];
extern char lbl_27_data_24658[];
extern char lbl_27_data_24748[];
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
    u8 array[0x90];
    u8 byteAC;
};

struct Object {
    void* vptr;
    s16 manager;
    s16 id;
    Sub* list;
    Sub sub;
};

extern "C" Object* fn_27_D6358(Object* self, s16 manager, s16 id) {
    self->manager = manager;
    self->vptr = lbl_27_data_26050;
    self->id = id;

    if (manager != -1) {
        s16 value = getManager__13soEventSystemFl(
            getInstance__13soEventSystemFv(), self->manager)->add(self);
        if (value > -1) {
            self->id = value;
        }
    }

    Sub* sub = &self->sub;
    self->list = sub;
    self->vptr = lbl_27_data_195E8;
    sub->byte4 = 0;
    sub->vptr = lbl_27_data_24658;
    sub->ptr8 = lbl_27_data_24658 + 0x34;
    sub->ptrC = lbl_27_data_24658 + 0x40;
    sub->ptr10 = lbl_27_data_24748;
    sub->ptr14 = lbl_27_data_24748 + 0x48;
    sub->flags &= 0xFFFF;
    __construct_array(sub->array, fn_27_EF114, fn_27_84398, 0xC, 0xC);
    sub->byteAC = 0;
    return self;
}
