#include <types.h>
#include <gm/gm_global.h>

#pragma force_active on

extern "C" {
u32* fn_8004E580(void*);
u32* fn_8004E594(void*);
u32* fn_8004E5A0(void*);
u32* fn_8004E5B8(void*);
u8* fn_8004E5D8(void*, int);
u32* fn_8004E5F8(void*);
u32* fn_8004E778(void*);
void fn_8004E7D8(void*);
void fn_8004E7FC(void*);
u32 fn_8004E810(void*);
void fn_8004E820(void*);
void fn_8004E844(void*);
void fn_8004FB48(u32);
u32 fn_8004FD50();
u32 fn_8004FDFC();
u32 fn_80050738();
u32 fn_8005297C();
u32 fn_80052D20();
u32 fn_80056898();
u32 fn_800568A0();
u32 fn_800596EC(u32);
u32 fn_80059890(u32);
u32 fn_80059AB8(u32);
int fn_80059C00(u32);
int fn_80059F94(u32);
}

#define TEST_BIT_CASE(n, p, w, b) \
    case n: if (((p[w] >> b) & 1U) == 1U) unlock = 1; break

#define THRESHOLD_CASE(n, value, threshold) \
    case n: if ((value) >= (threshold)) unlock = 1; break

#define RECORD_BIT_CASE(n, bit) \
    case n: if (fn_8004E5B8(g_GameGlobal)[0] & (1U << bit)) unlock = 1; break

static inline bool isUnlocked(u32* words, int bit) {
    return (words[bit / 32] & (1 << (bit % 32))) != 0;
}

extern "C" void fn_80057158() {
    int passes;
    int word;
    int changed;
    int i;
    u32 total;
    u32* flags2;
    u32* flags;
    u32* unlocked;

    unlocked = fn_8004E5F8(g_GameGlobal);
    flags = fn_8004E580(g_GameGlobal);
    flags2 = fn_8004E594(g_GameGlobal);
    total = fn_80050738();
    passes = 0;

    do {
        changed = 0;
        for (i = 0; i < 128; ++i) {
            int bit = i * 2;
            word = bit / 32;
            if (!((1 << (bit % 32)) & unlocked[word])) {
                u32 unlock = 0;
                switch (i) {
                TEST_BIT_CASE(0x00, flags, 0, 1);
                TEST_BIT_CASE(0x01, flags, 0, 4);
                TEST_BIT_CASE(0x02, flags, 0, 7);
                TEST_BIT_CASE(0x03, flags, 0, 10);
                TEST_BIT_CASE(0x04, flags, 0, 13);
                TEST_BIT_CASE(0x05, flags, 0, 16);
                TEST_BIT_CASE(0x06, flags, 0, 19);
                TEST_BIT_CASE(0x07, flags, 0, 22);
                TEST_BIT_CASE(0x08, flags, 0, 25);
                TEST_BIT_CASE(0x09, flags, 0, 28);
                TEST_BIT_CASE(0x0a, flags, 0, 31);
                TEST_BIT_CASE(0x0b, flags, 1, 2);
                TEST_BIT_CASE(0x0c, flags, 1, 5);
                TEST_BIT_CASE(0x0d, flags, 1, 8);
                TEST_BIT_CASE(0x0e, flags2, 0, 0);
                TEST_BIT_CASE(0x0f, flags2, 0, 1);
                TEST_BIT_CASE(0x10, flags2, 0, 2);
                TEST_BIT_CASE(0x11, flags2, 0, 3);
                TEST_BIT_CASE(0x12, flags2, 0, 4);
                TEST_BIT_CASE(0x13, flags2, 0, 5);
                TEST_BIT_CASE(0x14, flags2, 0, 6);
                TEST_BIT_CASE(0x15, flags2, 0, 7);
                TEST_BIT_CASE(0x16, flags2, 0, 8);
                TEST_BIT_CASE(0x17, flags2, 0, 9);
                TEST_BIT_CASE(0x18, flags2, 0, 10);
                TEST_BIT_CASE(0x19, flags2, 0, 11);

                case 0x1a:
                case 0x62: {
                    unlock = 1;
                    int flag;
                    int j;
                    for (j = 0, flag = 1; j < 14; ++j, flag += 3) {
                        u32* words = fn_8004E580(g_GameGlobal);
                        if (!(words[flag / 32] & (1 << (flag % 32)))) {
                            unlock = 0;
                            break;
                        }
                    }
                    if (unlock == 1) {
                        fn_8004E7D8(g_GameGlobal);
                    }
                    break;
                }

                case 0x1b: {
                    u32 first = 0;
                    u32 second = 0;
                    if (*(u32*)((u8*)g_GameGlobal->m_record + 0x804) >> 31) {
                        fn_8004FB48(0x2713);
                        fn_8004FB48(0x2825);
                        fn_8004FB48(0x2822);
                        fn_8004FB48(0x282c);
                        fn_8004FB48(0x282d);
                        first = 1;
                    }
                    for (int j = 0; j < 0x23; ++j) {
                        if ((*(u16*)(fn_8004E5D8(g_GameGlobal, j) + 0x9c) >> 8) & 7) {
                            second = 1;
                            break;
                        }
                    }
                    if (first == 1 && second == 1) {
                        unlock = 1;
                        fn_8004E7FC(g_GameGlobal);
                        fn_8004FB48(0x270a);
                    }
                    break;
                }

                case 0x1d:
                case 0x63:
                    unlock = 1;
                    for (int j = 0; j < 12; ++j) {
                        u32* words = fn_8004E594(g_GameGlobal);
                        if (!(words[j / 32] & (1 << (j % 32)))) {
                            unlock = 0;
                            break;
                        }
                    }
                    if (i == 0x1d && unlock == 1) {
                        if (fn_8004E810(g_GameGlobal) == 1) {
                            fn_8004E844(g_GameGlobal);
                        } else {
                            unlock = 0;
                        }
                    }
                    break;

                case 0x1c:
                    if (*fn_8004E778(g_GameGlobal) >= 200) {
                        fn_8004E820(g_GameGlobal);
                        unlock = 1;
                    }
                    break;

                case 0x21:
                    if (total >= 100) {
                        unlock = 1;
                        *fn_8004E5A0(g_GameGlobal) |= 1;
                    }
                    break;
                case 0x22:
                    if (total >= 200) {
                        unlock = 1;
                        *fn_8004E5A0(g_GameGlobal) |= 2;
                    }
                    break;
                case 0x23:
                    if (total >= 300) {
                        unlock = 1;
                        *fn_8004E5A0(g_GameGlobal) |= 4;
                    }
                    break;
                case 0x24:
                    if (fn_8004FD50() >= 25) {
                        unlock = 1;
                        *fn_8004E5A0(g_GameGlobal) |= 8;
                    }
                    break;
                case 0x25:
                    if (((fn_8004E580(g_GameGlobal)[0] >> 19) & 1) == 1) {
                        unlock = 1;
                        *fn_8004E5A0(g_GameGlobal) |= 0x10;
                    }
                    break;
                case 0x26:
                    if ((fn_8004E580(g_GameGlobal)[0] >> 31) == 1) {
                        unlock = 1;
                        *fn_8004E5A0(g_GameGlobal) |= 0x20;
                    }
                    break;

                THRESHOLD_CASE(0x6d, total, 100);
                THRESHOLD_CASE(0x6e, total, 1000);
                THRESHOLD_CASE(0x6f, total, 10000);
                THRESHOLD_CASE(0x70, total, 50000);
                THRESHOLD_CASE(0x71, total, 100000);
                THRESHOLD_CASE(0x72, total, 1000000);
                THRESHOLD_CASE(0x74, total, 4999);

                RECORD_BIT_CASE(0x27, 0);
                RECORD_BIT_CASE(0x28, 2);
                RECORD_BIT_CASE(0x29, 4);
                RECORD_BIT_CASE(0x2e, 6);
                RECORD_BIT_CASE(0x2d, 8);
                RECORD_BIT_CASE(0x2a, 10);
                RECORD_BIT_CASE(0x2c, 12);
                RECORD_BIT_CASE(0x2b, 14);

                case 0x6a: {
                    int count = 0;
                    if (*fn_8004E5B8(g_GameGlobal) & 0x40) ++count;
                    if (*fn_8004E5B8(g_GameGlobal) & 0x100) ++count;
                    if (*fn_8004E5B8(g_GameGlobal) & 0x400) ++count;
                    if (*fn_8004E5B8(g_GameGlobal) & 0x1000) ++count;
                    if (*fn_8004E5B8(g_GameGlobal) & 0x4000) ++count;
                    if (count >= 5) unlock = 1;
                    break;
                }

                case 0x2f: case 0x30: case 0x32: case 0x33:
                case 0x34: case 0x35: case 0x36: case 0x37:
                case 0x38: case 0x39: case 0x6b:
                    if (fn_800596EC(i) == 1) unlock = 1;
                    break;

                THRESHOLD_CASE(0x3c, fn_8005297C(), 100);
                THRESHOLD_CASE(0x3d, fn_8005297C(), 200);
                THRESHOLD_CASE(0x3e, fn_8005297C(), 300);
                THRESHOLD_CASE(0x3f, fn_8005297C(), 400);
                THRESHOLD_CASE(0x40, fn_8005297C(), 500);
                THRESHOLD_CASE(0x41, fn_80052D20(), 100);
                THRESHOLD_CASE(0x42, fn_80052D20(), 200);
                THRESHOLD_CASE(0x43, fn_80052D20(), 300);
                THRESHOLD_CASE(0x44, fn_80052D20(), 400);
                THRESHOLD_CASE(0x45, fn_80052D20(), 500);
                THRESHOLD_CASE(0x46, fn_80052D20(), 600);

                case 0x4b: case 0x4c: case 0x4e: case 0x4f:
                case 0x50: case 0x51: case 0x52: case 0x53:
                case 0x54: case 0x55: case 0x56: case 0x57:
                case 0x58: case 0x59: case 0x5a: case 0x5c:
                case 0x5d: case 0x5e: case 0x5f: case 0x60:
                case 0x61:
                    if (fn_80059890(i) == 1) unlock = 1;
                    break;

                case 0x3a:
                case 0x3b:
                    if (fn_80059AB8(i) == 1) unlock = 1;
                    break;

                case 0x65:
                    unlock = 1;
                    for (int j = 0; j < 6; ++j) {
                        u32* words = fn_8004E5A0(g_GameGlobal);
                        if (!(words[j / 32] & (1 << (j % 32)))) {
                            unlock = 0;
                            break;
                        }
                    }
                    break;

                case 0x66: {
                    u32 required = fn_80056898();
                    if (fn_8005297C() >= required) unlock = 1;
                    break;
                }
                case 0x67: {
                    u32 required = fn_800568A0();
                    if (fn_80052D20() >= required) unlock = 1;
                    break;
                }
                case 0x68:
                    if ((*fn_8004E5B8(g_GameGlobal) & 1) &&
                        (*fn_8004E5B8(g_GameGlobal) & 4) &&
                        (*fn_8004E5B8(g_GameGlobal) & 0x10)) {
                        unlock = 1;
                    }
                    break;

                THRESHOLD_CASE(0x48, fn_8004FDFC(), 150);
                THRESHOLD_CASE(0x49, fn_8004FDFC(), 200);
                THRESHOLD_CASE(0x4a, fn_8004FDFC(), 250);
                THRESHOLD_CASE(0x69, fn_8004FDFC(), 258);

                case 0x6c:
                    if (*(u32*)((u8*)g_GameGlobal->m_record + 0x804) >> 31) {
                        unlock = 1;
                        int flag;
                        int j;
                        for (j = 0, flag = 1; j < 14; ++j, flag += 3) {
                            u32* words = fn_8004E580(g_GameGlobal);
                            if (!(words[flag / 32] & (1 << (flag % 32)))) {
                                unlock = 0;
                                break;
                            }
                        }
                    }
                    break;

                case 0x75: case 0x76: case 0x77: case 0x78:
                case 0x79: case 0x7a: case 0x7b:
                    if (fn_80059C00(i)) unlock = 1;
                    break;
                case 0x7c: case 0x7d: case 0x7e: case 0x7f:
                    if (fn_80059F94(i)) unlock = 1;
                    break;
                }

                if (unlock) {
                    u32 previous = unlocked[word];
                    changed = 1;
                    unlocked[word] = previous | (1 << (bit % 32));
                }
            }
        }
        if (!changed) break;
        ++passes;
    } while (passes < 3);
}
