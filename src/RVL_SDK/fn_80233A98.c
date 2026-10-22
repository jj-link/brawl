#pragma force_active on
typedef unsigned char u8;

extern void fn_80232034(u8 *dst, const u8 *src);
extern u8 *fn_8023C7FC(u8 *p);
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern int lbl_80529918[];

typedef struct {
    u8 sp8[6];
    u8 spE[3];
    u8 sp11;
    u8 sp12;
    u8 pad[0xF9];
} Locals;

void fn_80233A98(u8 *arg0) {
    Locals s;
    u8 *temp_r3;

    fn_80232034(s.sp8, arg0 + 2);
    memcpy(s.spE, arg0 + 8, 3);
    s.sp11 = arg0[0xE];
    temp_r3 = fn_8023C7FC(arg0 + 2);
    if (temp_r3 != 0) {
        s.sp12 = 0;
    }
    ((void (*)(int, u8 *))lbl_80529918[0])(0, s.sp8);
    if (temp_r3 != 0) {
        temp_r3[0x10] = s.sp12;
    }
}
