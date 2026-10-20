#include <types.h>
#pragma force_active on

extern "C" int fn_27_25EF4C(void* self, int a, int b);

class soSoraWorkBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual void v4();
    virtual void v5();
};

extern "C" {
void fn_27_25ED08(soSoraWorkBase* self, u32* value) {
    int idx = self->v3();
    idx = fn_27_25EF4C(self, idx - 1, -1);
    if (idx >= 0) {
        u8* base = (u8*)self;
        *(u32*)(base + idx * 12 + 0xC) = *value;
    }
}
}
