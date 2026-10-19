#include <st/module.h>
#pragma force_active on

struct nw4r3g3dResFile {
    char pad0[0x40];
    void* p0;
};

extern "C" {
extern u32 GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(const void*);

extern "C" int fn_72_1A98(nw4r3g3dResFile* self) {
    if (self->p0 != 0) {
        return GetResMdlNumEntries__Q34nw4r3g3d7ResFileCFv(&self->p0);
    }
    return 0;
}
}
