#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct FnObject {
    u8 flags;
    u8 hasSource;
    u8 hasAlt;
    u8 pad03;
    s32 kind;
    s32 field08;
    s32 field0C;
    u16 width;
    u16 height;
    s32 field14;
    u8 loaderState[0x20];
    u8 extraState[0x40];
};

struct Resource {
    u8 pad00[0x10];
    s32 relative;
    u8 pad14[4];
    u32 value;
    u16 size;
};

struct ParseLocals {
    u8 special;
    u8 pad11;
    u16 width;
    u16 height;
    u16 pad16;
    u32 file;
    u32 formatA;
    u32 formatB;
    float x;
    float y;
};

extern "C" void fn_80192B00(const void *, u32 *, u16 *, u16 *, u32 *, float *, float *, u8 *);
extern "C" void fn_80192A44(const void *, u32 *, u16 *, u16 *, u32 *, float *, float *, u8 *);
extern "C" void fn_801F2AFC(void *, u32, u16, u16, u32, u32, u32, u8, u32);
extern "C" void fn_801F28F0(void *, u32, u16, u16, u32, u32, u32, u8);
extern "C" void fn_801F2B44(void *, s32, s32, s32, s32, s32, float, float, float);
extern "C" u16 fn_801F2D0C(void *);
extern "C" u16 fn_801F2D20(void *);
extern "C" void fn_801F3004(void *, const void *, u32, u16);
extern "C" const float lbl_90_rodata_0;

extern "C" void fn_90_7A3C(
    FnObject *out,
    s32 kind,
    s32 field08,
    s32 field0C,
    u8 flags,
    const Resource * const *source,
    const Resource * const *extra
) {
    const Resource *resource = *source;
    out->kind = kind;
    out->field08 = field08;
    out->field0C = field0C;
    out->flags = flags;
    out->hasSource = (-(u32)resource | (u32)resource) >> 31;
    out->field14 = -1;

    if (out->hasSource) {
        ParseLocals locals;

        if (resource->value & 1) {
            fn_80192B00(
                source,
                &locals.file,
                &locals.width,
                &locals.height,
                &locals.formatA,
                &locals.x,
                &locals.y,
                &locals.special
            );
            fn_801F2AFC(
                out->loaderState,
                locals.file,
                locals.width,
                locals.height,
                locals.formatA,
                0,
                0,
                locals.special,
                0
            );
        } else {
            fn_80192A44(
                source,
                &locals.file,
                &locals.width,
                &locals.height,
                &locals.formatB,
                &locals.x,
                &locals.y,
                &locals.special
            );
            fn_801F28F0(
                out->loaderState,
                locals.file,
                locals.width,
                locals.height,
                locals.formatB,
                0,
                0,
                locals.special
            );
        }

        if (locals.special) {
            fn_801F2B44(
                out->loaderState, 3, 1, 0, 0, 0,
                locals.x, locals.y, lbl_90_rodata_0
            );
        } else {
            fn_801F2B44(
                out->loaderState, 1, 1, 0, 0, 0,
                locals.x, locals.y, lbl_90_rodata_0
            );
        }

        if (out->kind != 4) {
            out->width = fn_801F2D0C(out->loaderState);
            out->height = fn_801F2D20(out->loaderState);
        } else {
            out->width = 0x40;
            out->height = 0x40;
        }

        out->hasAlt = (*source)->value & 1;

        if (out->hasAlt) {
            const Resource *r = *extra;
            s32 relative = r->relative;
            u16 size = r->size;
            u32 value = r->value;
            const void *data;

            if (relative != 0) {
                data = (const void *)((const u8 *)r + relative);
            } else {
                data = 0;
            }

            fn_801F3004(out->extraState, data, value, size);
        }
    } else {
        out->width = 0;
        out->height = 0;
        out->hasAlt = 0;
    }
}
