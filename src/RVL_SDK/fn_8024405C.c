#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Entry {
    u8 state;
    u8 pad0[3];
    u16 type;
    u16 id;
    u8 pad1[0xC];
    u8 sub[0xC];
    void (*callback)(u16, u32);
    u8 pad2[0x3C];
} Entry;

extern u8 lbl_8052C4C0[];
extern void fn_8022F0E0(s32);
extern void fn_8022F500(void *, s32);

static Entry *find(u16 id)
{
    u16 xx;
    Entry *p;
    for (xx = 0, p = (Entry *)(lbl_8052C4C0 + 0xAC); xx < 8; xx++, p++) {
        if (p->state != 0 && p->id == id) {
            return p;
        }
    }
    return 0;
}

void fn_8024405C(u16 arg0, s32 arg1)
{
    Entry *p;

    p = find(arg0);
    if (p == 0) {
        fn_8022F0E0(arg1);
        return;
    }
    if (p->state == 4) {
        fn_8022F500(p->sub, arg1);
        p->callback(p->type, 0x102);
        return;
    }
    fn_8022F0E0(arg1);
}
