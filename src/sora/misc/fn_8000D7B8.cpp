#include <types.h>
#include <nw4r/g3d/g3d_obj.h>

#pragma force_active on

struct SceneRoot {
    u8 pad00[0x44];
    void* field44;
    u8 pad48[8];
    u32 field50;
    u8 pad54[8];
    nw4r::g3d::G3dObj* field5C;
};

extern "C" void fn_801AC6EC(void*);

extern "C" void fn_8000D7B8(SceneRoot* self) {
    if (self->field5C != 0) {
        fn_801AC6EC(self->field44);
        self->field5C->Destroy();
    }
    if (self->field50 != 0) {
        self->field50 = 0;
    }
    self->field5C = 0;
}
