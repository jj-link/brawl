#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

extern char lbl_80529AC8[];
typedef void (*CB2)(int, void *);

void fn_80232034(u8 *, const u8 *);
void fn_8022E900(u8, u8, u16, u8);
void fn_80232138(int, u8, void *);
u8 fn_80247EBC(u8, u8, u8, u8, u8, u8);
extern void *memset(void *, int, unsigned long);

void fn_8023629C(u8 *arg0, u8 *arg1)
{
    u8 buf[8];
    u8 var_r30;
    u8 temp_r3;

    if (arg1 != 0) {
        var_r30 = (u8)*(u16 *)(arg1 + 6);
    } else {
        var_r30 = arg0[0x16];
    }
    memset(buf, 0, 8);
    buf[7] = var_r30;
    fn_80232034(buf, arg0 + 8);
    *(u8 *)(lbl_80529AC8 + 0x22D) = *(u8 *)(lbl_80529AC8 + 0x22D) + 1;
    fn_8022E900(arg0[0x16], arg0[0x13], *(u16 *)(arg0 + 0xE), arg0[0x15]);
    fn_80232138(0x17, arg0[0x15], arg0 + 8);
    if (arg0[0x1B] != 0) {
        temp_r3 = fn_80247EBC(var_r30, 7, arg0[0x1B], 0, 0, 0);
        buf[6] = temp_r3;
        if (temp_r3 != 0) {
            buf[6] = 8;
            (*(CB2 *)(lbl_80529AC8 + 0x224))(2, buf);
        } else {
            *(u16 *)(arg0 + 0x10) = 2;
        }
    } else {
        arg0[0x1A] = 1;
        (*(CB2 *)(lbl_80529AC8 + 0x224))(2, buf);
    }
    arg0[0x19] = 0;
}
