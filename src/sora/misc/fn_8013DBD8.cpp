#include <gf/gf_heap_manager.h>
#pragma force_active on
extern "C" {
extern unsigned char lbl_8045E7AC[];
extern unsigned char __vt__8NtBuffer[];
void __dl__FPv(void*);
}
class NtBuffer {
public:
    virtual void fn_8013DBD8();
    virtual void allocBuffer();
    virtual void freeBuffer();
    unsigned int m_size;
    int unk8;
    bool unkC;
    void* m_buf;
};
struct BufferObj : NtBuffer {
    int a, b, c, d;
};
extern "C" void* fn_8013DBD8(BufferObj* self, int flag) {
    if (self) {
        *(void**)self = lbl_8045E7AC;
        if (!self->unkC && self->m_buf)
            gfHeapManager::free(self->m_buf);
        self->m_buf = 0;
        self->m_size = 0;
        self->unk8 = 0;
        self->a = 0;
        self->b = 0;
        self->c = 0;
        self->d = 0;
        if (self) {
            *(void**)self = __vt__8NtBuffer;
            self->freeBuffer();
        }
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}