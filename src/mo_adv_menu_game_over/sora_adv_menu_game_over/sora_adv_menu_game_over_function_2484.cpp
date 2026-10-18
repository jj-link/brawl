#include <mu/adv/mu_adv_game_over.h>
#pragma force_active on

s32 muAdvGameOverTask::getSelection() const {
    s32 index = *reinterpret_cast<const s32*>(
        reinterpret_cast<const u8*>(this) + 0x22C);
    s32 result = *reinterpret_cast<const s32*>(
        reinterpret_cast<const u8*>(this) + 0x234 + index * 4);

    if (result == 1) {
        if (*reinterpret_cast<const u8*>(
                reinterpret_cast<const u8*>(this) + 0x1B0) == 0) {
            result = 5;
        } else {
            muAdvGameOverTask* other =
                *reinterpret_cast<muAdvGameOverTask* const*>(
                    reinterpret_cast<const u8*>(this) + 0x2BC);
            if (other != 0 && other->unk1AC == 1) {
                s32 value = *reinterpret_cast<const s32*>(
                    reinterpret_cast<const u8*>(other) + 0x1B4);
                result = 5;
                if (value == 0) {
                    result = 4;
                }
            }
        }
    }
    return result;
}
