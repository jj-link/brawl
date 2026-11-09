#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern void *memcpy(void *, const void *, u32);
extern void *fn_8024E73C(const void *);
extern u8 fn_80240F8C(u16);
extern u8 lbl_8052CDC0[];
extern void fn_802319E4(u32, const char *);
extern char lbl_80483888[];
extern void fn_80231A14(u32, const char *, s32, u8);
extern char lbl_804838B0[];
extern int fn_8024C7EC(u16, u8);
extern s32 fn_8023A0F0(s32);
extern void fn_80237FA0(void *, s32, s32, u16, u8);
extern void fn_8024E43C(s32);
extern void fn_80232020(void *);
extern void fn_8024AED0(void *, s32, void *);
extern void fn_8024F5B8(void *, s32, s32);
extern void fn_80231FB0(void *, s32, s32);
extern u8 fn_80250344(void);
extern void fn_8024E63C(void *);

s32 fn_8024C500(u8 arg0, u16 arg1, s32 arg2)
{
    u8 *entry;
    u8 *node;
    s32 result;
    u8 buf[24];

    buf[6] = arg0;
    memcpy(buf, (const void *)arg2, 6);
    entry = (u8 *)fn_8024E73C(buf);
    if (entry == 0) {
        if (fn_80240F8C(arg1) == 0 && lbl_8052CDC0[0] >= 2) {
            fn_802319E4(0x80001, lbl_80483888);
        }
        return 0;
    }

    if (*(s32 *)(entry + 4) != 3) {
        if (lbl_8052CDC0[0] >= 1) {
            fn_80231A14(0x80000, lbl_804838B0, *(s32 *)(entry + 4), arg0);
        }
        if (arg0 != 0) {
            fn_8024C7EC(*(u16 *)(entry + 0x28), arg0);
        }
        return 0;
    }

    *(u16 *)(entry + 0x28) = arg1;
    if (buf[6] == 0) {
        *(s32 *)(entry + 4) = 4;
        result = fn_8023A0F0(arg2);
        if (result != 0) {
            fn_80237FA0(buf, result + 0x22, result + 0x35,
                        arg1, entry[0x30]);
        } else {
            fn_80237FA0(buf, 0, 0, arg1, entry[0x30]);
        }
        fn_8024E43C(0);
        fn_80232020(entry + 0x10);

        node = *(u8 **)(entry + 8);
        while (node != 0) {
            fn_8024AED0(node, 0, buf);
            node = *(u8 **)(node + 8);
        }

        if (*(s32 *)(entry + 0x54) != 0) {
            fn_8024F5B8(entry, 0, 0);
            fn_80231FB0(entry + 0x10, 2, 0x1E);
        } else if (*(u8 **)(entry + 8) == 0) {
            fn_80231FB0(entry + 0x10, 2, 0x3C);
        }
    } else if (buf[6] == 9 && fn_80250344() != 0) {
        *(s32 *)(entry + 4) = 1;
        *(u16 *)(entry + 0x28) = 0xFFFF;
    } else {
        node = *(u8 **)(entry + 8);
        while (node != 0) {
            u8 *next = *(u8 **)(node + 8);
            fn_8024AED0(node, 1, buf);
            node = next;
        }
        fn_8024E63C(entry);
    }

    return 1;
}
