#include <types.h>
#pragma force_active on
typedef struct Node {
    u16 flags;
    u16 pad;
    u32 start;
    u32 current;
    u32 first;
    u32 last;
    u32 count;
    u32 base;
    u32 pad1c;
    struct Node *prev;
    struct Node *next;
} Node;
typedef struct Owner {
    u8 pad0[8];
    u32 limit;
    u8 padc[8];
    u16 special;
    u8 pad16[6];
    s32 mode;
    u8 shift;
    u8 pad21[15];
    u32 boundary;
} Owner;
extern Node *fn_803D911C(Owner *, Node *, u32);
extern int fn_803D91F4(Node *, Node **);
extern int fn_803D9280(Owner *, Node *);
int fn_803D936C(Owner *ctx, Node **head, u32 index, Node **out, int *found)
{
    int result;
    Node *entry;
    Node *headEntry;
    Node *node;
    *out = fn_803D911C(ctx, *head, index);
    if (*out != 0) {
        *found = 1;
    } else {
        *found = 0;
        if (fn_803D91F4(*head, out) == 0) {
            entry = *out;
            if (entry == 0) {
                *out = 0;
                return 0x1e;
            }
            result = fn_803D9280(ctx, entry);
            if (result != 0) {
                *out = 0;
                return result;
            }
            (*out)->first = 0;
            (*out)->last = 0;
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