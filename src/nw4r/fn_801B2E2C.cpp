#include <types.h>
#pragma force_active on

extern "C" u32 GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(void*);
extern "C" void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(void*, u32);

struct ResObj {
    u8 pad0[0xE8];
    u32 mdl;
    u8 pad1[0x13C - 0xEC];
    u32 flag;
    u8 pad2[8];
    u8* flags;
};

extern "C" void fn_801B2E2C(void* self_) {
    ResObj* p = (ResObj*)self_;
    u32 sp8;
    sp8 = p->mdl;
    u32 count = GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(&sp8);
    if (p->flags) {
        u32 i = 0;
        if (count) {
            while (i < count) {
                void* node = GetResNode__Q34nw4r3g3d6ResMdlCFUl(&sp8, i);
                u32 nv;
                if (node)
                    nv = (*(u32*)((u8*)node + 0x14) >> 8) & 1;
                else
                    nv = 0;
                if (nv)
                    p->flags[i] = 1;
                else
                    p->flags[i] = 0;
                i++;
            }
        }
    }
    p->flag &= ~1;
}
