#pragma force_active on
extern "C" const float lbl_51_rodata_90;

struct St51Object {
    char pad0[0x60];
    float f60;
    float f64;
    float f68;
    char pad1[8];
    unsigned int flags74;
};

extern "C" void fn_51_6254(St51Object* obj) {
    unsigned int v = obj->flags74;
    float z = lbl_51_rodata_90;
    v = v & ~31u;
    obj->f60 = z;
    obj->f64 = z;
    obj->f68 = z;
    obj->flags74 = v;
}
