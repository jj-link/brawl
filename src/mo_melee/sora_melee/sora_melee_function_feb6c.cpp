#pragma force_active on
struct FnBits {
    unsigned int hi : 4;
    unsigned int f : 2;
    unsigned int lo : 26;
};

struct FnObj {
    unsigned int pad[2];
    FnBits w;
};

extern "C" void fn_27_FEB6C(FnObj *o, unsigned int v) {
    o->w.f = v;
}
