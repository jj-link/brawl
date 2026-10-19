#pragma force_active on
extern const float lbl_63_rodata_B8;

struct StGwObj {
    char pad0[0x60];
    float f60;
    float f64;
    float f68;
    char pad1[0x74 - 0x6C];
    unsigned int v74;
};

extern "C" {
void fn_63_ABB8(StGwObj* obj)
{
    unsigned int v = obj->v74;
    float z = lbl_63_rodata_B8;
    v = v & ~31u;
    obj->f60 = z;
    obj->f64 = z;
    obj->f68 = z;
    obj->v74 = v;
}
}
