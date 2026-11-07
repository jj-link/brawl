#include <gm/gm_global.h>
#pragma force_active on

extern "C" {
unsigned int* fn_8004E5F8(void*);
unsigned int* fn_8004E594(void*);
unsigned int* fn_8004E5EC(void*);
void fn_8004F580(int);
void fn_8004FB48(int);
void fn_800516B4(int);
void fn_800553B8(int);
int fn_803F86E4(void*, const char*, ...);
void fn_803FC984();
extern char __files[];
}

extern char lbl_1_data_62D0[];

struct IdList {
    unsigned char bytes[14];
};
extern IdList lbl_1_rodata_22C8;

struct BitPosition {
    unsigned int* bits;
    unsigned int index;
};

static inline bool testBitValue(BitPosition pos)
{
    if (pos.index >= 0x33) {
        fn_803F86E4(__files + 0xA0, lbl_1_data_62D0);
        fn_803FC984();
    }
    return (pos.bits[pos.index / 32] & (1U << (pos.index % 32))) != 0;
}

static inline bool testBit(unsigned int* bits, unsigned int index)
{
    BitPosition pos = { bits, index };
    return testBitValue(pos);
}

extern "C" void fn_1_326E0()
{
    char* adventure = (char*)g_GameGlobal->m_advData;
    unsigned int* menu = fn_8004E5F8(g_GameGlobal);
    char* record = (char*)g_GameGlobal->m_record;
    unsigned int* flags = (unsigned int*)(record + 0x7F4);
    unsigned int* other = fn_8004E594(g_GameGlobal);

    for (unsigned int i = 0; i < 0x33; ++i) {
        if (testBit((unsigned int*)(adventure + 0x4898), i)) {
            flags[2 + i / 32] |= 1U << (i % 32);
        }
    }

    if (*(unsigned int*)((char*)g_GameGlobal->m_advData + 0x6CC) & 1)
        flags[4] |= 0x80000000;

    bool complete = true;
    for (int i = 0; i < 34; ++i) {
        if (*(int*)(adventure + 8) != 4) {
            complete = false;
            break;
        }
        adventure += 0x14;
    }
    if (complete)
        flags[4] |= 0x40000000;

    IdList ids = lbl_1_rodata_22C8;

    for (int i = 0; i < 14; ++i) {
        int id = ids.bytes[i];
        unsigned int* bits = (unsigned int*)((char*)g_GameGlobal->m_record + 0x7FC);
        if (bits[(unsigned int)id / 32] & (1 << (id % 32)))
            fn_8004F580(id);
    }

    if (*(unsigned int*)((char*)g_GameGlobal->m_record + 0x804) >> 31)
        fn_800553B8(0x42);
    if (*(unsigned int*)((char*)g_GameGlobal->m_record + 0x7FC) & 0x400)
        fn_800553B8(0x75);
    if (*(unsigned int*)((char*)g_GameGlobal->m_record + 0x7FC) & 0x800)
        fn_800553B8(0x35);
    if (*(unsigned int*)((char*)g_GameGlobal->m_record + 0x800) & 0x20)
        fn_800553B8(0x39);

    if (*(unsigned int*)((char*)g_GameGlobal->m_record + 0x804) >> 31)
        menu[4] |= 0x04000000;
    if ((*(unsigned int*)((char*)g_GameGlobal->m_record + 0x804) >> 30) & 1)
        menu[5] |= 0x00400000;

    bool all = true;
    for (int i = 0; i <= 0x73; ++i) {
        unsigned int* bits = fn_8004E5EC(g_GameGlobal);
        if (!(bits[i / 32] & (1 << (i % 32)))) {
            all = false;
            break;
        }
    }
    if (all)
        menu[6] |= 0x100;

    if (*(unsigned int*)((char*)g_GameGlobal->m_record + 0x800) & 0x100)
        *other |= 4;
    if (*(unsigned int*)((char*)g_GameGlobal->m_record + 0x800) & 0x800)
        *other |= 0x40;

    if (*(unsigned int*)((char*)g_GameGlobal->m_advData + 0x6CC) & 1) {
        fn_8004FB48(0x2713);
        fn_8004FB48(0x2822);
        fn_8004FB48(0x2825);
        fn_8004FB48(0x282C);
        fn_8004FB48(0x282D);
    }

    if ((unsigned int)(*(int*)((char*)g_GameGlobal->m_advData + 0xF4) - 3) <= 1)
        fn_800516B4(8);
    if ((unsigned int)(*(int*)((char*)g_GameGlobal->m_advData + 0x248) - 3) <= 1)
        fn_800516B4(0x10);
    if (*(unsigned int*)((char*)g_GameGlobal->m_advData + 0x6CC) & 1)
        fn_800516B4(0x20);
}
