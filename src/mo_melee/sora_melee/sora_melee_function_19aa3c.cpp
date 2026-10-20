#pragma force_active on
struct Obj {
    char pad[8];
    unsigned int flags;
};

extern "C" {
int fn_27_19AA3C(Obj* p) {
    return (int)(((p->flags >> 22) & 0xF) << 28) >> 29;
}
}
