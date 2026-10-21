#include <types.h>
#pragma force_active on

enum emKind { emKind_Dummy };

class emInfoBase {
public:
    virtual void vf0();
    virtual u32 vf1(u32 kind);
};

extern "C" emInfoBase* getInstance__6emInfoFv();
extern "C" void* fn_41_D5A0(void* self, u32 idx);

class emManager {
public:
    char pad0[0xC];
    u32 unkC;
    s32 getPreloadArchiveCountFromKind(emKind kind);
};

s32 emManager::getPreloadArchiveCountFromKind(emKind kind) {
    s32 count = 0;
    if (getInstance__6emInfoFv()->vf1((u32)kind) == 1) {
        return 0;
    }
    for (u32 i = 0; i < unkC; i++) {
        u8* e = (u8*)fn_41_D5A0(this, i);
        if (e != 0 && e[0] != 0 && *(s32*)(e + 0x14) != 0 && *(s32*)(e + 4) == (s32)kind) {
            count++;
        }
    }
    return count;
}
