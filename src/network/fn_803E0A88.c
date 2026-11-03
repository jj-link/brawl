#pragma force_active on

typedef unsigned int u32;
typedef int s32;
typedef unsigned short u16;

struct TableEntry {
    u32 field0, field4, field8, fieldC, field10;
};

extern const struct TableEntry lbl_8041B0E0[];

struct Inner {
    char pad[0x1c];
    s32 state;
    char pad20[0x14];
    u32 count;
};

struct Outer {
    char pad[8];
    u32 *start;
    u32 cached;
    u32 cachedIndex;
    u32 index;
    u32 current;
    char pad1c[0x18];
    struct Inner *inner;
};

struct Node {
    u16 a, b;
};

extern s32 fn_803DA454(struct Inner *, s32, struct Node **, s32 *);
extern void fn_803DA55C(struct Inner *, struct Node *);
extern s32 fn_803DF760(struct Inner *, struct Node *, u32);
extern s32 fn_803E0110(struct Outer *, u32, u32, u32 *, u32 *, struct Node *);
extern s32 fn_803E0728(struct Outer *, u32, u32, u32 *, u32 *, s32);
extern s32 fn_803E02DC(struct Outer *, u32, u32, u32, s32);
extern s32 PFFAT_FreeChain(struct Outer *, u32, u32, s32);

s32 fn_803E0A88(struct Outer *arg0, u32 arg1, u32 arg2, u32 arg3,
                u32 *arg4, u32 *arg5)
{
    u32 next;
    u32 saved;
    s32 unused;
    u32 flag;
    struct Node *node;
    u32 max, end;
    u32 current, remain, count, pos;
    u32 *start;
    s32 result;
    u32 state;

    state = arg0->inner->state;
    *arg5 = -1;
    *arg4 = -1;
    end = lbl_8041B0E0[state].field4;

    if ((max = lbl_8041B0E0[state].field0, arg0->index != 0) &&
        arg0->index <= arg1) {
        saved = arg0->current;
        start = &saved;
        remain = arg1 - arg0->index;
        pos = arg0->index + 1;
    } else {
        start = arg0->start;
        remain = arg1;
        pos = 1;
    }

    current = *start;
    next = current;
    if (arg2 == 2) {
        if (remain != 0 && arg3 != 0)
            remain = remain + arg3 - 1;
        else
            remain = arg3;
        count = remain;
        if (arg0->cached != 0) {
            current = arg0->cached;
            remain = 0;
            count = arg0->cachedIndex + arg3 - arg1;
            next = lbl_8041B0E0[arg0->inner->state].field8;
            pos = arg0->cachedIndex + 1;
        }
    } else {
        if (arg2 == 1 && current == 0)
            remain++;
        count = remain;
    }

    if (remain != 0) {
        result = fn_803DA454(arg0->inner, -1, &node, &unused);
        if (result != 0)
            return result;

        result = fn_803DF760(arg0->inner, node, current);
        if (result != 0) {
            fn_803DA55C(arg0->inner, node);
            return result;
        }

        node->b = 0;
        flag = 1;
        while (remain-- != 0 && current < max) {
            if (current != 0) {
                result = fn_803E0110(arg0, current, pos, &next, &flag, node);
                if (result != 0 && next + 0x10000 != 0xffff) {
                    fn_803DA55C(arg0->inner, node);
                    return result;
                }
            } else {
                pos--;
                next = lbl_8041B0E0[arg0->inner->state].field8;
            }

            if ((next < 2 || next >= arg0->inner->count + 2) && next < end) {
                fn_803DA55C(arg0->inner, node);
                return 14;
            }

            if (arg2 != 0 && next >= end)
                break;

            current = next;
            pos++;
        }

        count = remain;
        fn_803DA55C(arg0->inner, node);
    }

    if (arg2 != 0 && next >= end) {
        *arg4 = 0;
        result = fn_803E0728(arg0, count + 1, pos, arg4, &next, 0);
        if (result != 0) {
            if (*arg4 + 0x10000 != 0xffff)
                PFFAT_FreeChain(arg0, *arg4, pos, -1);
            *arg4 = -1;
            next = -1;
        } else {
            result = 0;
        }

        if (result != 0)
            return result;
        if (next + 0x10000 == 0xffff)
            return 6;

        if (*start == 0) {
            *start = *arg4;
        } else {
            result = fn_803E02DC(arg0, current, pos - 1, *arg4, 1);
            if (result != 0)
                return result;
        }
        current = next;
    }

    *arg5 = current;
    return 0;
}
