#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Obj {
    u8 pad[8];
    u32 hi : 12;
    u32 f : 6;
    u32 lo : 14;
};

extern "C" {
void fn_27_1D3BC(Obj* p, u32 v) {
    p->f = v;
}
}
