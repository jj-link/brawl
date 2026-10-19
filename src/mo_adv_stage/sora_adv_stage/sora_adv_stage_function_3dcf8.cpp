#include <string.h>
#pragma force_active on

extern char lbl_40_bss_29F0[0x20];

struct Obj {
    char pad0[0x40];
    int a40;
    char pad44[0x48 - 0x44];
    int a48;
    char pad4c[0x54 - 0x4c];
    char* p54;
};

extern "C" int fn_40_3DCF8(Obj* self, const char* name) {
    if (self->a48 == 0 && self->a40 == 0) {
        strcpy(lbl_40_bss_29F0, name);
        self->p54 = lbl_40_bss_29F0;
        self->a40 = 1;
        return 1;
    }
    return 0;
}
