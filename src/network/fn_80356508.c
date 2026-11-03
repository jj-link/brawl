#pragma force_active on
extern int strlen(const char *);
extern void fn_803571F4(int, int);
extern int fn_80356738(char *, const char *, int);
extern char *lbl_805344C8[];
extern char *(*lbl_805A1028)(int, int);

int fn_80356508(int index, const char *str)
{
    int len;
    int result;
    if (*str) {
        if (strlen(str) > 10) {
            fn_803571F4(5, 0);
            return 0;
        }
        len = strlen(str);
        if (len > 10) {
            fn_803571F4(5, 0);
            return 0;
        }
        lbl_805344C8[index] = lbl_805A1028(((len + 2) / 3) * 4 + 1, 4);
        if (lbl_805344C8[index] == 0) {
            fn_803571F4(1, 0);
            return 0;
        }
        result = fn_80356738(lbl_805344C8[index], str, len);
        lbl_805344C8[index][result] = 0;
    }
    return 1;
}