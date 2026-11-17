#include <types.h>
#pragma force_active on

struct Flags { unsigned char a : 5; unsigned char b : 1; unsigned char c : 1; unsigned char d : 1; };

extern "C" {
u8 fn_800C8548(void);
void fn_800D0AE0(void*, void*);
int fn_800D051C(void*, u8, int);
int fn_800D0908(void*, u8, int);
void netReport__FPCce(const char*, ...);
extern char lbl_804582C0[];
extern char lbl_804582EC[];

void fn_800D0398(void* arg0, void* arg1) {
    const char* fmt;
    void* d;
    int* q;
    u8* p;
    u8 cnt;
    u8 i;
    int j;
    int t;
    u8 old;
    u8 idx;

    fn_800D0AE0(arg0, arg1);
    idx = fn_800C8548();
    if (idx == 0xFF) {
        d = 0;
    } else {
        u32 base = (u32)arg0 + idx * 0x218;
        d = (void*)(base + 0x70);
    }

    if (d != 0 && ((((u8*)arg0)[0xFC9] >> 7) & 1 ||
                   ((*(s32*)((u8*)arg0 + 0xFCC)) >> 24) == 4)) {
        cnt = 0;
        for (i = 0; i != 4; i++) {
            j = 0;
            u32 qbase = (u32)d + i * 0x18;
            q = (int*)(qbase + 0x84);
            p = (u8*)arg0 + ((i << 2) - i);
            do {
                t = *q >> 24;
                if (t == 1)
                    cnt++;
                if (t <= 1) {
                    old = p[0xFE3];
                    if (t != old) {
                        netReport__FPCce(lbl_804582C0, i, j, old, t);
                        p[0xFE3] = (u8)t;
                        if (t == 1)
                            fn_800D051C(arg0, i, j);
                        else
                            fn_800D0908(arg0, i, j);
                        if (j == 0)
                            ((u8*)arg0)[0xFCA] |= 0x80;
                    }
                }
                j++;
                q += 2;
                p++;
            } while (j < 3);
        }

        old = ((u8*)arg0)[0xFD5];
        if (old != cnt) {
            netReport__FPCce(lbl_804582EC, old, cnt);
            ((u8*)arg0)[0xFD5] = cnt;
            ((Flags*)((u8*)arg0 + 0xFCA))->b = 1;
            ((Flags*)((u8*)arg0 + 0xFCA))->d = 0;
        }
    }
}
}