#include <types.h>
#pragma force_active on

extern "C" {
void fn_800BA364(void* item, u32 flags);

void fn_18_1754(char* self, u32 flags) {
    char* item = self + 0x48;
    for (u32 i = 0; i < 9; i++) {
        fn_800BA364(item, flags);
        item += 0xa8;
    }
}
}
