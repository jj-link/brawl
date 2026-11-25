#include <types.h>
#include <ft/ft_manager.h>
#include <so/so_external_value_accesser.h>
#include <if/if_adv_mngr.h>
#include <gm/gm_global.h>

#pragma force_active on

extern "C" {
extern const u8 lbl_40_rodata_120[];
extern const float lbl_40_rodata_1A8;
void* fn_800DFC68(void);
void fn_80107914(void*, int, int);
void fn_801079C0(void*);
int fn_80107A70(void*, int, int);
void fn_8010C0C4(void*, void*);
void fn_8010C0DC(void*, void*);
void* fn_80158BE0(void);
void fn_8015B01C(void*, int, int);
int fn_8015B038(void*, int);
void fn_27_109E6C(ftManager*, int, const Vec3f*, float);
}

static inline ftKind map_id(int n)
{
    ftKind result;
    if (n < 0 || n > 0x2b)
        result = Fighter_ROB;
    else
        result = (ftKind)lbl_40_rodata_120[n];
    return result;
}

static inline bool current_kind(const u8* list, ftKind& invalid)
{
    int id = (s8)list[5 + list[1]];
    invalid = map_id(-1);
    return invalid == map_id(id);
}

static inline u8 next_id(ftKind& invalid)
{
    u8* p = (u8*)g_GameGlobal->m_advData;
    u8* list = p + 0x2b4;
    list[1] &= ~(0 - (list[0] <= list[1]));
    if ((((u8*)g_GameGlobal->m_advData)[0x606] >> 7) & 1) {
        if (current_kind(list, invalid)) {
            u8 next = list[1] + 1;
            list[1] = next & ~(0 - (list[0] <= next));
        }
    }
    return list[5 + list[1]++];
}

static inline void reset_players()
{
    int entry;
    for (int i = 0; i < 2; ++i) {
        if (fn_8015B038(fn_80158BE0(), i)) {
            entry = g_ftManager->getEntryId(i);
            if (entry != -1) {
                Fighter* fighter = g_ftManager->getFighter(entry, -1);
                if (fighter != 0) {
                    Vec3f pos = soExternalValueAccesser::getPos(fighter);
                    fn_27_109E6C(g_ftManager, entry, &pos, lbl_40_rodata_1A8);
                    fn_8015B01C(fn_80158BE0(), i, 0);
                }
            }
        }
    }
}

extern "C" void fn_40_1048C(void)
{
    u8 count;
    ftKind invalid1;
    ftKind invalid2;
    ftKind invalid3;
    u8* players;
    u8* original;
    u8* m;
    u8 total;
    u8 saved;
    u8 i;
    count = 0;
    original = (u8*)g_GameGlobal->m_advData;
    u8* entry = original;
    for (int j = 0; j < (s8)original[0x5fa]; ++j, entry += 8) {
        if (*(s32*)(entry + 0x2e0) == 1)
            ++count;
    }
    total = original[0x5fb] - 1;
    if ((original[0x606] >> 7) & 1)
        --total;
    int removed;
    do {
        u8* p = (u8*)g_GameGlobal->m_advData;
        if ((s8)p[0x5fa] > 0) {
            int k = 0;
            u8* e = p;
            while (k < (s8)p[0x5fa] - 1) {
                *(s32*)(e + 0x2e0) = *(s32*)(e + 0x2e8);
                e[0x2e4] = e[0x2ec];
                ++k;
                e += 8;
            }
            e = p + (((s8)p[0x5fa] - 1) << 3);
            *(s32*)(e + 0x2e0) = -1;
            e[0x2e4] = 0xff;
            --p[0x5fa];
            removed = 1;
        } else {
            removed = 0;
        }
    } while (removed);
    if (g_IfAdvMngr != 0) {
        while (fn_80107A70(g_IfAdvMngr, 0, 0) != 0x3e) {}
    }
    saved = original[0x2b5];
    players = (u8*)g_GameGlobal->m_modeMelee;
    for (i = 0; i < total; ++i) {
        int id = next_id(invalid1);
        if (id == players[0x98])
            id = next_id(invalid2);
        if (((original[0x606] >> 7) & 1) && id == players[0xf4])
            id = next_id(invalid3);
        u8* p = (u8*)g_GameGlobal->m_advData;
        if ((s8)p[0x5fa] < 0x62) {
            *(s32*)(p + (((s8)p[0x5fa]) << 3) + 0x2e0) = 0;
            p[(((s8)p[0x5fa]) << 3) + 0x2e4] = id;
            ++p[0x5fa];
        }
        if (g_IfAdvMngr != 0) {
            fn_80107914(g_IfAdvMngr, id, 1);
            if (!((original[0x606] >> 7) & 1)) {
                m = (u8*)g_IfAdvMngr;
                m[0x48] |= 0x40;
                if (*(void**)(m + 0x104) != 0) {
                    if (((u32)(m[0x48] >> 6) & 1) == 1)
                        fn_8010C0C4(*(void**)(m + 0x104), fn_800DFC68());
                    else
                        fn_8010C0DC(*(void**)(m + 0x104), fn_800DFC68());
                }
            }
        }
    }
    original[0x2b5] = saved;
    for (u8 item = 0; item < count; ++item) {
        u8* p = (u8*)g_GameGlobal->m_advData;
        if ((s8)p[0x5fa] < 0x62) {
            *(s32*)(p + (((s8)p[0x5fa]) << 3) + 0x2e0) = 1;
            p[(((s8)p[0x5fa]) << 3) + 0x2e4] = 0xff;
            ++p[0x5fa];
        }
        if (g_IfAdvMngr != 0)
            fn_801079C0(g_IfAdvMngr);
        if (!((original[0x606] >> 7) & 1)) {
            u8* m2 = (u8*)g_IfAdvMngr;
            m2[0x48] |= 0x40;
            if (*(void**)(m2 + 0x104) != 0) {
                if (((u32)(m2[0x48] >> 6) & 1) == 1)
                    fn_8010C0C4(*(void**)(m2 + 0x104), fn_800DFC68());
                else
                    fn_8010C0DC(*(void**)(m2 + 0x104), fn_800DFC68());
            }
        }
    }
    reset_players();
}