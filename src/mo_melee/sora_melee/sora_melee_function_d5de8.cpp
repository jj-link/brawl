#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_26078[];
extern char lbl_27_data_19838[];
extern char lbl_27_data_24FE8[];
extern char lbl_27_data_250D8[];
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
void fn_27_EF0E4(void*);
void fn_27_84518(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int), unsigned long, unsigned long);
}
struct Manager {
    virtual s16 attach(void*);
};
struct Work {
    void* vt;
    u8 state;
    u8 pad[3];
    void* p8;
    void* pC;
    void* p10;
    void* p14;
    u32 flags;
    u8 array[12];
    u8 end;
};
struct Object {
    void* vt;
    s16 id;
    s16 slot;
    Work* work;
    Work data;
};
extern "C" Object* fn_27_D5DE8(Object* self, s16 id, s16 slot) {
    self->id = id;
    self->vt = lbl_27_data_26078;
    self->slot = slot;
    if (id != -1) {
        s16 result = ((Manager*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), self->id))->attach(self);
        if (result > -1)
            self->slot = result;
    }
    Work* work = &self->data;
    self->work = work;
    self->vt = lbl_27_data_19838;
    work->state = 0;
    work->vt = lbl_27_data_24FE8;
    work->p8 = lbl_27_data_24FE8 + 0x34;
    work->pC = lbl_27_data_24FE8 + 0x40;
    work->p10 = lbl_27_data_250D8;
    work->p14 = lbl_27_data_250D8 + 0x48;
    work->flags &= 0x01FFFFFF;
    __construct_array(work->array, fn_27_EF0E4, fn_27_84518, 12, 1);
    work->end = 0;
    return self;
}
