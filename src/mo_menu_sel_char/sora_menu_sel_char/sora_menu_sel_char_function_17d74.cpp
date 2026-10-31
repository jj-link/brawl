#pragma force_active on
extern "C" {
int fn_800B3C5C(void* obj, const void* info, int arg);
extern unsigned char lbl_10_rodata_744[];
extern signed char lbl_10_bss_10;
extern char lbl_10_data_B08[];
extern unsigned char lbl_10_data_A90[];

void fn_10_17D74(char* self, int idx) {
    unsigned char* sub = *(unsigned char**)(self + 0x1f4);
    if (sub[0x5c8] == 0) {
        return;
    }
    int n = *(int*)(self + 0x1c0);
    int r6;
    if (idx >= 0) {
        unsigned char* p = lbl_10_rodata_744 + n * 2;
        r6 = p[1];
    } else {
        r6 = lbl_10_rodata_744[n * 2];
    }
    char* str = lbl_10_data_B08;
    if (lbl_10_bss_10 == 0) {
        lbl_10_bss_10 = 1;
        *(char**)(lbl_10_data_A90 + 0x0c) = str;
        *(char**)(lbl_10_data_A90 + 0x20) = str;
        *(char**)(lbl_10_data_A90 + 0x34) = str;
        *(char**)(lbl_10_data_A90 + 0x48) = str;
        *(char**)(lbl_10_data_A90 + 0x5c) = str;
        *(char**)(lbl_10_data_A90 + 0x70) = str;
    }
    fn_800B3C5C(*(void**)(self + 0xbc), lbl_10_data_A90 + r6 * 0x14, 0);
}
}
