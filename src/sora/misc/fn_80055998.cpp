#include <gm/gm_global.h>
#pragma force_active on
struct Data { unsigned int a, b, c, d; };
extern "C" {
extern unsigned char lbl_8042C4B8[];
extern unsigned char lbl_804977E0[];
unsigned int fn_8004F3BC(unsigned char);
Data* fn_80055998(unsigned int arg) {
    int index;
    switch (arg) {
    default: index = 0; break;
    case 1: index = 1; break;
    case 2: index = 2; break;
    case 3: index = 3; break;
    case 4: index = 4; break;
    case 5: index = 5; break;
    case 6: index = 6; break;
    case 7: index = 7; break;
    case 8: index = 8; break;
    case 9: index = 9; break;
    case 11: index = 10; break;
    case 12: index = 11; break;
    case 13: index = 12; break;
    case 14: index = 13; break;
    case 19: index = 14; break;
    case 20: index = 15; break;
    case 21: index = 16; break;
    case 22: index = 17; break;
    case 23: index = 18; break;
    case 24: index = 19; break;
    case 25: index = 20; break;
    case 28: index = 21; break;
    case 29: index = 22; break;
    case 30: index = 23; break;
    case 31: index = 24; break;
    case 32: index = 25; break;
    case 33: index = 26; break;
    case 34: index = 27; break;
    case 35: index = 28; break;
    case 36: index = 29; break;
    case 37: index = 30; break;
    case 41: index = 31; break;
    case 42: index = 32; break;
    case 43: index = 33; break;
    case 44: index = 34; break;
    case 45: index = 35; break;
    case 46: index = 36; break;
    case 47: index = 37; break;
    case 48: index = 38; break;
    case 49: index = 39; break;
    case 50: index = 40; break;
    case 51: index = 41; break;
    case 53: index = 42; break;
    }
    Data* result = (Data*)lbl_804977E0;
    result->a = ((Data*)lbl_8042C4B8)[index].a;
    result->b = ((Data*)lbl_8042C4B8)[index].b;
    result->c = ((Data*)lbl_8042C4B8)[index].c;
    result->d = ((Data*)lbl_8042C4B8)[index].d;
    if (((unsigned char*)g_GameGlobal->m_modeMelee)[0x13] != 1)
        result->a &= ~0x4000;
    if (fn_8004F3BC(0) == 0) result->d &= ~0x8;
    if (fn_8004F3BC(1) == 0) result->d &= ~0x80000;
    if (fn_8004F3BC(2) == 0) result->d &= ~0x800000;
    if (fn_8004F3BC(3) == 0) result->d &= ~0x2;
    if (fn_8004F3BC(4) == 0) result->d &= ~0x4;
    if (fn_8004F3BC(5) == 0) result->d &= ~0x200000;
    return result;
}
}