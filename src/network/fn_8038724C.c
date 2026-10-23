#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern s16 SOHtoNs(u16);
extern u16 SONtoHs(u16);
extern s32 closesocket(s32);
extern s32 fn_8035A590(s32);
extern s32 *fn_8035A598(s32, s32);
extern u32 fn_8035D728(void);
extern s32 sendto(s32, void *, s32, s32, void *, s32);
extern s32 lbl_805A10F0;

void fn_8038724C(u8 *arg0, u8 *arg1, u8 *arg2) {
    u8 sp8[8];
    s32 var_r31;
    s32 *var_r30;
    s32 temp_r30;
    s32 *temp_r3;
    u16 sonv;
    u8 k;
    s32 sock;

    switch ((s32)arg1[7]) {
    case 1:
        k = arg1[12];
        if (k <= 3) {
            *(s32 *)(arg0 + 0x14 + k * 4) = 1;
            if (*(s32 *)(arg0 + 0x10) == 0 && *(s32 *)(arg0 + 0x18) != 0 && *(s32 *)(arg0 + 0x1C) != 0 &&
                *(s32 *)(arg0 + 0x20) != 0 &&
                (*(s32 *)(arg0 + 4) == -1 || *(s32 *)(arg0 + 0x14) != 0)) {
                *(s32 *)(arg0 + 0x10) = 1;
                *(u32 *)(arg0 + 0x2C) = fn_8035D728() + 0xEA60;
                ((void (*)(s32, s32))*(s32 *)(arg0 + 0x38))(*(s32 *)(arg0 + 0x10), *(s32 *)(arg0 + 0x40));
            }
        }
        break;
    case 2:
        arg1[7] = 3;
        sonv = SONtoHs(*(u16 *)(arg2 + 2));
        temp_r30 = *(s32 *)(arg2 + 4);
        sock = *(s32 *)arg0;
        sp8[1] = 2;
        *(s16 *)(sp8 + 2) = SOHtoNs(sonv);
        *(s32 *)(sp8 + 4) = temp_r30;
        sendto(sock, arg1, 0x15, 0, sp8, 8);
        break;
    case 14:
        *(s32 *)(arg0 + 0x10) = 6;
        ((void (*)(s32, s32, u8 *, s32))*(s32 *)(arg0 + 0x3C))(
            *(s32 *)(arg0 + 0x44), *(s32 *)(arg0 + 0x48), arg0 + 0x4C, *(s32 *)(arg0 + 0x40));
        if (*(s32 *)(arg0 + 4) == -1) {
            *(s32 *)arg0 = -1;
        }
        var_r31 = *(s32 *)(arg0 + 8);
        if (lbl_805A10F0 == 0) {
            var_r30 = 0;
        } else {
            temp_r30 = 0;
            while (temp_r30 < fn_8035A590(lbl_805A10F0)) {
                temp_r3 = fn_8035A598(lbl_805A10F0, temp_r30);
                if (temp_r3[2] == var_r31) {
                    var_r30 = temp_r3;
                    goto found;
                }
                temp_r30++;
            }
            var_r30 = 0;
        }
found:
        if (var_r30 != 0) {
            if (var_r30[0] != -1) {
                closesocket(var_r30[0]);
            }
            var_r30[0] = -1;
            var_r30[4] = 4;
        }
        break;
    }
}
