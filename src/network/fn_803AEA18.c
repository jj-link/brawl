#include <types.h>
#pragma force_active on

typedef struct Entry {
    u16 flags;
    u16 pad;
    u32 start;
    u32 current;
    u32 first;
    u32 last;
    u32 count;
    u32 base;
    u32 pad1c;
    struct Entry *prev;
    struct Entry *next;
} Entry;

typedef struct Context {
    u8 pad0[8];
    u32 limit;
    u8 padc[8];
    u16 special;
    u8 pad16[6];
    s32 mode;
    u8 shift;
    u8 pad21[15];
    u32 boundary;
} Context;

extern Entry *fn_803AE7B4(Context *, Entry *);
extern int fn_803AE88C(Entry *, Entry **);
extern int fn_803AE918(Context *, Entry *);
extern int fn_803C7F98(Context *, int);

int fn_803AEA18(Context *ctx, Entry **head, u32 index, Entry **out, int *found)
{
    int dirty = 0;
    int result;
    Entry *entry;
    Entry *headEntry;
    Entry *node;

    *out = fn_803AE7B4(ctx, *head);
    if (*out != 0) {
        *found = 1;
    } else {
        *found = 0;
        if (fn_803AE88C(*head, out) == 0) {
            entry = *out;
            if (entry == 0) {
                *out = 0;
                return 0x1e;
            }
            if (entry != 0 && (entry->flags & 2) && entry->base != 0xffffffffU) {
                dirty = 1;
            }
            result = fn_803AE918(ctx, entry);
            if (result != 0) {
                *out = 0;
                return result;
            }
            (*out)->first = 0;
            (*out)->last = 0;
            if (dirty && fn_803C7F98(ctx, 1) != 0) {
                return 0x11;
            }
        }
        if (index != 0xffffffffU) {
            if ((*out)->flags & 4) {
                (*out)->base = index - index % (*out)->count;
                (*out)->current = (*out)->start + ((index % (*out)->count) << ctx->shift);
            } else {
                if (ctx->mode == 2 && (index < ctx->boundary || index >= ctx->limit) && index == ctx->special) {
                    (*out)->count = 1;
                }
                (*out)->base = index - index % (*out)->count;
                (*out)->current = (*out)->start + ((index % (*out)->count) << ctx->shift);
            }
        } else {
            (*out)->base = index;
            (*out)->current = (*out)->start;
        }
        (*out)->flags |= 1;
    }
    node = *out;
    headEntry = *head;
    if (node != headEntry) {
        if (node == headEntry->next) {
            *head = node;
        } else {
            node->next->prev = node->prev;
            node->prev->next = node->next;
            headEntry = *head;
            node->prev = headEntry;
            node->next = (*head)->next;
            headEntry->next = node;
            node->next->prev = node;
            *head = node;
        }
    }
    return 0;
}
