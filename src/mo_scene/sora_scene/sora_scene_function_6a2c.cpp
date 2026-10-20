#include <types.h>
#pragma force_active on

extern "C" void startKeepScreen__17gfKeepFrameBufferFv(void* self);
extern "C" void exit__6gfTaskFv(void* self);
extern "C" void free__13gfHeapManagerFPv(void* ptr);
extern u8* g_gfApplication;

struct Pair {
    void* a;
    void* b;
};

struct Owner {
    u8 pad[0xc];
    Pair* p;
};

extern "C" s32 fn_1_6A2C(Owner* self) {
    if (self->p == nullptr) {
        return 0;
    }
    startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
    exit__6gfTaskFv(self->p->b);
    exit__6gfTaskFv(self->p->a);
    free__13gfHeapManagerFPv(self->p);
    self->p = nullptr;
    return 0;
}
