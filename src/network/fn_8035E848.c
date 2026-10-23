#pragma force_active on

extern char lbl_805348E0[];

int fn_8035E848(void) {
    int* p = (int*)lbl_805348E0;
    int result;
    if (p[3] != 0) {
        return 1;
    }
    result = 0;
    if (p[0] == 0) {
        result = 2;
    }
    return result;
}
