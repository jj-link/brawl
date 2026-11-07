#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 flags; int best; int previous; int index; int first; int active; } Context;
extern int fn_803A3540(u16 *, int);
extern int fn_803A5C38(int);
extern int fn_803A5C60(int);
extern int fn_803A5C88(int);
int fn_803A367C(Context *ctx, u16 *out) {
    u16 index;
    unsigned int descending;
    int found = 0;
    int (*get)(int);
    int status, value;
    if (!ctx->active) return -3;
    descending = ctx->flags >> 31;
    switch ((u16)ctx->flags) {
    case 0: get = fn_803A5C38; break;
    case 1: get = fn_803A5C60; break;
    case 2: get = fn_803A5C88; break;
    default: return -3;
    }
    if (!ctx->first) {
        status = fn_803A3540(&index, 1);
        while (status >= 0) {
            value = get(index);
            if (value == ctx->best && ctx->index < index) {
                *out = index;
                ctx->best = value;
                ctx->index = index;
                ctx->previous = value;
                return 0;
            }
            status = fn_803A3540(&index, 0);
        }
    } else {
        ctx->first = 0;
    }
    if (!(ctx->flags & 0x80000000)) ctx->best = 0x7fffffff;
    else ctx->best = 0x80000001;
    status = fn_803A3540(&index, 1);
    while (status >= 0) {
        int a, b, prev, best;
        value = get(index);
        prev = ctx->previous;
        a = descending ? value < prev : prev < value;
        if (a) {
            best = ctx->best;
            b = descending ? best < value : value < best;
            if (b) {
                found = 1;
                *out = index;
                ctx->best = value;
                ctx->index = index;
            }
        }
        status = fn_803A3540(&index, 0);
    }
    if (found) {
        ctx->previous = ctx->best;
        return 0;
    }
    ctx->active = 0;
    return -15;
}