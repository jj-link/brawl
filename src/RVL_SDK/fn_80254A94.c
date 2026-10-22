#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

void *fn_8022EFF8(int);
s8 fn_802560DC(int, void *);
void fn_80256858(void *, void *);

void fn_80254A94(void *arg0, int arg1) {
    u8 *temp_r31;
    u8 *temp_r30;
    int flag;
    int var_r3;

    var_r3 = 1;
    if (((u8 *)arg0)[0x6D] == 0) {
        var_r3 = 0;
    }
    flag = (var_r3 << 1) & 0xFE;
    temp_r30 = (u8 *)fn_8022EFF8(2);
    if (temp_r30 != 0) {
        temp_r31 = temp_r30 + 0x11;
        *(u16 *)(temp_r30 + 4) = 9;
        temp_r31[0] = (u8)(flag | 1 | ((arg1 << 2) & 0x3FC));
        temp_r31[1] = 0x3F;
        temp_r31[2] = 1;
        temp_r31[3] = fn_802560DC(3, temp_r31);
        *(u16 *)(temp_r30 + 2) = 4;
        fn_80256858(arg0, temp_r30);
    }
}
