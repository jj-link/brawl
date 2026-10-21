#include <types.h>
#pragma force_active on

enum emKind { emKind_dummy = 0 };

class emInfoBase {
public:
    virtual void vf0();
    virtual u32 getNodeNum(emKind kind);
};

extern "C" emInfoBase* getInstance__6emInfoFv();
extern "C" u8* fn_41_CD5C(s32* obj, s32 index);

class emManager {
public:
    u32 unk0;
    s32 getEnemyCountFromKind(emKind kind);
};

s32 emManager::getEnemyCountFromKind(emKind kind) {
    s32 count = 0;
    if (getInstance__6emInfoFv()->getNodeNum(kind) == 1) {
        return 0;
    }
    for (u32 i = 0; i < this->unk0; i++) {
        u8* entry = fn_41_CD5C((s32*)this, (s32)i);
        if (entry != 0 && *entry != 0) {
            s32* sub = *(s32**)(entry + 0x14);
            if (sub != 0 && (s32)kind == sub[0x2B]) {
                count++;
            }
        }
    }
    return count;
}
