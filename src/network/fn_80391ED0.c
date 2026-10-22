#pragma force_active on
extern int fn_803A6E94(int a, int b, int c);
extern int fn_803A85F4(int a, int b, int c, const void *data, int length);

int fn_80391ED0(void *arg0) {
    int sp8;
    int result;

    result = fn_803A6E94(2, 1, 0);
    sp8 = 0;
    if (arg0 != 0) {
        sp8 = *(int *)((char *)arg0 + 0x244);
    }
    if (result >= 0 && sp8 != 0) {
        fn_803A85F4(result, 0xFFFF, 0x1002, &sp8, 4);
    }
    return result;
}
