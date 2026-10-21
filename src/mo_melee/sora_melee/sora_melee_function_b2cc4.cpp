#include <types.h>
#pragma force_active on

struct Arr {
    virtual void unused0() = 0;
    virtual void* at(s32 i);
    virtual void unused2();
    virtual s32 size();
};

struct Owner {
    u8 pad[0x18];
    Arr* arr;
};

extern "C" void fn_27_B1D84(char* self, u32 v);

extern "C" void fn_27_B2CC4(Owner* self, s32 arg1, s32 arg2) {
    if (arg2 == -1) {
        s32 count = self->arr->size();
        for (s32 i = 0; i < count; ++i) {
            fn_27_B1D84((char*)self->arr->at(i), (u32)arg1);
        }
    } else {
        fn_27_B1D84((char*)self->arr->at(arg2), (u32)arg1);
    }
}
