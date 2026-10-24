#pragma force_active on
#include <types.h>

class GameGlobal {};

extern "C" u64 fn_8014FEB4(void);
extern "C" u32 getLanguage__10GameGlobalFv(GameGlobal*);
extern "C" u8 fn_8004EAC8(u8**);
extern "C" u32 NETCalcCRC32(void*, s32);

extern GameGlobal* g_GameGlobal;

struct Block {
    u64 m_00;
    u64 m_08;
    u32 m_10;
    u8 m_14;
    u8 m_15;
    u8 m_16;
    u8 m_17;
    u8 m_18;
    u8 m_19;
    u8 m_1A;
    u8 m_1B;
    u32 m_1C;
};

extern "C" s32 fn_80153D70(Block** arg0, s32 arg1, u64 arg2, u8 arg4) {
    Block* p = *arg0;
    if (p == 0) {
        return 0;
    }
    if (arg4 >= 4) {
        return 0;
    }
    p->m_00 = fn_8014FEB4();
    GameGlobal* gg = g_GameGlobal;
    u32 lang = getLanguage__10GameGlobalFv(gg);
    u32 sh = (u32)(fn_8004EAC8((u8**)gg) << 5);
    p->m_14 = (u8)(sh | lang);
    p->m_16 = arg4;
    p->m_08 = arg2;
    p->m_10 = 0xDEADBEEF;
    p->m_10 = NETCalcCRC32(p, (s32)(p->m_1C + 0x20));
    return 1;
}
