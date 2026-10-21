#include <types.h>
#pragma force_active on

struct NtBufferObj {
    void* vtable;
    u32 m_size;
    s32 unk8;
    bool unkC;
    void* m_buf;
};

extern "C" unsigned char __vt__8NtBuffer[];

extern "C" void fn_8013DB48(NtBufferObj* self) {
    self->m_size = 0;
    self->vtable = __vt__8NtBuffer;
    self->unk8 = 0;
    self->unkC = 0;
    self->m_buf = nullptr;
}
