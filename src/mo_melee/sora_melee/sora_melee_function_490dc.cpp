#include <types.h>
#pragma force_active on

struct Inner {
    u8 pad[4];
    u32 m4;
};

struct Mid {
    u8 pad[0xD8];
    Inner* mD8;
};

class VF {
public:
    virtual void* vf0();
    virtual void* vf1(u32 a);
    virtual void* vf2();
};

class Self {
public:
    u8 pad0[0x1C];
    Mid* m1C;
    u32 m20;
    u8 pad24[4];
    u8 body[0x20];
    VF* m48;
    u8 pad4C[4];
    u8 m50;
    u8 pad51[3];
};

extern "C" u32 fn_27_46E78(void*, void*, u32, u32, float, float, float);
extern "C" void fn_27_36A8C(void*);

extern "C" void fn_27_490DC(Self* self, u32 a, float f1, float f2, float f3) {
    u32 val = self->m1C->mD8->m4;
    void* result = self->m48->vf1(a);
    if (fn_27_46E78(result, &self->body, self->m20, val, f1, f2, f3) == 1U &&
        self->m50 == 0) {
        fn_27_36A8C(&self->body);
        self->m50 = 1;
    }
}
