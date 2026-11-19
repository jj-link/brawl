#include <types.h>
#define _current_locale lbl_804942B8
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <revolution/SO/SOBasic.h>
#pragma force_active on

extern char lbl_80490D80[];
extern char *lbl_805A1130;
extern s32 closesocket(s32);
extern s32 fn_8035C384(s32, void *, s32);
extern u32 fn_8035C620(char *);
extern void *fn_8035C788(char *);
extern s32 socket(s32, s32, s32);

typedef struct { u8 len; u8 fam; s16 port; u32 addr; } SA;

static inline u32 hash(const char *p) {
    u32 h = 0;
    while (*p) {
        h = h * 0x9CCF9319 + tolower(*p);
        p++;
    }
    return h;
}

s32 fn_8038A3E8(char *self) {
    SA sa;
    char buf[128];
    u32 m;
    u32 h = hash(self + 0xc);
    m = h % 20;
    if (lbl_805A1130 != 0) {
        strcpy(buf, lbl_805A1130);
    } else {
        sprintf(buf, lbl_80490D80, self + 0xc, m);
    }
    sa.fam = 2;
    sa.port = SOHtoNs(0x70ee);
    sa.addr = fn_8035C620(buf);
    if (sa.addr + 0x10000 == 0xffff) {
        void *r = fn_8035C788(buf);
        if (r == 0) return 2;
        memcpy(&sa.addr, **(void ***)((char *)r + 0xc), 4);
    }
    if (*(s32 *)(self + 0x6b4) == -1) {
        *(s32 *)(self + 0x6b4) = socket(2, 1, 6);
        if (*(s32 *)(self + 0x6b4) == -1) return 1;
    }
    if (fn_8035C384(*(s32 *)(self + 0x6b4), &sa, 8) != 0) {
        closesocket(*(s32 *)(self + 0x6b4));
        *(s32 *)(self + 0x6b4) = -1;
        return 3;
    }
    return 0;
}