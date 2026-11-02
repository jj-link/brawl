#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

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
    u8 pad4[0x3C];
} Entry;

extern u8 lbl_8052C4C0[];
extern const char lbl_80481FD8[];

extern void fn_802319FC(int, const char *, int);
extern void fn_8024AB20(int);
extern void fn_8022F77C(void *);
extern void fn_8022F0E0(void);
extern void fn_8024A4A0(u16);

static Entry *find(u16 id)
{
    u16 xx;
    Entry *p;
    for (xx = 0, p = (Entry *)(lbl_8052C4C0 + 0xAC); xx < 8; xx++, p++) {
        if (p->active && p->id == id) {
            return p;
        }
    }
    return 0;
}

static void release(Entry *p)
{
    u16 xx;
    u16 sound = p->sound;

    while (p->pending != 0) {
        fn_8022F77C(&p->pending);
        fn_8022F0E0();
    }
    p->active = 0;

    for (xx = 0, p = (Entry *)(lbl_8052C4C0 + 0xAC); xx < 8; xx++, p++) {
        if (p->active && p->sound == sound) {
            return;
        }
    }
    fn_8024A4A0(sound);
}

void fn_80243E64(u16 arg0, s32 arg1)
{
    Entry *p;

    if (lbl_8052C4C0[0x28] >= 4) {
        fn_802319FC(0xE0003, lbl_80481FD8, arg0);
    }

    if ((p = find(arg0)) == 0) {
        return;
    }
    if (arg1 != 0) {
        fn_8024AB20(arg0);
    }
    p->callback(p->type, 0x101);
    release(p);
}
