#pragma force_active on
struct Entry {
    unsigned int value[9];
    unsigned int *next;
};

extern "C" Entry lbl_27_bss_3210[];

extern "C" unsigned int fn_27_149450() {
    return lbl_27_bss_3210[0].next[49];
}
