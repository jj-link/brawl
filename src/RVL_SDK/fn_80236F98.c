#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern char lbl_8047FE30[];
extern u8 lbl_80529AC8[];
extern u8 lbl_805A0D30;
extern void *fn_8022EE58(unsigned short size);
extern void fn_802319FC(u32 a, void *b, void *c);
extern void fn_802324E0(void *arg);
extern void fn_80232780(void *arg);

void fn_80236F98(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 i;
    u32 sp8;
    u16 var_r31;
    u8 *temp;
    char *base;
    void *var_r5;

    base = lbl_8047FE30;
    var_r31 = 0x1710;
    sp8 = arg3;
    if (lbl_805A0D30 >= 5) {
        switch (arg1) {
        case 0:
            var_r5 = base + 0x3AC;
            break;
        case 1:
            var_r5 = base + 0x3C0;
            break;
        case 2:
            var_r5 = base + 0x3D4;
            break;
        case 3:
            var_r5 = base + 0x3EC;
            break;
        case 4:
            var_r5 = base + 0x404;
            break;
        case 5:
            var_r5 = base + 0x41C;
            break;
        case 6:
            var_r5 = base + 0x434;
            break;
        case 7:
            var_r5 = base + 0x44C;
            break;
        case 8:
            var_r5 = base + 0x464;
            break;
        default:
            var_r5 = base + 0x47C;
            break;
        }
        fn_802319FC(0x504, base + 0x490, var_r5);
    }
    switch (arg1) {
    case 0:
        var_r31 = 0x1702;
        break;
    case 1:
        var_r31 = 0x1703;
        break;
    case 3:
        var_r31 = 0x1704;
        break;
    case 7:
        var_r31 = 0x1706;
        break;
    case 5:
        var_r31 = 0x1705;
        break;
    case 4:
    case 6:
        fn_80232780(&sp8);
        break;
    case 8:
        for (i = 0; i < 16; i++) {
            if (arg0 == lbl_80529AC8[(u8)i * 0x20 + 0x26]) {
                lbl_80529AC8[(u8)i * 0x20 + 0x27] = 1;
                break;
            }
        }
        break;
    }
    if (var_r31 != 0x1710) {
        temp = (u8 *)fn_8022EE58(0x18);
        if (temp != 0) {
            *(u16 *)(temp + 0) = var_r31;
            *(u16 *)(temp + 6) = arg0;
            *(u32 *)(temp + 8) = arg2;
            *(u32 *)(temp + 0xC) = sp8;
            fn_802324E0(temp);
        }
    }
}
