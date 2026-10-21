#pragma force_active on
struct Obj {
    char pad[0xB1];
    unsigned char flags;
    char pad2[0x11C - 0xB2];
    int value;
};

extern "C" void fn_801D1354(Obj* obj, int value) {
    if (value == obj->value)
        return;
    obj->flags |= 0x10;
    obj->value = value;
}
