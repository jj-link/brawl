#pragma force_active on
typedef unsigned char u8;

extern char lbl_80529AC8[];
extern u8 lbl_8059EDF0[8];
extern char lbl_8047FF08[];
extern char lbl_8047FF28[];
extern u8 lbl_805A0D30;

typedef void (*CB3)(int, void *, void *);

void fn_802319FC(int, void *, u8);
void fn_80232034(u8 *, const u8 *);
void fn_80237600(void *, int, int);
void fn_80237C90(void *);
void fn_80237E20(void);
void fn_80247D90(u8);
u8 fn_80247E58(u8);
void fn_8024809C(void *, u8);
extern void *memset(void *, int, unsigned long);

void fn_802360CC(u8 *arg0, u8 *arg1)
{
    u8 buf[8];
    u8 var_r31;
    u8 temp_r3;

    if (lbl_805A0D30 >= 5) {
        fn_802319FC(0x504, lbl_8047FF08, *arg1);
    }
    memset(buf, 0, 8);
    buf[7] = arg0[0x16];
    fn_80232034(buf, arg0 + 8);
    var_r31 = *arg1;
    if (var_r31 == 0) {
        if (arg0[0x19] == 0) {
            fn_8024809C(lbl_8059EDF0, arg0[0x14]);
            temp_r3 = fn_80247E58(arg0[0x16]);
            var_r31 = temp_r3;
            if (temp_r3 != 0) {
                if (lbl_805A0D30 >= 5) {
                    fn_802319FC(0x504, lbl_8047FF28, temp_r3);
                }
                fn_80247D90(arg0[0x16]);
            }
        } else {
            fn_80237600(arg0, 0x170B, 0);
        }
    }
    if (var_r31 != 0) {
        if (*arg1 == 0xFF) {
            buf[6] = 0xA;
        } else {
            buf[6] = 7;
        }
        (*(CB3 *)(lbl_80529AC8 + 0x224))(2, buf, lbl_80529AC8);
        fn_80237600(arg0, 0x1701, 0);
        if (arg0[0x15] == 0 && arg0[0x19] == 0) {
            fn_80237C90(arg0);
        }
        fn_80237E20();
    }
}
