#pragma force_active on
extern int fn_80212730(int a, int b);

int fn_80215158(int a, int b) {
    if (b == 0 || (b & 0x1F) != 0) {
        return -0x65;
    }
    return fn_80212730(a, b);
}
