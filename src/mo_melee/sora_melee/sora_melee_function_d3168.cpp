#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Thing {
    u32 pad0;
    u32 pad1;
    u32 a : 4;
    s32 b : 2;
    u32 c : 26;
};

extern "C" s32 fn_27_D3168(Thing *p) {
    return p->b;
}
