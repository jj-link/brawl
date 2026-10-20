#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__9itManagerFv();
void fn_27_2A96F4(void* mgr, int a, int b);
void fn_27_1D494C(void* a, int b);
u8 lbl_27_data_270B8[];

u8* fn_27_11110C(u8* obj, int delFlag) {
    if (obj != NULL) {
        *(void**)(obj + 0xC) = lbl_27_data_270B8;
        u8 i;
        u8* base;
        for (i = 0; i < (base = *(u8**)obj)[0x73]; i++) {
            fn_27_2A96F4(getInstance__9itManagerFv(), base[0x74 + i], 0);
        }
        base[0x73] = 0;
        if ((u8*)(obj + 0x10) != NULL) {
            fn_27_1D494C(obj + 0x848, -1);
        }
        if (delFlag > 0) {
            delete obj;
        }
    }
    return obj;
}
}
