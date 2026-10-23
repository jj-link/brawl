#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
#define NULL ((void*)0)

extern void fn_802319FC(u32, const char*, u32);
extern void fn_80231A14(u32, const char*, u32, s32);
extern unsigned char lbl_8052C9B8[0x408];
extern char lbl_804827D8[];
extern char lbl_80482810[];

#define CHECK(i)                                                              \
    {                                                                         \
        u8* e = lbl_8052C9B8 + (u8)(i) * 0x34;                                \
        if (lbl_8052C9B8[(u8)(i) * 0x34] != 0 && e[0x10] != 0 &&             \
            (arg0 == *(u16*)(e + 0x14) || arg0 == *(u16*)(e + 0x16))) {       \
            goto found;                                                       \
        }                                                                     \
        (i)++;                                                                \
    }

void fn_802499B0(u32 arg0, s32 arg1) {
    u8 idx;
    u8* entry;
    s32 n;

    entry = NULL;
    idx = 0;
    for (n = 4; n > 0; n--) {
        CHECK(idx)
        CHECK(idx)
        CHECK(idx)
        CHECK(idx)
    }

found:
    if (idx != 0x10) {
        entry = lbl_8052C9B8 + idx * 0x34 + 0x10;
    }

    if (entry == NULL) {
        if (lbl_8052C9B8[0x401] >= 2) {
            fn_802319FC(0x1E0001, lbl_804827D8, arg0);
        }
    } else {
        if (lbl_8052C9B8[0x401] >= 4) {
            fn_80231A14(0x1E0003, lbl_80482810, arg0, arg1);
        }
        if (arg1 != 0) {
            entry[1] |= 0x20;
        } else {
            entry[1] &= ~0x20;
        }
    }
}
