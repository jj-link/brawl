#include <types.h>
#include <ft/ft_slot_manager.h>
#pragma force_active on

extern "C" u32 fn_27_122218(void* self, s32 a, u32 b);

extern "C" u32 fn_27_14583C(void* self, s32 a, u32 b) {
    return fn_27_122218(g_ftSlotManager, a, b);
}
