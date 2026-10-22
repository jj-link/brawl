#pragma force_active on
extern "C" {

int fn_803C3DE0(int*, int, int);
void fn_8001B9E8(void);
int fn_803C3ED8(int*);

int fn_8001F7C4(int arg0) {
    int sp8[273];
    int var_r31;
    int var_r3;

    var_r31 = -1;
    var_r3 = fn_803C3DE0(sp8, arg0, 0x20);
    if (var_r3 != 0) {
        if (var_r3 != 2) {
            fn_8001B9E8();
        }
    } else {
        var_r31 = 1;
        while (var_r3 == 0) {
            var_r3 = fn_803C3ED8(sp8);
            if (var_r3 != 0) {
                if (var_r3 != 2) {
                    fn_8001B9E8();
                }
                break;
            }
            var_r31 += 1;
        }
    }
    return var_r31;
}

}
