#pragma force_active on
struct Obj {
    int pad[2];
    unsigned int hi : 2;
    unsigned int rest : 30;
};

extern "C" void fn_74_6944(struct Obj *o, unsigned int v) {
    o->hi = v;
}
