#include <types.h>
#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on
struct Model {
    char pad0[0xE8];
    void* data;
    char pad1[0x18];
    u32 flags;
};
extern "C" void fn_800479A8(Model* self, s8* out) {
    nw4r::g3d::ResMdl mdl(self->data);
    u32 count = mdl.GetResNodeNumEntries();
    for (int i = 0; i < count; ++i) {
        *out++ = 0;
    }
    self->flags &= ~4U;
}
