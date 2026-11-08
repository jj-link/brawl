#pragma force_active on
extern void fn_80230450(void);
extern void fn_80230454(void);
extern unsigned char fn_80239C44(int, int, int, int, void *, int);
extern void *memset(void *, int, unsigned long);
extern unsigned int lbl_8040D768[];

unsigned char fn_80234DFC(int arg0, int arg1, unsigned int arg2, int arg3) {
    unsigned int sp8[2];
    unsigned char temp_r28;
    unsigned char i;

    i = 0;
    memset(sp8, 0, 8);
    if (arg3 != 0) {
        while (arg2 != 0 && i < 0x17) {
            if (arg2 & (1U << i)) {
                unsigned int e;
                arg2 &= ~(1U << i);
                e = lbl_8040D768[i];
                sp8[(e >> 5) & 0xFF] |= 1U << (e - (e & 0x1FE0));
            }
            i++;
        }
    }
    fn_80230450();
    temp_r28 = fn_80239C44(arg0, 0, 0, 0, sp8, arg1);
    fn_80230454();
    return (unsigned char)(temp_r28 == 0);
}
