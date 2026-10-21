#pragma force_active on
struct FnObj801D13B4 {
    unsigned char pad[0xb1];
    unsigned char flags;
    unsigned char pad2[0xa];
    float value;
};

extern "C" void fn_801D13B4(FnObj801D13B4* obj, float v) {
    if (v == obj->value) {
        return;
    }
    obj->value = v;
    obj->flags |= 0x10;
}
