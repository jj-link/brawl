#include <types.h>
#include <internal/mem.h>
#pragma force_active on

extern u8 lbl_8052D9C0[];
extern void *fn_80257938(u32 key);
extern void *fn_80257994(void *self, u32 lo, u32 hi);

typedef struct Entry {
    u32 len;
    u8 *data;
} Entry;

typedef struct ByteArray {
    u8 bytes[80];
} ByteArray;

typedef struct Output {
    u8 pad[11];
    u8 a[80];
    u8 b[80];
    u8 c[80];
} Output;

static inline s32 attr_len(Entry *entry) {
    s32 len = 80;
    if (entry->len < 80) {
        len = (s32)entry->len;
    }
    return len;
}

s32 fn_80257250(u8 *out, u32 *key) {
    s32 result = 9;
    void *table;
    Entry *entry;
    u8 *src;
    s32 i;
    u8 *dst;
    s32 len;

    if (*key == 0) {
        *key = *(u32 *)(lbl_8052D9C0 + 0x121C);
    }

    table = fn_80257938(*key);
    if (table != 0) {
        memset(out, 0, 0xFA);
        result = 0;

        entry = (Entry *)fn_80257994(table, 0x200, 0x200);
        if (entry != 0) {
            *(u16 *)(out + 0) = (entry->data[0] << 8) + entry->data[1];
        }

        entry = (Entry *)fn_80257994(table, 0x201, 0x201);
        if (entry != 0) {
            *(u16 *)(out + 2) = (entry->data[0] << 8) + entry->data[1];
        }

        entry = (Entry *)fn_80257994(table, 0x202, 0x202);
        if (entry != 0) {
            *(u16 *)(out + 6) = (entry->data[0] << 8) + entry->data[1];
        }

        entry = (Entry *)fn_80257994(table, 0x203, 0x203);
        if (entry != 0) {
            *(u16 *)(out + 8) = (entry->data[0] << 8) + entry->data[1];
        }

        entry = (Entry *)fn_80257994(table, 0x205, 0x205);
        if (entry != 0) {
            *(u16 *)(out + 4) = (entry->data[0] << 8) + entry->data[1];
        }

        entry = (Entry *)fn_80257994(table, 0x204, 0x204);
        if (entry != 0) {
            out[10] = entry->data[0];
        }

        entry = (Entry *)fn_80257994(table, 0x0B, 0x0B);
        if (entry != 0) {
            len = attr_len(entry);
            src = entry->data;
            for (i = 0; i < len; i++) {
                ((ByteArray *)(out + 0x0B))->bytes[i] = *src++;
            }
        }

        entry = (Entry *)fn_80257994(table, 0x101, 0x101);
        if (entry != 0) {
            len = attr_len(entry);
            src = entry->data;
            for (i = 0; i < len; i++) {
                ((ByteArray *)(out + 0x5B))->bytes[i] = *src++;
            }
        }

        entry = (Entry *)fn_80257994(table, 0x0A, 0x0A);
        if (entry != 0) {
            len = attr_len(entry);
            src = entry->data;
            for (i = 0; i < len; i++) {
                ((ByteArray *)(out + 0xAB))->bytes[i] = *src++;
            }
        }
    } else {
        *key = 0;
    }

    return result;
}
