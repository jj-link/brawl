#pragma force_active on
struct SomeObj {
    unsigned char pad[0xB1];
    unsigned char flags;
    unsigned char pad2[0x12];
    int value;
};

extern "C" void fn_801D1450(SomeObj* obj, int value) {
    if (value == obj->value) return;
    obj->value = value;
    obj->flags |= 0x10;
}
