#include <ut/ut_relocate.h>
#pragma force_active on

struct Table41 {
    const char* p[41];
};

struct Table21 {
    const char* p[21];
};

extern "C" {
extern const Table41 lbl_1_rodata_22E8;
extern const Table21 lbl_1_rodata_238C;
extern void* lbl_1_bss_1A64[41];
extern void* lbl_1_bss_1B08[21];

void fn_1_33DBC(u8* arg0, u32 arg1) {
    utRelocate reloc(arg0, arg1);
    Table21 t2;
    Table41 t1;
    t1 = lbl_1_rodata_22E8;
    t2 = lbl_1_rodata_238C;
    for (int i = 0; i < 41; i++) {
        lbl_1_bss_1A64[i] = reloc.getPublicAddress(t1.p[i]);
    }
    for (int j = 0; j < 21; j++) {
        lbl_1_bss_1B08[j] = reloc.getPublicAddress(t2.p[j]);
    }
}
}
