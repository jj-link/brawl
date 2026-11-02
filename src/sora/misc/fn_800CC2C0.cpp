#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern "C" {
extern char g_Network[];
extern int lbl_805A03E8;
extern int lbl_805A03F4;

s32 fn_800CC2C0(u8* arg0) {
    s32 temp_r3 = *(s32*)(arg0 + 0x104c);
    if (temp_r3 != 0) {
        return temp_r3;
    }
    if (g_Network == 0) {
        return 0;
    }
    if (lbl_805A03E8 == 0) {
        return 0;
    }
    switch (lbl_805A03E8) {
    case 1:
    case 2:
    case 3:
        return 1;
    case 4:
        return 2;
    case 6:
        return 1;
    case 7:
        switch (lbl_805A03F4) {
        case 0:
            return 0;
        case 1:
            return 2;
        case 2:
        case 3:
        case 6:
            return 1;
        case 7:
            return 3;
        default:
            return 1;
        }
    case 8:
        return 2;
    case 9:
        return 2;
    case 10:
        return 2;
    case 11:
        return 2;
    case 12:
        return 2;
    case 13:
        return 2;
    case 14:
        return 1;
    }
    return 0;
}
}
