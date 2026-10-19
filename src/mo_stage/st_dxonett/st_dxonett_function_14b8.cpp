#pragma force_active on
typedef unsigned char u8;
typedef unsigned long u32;

struct Fn78Obj {
    char pad[0x184];
    u8 field184;
    u32 field188;
    float field18C;
};

extern "C" void fn_78_14B8(Fn78Obj* obj, u8 a, u32 b, float c) {
    obj->field184 = a;
    obj->field188 = b;
    obj->field18C = c;
}
