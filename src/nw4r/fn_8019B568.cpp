#include <types.h>
#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on

using namespace nw4r::g3d;

struct Owner {
    char pad[0x14];
    u16* entries;
};

static inline ResNodeData* objOf(char* base, s32 off) {
    if (off != 0)
        return (ResNodeData*)(base + off);
    return 0;
}

static inline u32 getEndCount(ResMdl* mdl, u32 idx) {
    ResNodeData* n = mdl->GetResNode(idx).ptr();
    ResNodeData* c = objOf((char*)n, *(s32*)((char*)n + 0x64));
    while (c == 0) {
        n = objOf((char*)n, *(s32*)((char*)n + 0x5c));
        if (n == 0)
            break;
        c = objOf((char*)n, *(s32*)((char*)n + 0x64));
    }
    if (c != 0) {
        if (c != 0)
            return c->m_nodeIndex;
        return 0;
    }
    return mdl->GetResNodeNumEntries();
}

extern "C" void fn_8019B568(Owner* self, ResMdl* src, u32 idx, s32 mode) {
    switch (mode) {
    case 1: {
        ResMdl mdl = *src;
        u32 count = getEndCount(&mdl, idx);
        for (u32 i = idx; i < count; i++) {
            u16* e = self->entries;
            e[i] = 0x8000;
        }
        break;
    }
    case 0:
        self->entries[idx] = 0x8000;
        break;
    }
}
