#pragma force_active on
typedef unsigned int u32;

struct Obj27 {
    u32 pad0;
    u32 pad4;
    u32 flags;
};

extern "C" {
void fn_27_92778(Obj27* p) {
    p->flags &= ~2u;
}
}
