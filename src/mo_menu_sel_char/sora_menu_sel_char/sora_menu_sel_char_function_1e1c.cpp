#include <gf/gf_pad_status.h>
#include <gf/gf_pad_system.h>
#include <gm/gm_global.h>
#include <gm/gm_global_mode_melee.h>
#include <gm/gm_sel_char_data.h>
#include <mu/menu.h>
#include <ms/ms_message.h>
#include <stdio.h>
#include <string.h>
#include <types.h>

#pragma force_active on

struct SelCharRuleFlags {
    char pad[0x2e];
    u8 high : 3;
    u8 mid : 3;
    u8 low : 2;
};

struct SelCharFlag {
    u8 other : 1;
    u8 flag : 1;
    u8 rest : 6;
};

struct SelCharSub {
    char pad[0x10];
    s32 v;
};

struct SelCharArea {
    s32 unk0;
    char pad0[0x1A8];
    SelCharSub* unk1AC;
    char pad1[0x4];
    s32 unk1B4;
    s32 unk1B8;
    s32 unk1BC;
    s32 unk1C0;
    u8 unk1C4;
    char pad2[0x3];
    s32 unk1C8;
    s32 unk1CC;
    s32 unk1D0;
    s32 unk1D4;
    s32 unk1D8;
    s32 unk1DC;
    char pad3[0x230];
    s32 unk410;
    s32 unk414;
    s32 unk418;
};

struct SelCharTask {
    char pad0[0x44];
    SelCharArea* areas[4];
    char pad1[0x570];
    void* msg;
    u8 flag5C8;
    char pad2[0xF];
    s32 unk5D8;
    s32 unk5DC;
    s32 unk5E0;
    char pad3[0x1C];
    s32 unk600;
    s32 unk604;
    char pad4[0x18];
    s32 unk620;
    char pad5[0x24];
    s32 unk648;
};

extern "C" {
s32 exchangeMuSelchkind2GmCharacterKind__6muMenuFiii(s32);
s32 exchangeMuSelchkindToMuCharKind__6muMenuFiii(s32);
s32 getNumCharColor__6muMenuFiii(s32);
void setCharRefered__6muMenuFiii(s32);
s32 fn_10_2674(void*, s32, s32);
s32 fn_10_12010(SelCharArea*, s32);
s32 fn_10_12000(s32);
void fn_10_13F70(SelCharArea*, s32, s32, s32);
s32 fn_10_15168(SelCharArea*);
void fn_8004D674(GameGlobal*, s32, wchar_t*);
u32 fn_8004D9A8(GameGlobal*, s32);
u32 fn_8004DA94(GameGlobal*, s32);
void* getMsgData__5MuMsgFUlPPv(void*, u32, void**);
extern char lbl_10_data_10[];
extern u32 lbl_10_rodata_8[];
}

inline s32 findTeamColor(s32 kind, SelCharArea* area) {
    if (kind == 0x15 && area->unk1C4 != 0)
        return muMenu::findCharTeamColorNo(0x15, area->unk1C0, 6);
    return muMenu::findCharTeamColorNo(kind, area->unk1C0, 0);
}

inline bool isTimeMode(s32 mode) {
    if (mode == 8 || mode == 0xE)
        return true;
    return false;
}

inline bool isStockMode(s32 mode) {
    if (mode == 9 || mode == 0xD)
        return true;
    return false;
}

inline bool isSpecialMode(s32 mode) {
    if (mode == 4 || mode == 5 || mode == 6 || mode == 7 || mode == 0xF)
        return true;
    return false;
}

inline bool isPressed(gfPadStatus& status, u32* table) {
    if (status.m_error == 0 &&
        (status.m_buttonsCurrentFrame2.bits & table[status.m_controllerType]) != 0)
        return true;
    return false;
}

inline bool usedColor(SelCharTask* self, s32 kind, s32 color,
                      s32* kinds, s32* colorNos, s32 count) {
    for (s32 j = 0; j < count; j++) {
        if (fn_10_2674(self, kind, kinds[j]) != 0 && color == colorNos[j])
            return true;
    }
    return false;
}

inline void updateSelChar(SelCharTask* self, u8& st, s32& i,
                          s32& kind, s32& color, u16& r27,
                          gfPadStatus& status, char* text, wchar_t* name,
                          s32* kinds, s32* colorNos, u32& msgSize) {
    u32* table;
    gmSelCharData* data;
    s32* colorPtr;
    s32* kindPtr;
    char* cursor = (char*)self;

    kindPtr = kinds;
    colorPtr = colorNos;
    table = lbl_10_rodata_8;
    ((u8*)(data = g_GameGlobal->m_selCharData))[0x33] = (self->flag5C8 != 0);

    for (i = 0; i < self->unk648; i++) {
        SelCharArea* area = *(SelCharArea**)(cursor + 0x44);
        u8* p = (u8*)data + 0x5C * i;
        u8* q = (u8*)data + 4 * i;
        u8* nm = (u8*)data + 0xC4 + 0x5C * i;
        u8* fl = (u8*)data + 0xD3 + 0x5C * i;
        s32 flag2;

        *kindPtr = 0x28;
        *colorPtr = -1;
        if (area->unk0 == 2) {
            p[0xB9] = 3;
        } else {
            kind = fn_10_12010(area, area->unk1B8);
            color = area->unk1BC;
            flag2 = 0;
            if (area->unk1AC->v != 0) {
                flag2 = 1;
                kind = 0x29;
            } else {
                switch (kind) {
                case 3:
                    if (area->unk1B4 != 0) {
                        if (area->unk1DC >= 0) {
                            s32 hit;
                            g_gfPadSystem->getSysPadStatus(area->unk1DC, &status);
                            hit = isPressed(status, table);
                            if (hit != 0) {
                                kind = 4;
                            }
                        }
                    }
                    break;
                case 0x29:
                    flag2 = 1;
                    break;
                }
            }

            q[0xA] = kind;

            if (flag2 != 0) {
                kind = area->unk410;
                color = area->unk414;
                if (usedColor(self, kind, color, kinds, colorNos, i)) {
                    color = 0;
                    while (color < getNumCharColor__6muMenuFiii(kind)) {
                        if (!usedColor(self, kind, color, kinds, colorNos, i)) {
                            break;
                        }
                        color++;
                    }
                    if (color >= getNumCharColor__6muMenuFiii(kind)) {
                        color = 0;
                    }
                }
                setCharRefered__6muMenuFiii(
                    exchangeMuSelchkindToMuCharKind__6muMenuFiii(kind));
            }

            *kindPtr = kind;
            *colorPtr = color;
            if (kind == 0x1B) {
                kind = fn_10_12000(area->unk418);
            }
            p[0xB8] = exchangeMuSelchkind2GmCharacterKind__6muMenuFiii(kind);

            if (self->flag5C8 != 0) {
                color = findTeamColor(kind, area);
            }
            p[0xBD] = color;

            if (area->unk1B4 != 0) {
                fn_10_13F70(area, kind, color, 1);
            }

            switch (area->unk1B4) {
            case 0:
                st = 3;
                r27 = 0;
                break;
            case 2:
                st = 1;
                r27 = 0;
                break;
            case 1:
                st = 0;
                r27 = (u16)area->unk1D8;
                break;
            }
            p[0xB9] = st;
            *(u16*)(q + 0xC) = r27;

            switch (fn_10_15168(area)) {
            case 1:
                *(s16*)(p + 0xDE) = (s16)(area->unk1D0 * 10);
                break;
            case 2:
                if (area->unk1D0 == 0) {
                    *(s16*)(p + 0xDC) = 1;
                } else {
                    *(s16*)(p + 0xDC) = (s16)(area->unk1D0 * 10);
                }
                break;
            }

            p[0xC3] = area->unk1C0;
            p[0xD7] = area->unk1D4;
            p[0xBC] = self->unk5DC;
            {
                s32 nameIdx = area->unk1C8;
                if (nameIdx < 0) {
                    nameIdx = 0x78;
                }
                p[0xD0] = nameIdx;
            }

            memset(name, 0, 12);
            if (area->unk1C8 >= 0) {
                fn_8004D674(g_GameGlobal, area->unk1C8, name);
            } else {
                s32 n = area->unk1CC;
                if (n > 0) {
                    void* src = getMsgData__5MuMsgFUlPPv(
                        self->msg, 1, (void**)&msgSize);
                    memcpy(text, src, msgSize);
                    sprintf(text + msgSize, lbl_10_data_10, n);
                    Message::utf8to16(name, text);
                }
            }
            memcpy(nm, name, 12);
            p[0xBF] = area->unk1DC + 1;

            {
                unsigned int f;
                if (area->unk1C8 >= 0) {
                    f = fn_8004D9A8(g_GameGlobal, area->unk1C8);
                } else if (area->unk1DC >= 0) {
                    f = fn_8004DA94(g_GameGlobal, area->unk1DC);
                } else {
                    f = 0;
                }
                ((SelCharFlag*)fl)->flag = f;
            }
        }
        cursor += 4;
        kindPtr++;
        colorPtr++;
    }

    {
        u8* fill = (u8*)data + 0x5C * i;
        for (; i < 7; i++) {
            fill[0xB9] = 3;
            fill += 0x5C;
        }
    }

    {
        u8* sel = (u8*)g_GameGlobal->m_selCharData;
        u8* rule = (u8*)g_GameGlobal->m_setRule;
        if ((s32)sel[4] == 4) {
            ((SelCharRuleFlags*)sel)->mid = self->unk5DC;
        } else if ((s32)rule[2] == 1) {
            rule[4] = self->unk5DC;
        } else {
            rule[3] = self->unk5D8;
        }
        {
            u8 v = ((u8*)g_GameGlobal->m_selCharData)[4];
            s32 c = isTimeMode(v);
            if (c != 0) {
                ((u8*)data)[1] = self->unk600;
            }
        }
        {
            u8 v = ((u8*)g_GameGlobal->m_selCharData)[4];
            s32 c = isStockMode(v);
            if (c != 0) {
                ((u8*)data)[2] = self->unk604;
            }
        }
        {
            u8 v = ((u8*)g_GameGlobal->m_selCharData)[4];
            if ((s32)v == 1) {
                ((u8*)data)[3] = self->unk620;
            }
        }
        {
            u8 v = ((u8*)g_GameGlobal->m_selCharData)[4];
            s32 c = isSpecialMode(v);
            if (c != 0) {
                ((SelCharRuleFlags*)data)->high = self->unk5E0;
            }
        }
        ((u8*)data)[7] = 1;
    }
}

extern "C" void fn_10_1E1C(SelCharTask* self) {
    gfPadStatus status;
    char text[28];
    wchar_t name[6];
    s32 kinds[4];
    s32 colorNos[4];
    u32 msgSize;
    u8 st;
    s32 i;
    s32 kind;
    s32 color;
    u16 r27;
    updateSelChar(self, st, i, kind, color, r27, status, text, name,
                  kinds, colorNos, msgSize);
}
