#pragma force_active on
extern int fn_803A85F4(int a, int b, int c, const void *data, int length);
extern int lbl_805A1044;

int fn_8035CDD8(int s, int value) {
    int tmp;
    int result;
    tmp = value;
    result = fn_803A85F4(s, 0xFFFF, 0x1001, &tmp, 4);
    result = (result >= 0) ? result : (lbl_805A1044 = result, -1);
    return result != -1;
}