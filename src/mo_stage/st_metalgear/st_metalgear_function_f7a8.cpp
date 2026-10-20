#pragma force_active on
struct Obj {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int a : 12;
    unsigned int b : 1;
    unsigned int c : 19;
};

extern "C" unsigned int fn_71_F7A8(Obj* o) {
    return o->b;
}
