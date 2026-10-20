#pragma force_active on
struct FooObj {
    char pad[8];
    unsigned int flags;
};

extern "C" void fn_27_1A0248(FooObj* p) {
    p->flags &= ~0x00400000u;
}
