#include <types.h>
#pragma force_active on

extern "C" void __dla__FPv(void*);

struct fn_27_262434_Obj {
    u32 unk0;
    void* m_ptr;
    u32 unk8;
    u32 unkC;
};

extern "C" {
bool fn_27_262434(fn_27_262434_Obj* self) {
    if (self->m_ptr) {
        if (self->m_ptr) {
            __dla__FPv((char*)self->m_ptr - 0x10);
        }
    }
    self->unkC = 0;
    self->unk8 = 0;
    self->m_ptr = nullptr;
    return true;
}
}
