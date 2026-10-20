#pragma force_active on
struct FooObj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" void fn_27_1A41FC(FooObj* p) {
    p->flags &= ~2u;
}
