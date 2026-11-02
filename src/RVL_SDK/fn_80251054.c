#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry {
    u8 id;
    u8 pad1[0xE];
    u8 flags;
    u8 pad10[0x78];
    u32 mask;
    void (*cb)(u32, u8);
} Entry;

extern void fn_802319E4(u32, const char *);
extern Entry *fn_80251AD0(const u8 *, u16);
extern unsigned char lbl_8052D5A8[];
extern char lbl_80484098[];

void fn_80251054(const u8 *arg0, u16 arg1, u32 arg2) {
    Entry *entry;
    u32 bits;
    void (*cb)(u32, u8);
    u32 masked;

    entry = fn_80251AD0(arg0, arg1);
    bits = 0;
    if (lbl_8052D5A8[0x414] >= 4U) {
        fn_802319E4(0x90003, lbl_80484098);
    }
    if (entry != 0) {
        entry->flags = entry->flags | arg2;
        if (arg2 & 2) {
            bits |= 0x2000;
        }
        if (arg2 & 1) {
            bits |= 0x40;
        }
        if (arg2 & 0xFC) {
            bits |= 0x80;
        }
        cb = entry->cb;
        if (cb != 0) {
            masked = entry->mask & bits;
            if (masked != 0) {
                cb(masked, entry->id);
            }
        }
    }
}
