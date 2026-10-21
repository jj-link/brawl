#include <types.h>
#pragma force_active on

extern "C" {
void exit__6gfTaskFv(void*);
void startKeepScreen__17gfKeepFrameBufferFv(void*);
extern void* g_gfApplication;
}

struct SceneObj {
    u8 unk0[8];
    void* f8;
    void* fC;
    void* f10;
    void* f14;
    void* f18;
};

extern "C" s32 fn_1_1E4D0(void* p) {
    SceneObj* self = (SceneObj*)p;
    if (self->f8 != 0) {
        exit__6gfTaskFv(self->f8);
        self->f8 = 0;
    }
    if (self->fC != 0) {
        exit__6gfTaskFv(self->fC);
        self->fC = 0;
    }
    if (self->f10 != 0) {
        exit__6gfTaskFv(self->f10);
        self->f10 = 0;
    }
    if (self->f14 != 0) {
        exit__6gfTaskFv(self->f14);
        self->f14 = 0;
    }
    if (self->f18 != 0) {
        exit__6gfTaskFv(self->f18);
        self->f18 = 0;
    }
    startKeepScreen__17gfKeepFrameBufferFv((u8*)g_gfApplication + 0xD0);
    return 0;
}
