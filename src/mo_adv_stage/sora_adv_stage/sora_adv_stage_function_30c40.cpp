#pragma force_active on
typedef unsigned int u32;

struct Bits {
    u32 a : 10;
    u32 b : 5;
    u32 c : 17;
};

struct Obj {
    u32 pad[2];
    Bits bits;
};

extern "C" {
void fn_40_30C40(Obj* obj, u32 val) {
    obj->bits.b = val;
}
}
