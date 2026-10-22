#pragma force_active on
typedef float f32;

struct CopyStruct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    int v28;
    int v2C;
    int v30;
    int v34;
    f32 f38;
    f32 f3C;
    int v40;
    int v44;
    int v48;
    int v4C;
    int v50;
};

void fn_8028965C(struct CopyStruct* dst, const struct CopyStruct* src) {
    dst->f0 = src->f0;
    dst->f4 = src->f4;
    dst->f8 = src->f8;
    dst->fC = src->fC;
    dst->f10 = src->f10;
    dst->f14 = src->f14;
    dst->f18 = src->f18;
    dst->f1C = src->f1C;
    dst->f20 = src->f20;
    dst->f24 = src->f24;
    dst->v28 = src->v28;
    dst->v2C = src->v2C;
    dst->v30 = src->v30;
    dst->v34 = src->v34;
    dst->f38 = src->f38;
    dst->f3C = src->f3C;
    dst->v40 = src->v40;
    dst->v44 = src->v44;
    dst->v48 = src->v48;
    dst->v4C = src->v4C;
    dst->v50 = src->v50;
}
