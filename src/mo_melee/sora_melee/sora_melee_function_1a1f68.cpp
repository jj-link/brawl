#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
};

struct Obj {
    u32 pad[2];
    Bits bits;
};

extern "C" void fn_27_1A1F68(Obj* obj, u32 v) {
    obj->bits.b = v;
}
