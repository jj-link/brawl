#pragma force_active on
typedef unsigned int u32;
typedef signed char s8;

struct GameGlobal { char _pad[0x34]; s8* m_nteData; };
extern "C" GameGlobal* g_GameGlobal;

extern "C" void fn_8014FD1C(u32 arg0, u32 arg1) {
    s8* p = g_GameGlobal->m_nteData;
    u32 r6 = (arg1 << 8) | (arg1 >> 24);
    u32 r5 = (arg1 << 16) | (arg1 >> 16);
    u32 r0 = (arg1 << 24) | (arg1 >> 8);
    s8 b24 = (s8)(arg0 >> 24);
    s8 b16 = (s8)(arg0 >> 16);
    s8 b8 = (s8)(arg0 >> 8);
    s8 b0 = (s8)arg0;
    p[0x27] = b24;
    p[0x28] = b16;
    p[0x29] = b8;
    p[0x2A] = b0;
    p[0x2B] = (s8)__rlwimi(r6, arg0, 8, 0, 23);
    p[0x2C] = (s8)__rlwimi(r5, arg0, 16, 0, 15);
    p[0x2D] = (s8)__rlwimi(r0, arg0, 24, 0, 7);
    p[0x2E] = (s8)arg1;
}
