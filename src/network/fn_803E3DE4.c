#include <types.h>
#include <revolution/VF/pf_sector.h>
#pragma force_active on

typedef struct Fmt {
    u16 size;
    u8 pad[0x1E];
    u8 shift;
} Fmt;

typedef struct Mgr {
    u8 pad[0x264];
    u32 endPos;
    Fmt *fmt;
} Mgr;

typedef struct Ctx {
    u8 pad0[8];
    Mgr *mgr;
    u8 pad1[0x10];
    u32 unk1C;
    s32 unk20;
    u32 unk24;
    u16 unk28;
} Ctx;

extern void fn_803DAAE8(void *, int);
extern s32 fn_803E1414(void *, u32, s32, void *);

s32 fn_803E3DE4(Ctx *ctx, void *buf, u32 size, s32 *out)
{
    int sp8;
    Fmt *fmt;
    Fmt *f;
    s32 ret;
    u32 n;
    u32 oldUnk20;
    u32 temp;
    u32 cand;

    *out = 0;
    if (ctx->unk28 == 0)
        return 0;

    if (ctx == 0)
        fmt = 0;
    else
        fmt = ctx->mgr->fmt;

    n = fmt->size - ctx->unk28;
    if (size > n)
        size = n;

    if ((u32)(ctx->unk20 + 0x10000) == 0xFFFF) {
        ret = fn_803E1414((char *)ctx->mgr + 4, ctx->unk24, 0, &ctx->unk20);
        if (ret != 0)
            return ret;

        if ((u32)(ctx->unk20 + 0x10000) == 0xFFFF) {
            ctx->unk1C = ctx->mgr->endPos;
            if (ctx == 0)
                f = 0;
            else
                f = ctx->mgr->fmt;

            ctx->unk24 = ctx->unk1C >> f->shift;
            ctx->unk28 = ctx->unk1C & (f->size - 1);
            return 0x1C;
        }
    }

    ret = PFSEC_WriteData(fmt, buf, ctx->unk20, ctx->unk28, size, &sp8, 1);
    if (ret != 0 && sp8 == 0)
        return ret;

    *out = sp8;
    oldUnk20 = ctx->unk20;
    n = sp8;
    if (ctx == 0)
        f = 0;
    else
        f = ctx->mgr->fmt;

    temp = ctx->unk28 + n;
    cand = oldUnk20 + (temp >> f->shift);
    if ((f->size - 1) & temp)
        ctx->unk20 = cand;
    else
        ctx->unk20 = -1;

    ctx->unk1C += n;
    if (ctx->unk1C > ctx->mgr->endPos)
        ctx->mgr->endPos = ctx->unk1C;

    if (ctx == 0)
        f = 0;
    else
        f = ctx->mgr->fmt;

    ctx->unk24 = ctx->unk1C >> f->shift;
    ctx->unk28 = ctx->unk1C & (f->size - 1);
    fn_803DAAE8(ctx, (int)cand);

    if ((u32)sp8 != size)
        return ret;
    return 0;
}
