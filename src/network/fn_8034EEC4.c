#pragma force_active on

typedef struct Entry {
    int pad0;
    int unk4;
    int unk8;
    int padC;
    int unk10;
    int unk14;
    int unk18;
    unsigned char pad1C;
    unsigned char state;
    unsigned char pad1E[2];
    int pad20;
    int pad24;
    int unk28;
    int unk2C;
    int unk30;
    int pad34;
    int pad38;
    int pad3C;
    int pad40;
    int pad44;
} Entry;

extern void fn_80335638(int level, const char *fmt, ...);
extern void fn_8033524C(int arg0, int arg1);
extern void fn_8034F028(void *arg0, const void *arg1, unsigned long arg2);
extern void *fn_8033ABE8(int arg0);
#include <revolution/OS/OSTime.h>
extern int fn_80374BF0(void *);
extern char lbl_8048D1F0[];
extern char lbl_8048D208[];
extern char *lbl_805A0FB0;

void fn_8034EEC4(int arg0, const void *unused, int arg2) {
    int u10;
    Entry *e;
    int off;
    unsigned char st;
    void (*cb)(int, int, int);
    int size;
    unsigned long long tm;

    off = arg0 * 0x48;
    e = (Entry *)(lbl_805A0FB0 + off);
    if ((int)e->state == 2) {
        u10 = e->unk10;
        if (u10 + arg2 > e->unk8) {
            fn_80335638(2, lbl_8048D1F0);
            fn_8033524C(6, (int)0xFFFE82AC);
            return;
        }
        fn_8034F028((void *)(e->unk4 + u10), unused, arg2);
    }
    e->unk10 += arg2;
    st = ((Entry *)(lbl_805A0FB0 + off))->state;
    fn_80335638(0x10000, lbl_8048D208, arg0, e->unk10, e->unk18, st, fn_80374BF0(fn_8033ABE8(arg0)));
    size = e->unk18;
    if (e->unk10 == size) {
        e->state = 1;
        e->unk10 = 0;
        e->unk18 = 0;
        cb = *(void (**)(int, int, int))(lbl_805A0FB0 + 0x904);
        if (cb != 0) {
            cb(arg0, e->unk4, size);
        }
    }
    if (*(int *)(lbl_805A0FB0 + 0x908) != 0 && e->unk30 != 0) {
        tm = OSGetTime();
        e->unk2C = (int)tm;
        e->unk28 = (int)(tm >> 32);
    }
}
