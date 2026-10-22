#pragma force_active on
extern "C" {
extern char lbl_5_bss_11;
extern int lbl_5_data_988;
extern int lbl_5_data_9A8;
void fn_6_0(void*, int, int);
void fn_800B3C5C(void*, const void*, int);

struct AnimInfo {
    float start;
    float end;
    float rate;
    const char* name;
    unsigned char flags[4];
};
struct AnimTable {
    AnimInfo first[11];
    AnimInfo second[11];
    unsigned char ids[12];
};
extern AnimTable lbl_5_bss_14;

void fn_5_13194(void* arg0, int arg1, int arg2) {
    if (lbl_5_bss_11 == 0) {
        fn_6_0(&lbl_5_bss_14, lbl_5_data_988, lbl_5_data_9A8);
        lbl_5_bss_11 = 1;
    }
    fn_800B3C5C(*(void**)((char*)*(void**)((char*)arg0 + 0x1ac) + 0x108),
                &lbl_5_bss_14.first[lbl_5_bss_14.ids[arg1]], 0);
    if (arg2 != 0) {
        fn_800B3C5C(*(void**)((char*)*(void**)((char*)arg0 + 0x1ac) + 0x160),
                    &lbl_5_bss_14.second[lbl_5_bss_14.ids[arg1]], 0);
    }
    *(int*)((char*)*(void**)((char*)arg0 + 0x1ac) + 0x1bf0) = arg1;
}
}
