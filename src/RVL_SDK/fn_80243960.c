#include <types.h>
#pragma force_active on
typedef struct Entry {
    u8 active;
    u8 pad0[3];
    u16 type;
    u16 id;
    u8 pad1[8];
    u16 sound;
    u8 pad2[2];
    void *pending;
    u8 pad3[8];
    void (*callback)(u16, u32);
    u8 tail[0x3c];
} Entry;
extern u8 lbl_8052C4C0[];
extern void *fn_8022F77C(void *);
extern void fn_8022F0E0(void *);
extern void fn_8024A4A0(u16);
extern void fn_8024A8F4(u32, void *);
static Entry *find(u32 id) {
    u16 xx;
    Entry *p;
    for (xx = 0, p = (Entry *)(lbl_8052C4C0 + 0xAC); xx < 8; xx++, p++) {
        if (p->active && p->id == id) return p;
    }
    return 0;
}
static void release(Entry *p) {
    u16 xx;
    u16 sound = p->sound;
    while (p->pending != 0) {
        fn_8022F0E0(fn_8022F77C(&p->pending));
    }
    p->active = 0;
    for (xx = 0, p = (Entry *)(lbl_8052C4C0 + 0xAC); xx < 8; xx++, p++) {
        if (p->active && p->sound == sound) return;
    }
    fn_8024A4A0(sound);
}
void fn_80243960(u32 arg0, s32 arg1) {
    Entry *p;
    p = find(arg0);
    if (p != 0) {
        if (arg1 == 0 && p->active == 2) {
            p->active = 3;
            fn_8024A8F4(arg0, p->tail);
            return;
        }
        if (p->callback != 0) p->callback(p->type, 0x101);
        release(p);
    }
}