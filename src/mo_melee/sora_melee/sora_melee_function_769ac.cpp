#include <types.h>
#pragma force_active on

struct Inner {
    virtual void f0();
    virtual void* f1(s32);
};

struct Holder {
    u32 pad0;
    Inner* inner;
    s32 index;
};

extern "C" u32 fn_27_ABF78(void*);
extern "C" s32 fn_27_AB758(void*, s32, s32, s32, s32);

extern "C" s32 fn_27_769AC(Holder* self, s32 index, s32 a, s32 b, s32 c, s32 d) {
    if (fn_27_ABF78(self->inner->f1(index <= -1 ? self->index : index)) == 1U) {
        return -1;
    }
    return fn_27_AB758(self->inner->f1(index <= -1 ? self->index : index), b, c, a, d);
}
