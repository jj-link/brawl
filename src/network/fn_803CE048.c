#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Entry {
    u16 count;
    u16 pad;
    u32 offset;
} Entry;

typedef struct Blob {
    char pad_00[0x94];
    u32 base;
    u32 flag;
} Blob;

extern s32 lbl_8041ACC0[];
extern s32 fn_803CD270(void);
extern Blob *fn_803CD2E0(void);
extern void *fn_803CDAC8(void *dst, Blob *blob, s32 type, u32 index);
extern void *memcpy(void *dst, const void *src, unsigned long n);

void *fn_803CE048(s32 arg0, u32 arg1, void *arg2) {
    s32 type;
    Blob *blob;
    Blob *blob2;
    Entry *entry;
    u32 base;
    u32 *table;
    u32 start;
    u32 off;
    u32 end;
    s32 flag;

    type = lbl_8041ACC0[arg0];
    if (fn_803CD270() == 0) {
        arg2 = 0;
    } else {
        blob = fn_803CD2E0();
        if (blob == 0) {
            arg2 = 0;
        } else {
            entry = (Entry *)((u8 *)blob + type * 8);
            if (arg1 >= entry->count) {
                arg2 = 0;
            } else {
                if (fn_803CD270() == 0) {
                    flag = 0;
                } else {
                    blob2 = fn_803CD2E0();
                    if (blob2 == 0) {
                        flag = 0;
                    } else {
                        flag = blob2->flag;
                    }
                }
                if (flag != 0) {
                    base = blob->base;
                    off = entry->offset;
                    table = (u32 *)(base + off);
                    start = table[(u16)arg1];
                    end = table[arg1 + 1];
                    memcpy(arg2, (u8 *)base + (off + start + entry->count * 4 + 4), end - start);
                } else {
                    arg2 = fn_803CDAC8(arg2, blob, type, arg1);
                }
            }
        }
    }
    return arg2;
}
