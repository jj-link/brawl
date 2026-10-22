#pragma force_active on
extern "C" {
void fn_800E48F4(void *, int);

int fn_800E485C(void *arg0, unsigned int arg1) {
    int var_r31;
    char *p = (char *) arg0;

    var_r31 = 0;
    if (((*(int *) (p + 0x26C) == 0) || (arg1 != (unsigned char) p[0x268])) && ((var_r31 = 1, (*(int *) (p + 0x278) == 0)) || (arg1 != (unsigned char) p[0x274])) && ((var_r31 = 2, (*(int *) (p + 0x284) == 0)) || (arg1 != (unsigned char) p[0x280]))) {
        var_r31 = 3;
    }
    if (var_r31 >= 3) {
        return -1;
    }
    fn_800E48F4(arg0, var_r31);
    return var_r31;
}
}
