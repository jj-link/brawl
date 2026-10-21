#include <types.h>
#pragma force_active on

extern "C" {
void* getInstance__14gfSceneManagerFv();
s32 fn_2_39F9C(void*, s32);
void fn_801E9A30(s32);
void fn_801E98B0();
void VIWaitForRetrace();
void fn_8003D4E8(void*, s32);
extern void** lbl_1_data_4250;

s32 fn_1_CDEC(void* self) {
    char* obj = *(char**)((char*)self + 0x35C);
    if (*(s32*)(obj + 0x1AC) == 1) {
        s32 index = *(s32*)(obj + 0x208);
        if (index == -1) {
            char* mgr = (char*)getInstance__14gfSceneManagerFv();
            *(s32*)(mgr + 0x284) = 0;
            *(s32*)(mgr + 0x288) = 2;
        } else {
            s32 value = fn_2_39F9C(obj, index);
            fn_801E9A30(1);
            fn_801E98B0();
            VIWaitForRetrace();
            fn_8003D4E8(lbl_1_data_4250[index], value);
        }
    }
    return 0;
}
}
