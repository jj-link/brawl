#pragma force_active on
struct Obj {
    unsigned char pad[0x184];
    unsigned char a;
    unsigned char pad2[3];
    unsigned int b;
    float c;
};

extern "C" void fn_68_21B8(Obj* obj, unsigned char a, unsigned int b, float c) {
    obj->a = a;
    obj->b = b;
    obj->c = c;
}
