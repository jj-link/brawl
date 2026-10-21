#pragma force_active on
#include <types.h>

extern s32 fn_8037C720(void);
extern void fn_8037E8B4(void);

s32 fn_8037EEE8(void) {
    if (fn_8037C720() == 0) {
        return 0;
    }
    fn_8037E8B4();
    return 1;
}
