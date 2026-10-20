#pragma force_active on
struct Bits {
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int rest : 28;
};

struct Obj {
    char pad[8];
    Bits bits;
};

extern "C" void fn_78_56B8(Obj* obj, unsigned int v) {
    obj->bits.b = v;
}
