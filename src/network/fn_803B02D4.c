#pragma force_active on
extern int fn_803AFA84(int, void*);

int fn_803B02D4(int arg0) {
    int temp_r3;

    temp_r3 = fn_803AFA84(arg0, *(void**)(arg0 + 0x15F4));
    if (temp_r3 != 0) {
        return temp_r3;
    }
    temp_r3 = fn_803AFA84(arg0, *(void**)(arg0 + 0x15F8));
    return temp_r3 & ((-temp_r3 | temp_r3) >> 31);
}
