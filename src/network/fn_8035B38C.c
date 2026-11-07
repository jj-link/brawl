#include <string.h>
#pragma force_active on
typedef struct {
    unsigned int state[4];
    unsigned int count[2];
    unsigned char buffer[64];
} Context;
extern void fn_8035B5FC(Context *, const unsigned char *);
void fn_8035B38C(Context *ctx, const unsigned char *data, unsigned int len) {
    unsigned int index, part, i;
    unsigned int bits = len << 3;
    index = (ctx->count[0] >> 3) & 63;
    ctx->count[0] += bits;
    if (ctx->count[0] < bits)
        ctx->count[1]++;
    ctx->count[1] += len >> 29;
    part = 64 - index;
    if (len >= part) {
        memcpy(ctx->buffer + index, data, part);
        fn_8035B5FC(ctx, ctx->buffer);
        for (i = part; i + 63 < len; i += 64)
            fn_8035B5FC(ctx, data + i);
        index = 0;
    } else {
        i = 0;
    }
    memcpy(ctx->buffer + index, data + i, len - i);
}