#pragma force_active on
struct FnObj {
    unsigned char pad[0xb1];
    unsigned char flags;
    unsigned char pad2[0xb8 - 0xb2];
    float value;
};

extern "C" void fn_801D1394(FnObj* obj, float v) {
    if (v == obj->value) {
        return;
    }
    obj->value = v;
    obj->flags |= 0x10;
}
