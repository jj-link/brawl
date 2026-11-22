#pragma force_active on
#pragma use_lmw_stmw off

#include <types.h>

typedef struct Node {
    struct Node *end;
    struct Node *next;
    char *first;
    char *second;
} Node;

typedef struct Owner {
    u8 pad[0x34];
    Node *head;
} Owner;

typedef struct Context {
    u8 pad[0xC];
    Owner *owner;
} Context;

extern s32 fn_803974FC(void);
extern s32 fn_80397580(s32);
extern Context **fn_80397570(s32);
extern u8 *fn_80397578(s32, void *);
extern u8 *fn_80397564(s32);
extern s32 fn_80392810(char *);
extern s32 fn_803928F4(char *, s8);
extern s32 fn_80392B58(char *, s32);
extern s32 fn_80393350(s32, Owner *, char *, s32 *, s32);
extern s32 fn_80393454(s32, Owner *, u8 *, char *, s32, s32, s32);
extern s32 fn_803936B0(s32, char *, s32);

extern char lbl_804168B4[];
extern char lbl_8049170C[];
extern char lbl_8059FC6C[3];
extern char lbl_8059FC88[2];
extern char lbl_8059FC8C[2];

static inline u8 *get_buffer(u8 *p, s32 root, u8 **out, s32 *size)
{
    *out = fn_80397564(root);
    *size = 0;
    return p + 0x360;
}

s32 fn_80394220(s32 arg0)
{
    Node *node;
    char spC[12];
    s32 sp8;
    s32 r30;
    Owner *owner;
    u8 *r28;
    u8 *r31;
    Context *ctx;
    s32 root, r, len, i;

    root = fn_803974FC();
    r30 = fn_80397580(root);
    ctx = *fn_80397570(root);
    owner = ctx->owner;
    r28 = get_buffer(fn_80397578(root, ctx), root, &r31, &sp8);
    node = owner->head;
    while (node != 0) {
        sp8 += fn_80392810(node->first);
        sp8 += 1;
        if (node->second == 0) {
            if (fn_80393350(r30, owner, node->first, &sp8, 2) == 0)
                return 3;
        } else {
            sp8 += fn_80392810(node->second);
        }
        if (node == owner->head->end)
            break;
        sp8 += 1;
        node = node->next;
    }

    len = fn_80392B58(spC, sp8);
    r = fn_803936B0(arg0, lbl_804168B4, 0x31);
    if (r != 0) return r;
    r = fn_803936B0(arg0, lbl_8049170C, 0x10);
    if (r != 0) return r;
    r = fn_803936B0(arg0, spC, len);
    if (r != 0) return r;
    r = fn_803936B0(arg0, lbl_8059FC6C, 2);
    if (r != 0) return r;
    r = fn_803936B0(arg0, lbl_8059FC6C, 2);
    if (r != 0) return r;

    node = owner->head;
    while (node != 0) {
        for (i = 0; node->first[i] != 0; i++) {
            r = fn_803936B0(arg0, spC, fn_803928F4(spC, node->first[i]));
            if (r != 0) return r;
        }

        r = fn_803936B0(arg0, lbl_8059FC88, 1);
        if (r != 0) return r;

        if (node->second == 0) {
            r = fn_80393454(r30, owner, r28, node->first,
                            *(s32 *)(r31 + 0x7D0), arg0 + 0x324, 2);
            if (r != 0) return r;
        } else {
            for (i = 0; node->second[i] != 0; i++) {
                r = fn_803936B0(arg0, spC, fn_803928F4(spC, node->second[i]));
                if (r != 0) return r;
            }
        }

        if (node == owner->head->end)
            break;
        r = fn_803936B0(arg0, lbl_8059FC8C, 1);
        if (r != 0) return r;
        node = node->next;
    }

    return 0;
}
