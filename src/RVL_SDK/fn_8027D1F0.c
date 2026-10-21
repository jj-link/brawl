#pragma force_active on
int fn_8027D230(int a, int b, int *out);

int fn_8027D1F0(int a, int b, int c) {
    int sp8;
    int var_r31;

    var_r31 = c;
    if (fn_8027D230(a, b, &sp8) == 0) {
        var_r31 = sp8;
    }
    return var_r31;
}
