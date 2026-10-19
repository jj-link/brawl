#pragma force_active on
struct Fn40Obj {
    char pad0[0x40];
    int f40;
    char pad44[0x8];
    char f4c;
    char f4d;
    char f4e;
    char pad4f;
    int f50;
    int f54;
    int f58;
    int f5c;
};

extern "C" void fn_40_152CC(Fn40Obj* p) {
    p->f40 = 0;
    p->f4c = 0;
    p->f4d = 0;
    p->f4e = 0;
    p->f50 = 0;
    p->f54 = 0;
    p->f58 = 0;
    p->f5c = 0;
}
