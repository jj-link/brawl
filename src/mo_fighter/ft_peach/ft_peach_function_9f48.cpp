#include <sr/sr_common.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_57F78(void* member);

void fn_103_9F48(void* object) {
    s32 i;
    for (i = 0; i < 2; i++) {
        fn_27_57F78((u8*)object + i * 8 + 4);
    }
}
}
