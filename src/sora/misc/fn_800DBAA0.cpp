#include <types.h>
#include <gf/gf_resource_loader.h>
#pragma force_active on

struct FooObj {
    u8 m_flags;
    u8 m_pad[0xC4 - 1];
    gfResourceLoader* m_loader;
};

extern "C" void fn_800DBB10(FooObj* self);

extern "C" s32 fn_800DBAA0(FooObj* self) {
    if ((u32)((self->m_flags >> 6) & 1) == 1) {
        return 1;
    }
    if (self->m_loader->isLoaded() == 0) {
        return 0;
    }
    fn_800DBB10(self);
    self->m_flags |= 0x40;
    return 1;
}
