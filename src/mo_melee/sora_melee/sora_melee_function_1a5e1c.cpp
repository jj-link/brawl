#pragma force_active on
struct FnObj {
    int pad[2];
    unsigned int f : 10;
    unsigned int g : 22;
};

extern "C" void fn_27_1A5E1C(FnObj* p, unsigned int v) {
    p->f = v;
}
