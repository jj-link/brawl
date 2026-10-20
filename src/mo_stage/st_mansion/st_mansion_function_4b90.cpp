#pragma force_active on
struct Obj {
    int a;
    int b;
    int flags;
};

extern "C" {
int fn_47_4B90(Obj* p) {
    return (int)((unsigned int)(p->flags << 2) & 0xE0000000u) >> 30;
}
}
