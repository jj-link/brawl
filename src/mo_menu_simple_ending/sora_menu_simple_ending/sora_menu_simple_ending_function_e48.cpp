#include <types.h>
#pragma force_active on

extern "C" {
void fn_8000D7B8(void*);
void fn_8018E808(void*);
void fn_8007EA78(void*, s32);
}

extern void* g_gfSceneRoot;

struct SceneRawPad {
    u8 raw[0x5c];
};

struct SceneObj : SceneRawPad {
    virtual void vfn0(s32);
    virtual void vfn1();
    virtual void vfn2();
};

extern "C" void fn_19_E48(void* self) {
    u8* p = (u8*)self;
    fn_8000D7B8(g_gfSceneRoot);
    fn_8018E808(p + 0x40);
    fn_8018E808(p + 0x44);
    SceneObj* obj = *(SceneObj**)(p + 0x48);
    if (obj != nullptr) {
        obj->vfn0(1);
    }
    void* h = *(void**)(p + 0x9ac);
    *(void**)(p + 0x48) = nullptr;
    fn_8007EA78(h, 1);
    *(void**)(p + 0x9ac) = nullptr;
}
