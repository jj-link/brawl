#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

typedef struct Owner {
    u8 pad[0x72];
    u8 state;
} Owner;

typedef struct Entry {
    u8 pad0[2];
    u8 kind;
    u8 pad3[0xA];
    u8 id;
    u8 padE[4];
    u16 count;
    u16 count2;
    u8 pad16[0xE];
    u8 flag;
    u8 pad25[0x73];
    s16 value;
} Entry;

extern unsigned char lbl_8052D5A8[];
extern char lbl_80483F58[];

extern Entry *fn_80251AD0(Owner *, u16);
extern void fn_80231A44(u32, const char *, u16, u16, u32, s16);
extern void fn_80254594(Owner *, u8, u16);

void fn_80250828(Owner *arg0, u16 arg1, u16 arg2, u32 arg3, s16 arg4)
{
    Entry *entry;

    entry = fn_80251AD0(arg0, arg1);
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_80231A44(0x90003, lbl_80483F58, arg1, arg2, arg3, arg4);
    }

    if (entry != 0) {
        if (arg0->state == 0) {
            if (arg3 == 0xE0U) {
                arg0->state = 2;
            } else {
                arg0->state = 1;
            }
        }

        if (entry->count < arg2) {
            arg2 = entry->count;
        }
        entry->count = arg2;
        entry->count2 = arg2;

        if (arg0->state == 2) {
            entry->value = arg4;
            if (arg4 == 0) {
                entry->flag = 1;
            }
        }

        if (entry->kind == 1) {
            fn_80254594(arg0, entry->id, entry->count);
        }
    }
}
