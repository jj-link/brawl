#pragma force_active on
typedef unsigned int u32;

struct FooObj {
    u32 pad[2];
    u32 flags;
};

extern "C" {
void fn_27_FEA68(FooObj* p) {
    p->flags &= 0xFFBFFFFF;
}
}
