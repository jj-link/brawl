#pragma force_active on
struct FooObj {
    char pad[8];
    unsigned int flags;
};

extern "C" {
void fn_27_C5238(FooObj* p) {
    p->flags &= 0xFDFFFFFFu;
}
}
