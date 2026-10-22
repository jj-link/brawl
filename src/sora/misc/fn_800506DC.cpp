#pragma force_active on

typedef unsigned int u32;
typedef signed int s32;

extern "C" {
void* fn_8004E628(void*);
void* fn_8004E6A0(void*);
extern void* g_GameGlobal;
}

extern "C" s32 fn_800506DC() {
    void* p = g_GameGlobal;
    u32 x = *static_cast<u32*>(fn_8004E628(p));
    u32 y = *static_cast<u32*>(fn_8004E6A0(p));
    s32 res = -1;
    if (x <= (0xFFFFFFFFu - y)) {
        res = x + y;
    }
    return res;
}
