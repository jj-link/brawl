#pragma force_active on
extern "C" const float lbl_76_rodata_58;

struct StDxyOrsterObj {
    char pad[0x60];
    float f60;
    float f64;
    float f68;
    char pad2[8];
    unsigned int flags74;
};

extern "C" void fn_76_3C7C(StDxyOrsterObj* obj) {
    unsigned int v = obj->flags74;
    float zero = lbl_76_rodata_58;
    obj->f60 = zero;
    obj->f64 = zero;
    obj->f68 = zero;
    obj->flags74 = v & ~0x1Fu;
}
