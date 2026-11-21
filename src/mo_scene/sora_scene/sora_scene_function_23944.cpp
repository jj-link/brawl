#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" {
void fn_8005033C(void*);
void fn_80050424(void*);
void fn_80055760(u16, u8);
u32* fn_80055998(u16);
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
int getFighterColorFileNo__6muMenuFiii(int, int);
void fn_8010F960(u16, void*, void*, u32);
extern const float lbl_1_rodata_9E8[];
}

struct RuleByte { u8 rule : 3; u8 count : 3; u8 bit1 : 1; u8 bit0 : 1; };
struct RuleBits { u8 upper : 4; u8 choice : 2; u8 lower : 2; };
struct OptionBits { u8 pad[13]; u8 upper : 3; u8 value : 2; u8 lower : 3; };
struct LowBits { u8 upper : 6; u8 choice : 2; };
struct ByteBits { u8 b7 : 1; u8 b6 : 1; u8 b5 : 1; u8 b4 : 1; u8 b3 : 1; u8 b2 : 1; u8 b1 : 1; u8 b0 : 1; };
struct ModeBits { u8 pad[8]; u8 mode : 6; u8 rest0 : 2; u8 rule : 3; u8 count : 3; u8 rest1 : 2; };

extern "C" void fn_1_23944(void* unused, int stage)
{
    const float* values = lbl_1_rodata_9E8;
    u8* melee = (u8*)g_GameGlobal->m_modeMelee;
    u8* rule;
    u8* stages;
    u8* chars = (u8*)g_GameGlobal->m_selCharData;
    stages = (u8*)g_GameGlobal->m_selStageData;
    u8* record = (u8*)g_GameGlobal->getGlobalRecordMenuDatap();
    rule = (u8*)g_GameGlobal->m_setRule;

    fn_8005033C(melee);
    fn_80050424(melee);

    if (stage == 0) {
        stage = *(u16*)(stages + 0x22);
    }
    *(u16*)(melee + 0x1A) = (u16)stage;
    ((ModeBits*)melee)->mode = 0;
    melee[0x13] = chars[0x33];
    fn_80055760((u16)stage, stages[0x24]);

    u32* flags = fn_80055998(*(u16*)(melee + 0x1A));
    *(u64*)(melee + 0x30) = *(u64*)flags;
    *(u32*)(melee + 0x38) = flags[2];
    *(u32*)(melee + 0x3C) = flags[3];
    *(u64*)(melee + 0x30) &= *(u64*)(record + 0x08);
    melee[0x16] = record[0];
    melee[9] = (u8)(melee[9] & 0xFFFFFFE3);

    u8* src = chars;
    u8* dst = melee;
    for (int i = 0; i < 4; i++) {
        if (src[0xB9] != 3) {
            int character = src[0xB8];
            dst[0x98] = character;
            dst[0x99] = src[0xB9];
            dst[0xA3] = src[0xC3];
            u8 color = src[0xBD];
            int menu = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(character);
            dst[0x9D] = (u8)(menu == 0x28 ? 0 : getFighterColorFileNo__6muMenuFiii(menu, color));
            dst[0x9E] = src[0xBD];
            dst[0xB0] = src[0xD0];
            dst[0x9F] = src[0xBF];
            dst[0x9A] = (u8)i;
            dst[0xA0] = (u8)((melee[9] >> 2) & 7);
            *(s8*)(dst + 0x9C) = -1;
            if (((ModeBits*)melee)->rule == 1) {
                dst[0x9C] = ((u8*)g_GameGlobal->m_setRule)[4];
            }
            ((ModeBits*)melee)->count++;
        }
        src += 0x5C;
        dst += 0x5C;
    }

    u8* flagB4 = melee + 0xB4;
    u8* output = melee;
    u8* flagB3 = melee + 0xB3;
    for (int i = 0; i < 4; i++) {
        switch (rule[0x18]) {
        case 0:
            ((ByteBits*)flagB4)->b7 = 0;
            *(u16*)(output + 0xBC) = 0;
            ((ByteBits*)(melee + 0xB))->b5 = 0;
            break;
        case 1:
            *(u16*)(output + 0xBA) = 300;
            ((ByteBits*)flagB4)->b7 = 0;
            *(u16*)(output + 0xBC) = 0;
            ((ByteBits*)(melee + 0xB))->b5 = 0;
            break;
        case 2:
            *(u16*)(output + 0xBA) = 0;
            *flagB4 |= 0x80;
            *(u16*)(output + 0xBC) = *(u16*)(chars + 0xDC);
            output[0x9C] = 1;
            ByteBits byteC = *(ByteBits*)(melee + 0xC);
            ByteBits byteB = *(ByteBits*)(melee + 0xB);
            RuleByte byte9 = *(RuleByte*)(melee + 9);
            byte9.rule = 1;
            byte9.bit1 = 0;
            byteB.b5 = 1;
            byteB.b2 = 0;
            byteC.b7 = 0;
            *(ByteBits*)(melee + 0xC) = byteC;
            *(ByteBits*)(melee + 0xB) = byteB;
            *(RuleByte*)(melee + 9) = byte9;
            *(u32*)(melee + 0x20) = 0;
            ((ByteBits*)(melee + 0xA))->b7 = 0;
            break;
        }

        switch (rule[0x19]) {
        case 0: *(float*)(output + 0xD8) = values[0]; break;
        case 1: *(float*)(output + 0xD8) = values[1]; break;
        case 2: *(float*)(output + 0xD8) = values[2]; break;
        }
        output[0xD4] = rule[0x19];

        switch (rule[0x1A]) {
        case 0: ((RuleBits*)flagB4)->choice = 0; break;
        case 1: ((ByteBits*)flagB4)->b3 = 0; ((ByteBits*)flagB4)->b2 = 1; break;
        case 2: ((ByteBits*)flagB4)->b3 = 1; ((ByteBits*)flagB4)->b2 = 0; break;
        }

        switch (rule[0x1B]) {
        case 0: ((ByteBits*)flagB3)->b4 = 0; ((ByteBits*)flagB3)->b2 = 0; break;
        case 1: ((ByteBits*)flagB3)->b4 = 1; ((ByteBits*)flagB3)->b2 = 0; break;
        case 2: ((ByteBits*)flagB3)->b4 = 0; ((ByteBits*)flagB3)->b2 = 1; break;
        }

        switch (rule[0x1C]) {
        case 0: ((LowBits*)flagB4)->choice = 0; break;
        case 1: ((ByteBits*)flagB4)->b1 = 1; ((ByteBits*)flagB4)->b0 = 0; break;
        case 2: ((ByteBits*)flagB4)->b1 = 0; ((ByteBits*)flagB4)->b0 = 1; break;
        }

        switch (rule[0x1D]) {
        case 0: *(float*)(output + 0xE0) = values[0]; break;
        case 1: *(float*)(output + 0xE0) = values[3]; break;
        case 2: *(float*)(output + 0xE0) = values[4]; break;
        }

        flagB4 += 0x5C;
        output += 0x5C;
        chars += 0x5C;
        flagB3 += 0x5C;
    }

    switch (rule[0x1E]) {
    case 0: *(float*)(melee + 0x50) = values[0]; break;
    case 1: *(float*)(melee + 0x50) = values[5]; break;
    case 2: *(float*)(melee + 0x50) = values[6]; break;
    }

    ((OptionBits*)melee)->value = rule[0x1F];
    melee[0x62] |= 0x20;
    flags[1] = 0xFFFFFFFF;
    flags[0] = 0xFFFFFFFF;

    switch (rule[0x1A]) {
    case 1: flags[1] &= 0xFFBFFFFF; break;
    case 2: flags[1] &= 0xFFFF7FFF; break;
    }
    switch (rule[0x1B]) {
    case 1: flags[1] &= 0xFFFFBFFF; break;
    }
    switch (rule[0x1C]) {
    case 1: flags[1] &= 0xFFFEFFFF; break;
    case 2: flags[0] &= 0xFFFF7FFF; break;
    }

    *(u64*)(melee + 0x30) &= *(u64*)flags;

    if (melee[0x13] == 0) {
        melee[0xA3] = 0;
        melee[0xFF] = 1;
        melee[0x15B] = 2;
        melee[0x1B7] = 3;
    }

    fn_8010F960(*(u16*)(melee + 0x1A), melee + 0x1C, melee + 0x5C, 0);
}
