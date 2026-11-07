#include <stdio.h>
#include <string.h>
#pragma force_active on

typedef struct Info {
    char pad[0x24];
    unsigned int code;
} Info;

typedef struct State {
    char pad0[4];
    void *ctx;
    char pad1[0x10];
    int count;
    void *entries;
} State;

typedef struct Arg {
    int status;
    int id;
    char pad[0x86];
    char name[9];
    char code[4];
} Arg;

extern char lbl_80489460[];
extern char lbl_8059F080;
extern State *lbl_805A0F70;

extern void fn_80335638(int, const char *, ...);
extern int fn_80350C70(const void *);
extern Info *fn_8033891C(void);
extern void fn_80351AE8(Info *, void *, char *);
extern int fn_803517BC(Info *, void *);
extern void fn_80351A80(void *, int);
extern void fn_80368238(void *, int);
extern void fn_803682A8(void *, int);
extern void fn_803680C8(void *, int, char *);
extern void fn_80337BBC(void);
extern int fn_803F6150(const char *, const char *, unsigned int);

void fn_80338128(void *a, Arg *b)
{
    char code[8];
    char name[32];
    char *base;
    int rid;
    int off;
    int i;
    unsigned int v;
    int id;
    int found = 0;

    base = lbl_80489460;

    if (b->status != 0) {
        fn_80335638(0x20, base + 0x2C8, b->status);
        return;
    }

    fn_80335638(4, base + 0x2EC, b->id, b->name);

    i = 0;
    off = 0;
    for (; i < lbl_805A0F70->count; i++) {
        if (fn_80350C70((char *)lbl_805A0F70->entries + off) == 1) {
            fn_80351AE8(fn_8033891C(), (char *)lbl_805A0F70->entries + off, name);
            if (strcmp(name, b->name) == 0) {
                fn_80368238(a, b->id);
                fn_80351A80((char *)lbl_805A0F70->entries + off, b->id);
                found = 1;
                fn_80335638(0x20000, base + 0x318, b->id, i);
            }
        } else if (fn_80350C70((char *)lbl_805A0F70->entries + off) == 3 ||
                   fn_80350C70((char *)lbl_805A0F70->entries + off) == 2) {
            v = fn_8033891C()->code;
            snprintf(code, 5, base + 0x344, v >> 24,
                     (v >> 16) & 0xff, (v >> 8) & 0xff, v & 0xff);
            id = b->id;
            if (id == fn_803517BC(fn_8033891C(), (char *)lbl_805A0F70->entries + off) &&
                fn_803F6150(code, b->code, 4) == 0) {
                fn_80368238(a, id);
                found = 1;
                fn_80335638(0x20000, base + 0x350, b->id, i);
            }
        }
        off += 12;
    }

    if (found) {
        rid = b->id;
        fn_803680C8(lbl_805A0F70->ctx, rid, &lbl_8059F080);
        fn_80337BBC();
        fn_80335638(0x20000, base + 0x1B0, rid);
        return;
    }

    fn_803682A8(a, b->id);
    fn_80335638(0x20000, base + 0x37C, b->id);
}
