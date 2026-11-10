#pragma force_active on
#include <types.h>

class Inner {
public:
    virtual void v0();
    virtual void* at(s32 i);
    virtual void v2();
    virtual s32 size();
};

struct Owner {
    char pad[0x18];
    Inner* arr;
};

struct FlagObj {
    u8 hi : 1;
    u8 low : 7;
};

extern "C" void fn_27_B1C48(void* p);

extern "C" void fn_27_B2728(Owner* self, u32 v, s32 idx) {
    if (idx == -1) {
        s32 count = self->arr->size();
        for (s32 i = 0; i < count; ++i) {
            if (v == 1) {
                FlagObj* f = (FlagObj*)self->arr->at(i);
                f->hi = 1;
            } else {
                FlagObj* f = (FlagObj*)self->arr->at(i);
                f->hi = 0;
                fn_27_B1C48(self->arr->at(i));
            }
        }
    } else {
        if (v == 1) {
            FlagObj* f = (FlagObj*)self->arr->at(idx);
            f->hi = 1;
        } else {
            FlagObj* f = (FlagObj*)self->arr->at(idx);
            f->hi = 0;
            fn_27_B1C48(self->arr->at(idx));
        }
    }
}
