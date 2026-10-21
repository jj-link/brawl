#include <types.h>
#pragma force_active on

struct CopiedMatAccess {
    void* m_resMat;
    s32 m_index;
    char pad[0x1C];
    s32 m_unk24;
};

extern "C" s32 GetResMatTevColor__Q44nw4r3g3d6ScnMdl15CopiedMatAccessFb(CopiedMatAccess* self, bool arg) {
    void* resMat = self->m_resMat;
    if (resMat != NULL && self->m_unk24 != 0) {
        if (arg) {
            s32* ptr = (s32*)(*(s32**)((char*)resMat + 0x140));
            ptr[self->m_index] |= 0x100;
        }
        return self->m_unk24;
    }
    return 0;
}
