#pragma force_active on
struct fn_27_295750_Obj {
    char pad[8];
    unsigned int flags;
};

extern "C" void fn_27_295750(fn_27_295750_Obj* p) {
    p->flags |= 0x10000;
}
