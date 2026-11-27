#pragma force_active on

#include <types.h>

typedef struct Node {
    struct Node *next;
    u16 id;
    u16 flags;
    u32 value;
} Node;

typedef struct Ctx {
    u32 pad0;
    u32 remain;
    u8 pad8[0x60];
    Node *cur;
} Ctx;

extern void fn_802319E4(s32, void *);
extern void fn_802319FC(s32, void *, u32);
extern u8 *fn_8025BA20(u8 *, u8, u32 *);
extern u8 fn_8025BAF0(u8 *);
extern u8 lbl_80484C80[];
extern u8 lbl_8052D9C0[];

static inline u8 *copy_bytes(u8 *dst, u8 *src, u32 *length)
{
    s32 i;
    for (i = 0; i < (s32)*length; i++) {
        *dst++ = *src++;
    }
    return src;
}

u8 *fn_802590D0(u8 *p, Ctx *ctx, Node **head, u16 id, Node *parent, u8 depth)
{
    u8 *base = lbl_80484C80;
    u32 need;
    u32 len;
    u32 size;
    Node *node;
    u32 t;
    u32 flagHi;
    u32 bits;
    u8 lvl;
    u8 *end;
    u32 v;
    s32 i;
    u8 *dst;
    u8 type;
    Node *n;

    type = *p;
    flagHi = depth & 0x80;
    lvl = depth & 0x7F;
    p = fn_8025BA20(p + 1, type, &len);
    t = (type >> 3) & 0xF;
    size = len & 0xFFF;
    len = size;
    need = ((size > 4 ? size + 8 : 0xC) + 3) & ~3;
    if (ctx->remain < need) {
        return 0;
    }
    node = ctx->cur;
    bits = (u32)(u16)t << 12;
    node->id = id;
    node->flags = (u16)len | bits;
    node->next = 0;

    switch (t) {
    case 0:
        break;
    case 1:
        if (flagHi != 0 && len == 2 && (u16)((p[0] << 8) + p[1]) == 4) {
            need = 0;
            ctx->cur = (Node *)((u8 *)ctx->cur + 0xC);
            ctx->remain -= 0xC;
            end = p + 2 + len;
            if (lvl >= 5) {
                if (lbl_8052D9C0[0x4630] >= 1) {
                    fn_802319E4(0xA0000, base + 0xD8);
                }
                return end;
            }
            p = fn_802590D0(p + 2, ctx, head, 4, node, (u8)(lvl + 1));
            goto done;
        }
        /* fall through */
    case 2:
        switch ((s32)len) {
        case 1:
            *(u8 *)&node->value = p[0];
            p += 1;
            break;
        case 2:
            *(u16 *)&node->value = (u16)((p[0] << 8) + p[1]);
            p += 2;
            break;
        case 4:
            node->value = ((p[0] << 24) + (p[1] << 16)) +
                          (p[3] + (p[2] << 8));
            p += 4;
            break;
        default:
            p = copy_bytes((u8 *)&node->value, p, &len);
            break;
        }
        break;
    case 3:
        switch ((s32)len) {
        case 2:
            *(u16 *)&node->value = (u16)((p[0] << 8) + p[1]);
            p += 2;
            break;
        case 4:
            v = ((p[0] << 24) + (p[1] << 16)) +
                (p[3] + (p[2] << 8));
            node->value = v;
            p += 4;
            if (v < 0x10000) {
                len = 2;
                node->flags = (u16)(bits | 2);
                *(u16 *)&node->value = (u16)node->value;
            }
            break;
        case 16:
            if (fn_8025BAF0(p) != 0) {
                if (p[0] == 0 && p[1] == 0) {
                    node->flags = (u16)((node->flags & ~0xFFF) | 2);
                    v = (p[2] << 8) + p[3];
                    p += 16;
                    *(u16 *)&node->value = (u16)v;
                } else {
                    node->flags = (u16)((node->flags & ~0xFFF) | 4);
                    v = ((p[0] << 24) + (p[1] << 16)) +
                        (p[3] + (p[2] << 8));
                    p += 16;
                    node->value = v;
                }
            } else {
                p = copy_bytes((u8 *)&node->value, p, &len);
            }
            break;
        default:
            if (lbl_8052D9C0[0x4630] >= 2) {
                fn_802319FC(0xA0001, base + 0xF4, len);
            }
            return p + len;
        }
        break;
    case 6:
    case 7:
        need = 0;
        ctx->cur = (Node *)((u8 *)ctx->cur + 0xC);
        ctx->remain -= 0xC;
        end = p + len;
        if (lvl >= 5) {
            if (lbl_8052D9C0[0x4630] >= 1) {
                fn_802319E4(0xA0000, base + 0xD8);
            }
            return end;
        }
        if (flagHi != 0 || id == 0xD) {
            lvl |= 0x80;
        }
        while (p < end) {
            p = fn_802590D0(p, ctx, head, 0, node, (u8)(lvl + 1));
            if (p == 0) {
                return 0;
            }
        }
        break;
    case 4:
    case 8:
        p = copy_bytes((u8 *)&node->value, p, &len);
        break;
    case 5:
        switch ((s32)len) {
        case 1:
            *(u8 *)&node->value = p[0];
            p += 1;
            break;
        default:
            if (lbl_8052D9C0[0x4630] >= 2) {
                fn_802319FC(0xA0001, base + 0x114, len);
            }
            return p + len;
        }
        break;
    default:
        break;
    }

done:
    ctx->cur = (Node *)((u8 *)ctx->cur + need);
    ctx->remain -= need;
    if (parent == 0) {
        n = *head;
        if (n == 0) {
            *head = node;
        } else {
            while (n->next != 0) {
                n = n->next;
            }
            n->next = node;
        }
    } else {
        n = *(Node **)&parent->value;
        if (n == 0) {
            *(Node **)&parent->value = node;
        } else {
            while (n->next != 0) {
                n = n->next;
            }
            n->next = node;
        }
    }
    return p;
}
