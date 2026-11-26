#include <types.h>
#include <gm/gm_global.h>

#pragma force_active on

extern "C" {
int fn_803F86E4(void*, const char*, ...);
void fn_803FC984(void);
extern char __files[];
int exchangeMuSelchkind2GmCharacterKind__6muMenuFiii(int);
}

extern char lbl_1_data_62D0[];

struct BitPosition {
    u32* bits;
    u32 index;
};

static inline bool testBitValue(BitPosition pos) {
    if (pos.index >= 0x33) {
        fn_803F86E4(__files + 0xA0, lbl_1_data_62D0);
        fn_803FC984();
    }
    return (pos.bits[pos.index / 32] & (1U << (pos.index % 32))) != 0;
}

static inline BitPosition testBit(u32* bits, u32 index) {
    BitPosition pos = { bits, index };
    return pos;
}

static inline int getKind(s32 selch) {
    if (selch == 0x1B) {
        u8* d = (u8*)g_GameGlobal->m_advData;
        if (testBitValue(testBit((u32*)(d + 0x4898), 0x1D)))
            return 0x1D;
        if (testBitValue(testBit((u32*)(d + 0x4898), 0x21)))
            return 0x21;
        return 0x1F;
    }
    return exchangeMuSelchkind2GmCharacterKind__6muMenuFiii(selch);
}

static inline void appendKind(int v) {
    u8* d = (u8*)g_GameGlobal->m_advData;
    u8* list = d + 0x2B4;
    *(s8*)(list + list[0]++ + 5) = v;
    *(s32*)(d + (s8)d[0x5FA] * 8 + 0x2E0) = 0;
    *(s8*)(d + (s8)d[0x5FA] * 8 + 0x2E4) = v;
    d[0x5FA] = d[0x5FA] + 1;
    d[0x5FB] = d[0x5FB] + 1;
}

struct Entry {
    s32 value;
    u8 kind;
};

static inline void clearEntry(Entry* p) {
    p->value = -1;
    p->kind = 0xFF;
}

struct SelList {
    s32 entries[20];
    s32 count;
    s32 target;
};

struct SelHolder {
    u8 pad[0x24];
    SelList* sel;
};

extern "C" void fn_1_30AAC(SelHolder* self) {
    s8* adv = (s8*)g_GameGlobal->m_advData;
    s32 i;
    s32 n;
    s32 off;
    s32 base;
    int kind;

    if (self->sel->count == 0)
        return;

    adv[0x2B4] = 0;
    adv[0x2B5] = 0;
    adv[0x2B6] = -1;
    adv[0x2B7] = -1;
    adv[0x2B8] = -1;
    ((s8*)g_GameGlobal->m_advData)[0x4922] = -1;
    ((s8*)g_GameGlobal->m_advData)[0x4923] = -1;
    adv[0x2B9] = -1;
    adv[0x2BA] = -1;
    adv[0x2BB] = -1;
    adv[0x2BC] = -1;
    adv[0x2BD] = -1;
    adv[0x2BE] = -1;
    adv[0x2BF] = -1;
    adv[0x2C0] = -1;
    adv[0x2C1] = -1;
    adv[0x2C2] = -1;
    adv[0x2C3] = -1;
    adv[0x2C4] = -1;
    adv[0x2C5] = -1;
    adv[0x2C6] = -1;
    adv[0x2C7] = -1;
    adv[0x2C8] = -1;
    adv[0x2C9] = -1;
    adv[0x2CA] = -1;
    adv[0x2CB] = -1;
    adv[0x2CC] = -1;
    adv[0x2CD] = -1;
    adv[0x2CE] = -1;
    adv[0x2CF] = -1;
    adv[0x2D0] = -1;
    adv[0x2D1] = -1;
    adv[0x2D2] = -1;
    adv[0x2D3] = -1;
    adv[0x2D4] = -1;
    adv[0x2D5] = -1;
    adv[0x2D6] = -1;
    adv[0x2D7] = -1;
    adv[0x2D8] = -1;
    adv[0x2D9] = -1;
    adv[0x2DA] = -1;
    adv[0x2DB] = -1;
    adv[0x2DC] = -1;
    adv[0x2DD] = -1;
    adv[0x2DE] = -1;
    adv[0x2DF] = -1;
    ((u8*)g_GameGlobal->m_advData)[0x5FA] = 0;
    ((u8*)g_GameGlobal->m_advData)[0x5FB] = 0;

    n = 0;
    off = 0;
    for (i = 0; i < 12; i++) {
        n += 8;
        clearEntry((Entry*)((u8*)g_GameGlobal->m_advData + off + 0x2E0));
        clearEntry((Entry*)((u8*)g_GameGlobal->m_advData + off + 0x2E8));
        clearEntry((Entry*)((u8*)g_GameGlobal->m_advData + off + 0x2F0));
        clearEntry((Entry*)((u8*)g_GameGlobal->m_advData + off + 0x2F8));
        clearEntry((Entry*)((u8*)g_GameGlobal->m_advData + off + 0x300));
        clearEntry((Entry*)((u8*)g_GameGlobal->m_advData + off + 0x308));
        clearEntry((Entry*)((u8*)g_GameGlobal->m_advData + off + 0x310));
        clearEntry((Entry*)((u8*)g_GameGlobal->m_advData + off + 0x318));
        off += 0x40;
    }

    base = n * 8;
    clearEntry((Entry*)((u8*)g_GameGlobal->m_advData + base + 0x2E0));
    clearEntry((Entry*)((u8*)g_GameGlobal->m_advData + base + 0x2E8));
    clearEntry((Entry*)((u8*)g_GameGlobal->m_advData + base + 0x2F0));

    adv[0x606] = (adv[0x606] & ~0x40) | 0x20;
    adv[0x607] = adv[0x607] | 0x30;

    kind = getKind(self->sel->entries[0]);
    appendKind(kind);

    if (self->sel->target != 0x28) {
        int kind2 = getKind(self->sel->target);
        if (self->sel->entries[0] != self->sel->target)
            appendKind(kind2);
        adv[0x606] = adv[0x606] | 0x80;
    } else {
        adv[0x606] = adv[0x606] & ~0x80;
    }

    for (s32 j = 1; j < self->sel->count; j++)
        appendKind(getKind(self->sel->entries[j]));
}
