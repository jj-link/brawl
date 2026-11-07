#pragma force_active on
extern int fn_803D8C48(int, int, unsigned int, unsigned int, unsigned short, int);
extern int fn_803D899C(int);
extern char lbl_805644C0[];

int fn_803D7248(char *arg0, int a, unsigned int offset, unsigned int length, int last) {
    int result;

    result = fn_803D8C48(*(int *)(arg0 + 0x1FBC), a, offset, length, *(unsigned short *)arg0, last);
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
