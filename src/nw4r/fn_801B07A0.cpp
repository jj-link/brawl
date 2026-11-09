#pragma force_active on
#include <types.h>

extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(void*, u32);

struct CopiedVisObj {
    char pad[0xE8];
    void* mdl;
};

struct VisAcc {
    CopiedVisObj* unk0;
    u32 pad4;
    u8* unk8;
};

extern "C" bool fn_801B07A0(const VisAcc* self) {
    if (self->unk0 != 0) {
        if (self->unk8 != 0) {
            return *self->unk8 != 0;
        }
        void* mdl = self->unk0->mdl;
        void* node = GetResNode__Q34nw4r3g3d6ResMdlCFUl(&mdl, self->pad4);
        if (node != 0) {
            return (((u32)*(u32*)((u8*)node + 0x14)) >> 8) & 1;
        }
        return false;
    }
    return false;
}
