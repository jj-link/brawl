#include <types.h>
#pragma force_active on

extern "C" void startKeepScreen__17gfKeepFrameBufferFv(void*);
extern "C" void exit__6gfTaskFv(void*);
extern "C" void free__13gfHeapManagerFPv(void*);
extern "C" void fn_8000D7B8(void*);
extern "C" void removeResAnmScn__11gfSceneRootFv(void*);
extern "C" u8* g_gfApplication;
extern "C" void* g_gfSceneRoot;

struct SubObj {
    void* f0;
    void* f4;
    void* f8;
};

struct Self {
    u8 pad[8];
    SubObj* f8;
};

extern "C" s32 fn_1_6CBC(Self* self) {
    startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
    if (self->f8 == nullptr) {
        return 0;
    }
    exit__6gfTaskFv(self->f8->f4);
    exit__6gfTaskFv(self->f8->f8);
    free__13gfHeapManagerFPv(self->f8);
    self->f8 = nullptr;
    fn_8000D7B8(g_gfSceneRoot);
    removeResAnmScn__11gfSceneRootFv(g_gfSceneRoot);
    return 0;
}
