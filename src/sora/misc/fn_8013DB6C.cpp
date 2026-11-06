#include <nt/nt_report.h>
#pragma force_active on

extern "C" unsigned char __vt__8NtBuffer[];
extern "C" void __dl__FPv(void*);

struct NtBufferDispatch : NtBuffer {
    virtual void freeBuffer() = 0;
};

extern "C" NtBuffer* fn_8013DB6C(NtBuffer* self, int flag) {
    if (self) {
        if (self) {
            *(void**)self = __vt__8NtBuffer;
            static_cast<NtBufferDispatch*>(self)->freeBuffer();
        }
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}
