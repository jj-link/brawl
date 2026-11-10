#pragma force_active on
#include <types.h>

extern "C" {
void* getInstance__9itManagerFv();
void fn_27_2A96F4(void* mgr, int a, int b);

void fn_27_111C4C(void* obj, u32 id) {
    u8* base = *(u8**)obj;
    u8 count = base[0x73];
    u8 i = 0;
    for (; i < count; i++) {
        if (id == base[0x74 + i]) {
            break;
        }
    }
    if (i != count) {
        int n;
        for (; i < (base = *(u8**)obj)[0x73] - 1; i++) {
            base[0x74 + i] = base[0x75 + i];
        }
        n = (*(u8**)obj)[0x73] - 1;
        base = *(u8**)obj;
        base[0x73] = n;
        fn_27_2A96F4(getInstance__9itManagerFv(), id, 0);
    }
}
}
