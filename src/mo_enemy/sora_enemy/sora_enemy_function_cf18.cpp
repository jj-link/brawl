#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" s32* fn_41_CD5C(s32* obj, s32 index);

class emManager {
public:
    s32 getEnemyCount();
};

s32 emManager::getEnemyCount() {
    s32 count = 0;
    for (u32 i = 0; i < *(u32*)this; i++) {
        s32* entry = fn_41_CD5C((s32*)this, (s32)i);
        if (entry != 0 && *(u8*)entry != 0) {
            count++;
        }
    }
    return count;
}
