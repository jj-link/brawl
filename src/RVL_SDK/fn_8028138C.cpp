#include <types.h>
#pragma force_active on

class Alloc {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void* alloc(s32, s32, s32);
};

extern char lbl_80486498[];
extern Alloc* lbl_805A0EB8;

struct RefObject {
    u32 pad0;
    u16 count;
    s16 refs;
};

struct FnObject {
    void* vt;
    u16 pad4;
    u16 flag;
    RefObject* ref;
    void* buf;
    s32 zero;
    s32 arg;
    u8 active;
};

extern "C" FnObject* fn_8028138C(FnObject* self, RefObject* ref, s32 arg) {
    self->flag = 1;
    self->vt = lbl_80486498;
    self->ref = ref;
    self->active = 1;
    if (ref != 0 && ref->count != 0) {
        ref->refs = ref->refs + 1;
    }
    self->buf = lbl_805A0EB8->alloc(0x40, arg, 0x18);
    self->zero = 0;
    self->arg = arg;
    return self;
}
