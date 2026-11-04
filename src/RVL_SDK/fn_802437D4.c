#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 state;
    u8 pad1[5];
    u16 unk6;
    u8 flag8;
    u8 addr[6];
    u8 pad15;
    u16 id;
    u8 pad12[0x12];
    u8 tail[0x3C];
} Entry;

typedef struct {
    u8 pad0[0x28];
    u8 level;
    u8 pad29[0x83];
    Entry entries[8];
} State;

extern State lbl_8052C4C0;
extern char lbl_8059EE10[8];
extern char lbl_80481F68[];
extern char lbl_80481FAC[];

extern void fn_802319E4(u32, const char *);
extern void fn_802319FC(u32, const char *, u16);
extern void fn_8024A764(void *, u32, u16, u32, u32);
extern void fn_8024A8F4(u16, void *);
extern void fn_8024AA7C(u16);
extern int fn_803F6150(void *, void *, u32);
extern void *memcpy(void *, const void *, u32);

void fn_802437D4(void *arg0, u16 arg1, u32 arg2, u32 arg3)
{
    u16 i;
    Entry *e;

    e = lbl_8052C4C0.entries;
    for (i = 0; i < 8; i++, e++) {
        if (e->state == 1 && e->id == arg2 && (e->flag8 == 0 || fn_803F6150(arg0, e->addr, 6) == 0)) {
            break;
        }
    }

    if (i == 8) {
        if (lbl_8052C4C0.level >= 2) {
            fn_802319E4(0xE0001, lbl_8059EE10);
        }
        if (lbl_8052C4C0.level >= 2) {
            fn_802319E4(0xE0001, lbl_80481F68);
        }
        if (lbl_8052C4C0.level >= 2) {
            fn_802319E4(0xE0001, lbl_8059EE10);
        }
        fn_8024AA7C(arg1);
        return;
    }

    e->state = 3;
    memcpy(e->addr, arg0, 6);
    e->unk6 = arg1;
    fn_8024A764(arg0, arg3, arg1, 0, 0);
    if (lbl_8052C4C0.level >= 4) {
        fn_802319FC(0xE0003, lbl_80481FAC, e->unk6);
    }
    fn_8024A8F4(arg1, e->tail);
}
