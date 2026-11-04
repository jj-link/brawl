#include <string.h>
#pragma force_active on

extern unsigned char lbl_8052D5A8[];
extern char lbl_80484B08[];
extern char lbl_80484B18[];

extern int fn_803F6150(const void *, const void *, unsigned long);
extern void fn_802319E4(int, const char *);
extern void fn_802319FC(int, const char *, int);
extern void fn_80232020(void *);
extern void fn_8022EE44(void *);
extern void fn_80231FB0(void *, int, int);

void *fn_80256160(void *arg0, unsigned char arg1)
{
    unsigned char *p = lbl_8052D5A8 + 0x3fe;
    int i;

    for (i = 0; i < 1; i++, p += 0x78) {
        if (p[0xa] && fn_803F6150(p, arg0, 6) == 0) {
            if (lbl_8052D5A8[0x414] >= 4)
                fn_802319E4(0x90003, lbl_80484B08);
            p = (unsigned char *)((unsigned long)lbl_8052D5A8 + i * 0x78 + 0x39c);
            fn_80232020(p);
            return p;
        }
    }

    {
        int next;
        unsigned char *slot;
        unsigned char *entry;

        p = lbl_8052D5A8;
        next = p[0x65] + 1;
        if (next >= 1)
            next = 0;

        slot = p + next * 0x78;
        entry = slot + 0x39c;
        if (slot[0x408] == 0) {
            memset(entry, 0, 0x78);
            memcpy(entry + 0x62, arg0, 6);
            fn_8022EE44(entry + 0x18);
            entry[0x6d] = arg1;
            if (p[0x414] >= 4)
                fn_802319FC(0x90003, lbl_80484B18, 0x3c);
            *(void **)(entry + 0x10) = entry;
            fn_80231FB0(entry, 0xb, 0x3c);
            lbl_8052D5A8[0x65] = next;
            return entry;
        }
    }

    return 0;
}
