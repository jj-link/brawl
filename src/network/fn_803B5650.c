#pragma force_active on
typedef struct {
    char pad0[12];
    unsigned int stride;
    char pad10[8];
    unsigned short flags;
    char pad1a[2];
    int kind;
    unsigned char shift;
    char pad21;
    unsigned char count;
    char pad23[5];
    unsigned int base;
    char pad2c[0x1844];
    int callback_arg;
    char pad1874[0x1c];
    int (*callback)(int);
} Context;
extern int fn_803AFEDC(Context *, int, int);
int fn_803B5650(Context *ctx, int arg1, unsigned int arg2) {
    unsigned int offset;
    int result;
    unsigned int index;
    unsigned int sector;
    int status;
    switch (ctx->kind) {
    case 0: offset = (unsigned short)(arg2 + (arg2 >> 1)); break;
    case 1: offset = arg2 << 1; break;
    case 2: offset = arg2 << 2; break;
    default: return 15;
    }
    index = 1;
    sector = (unsigned short)(ctx->base + (offset >> ctx->shift));
    if (ctx->flags & 0x80) index = ctx->flags & 7;
    do {
        result = fn_803AFEDC(ctx, sector, arg1);
        if (result == 0x1000 && ctx->callback != 0) {
            status = ctx->callback(ctx->callback_arg);
            if (status == 0) continue;
            if (status == 1 && ctx->count >= 2 && index < ctx->count) {
                index++;
                sector += ctx->stride;
                continue;
            }
        }
        if (result != 0) return result;
    } while (result != 0);
    return result;
}