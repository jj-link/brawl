#pragma force_active on
typedef unsigned int u32;

struct ftBits {
    u32 a : 10;
    u32 b : 5;
    u32 c : 17;
};

struct ftObj {
    char pad[8];
    ftBits flags;
};

extern "C" {
void fn_27_1CF768(ftObj* p, u32 v) {
    p->flags.b = v;
}
}
