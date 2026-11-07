#include <stdlib.h>
#include <string.h>
#pragma force_active on

typedef struct Entry {
    char pad0[0x14];
    unsigned char flags;
    char pad15[7];
    int time;
    int value;
    char pad24[4];
    unsigned char field28;
} Entry;
typedef struct Context {
    char pad0[8];
    char queue[0x24];
    unsigned char keys[0x14];
    int count;
    void (*callback)(struct Context *, int, Entry *, void *);
    void *userdata;
} Context;
extern char *lbl_804901F0[];
extern char lbl_80490D34[];
extern int fn_8035D728(void);
extern void fn_80387A3C(void *, Entry *);
extern void fn_80387AB0(Context *, Entry *);
extern int fn_8038A298(const unsigned char *, int);
extern void fn_8038866C(Entry *, const char *, const unsigned char *);
extern void fn_80388D68(Entry *, unsigned char *, int);
extern void fn_80388B84(Entry *, unsigned char *, int);

void fn_80387F48(Context *ctx, Entry *entry, unsigned char *data, int size) {
    int i;
    int remaining;
    unsigned char *pos;
    int length;
    if ((signed char)data[0] == 0 || (signed char)data[0] == 9) {
        pos = data + 5;
        remaining = size - 5;
        if (entry->flags & 0x80) {
            entry->flags &= 0x7f;
            if (remaining > 0) {
                entry->value = atoi((char *)pos);
                fn_80387A3C(ctx->queue, entry);
                fn_80387AB0(ctx, entry);
                ctx->callback(ctx, 3, entry, ctx->userdata);
                return;
            }
        } else if (entry->flags & 4) {
            for (i = 0; i < ctx->count; i++) {
                length = fn_8038A298(pos, remaining);
                if (length < 0) break;
                fn_8038866C(entry, lbl_804901F0[ctx->keys[i]], pos);
                pos += length;
                remaining -= length;
            }
            entry->flags |= 0x41;
        } else if ((signed char)*pos != 0 && strncmp(lbl_80490D34, (char *)pos, 8) == 0) {
            fn_80388D68(entry, pos, remaining);
            if (entry->field28 != 0xff) return;
            entry->flags |= 0x43;
        } else {
            fn_80388B84(entry, pos, remaining);
            entry->flags |= 0x43;
        }
        entry->flags &= 0xf3;
        entry->time = fn_8035D728() - entry->time;
        fn_80387A3C(ctx->queue, entry);
        ctx->callback(ctx, 0, entry, ctx->userdata);
    }
}