#pragma force_active on
struct Obj {
    signed char status;
    unsigned char unk1;
    unsigned char pad[0x4A];
    int value;
    unsigned char pad2[0x5C];
    int other;
};

extern "C" void fn_27_207F50(Obj* obj, int a, int b, int c, unsigned char d) {
    if (a < 0 || b == -1 || c == 0) {
        obj->status = -1;
        obj->other = -1;
        obj->value = 0;
    } else {
        obj->status = a;
        obj->other = b;
        obj->value = c;
    }
    obj->unk1 = d;
}
