#pragma force_active on
typedef unsigned int u32;

struct FnBits {
    u32 a : 5;
    u32 f : 5;
    u32 b : 22;
};

struct FnObj {
    char pad[8];
    FnBits bits;
};

extern "C" void fn_27_C6F70(FnObj* obj, u32 val) {
    obj->bits.f = val;
}
