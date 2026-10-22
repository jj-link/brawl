#pragma force_active on
typedef struct Ctx {
    float *p0;
    int pad4;
    unsigned int *p8;
} Ctx;

void fn_8028F960(float *src, void *unused, Ctx *ctx) {
    float *dst = ctx->p0;
    unsigned int *cmd = ctx->p8;
    float d, c, b, a;
    a = src[0];
    *cmd = 0x11040004;
    b = src[1];
    dst[0] = a;
    c = src[2];
    dst[1] = b;
    d = src[3];
    dst[2] = c;
    dst[3] = d;
    ctx->p8 = cmd + 1;
    ctx->p0 = ctx->p0 + 4;
}
