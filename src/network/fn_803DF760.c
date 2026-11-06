#pragma force_active on
typedef struct {
    unsigned short size;
    char pad02[10];
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
    char pad2c[0x1f58];
    int callback_arg;
    char pad1f88[0x38];
    int (*callback)(int);
} Context;
typedef struct {
    char pad0[8];
    unsigned char *data;
    char padc[12];
    unsigned int position;
} Buffer;
extern int fn_803E8DC0(Context *, unsigned char *, unsigned int, unsigned int, unsigned short);
int fn_803DF760(Context *ctx, Buffer *buffer, unsigned int arg2) {
    unsigned int offset;
    int result;
    unsigned int index;
    int status;
    switch (ctx->kind) {
    case 0: offset = (unsigned short)(arg2 + (arg2 >> 1)); break;
    case 1: offset = arg2 << 1; break;
    case 2: offset = arg2 << 2; break;
    default: return 15;
    }
    index = 1;
    buffer->position = (unsigned short)(ctx->base + (offset >> ctx->shift));
    if (ctx->flags & 0x80) index = ctx->flags & 7;
    do {
        result = fn_803E8DC0(ctx, buffer->data, buffer->position, 0, ctx->size);
        if (result == 0x1000 && ctx->callback != 0) {
            status = ctx->callback(ctx->callback_arg);
            if (status == 0) continue;
            if (status == 1 && ctx->count >= 2 && index < ctx->count) {
                index++;
                buffer->position += ctx->stride;
                continue;
            }
        }
        if (result != 0) return result;
    } while (result != 0);
    return result;
}