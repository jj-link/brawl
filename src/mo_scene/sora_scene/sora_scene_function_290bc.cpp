#include <ut/ut_relocate.h>
#include <stdio.h>
#pragma force_active on
extern void* lbl_1_bss_1998[];
extern char lbl_1_data_7998[];
extern char lbl_1_data_79AC[];
extern "C" void fn_1_290BC(u8* data, u32 size) {
    utRelocate reloc(data, size);
    char buf1[64];
    char buf2[64];
    void** p = lbl_1_bss_1998;
    int i = 0;
    do {
        sprintf(buf1, lbl_1_data_7998, i + 1);
        *p = reloc.getPublicAddress(buf1);
        i++;
        p++;
    } while (i < 19);
    int j = 0;
    void** p2 = lbl_1_bss_1998;
    do {
        sprintf(buf2, lbl_1_data_79AC, j + 1);
        p2[19] = reloc.getPublicAddress(buf2);
        j++;
        p2++;
    } while (j < 19);
}