#pragma force_active on

extern const float lbl_41_rodata_C98;

extern "C" void fn_41_1AE94(void* p) {
    float* a = (float*)p;

    if ((int)a[1] != 35791 || (int)a[1] != 35789 ||
        (int)a[1] != 35788 || (int)a[1] != 35790) {
        a[1] = -a[1];
    }

    a[3] = -a[3];

    if ((int)a[10] != 35791) {
        a[10] = -a[10];
    }

    if ((int)a[5] == 35795) {
        a[5] = -a[7];
        a[7] = lbl_41_rodata_C98;
    }

    if ((int)a[7] == 35795) {
        a[7] = -a[5];
        a[5] = lbl_41_rodata_C98;
    }
}
