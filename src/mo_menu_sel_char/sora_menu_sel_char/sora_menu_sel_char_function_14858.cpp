#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_10_rodata_6A8;
extern const float lbl_10_rodata_6D4;
extern const double lbl_10_rodata_6C0;
int exchangeMuSelchkind2MuStockchkind__6muMenuFi(int);
int fn_800AF6F0(int);
void setFrameTex__8MuObjectFf(void*, float);
}

extern "C" void fn_10_14858(void* self, int kind) {
    float var_f1;
    switch (kind) {
    case 40:
        var_f1 = lbl_10_rodata_6A8;
        break;
    case 41:
        var_f1 = lbl_10_rodata_6D4;
        break;
    default:
        var_f1 = fn_800AF6F0(exchangeMuSelchkind2MuStockchkind__6muMenuFi(kind)) + 1;
        break;
    }
    setFrameTex__8MuObjectFf(*(void**)((char*)self + 0xB8), var_f1);
}
