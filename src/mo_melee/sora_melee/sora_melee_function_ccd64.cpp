#pragma force_active on
struct Obj {
    char pad[8];
    unsigned int hi : 6;
    unsigned int mid : 3;
    unsigned int lo : 23;
};

extern "C" void fn_27_CCD64(Obj* p, int v) {
    p->mid = v;
}
