#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry {
    u8 pad0[0x10];
    u8 active;
    u8 state;
    u8 pad12[2];
    u16 value14;
    u16 value16;
    u16 value18;
    u16 value1a;
    u8 pad1c[0x18];
} Entry;

typedef void (*Callback)(u8, int, int, void *);

typedef struct Global {
    Entry entries[16];
    Callback callback;
    u8 pad344[0xbd];
    u8 debug;
    u8 pad402[6];
} Global;

extern Global lbl_8052C9B8;
extern char lbl_804825F4[];
extern u16 fn_8024A530(int, void *);
extern void fn_802319E4(int, const char *);

int fn_8024A1DC(int index)
{
    Entry *entry = &lbl_8052C9B8.entries[index];

    if (entry->active)
        return 9;

    entry->value14 = 0;
    entry->value16 = 0;
    entry->value1a = 0x100;
    entry->state = 1;
    entry->value14 = fn_8024A530(0x11, (u8 *)entry + 1);

    if (entry->value14 == 0) {
        if (lbl_8052C9B8.debug >= 2)
            fn_802319E4(0x1e0001, lbl_804825F4);

        lbl_8052C9B8.callback(
            (u8)((u32)(entry - lbl_8052C9B8.entries) / sizeof(Entry)),
            1, 14, 0);
    } else {
        entry->active = 1;
    }

    return 0;
}
