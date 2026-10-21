#pragma force_active on
extern "C" {

extern const float lbl_68_rodata_210;

void fn_68_13888(int arg1, int count, float *array, unsigned char *out)
{
    if (array == 0) return;
    if (out == 0) return;
    *out = 0;
    if (count == 0) return;

    int c_gt = 0;
    int c_not = 0;
    while (count--) {
        if (*array > lbl_68_rodata_210) c_gt++;
        else c_not++;
        array += 3;
    }
    if (c_gt > c_not) {
        *out = 0;
        return;
    }
    *out = 1;
}

}
