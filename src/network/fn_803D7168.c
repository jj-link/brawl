#pragma force_active on
extern int fn_803D8AFC(int);
extern int fn_803D899C(int);
extern char lbl_805644C0[];

int fn_803D7168(char *arg0) {
    int result;

    result = fn_803D8AFC(*(int *)(arg0 + 0x1FBC));
    if (result != 0) {
        if (result == 0x15) {
            int t = fn_803D899C(*(int *)(arg0 + 0x1FBC));
            *(int *)(lbl_805644C0 + 0x44) = t;
            *(int *)(arg0 + 0x1F84) = t;
            return 0x1000;
        }
        return -1;
    }
    return 0;
}
