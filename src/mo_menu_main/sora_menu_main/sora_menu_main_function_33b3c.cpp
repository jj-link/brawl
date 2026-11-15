#include <types.h>
#include <mu/mu_msg.h>
#include <mu/mu_object.h>
#pragma force_active on
extern "C" {
void fn_2_3192C(void*, int, int, int, int, int);
void fn_800B3C5C(void*, const void*, int);
extern s8 lbl_2_bss_51;
extern int lbl_2_data_40A0;
extern u8 lbl_2_data_40A4[];
extern u8 lbl_2_rodata_12E0[];
extern u8 lbl_2_rodata_1320[];
}
inline int findChoice(const u8* p, int target) {
    int i = 0;
    while (*p != 13) {
        if (*p == target)
            return i;
        ++p;
        ++i;
    }
    return -1;
}
inline int choiceCount(const u8* p) {
    int len = 0;
    while (*p != 13) {
        ++p;
        ++len;
    }
    return len;
}
extern "C" void fn_2_33B3C(void* self) {
    u8* obj = *(u8**)((char*)self + 0x40);
    int b4 = *(int*)(obj + 0xB4);
    int index = *(int*)(obj + 0x1AC);
    const u8** tbl = *(const u8***)(lbl_2_rodata_12E0 + b4 * 16);
    u8* target = obj + index;
    int n = findChoice(*(const u8**)((char*)tbl + index * 4), target[0x19C]);
    if (n < 0)
        n = 0;
    *(int*)(obj + 0x1B0) = n;
    int choice = *(u8*)(*(u8**)((char*)self + 0x40) + index + 0x19C);
    fn_2_3192C(self, b4, index, index + 5, choice, 1);
    (*(MuMsg**)(*(u8**)((char*)self + 0x40) + 0x164))->printIndex(1, ((u8 (*)[2])lbl_2_rodata_1320)[choice][1], 0);
    int flags = 0;
    if (n > 0)
        flags |= 1;
    if (n < choiceCount(*(const u8**)((char*)*(const u8***)(lbl_2_rodata_12E0 + b4 * 16) + index * 4)) - 1)
        flags |= 2;
    (*(MuObject**)(*(u8**)((char*)self + 0x40) + 0x68))->setFrameVisible((float)flags);
    if (lbl_2_bss_51 == 0) {
        *(int*)(lbl_2_data_40A4 + 0xC) = lbl_2_data_40A0;
        *(int*)(lbl_2_data_40A4 + 0x20) = lbl_2_data_40A0;
        *(int*)(lbl_2_data_40A4 + 0x34) = lbl_2_data_40A0;
        lbl_2_bss_51 = 1;
    }
    fn_800B3C5C(*(void**)(*(u8**)((char*)self + 0x40) + 0x68), lbl_2_data_40A4, 0);
}