#pragma force_active on
#pragma opt_propagation off
extern void fn_803425D8(int);
extern void fn_8037B354(int, const char *);
extern char lbl_8048AA60[];
extern char lbl_8059F0E8[8];
extern unsigned char *lbl_805A0FA8;

void fn_8034296C(signed char arg0, signed char arg1, int arg2, int arg3)
{
    char *base = lbl_8048AA60;
    fn_803425D8(0);
    lbl_805A0FA8[0x15] = arg0;
    lbl_805A0FA8[0x18] = arg1;
    *(int *)(lbl_805A0FA8 + 0x480) = arg2;
    *(int *)(lbl_805A0FA8 + 0x484) = arg3;
    lbl_805A0FA8[0x191] = 0;
    lbl_805A0FA8[0x2E8] = 0;
    fn_8037B354(0x32, lbl_8059F0E8);
    fn_8037B354(0x33, base + 0x16C);
    fn_8037B354(0x34, base + 0x178);
    fn_8037B354(0x35, base + 0x160);
    fn_8037B354(0x36, base + 0xD00);
    fn_8037B354(0x37, base + 0xD0C);
    fn_8037B354(0x38, base + 0xD18);
    lbl_805A0FA8[0x17] = 0;
    fn_8037B354(0x39, base + 0xD24);
    lbl_805A0FA8[0x4B0] = 1;
    lbl_805A0FA8[0x19] = arg1;
    fn_8037B354(0x3A, base + 0xD34);
    *(int *)(lbl_805A0FA8 + 0x1C) = 0;
    *(int *)(lbl_805A0FA8 + 0x28) = 0;
    {
        unsigned char *p = lbl_805A0FA8;
        *(int *)(p + 0x24) = 0;
        *(int *)(p + 0x20) = 0;
    }
}
