#include <types.h>
#pragma force_active on

class SoHeapAllocator {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f(void* ptr, u32 size, s32 align);
};

extern SoHeapAllocator* lbl_805A0EB8;

struct Obj {
    void* m_00;
    u32 m_04;
    u32 m_08;
};

extern "C" {
Obj* fn_8027DC80(Obj* arg0, s32 arg1) {
    if (arg0 != 0) {
        lbl_805A0EB8->f(arg0->m_00, ((arg0->m_08 + 1) * 3) << 2, 0x15);
        if (arg1 > 0) {
            lbl_805A0EB8->f(arg0, 0xC, 0x1A);
        }
    }
    return arg0;
}
}
