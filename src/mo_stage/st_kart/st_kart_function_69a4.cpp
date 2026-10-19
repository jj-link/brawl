#pragma force_active on
extern "C" const float lbl_49_rodata_90[];

struct StKartObj {
    unsigned char pad_00[0x60];
    float f60;
    float f64;
    float f68;
    unsigned char pad_6c[0x74 - 0x6C];
    unsigned int u74;
};

extern "C" void fn_49_69A4(StKartObj* obj) {
    unsigned int v = obj->u74;
    v &= ~31u;
    obj->f60 = lbl_49_rodata_90[0];
    obj->f64 = lbl_49_rodata_90[0];
    obj->f68 = lbl_49_rodata_90[0];
    obj->u74 = v;
}
