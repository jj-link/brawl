#include <mu/menu.h>
#pragma force_active on

extern "C" {
extern char lbl_40_data_17DC0[];
void fn_800FABEC(void*);
void fn_800FAC58(void*, const char*, int, int);
}

extern "C" void fn_40_4410C(void* object)
{
    char* p = (char*)object;
    int a = *(int*)(p + 0x1b0);
    char* s = lbl_40_data_17DC0 + 0x50;

    fn_800FABEC(p + 0x145c);
    int zero = 0;
    *(int*)(p + 0x1448) = zero;
    *(char*)(p + 0x1474) = zero;
    fn_800FAC58(p + 0x145c, s, a, 0);

    a = *(int*)(p + 0x1b0);
    s = lbl_40_data_17DC0 + 0x68;
    fn_800FABEC(p + 0x1490);
    *(int*)(p + 0x147c) = zero;
    *(char*)(p + 0x14a8) = zero;
    fn_800FAC58(p + 0x1490, s, a, 0);

    a = *(int*)(p + 0x1b0);
    s = lbl_40_data_17DC0 + 0x90;
    fn_800FABEC(p + 0x14c4);
    *(int*)(p + 0x14b0) = zero;
    *(char*)(p + 0x14dc) = zero;
    fn_800FAC58(p + 0x14c4, s, a, 0);

    a = *(int*)(p + 0x1b0);
    s = lbl_40_data_17DC0 + 0xb0;
    fn_800FABEC(p + 0x14f8);
    *(int*)(p + 0x14e4) = zero;
    *(char*)(p + 0x1510) = zero;
    fn_800FAC58(p + 0x14f8, s, a, 0);

    fn_800FAC58(p + 0x1518, lbl_40_data_17DC0 + 0xd0,
                *(int*)(p + 0x1b0), 0);
    s = lbl_40_data_17DC0 + 0xf0;
    fn_800FAC58(p + 0x1530, s,
                *(int*)(p + 0x1b0), 0);
    s = lbl_40_data_17DC0 + 0x10c;
    fn_800FAC58(p + 0x1548, s,
                *(int*)(p + 0x1b0), 0);
    muMenu::loadMenuSound();
}
