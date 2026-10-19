#include <types.h>
#pragma force_active on

extern "C" void fn_80137684(void* p);

struct FnObj {
    void* m_a;
    void* m_b;
};

struct FnFlags {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
};

extern "C" {
void fn_27_30154(FnObj* p, int a2, int a3, int a4, int a5, u32 flag) {
    fn_80137684(p->m_b);
    FnFlags* q = (FnFlags*)((u8*)p->m_b + 0x73);
    q->b1 = flag;
}
}
