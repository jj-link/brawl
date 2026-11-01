#include <types.h>
#pragma force_active on

extern "C" void fn_27_301A0(void*, u8*, u8*, u8*, u8*);

class soSubObj {
public:
    virtual void f0();
    virtual void* f1(u32);
    virtual void f2();
    virtual void f3();
};

struct soOwner {
    u8 pad[0x28];
    soSubObj* sub;
};

static inline void* callSub(soSubObj* sub, u32 e) {
    return sub->f1(e);
}

extern "C" void fn_27_2A468(const soOwner* self, u8* a, u8* b, u8* c, u8* d, u32 e) {
    void* result = callSub(self->sub, e);
    fn_27_301A0(result, a, b, c, d);
}
