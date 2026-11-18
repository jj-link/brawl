#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

typedef struct ListNode {
    void *prev;
    struct ListNode *next;
    char pad[0xC];
    s32 flag;
} ListNode;

typedef struct Owner {
    char pad0[8];
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    char pad1[4];
    char *f24;
    char pad2[0xC];
    ListNode *f34;
    char pad3[0x14];
    char arr4C[0x5C];
    s32 fA8;
    char pad5[0x24];
    s32 fD0;
    char pad6[0x110];
    char arr1E4[0x5C];
    s32 f240;
} Owner;

typedef struct Ctx {
    char pad[0xC];
    Owner *owner;
} Ctx;

typedef struct Self {
    char pad[0x324];
    s32 f324;
    char pad2[8];
    s32 f330;
} Self;

typedef struct NetObj {
    char pad[0x7D0];
    s32 f7D0;
} NetObj;

extern char lbl_804916B0[0x5C];
extern char lbl_8059FC64[7];
extern char lbl_8059FC6C[3];
extern char lbl_8059FC90[5];
extern char lbl_8059FC98[6];
extern char lbl_8059FCA0[6];
extern char lbl_8059FCA8[2];

extern void *fn_803974FC(void);
extern Ctx **fn_80397570(void);
extern void *fn_80397580(void *root, Ctx *ctx);
extern NetObj *fn_80397564(void *root);
extern s32 fn_80397578(void *root);
extern s32 *fn_803970CC(void *lock, Owner *owner);
extern s32 fn_80392730(const char *s);
extern s32 fn_803936B0(Self *self, const char *p, s32 n);
extern s32 fn_80393BFC(Self *self);
extern s32 fn_80393CF4(Self *self);
extern s32 fn_80393E7C(Self *self);
extern s32 fn_80394220(Self *self);
extern s32 fn_803925B8(Owner *o, s32 a, void *b, s32 c, s32 d);
extern void fn_80392738(void *dst, s32 n);

s32 fn_80394B44(Self *arg0) {
    s32 res;
    s32 six;
    char *base = lbl_804916B0;
    void *root;
    Ctx *ctx;
    Owner *owner;
    Owner *owner2;
    void *lock;
    NetObj *net;
    s32 *p;
    void *buf;
    s32 len;
    s32 ret;
    s32 r;
    s32 t;
    ListNode *head;
    s32 found;
    ListNode *node;

    root = fn_803974FC();
    ctx = *fn_80397570();
    owner = ctx->owner;
    lock = fn_80397580(root, ctx);
    net = fn_80397564(root);
    p = fn_803970CC(lock, owner);
    buf = (void *)(fn_80397578(root) + 0x360);
    len = fn_80392730(owner->f24);
    arg0->f330 = 10;
    ret = 0;
    if (p != 0) {
        *p = 2;
    }
    arg0->f324 = 0;
    switch (owner->f1C) {
    case 0:
        ret = fn_803936B0(arg0, lbl_8059FC90, 4);
        break;
    case 1:
        ret = fn_803936B0(arg0, lbl_8059FC98, 5);
        break;
    case 2:
        ret = fn_803936B0(arg0, lbl_8059FCA0, 5);
        break;
    }
    if (ret != 0) return ret;
    if (owner->fC != 0 && owner->f8 == 0) {
        ret = fn_803936B0(arg0, owner->f24, len);
        if (ret != 0) return ret;
    } else if (len > owner->f18) {
        ret = fn_803936B0(arg0, owner->f24 + owner->f18, len - owner->f18);
        if (ret != 0) return ret;
    } else {
        ret = fn_803936B0(arg0, lbl_8059FCA8, 1);
        if (ret != 0) return ret;
    }
    ret = fn_803936B0(arg0, base + 0xC, 0xB);
    if (ret != 0) return ret;
    six = (owner->f8 != 0) + 7;
    ret = fn_803936B0(arg0, lbl_8059FC64, 6);
    if (ret != 0) return ret;
    ret = fn_803936B0(arg0, owner->f24 + six, owner->f14 - six);
    if (ret != 0) return ret;
    ret = fn_803936B0(arg0, lbl_8059FC6C, 2);
    if (ret != 0) return ret;
    if (owner->fC != 0 && owner->f8 == 0) {
        fn_803974FC();
        owner2 = (*fn_80397570())->owner;
        if (owner2->f240 == 0) {
            ret = 0;
        } else {
            ret = fn_803936B0(arg0, base + 0x40, 0x1B);
            switch (ret) {
            case 0:
                break;
            default:
                goto proxy_auth_done;
            }
            ret = fn_803936B0(arg0, owner2->arr1E4, owner2->f240);
            switch (ret) {
            case 0:
                break;
            default:
                goto proxy_auth_done;
            }
            ret = fn_803936B0(arg0, lbl_8059FC6C, 2);
            ret = ret & ((-ret | ret) >> 31);
        }
proxy_auth_done:
        if (ret != 0) return ret;
    }
    fn_803974FC();
    owner2 = (*fn_80397570())->owner;
    if (owner2->fA8 == 0) {
        ret = 0;
    } else {
        ret = fn_803936B0(arg0, base + 0x70, 0x15);
        switch (ret) {
        case 0:
            break;
        default:
            goto auth_done;
        }
        ret = fn_803936B0(arg0, owner2->arr4C, owner2->fA8);
        switch (ret) {
        case 0:
            break;
        default:
            goto auth_done;
        }
        ret = fn_803936B0(arg0, lbl_8059FC6C, 2);
        ret = ret & ((-ret | ret) >> 31);
    }
auth_done:
    if (ret != 0) return ret;
    ret = fn_80393BFC(arg0);
    if (ret != 0) return ret;
    if (owner->f1C == 1) {
        if (owner->f10 != 0) {
            r = fn_80393CF4(arg0);
        } else {
            if (owner->fD0 == 0) {
                found = 0;
                head = owner->f34;
                node = head;
                while (node != 0) {
                    if (node->flag != 0) {
                        found = 1;
                        break;
                    }
                    if ((u32)node == (u32)head->prev) break;
                    node = node->next;
                }
            } else {
                found = (owner->fD0 == 2);
            }
            if (found != 0) r = fn_80393E7C(arg0);
            else r = fn_80394220(arg0);
        }
        if (r != 0) {
            if (r == 3) arg0->f330 = 3;
            return r;
        }
    } else {
        ret = fn_803936B0(arg0, lbl_8059FC6C, 2);
        if (ret != 0) return ret;
    }
    res = 0;
    if (arg0->f324 > 0) {
        t = fn_803925B8(owner, net->f7D0, buf, arg0->f324, 0);
        arg0->f324 = 0;
        fn_80392738(buf, 0x100);
        if (t < 0) res = 1;
        if (t == 0) res = 2;
    }
    arg0->f324 = 0;
    fn_80392738(buf, 0x100);
    return res;
}
