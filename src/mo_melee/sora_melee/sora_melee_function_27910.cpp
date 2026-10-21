#include <types.h>
#pragma force_active on

extern "C" int fn_80134344(void* p, u32 idx);

struct Inner {
    int pad;
    void* ptr;
};

struct Sub {
    virtual void f0();
    virtual Inner* f3(u32 a);
};

struct Outer {
    u8 pad[0x28];
    Sub* sub;
};

extern "C" {
int fn_27_27910(Outer* self, u32 flags, u32 arg) {
    u32 i = 0;
    for (u32 mask = 1; mask <= 0xff; mask <<= 1, i++) {
        if (flags & mask) {
            Inner* in = self->sub->f3(arg);
            if (fn_80134344(in->ptr, i)) {
                return 1;
            }
        }
    }
    return 0;
}
}
