#include <types.h>
#pragma force_active on

extern "C" {
void exit__6gfTaskFv(void*);
void fn_8000D7B8(void*);
void fn_8018E808(void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void free__13gfHeapManagerFPv(void*);
void release__14gfFileIOHandleFv(void*);
void startKeepScreen__17gfKeepFrameBufferFv(void*);
extern void* g_gfSceneRoot;
extern void* g_gfApplication;
}

struct SceneObj {
    u8 unk0[8];
    void* f8;
    void* fC;
    u8 unk10[4];
    u8 f14[4];
    u8 f18[4];
};

extern "C" s32 fn_1_1CBB0(void* p) {
    SceneObj* self = (SceneObj*)p;
    if (self->f8 != 0) {
        exit__6gfTaskFv(self->f8);
        self->f8 = 0;
    }
    if (self->fC != 0) {
        exit__6gfTaskFv(self->fC);
        self->fC = 0;
    }
    fn_8000D7B8(g_gfSceneRoot);
    fn_8018E808(self->f18);
    free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(self->f14));
    release__14gfFileIOHandleFv(self->f14);
    startKeepScreen__17gfKeepFrameBufferFv((u8*)g_gfApplication + 0xD0);
    return 0;
}
