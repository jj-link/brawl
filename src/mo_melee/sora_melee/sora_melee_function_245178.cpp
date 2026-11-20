#include <types.h>
#include <gm/gm_global.h>
#include <gm/gm_global_mode_melee.h>
#pragma force_active on

extern u8 lbl_27_rodata_3F00[];

extern "C" int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
extern "C" int getFighterColorFileNo__6muMenuFiii(int, int);

struct UnkParam {
    union {
        bool asBool;
        u32 asInt;
    } unk0;
    u32 unk4;
};

static inline int mapKind(int kind) {
    if (kind < 0 || kind > 0x2B) return 0x23;
    return lbl_27_rodata_3F00[kind];
}

extern "C" void fn_27_245178(int unused, s8 arg1)
{
    gmAdvData* adv = g_GameGlobal->m_advData;
    gmGlobalModeMelee* mm = g_GameGlobal->m_modeMelee;
    s32 i;
    u8* slot;
    u8* sp;
    s32 flag;
    u8* advb = (u8*)adv;

    if ((s8)advb[0x5FA] > 0) {
        sp = advb;
        i = 0;
        while (i < (s8)advb[0x5FA] - 1) {
            *(s32*)(sp + 0x2E0) = *(s32*)(sp + 0x2E8);
            i++;
            sp[0x2E4] = sp[0x2EC];
            sp += 8;
        }
        slot = advb + (((s8)advb[0x5FA] - 1) << 3);
        *(s32*)(slot + 0x2E0) = -1;
        slot[0x2E4] = 0xFF;
        advb[0x5FA] = advb[0x5FA] - 1;
        flag = 1;
    } else {
        flag = 0;
    }

    if (flag != 0) {
        u8 b1;
        u8 b0;
        u8 kind0 = ((u8*)mm)[0x98];
        u8* cur = (u8*)g_GameGlobal->m_advData + 0x2B4;
        b0 = cur[0];
        b1 = cur[1];
        cur[1] = (b1 >= b0) ? 0 : b1;
        if ((((u8*)g_GameGlobal->m_advData)[0x606] >> 7) & 1) {
            if (mapKind(kind0) == mapKind(*(s8*)(cur + (u8)((s8*)cur)[1] + 5))) {
                u8 n = (u8)(cur[1] + 1);
                cur[1] = (n >= cur[0]) ? 0 : n;
            }
        }
        {
            u8 old = cur[1];
            u8* q = cur + old;
            cur[1] = (u8)(old + 1);
            u8 sel = q[5];
            mm->m_playersInitData[1].m_state = arg1;
            ((u8*)mm)[0xF4] = sel;
        }

        UnkParam s18;
        UnkParam s10;
        gmAdvData* adv2 = g_GameGlobal->m_advData;
        if (adv2 != NULL) {
            s10.unk0.asInt = *(u32*)((u8*)adv2 + 0x4930);
            s10.unk4 = *(u32*)((u8*)adv2 + 0x4934);
        } else {
            s18.unk0.asBool = false;
            s18.unk4 = -1;
            s10 = s18;
        }

        UnkParam copy = s10;
        s8 ctrl = (s8)(copy.unk4 + 1);
        mm->m_playersInitData[1].m_controllerNo = ctrl;
        mm->m_playersInitData[1]._0x3C[1] = ctrl;

        s32 found = 0;
        gmPlayerInitData* pl = &mm->m_playersInitData[0];
        s32 idx = 0;
        for (idx = 0; idx < 4; pl++, idx++) {
            if (idx != 1 && pl->m_state != 3 &&
                ((u8*)mm)[0xF4] == ((u8*)pl)[0] &&
                !((pl->_0x1D[0] >> 4) & 1) && !((pl->_0x1D[0] >> 3) & 1) && ((u8*)pl)[6] == 0) {
                found = 1;
                break;
            }
        }

        if (found != 0) {
            s32 r = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(((u8*)mm)[0xF4]);
            int c = (r == 0x28) ? 0 : getFighterColorFileNo__6muMenuFiii(r, 1);
            mm->m_playersInitData[1].m_colorFileNo = c;
            mm->m_playersInitData[1].m_colorNo = 1;
        } else {
            s32 r = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(((u8*)mm)[0xF4]);
            int c = (r == 0x28) ? 0 : getFighterColorFileNo__6muMenuFiii(r, 0);
            mm->m_playersInitData[1].m_colorFileNo = c;
            mm->m_playersInitData[1].m_colorNo = 0;
        }
    }
}
