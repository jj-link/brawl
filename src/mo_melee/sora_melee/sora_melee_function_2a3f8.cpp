#include <types.h>
#pragma force_active on

struct FnObj {
    void* m_a;
    void* m_b;
};

struct FnInner {
    virtual void v0();
    virtual FnObj* get(u32 x);
};

struct FnHolder {
    u8 pad[0x28];
    FnInner* inner;
};

extern "C" {
void fn_27_30154(FnObj* p, int a2, int a3, int a4, int a5, u32 flag);

void fn_27_2A3F8(FnObj* p, int a2, int a3, int a4, int a5, u32 a6, u32 a7) {
    FnObj* r = ((FnHolder*)p)->inner->get(a7);
    fn_27_30154(r, a2, a3, a4, a5, a6);
}
}
