#include <types.h>
#pragma force_active on

extern "C" void* getInstance__9itManagerFv();
extern "C" void fn_27_2A96F4(void* mgr, int a, int b);

extern "C" {
void fn_27_111CF8(u8** p) {
    u8 i = 0;
    while (i < (*p)[0x73]) {
        fn_27_2A96F4(getInstance__9itManagerFv(), (*p)[0x74 + i], 0);
        i++;
    }
    (*p)[0x73] = 0;
}
}
