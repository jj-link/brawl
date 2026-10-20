#pragma force_active on
struct Obj {
    char pad[8];
    unsigned int a : 9;
    unsigned int b : 1;
    unsigned int rest : 22;
};

extern "C" unsigned int fn_51_D9B8(Obj* o) {
    return o->b;
}
