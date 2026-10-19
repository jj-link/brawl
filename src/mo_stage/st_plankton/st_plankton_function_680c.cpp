#pragma force_active on
extern "C" const float lbl_74_rodata_F0;

struct StPlanktonObj {
    unsigned char pad[0x60];
    float f60;
    float f64;
    float f68;
    unsigned char pad2[8];
    unsigned int flags74;
};

extern "C" void fn_74_680C(StPlanktonObj* obj) {
    unsigned int flags = obj->flags74;
    float zero = lbl_74_rodata_F0;
    flags = flags & ~0x1Fu;
    obj->f60 = zero;
    obj->f64 = zero;
    obj->f68 = zero;
    obj->flags74 = flags;
}
