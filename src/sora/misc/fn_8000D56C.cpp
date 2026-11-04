#include <types.h>

#pragma force_active on

struct gfSceneRoot {
    u8 pad[0x40];
    void* field40;
    u8 pad44[8];
    u32 field4C;
    u8 pad50[4];
    void* field54;
    u32 field58;
};

extern "C" void fn_801AC6EC(void*);
extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);

extern "C" void removeResAnmScn__11gfSceneRootFv(void* self) {
    gfSceneRoot* s = (gfSceneRoot*)self;
    if (s->field54 != nullptr) {
        fn_801AC6EC(s->field40);
        Destroy__Q34nw4r3g3d6G3dObjFv(s->field54);
    }
    if (s->field4C != 0) {
        s->field4C = 0;
    }
    s->field54 = nullptr;
    s->field58 = 0;
}
