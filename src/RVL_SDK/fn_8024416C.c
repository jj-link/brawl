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
    void (*callback)(u16, u16);
    u8 pad4[0x3C];
} Entry;

extern u8 lbl_8052C4C0[];
extern const char lbl_80482000[];

extern void fn_80231A14(u32, const char *, s32, u32);

static Entry *find(u32 id)
{
    u16 i;
    Entry *p;
    for (i = 0, p = (Entry *)(lbl_8052C4C0 + 0xAC); i < 8; i++, p++) {
        if (p->active && p->id == id) {
            return p;
        }
    }
    return 0;
}

void fn_8024416C(u32 arg0, s32 arg1)
{
    Entry *p;

    if (lbl_8052C4C0[0x28] >= 4) {
        fn_80231A14(0xE0003, lbl_80482000, arg1, arg0);
    }

    p = find(arg0);
    if (p != 0) {
        p->callback(p->type, arg1 ? 0x103 : 0x104);
    }
}
