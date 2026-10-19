#pragma force_active on
extern "C" const float lbl_54_rodata_8C;

struct StNorfairObj {
    char pad_00[0x60];
    float f60;
    float f64;
    float f68;
    char pad_6c[0x74 - 0x6C];
    unsigned int m74;
};

extern "C" void fn_54_6364(StNorfairObj* obj) {
    unsigned int v = obj->m74;
    float zero = lbl_54_rodata_8C;
    obj->f60 = zero;
    obj->f64 = zero;
    obj->f68 = zero;
    obj->m74 = v & ~0x1Fu;
}
