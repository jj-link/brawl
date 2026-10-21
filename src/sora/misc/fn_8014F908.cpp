#pragma force_active on
typedef unsigned long long u64;
typedef signed char s8;

struct GameGlobal {
    char pad[0x34];
    s8* unk34;
};

extern GameGlobal* g_GameGlobal;

extern "C" void fn_8014F908(u64 arg0) {
    s8* p = g_GameGlobal->unk34;
    p[0x30] = (s8)(arg0 >> 56);
    p[0x31] = (s8)(arg0 >> 48);
    p[0x32] = (s8)(arg0 >> 40);
    p[0x33] = (s8)(arg0 >> 32);
    p[0x34] = (s8)(arg0 >> 24);
    p[0x35] = (s8)(arg0 >> 16);
    p[0x36] = (s8)(arg0 >> 8);
    p[0x37] = (s8)arg0;
}
