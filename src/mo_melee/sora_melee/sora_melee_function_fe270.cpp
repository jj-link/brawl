#pragma force_active on
struct fn_27_FE270_Obj {
    char pad[8];
    unsigned int flags;
};

extern "C" {
void fn_27_FE270(fn_27_FE270_Obj* p) {
    p->flags &= ~0x2000;
}
}
