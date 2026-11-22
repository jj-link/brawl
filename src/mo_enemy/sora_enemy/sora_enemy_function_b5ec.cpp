#include <em/em_manager.h>
#include <types.h>
#pragma force_active on

extern "C" double lbl_41_rodata_60;
extern const float lbl_41_rodata_18;

extern "C" int fn_41_B5EC(void*, EnemyKind kind, u32 value, float factor) {
    u32 total = emManager::getInstance()->getEnemyCount();
    u32 kind_count = emManager::getInstance()->getEnemyCountFromKind(kind);
    u32 difference = total - kind_count;
    float remaining = (float)value - (float)difference * factor;

    if (remaining <= lbl_41_rodata_18)
        return 0;

    return (remaining <= (float)kind_count) ? 0 : 1;
}
