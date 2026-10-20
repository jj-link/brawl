#pragma force_active on
#include <types.h>

extern "C" {
void fn_8000D7B8(void*);
void fn_8018E808(void*);
void fn_8007EA78(void*, s32);
}

extern void* g_gfSceneRoot;

class ObjBase {
    u8 pad[0x5C];
};

class Obj : public ObjBase {
public:
    virtual void vfn0(s32);
};

extern "C" void fn_24_1650(void* self) {
    u8* p = (u8*)self;
    fn_8000D7B8(g_gfSceneRoot);
    fn_8018E808(p + 0x48);
    fn_8018E808(p + 0x4C);
    Obj* obj = *(Obj**)(p + 0x50);
    if (obj != nullptr) {
        obj->vfn0(1);
    }
    *(void**)(p + 0x50) = 0;
    void* h = *(void**)(p + 0x54);
    fn_8007EA78(h, 1);
    *(void**)(p + 0x54) = 0;
}
