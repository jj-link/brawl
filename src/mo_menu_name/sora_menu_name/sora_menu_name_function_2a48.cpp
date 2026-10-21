#pragma force_active on

typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;

struct GameGlobal;

struct Entry {
    u8 pad[2];
    s16 idx;
};

extern "C" void* fn_8004D138(GameGlobal*, s16);
extern GameGlobal* g_GameGlobal;

extern "C" s32 fn_16_2A48(const Entry* a, const Entry* b) {
    s16 idxA = a->idx;
    s16 idxB = b->idx;

    if (idxA == -1) return -1;
    if (idxB == -1) return 1;
    if (idxA == -2) return 1;
    if (idxB == -2) return -1;

    GameGlobal* g = g_GameGlobal;
    void* pA = fn_8004D138(g, idxA);
    void* pB = fn_8004D138(g, idxB);

    s32 result = idxA - idxB;
    s32 diff = *(s32*)((u8*)pB + 0xF0) -
               *(s32*)((u8*)pA + 0xF0);

    if (diff != 0) result = diff;
    return result;
}
