#pragma force_active on
#pragma use_lmw_stmw on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct Grid {
    u16 width, height, x, y;
    u8 flag8, flag9;
} Grid;

typedef struct Context {
    char pad0[0x10];
    int reset;
    int remaining;
    char pad18[0xc];
    int (*callback)(int, int, Grid *);
    int (*callback2)(int, int, int, Grid *);
    char pad2c[0x1580 - 0x2c];
    Grid grid;
    char pad158a[0x1634 - 0x158a];
    char state[0xc];
    u8 done;
} Context;

typedef struct Work {
    Context *ctx;
    char pad4[8];
    u16 x, y;
    u32 pos;
} Work;

extern void fn_8026D514(void *, u32 *);
extern void fn_8026D4DC(Context *);
extern int fn_8026D4BC(void *);

int fn_8026D53C(Context *ctx, Work *work, int count, int interval)
{
    Grid *grid;
    int x;
    int y;
    int width_m1;
    int height_m1;
    int total;
    int n;
    int remaining;
    int batch;
    int ret;

    grid = &ctx->grid;
    n = 0;
    batch = 0;
    remaining = ctx->remaining;
    width_m1 = grid->width - 1;
    y = grid->y;
    total = grid->width * grid->height;
    x = grid->x;
    height_m1 = grid->height - 1;

    goto L668;

L590:
    batch++;
    if (batch < interval) goto L5D0;
    ret = ctx->callback(x, y, grid);
    if (ret < 0) return ret;
    batch = 0;
    fn_8026D514(ctx->state, &work->pos);

L5D0:
    remaining--;
    n--;
    x++;
    if (remaining != 0) goto L5EC;
    fn_8026D4DC(ctx);
    remaining = ctx->reset;

L5EC:
    if (x >= width_m1) goto L5FC;
    if (n < count) goto L590;

L5FC:
    if (n >= count) goto L668;
    batch++;
    if (batch < interval) goto L648;
    ret = ctx->callback2(x, y, 0, grid);
    if (ret < 0) return ret;
    batch = 0;
    fn_8026D514(ctx->state, &work->pos);

L648:
    remaining--;
    x = 0;
    n--;
    y++;
    if (remaining != 0) goto L668;
    fn_8026D4DC(ctx);
    remaining = ctx->reset;

L668:
    if (y >= height_m1) goto L6DC;
    if (n < count) goto L5EC;
    goto L6DC;

L67C:
    batch++;
    if (batch < interval) goto L6C0;
    ret = ctx->callback2(x, y, 1, grid);
    if (ret < 0) return ret;
    batch = 0;
    fn_8026D514(ctx->state, &work->pos);

L6C0:
    remaining--;
    n--;
    x++;
    if (remaining != 0) goto L6DC;
    fn_8026D4DC(ctx);
    remaining = ctx->reset;

L6DC:
    if (x >= width_m1) goto L6EC;
    if (n < count) goto L67C;

L6EC:
    if (n >= count) goto L778;
    if (batch + 1 < interval) goto L734;
    ret = ctx->callback2(x, y, 2, grid);
    if (ret < 0) return ret;
    fn_8026D514(ctx->state, &work->pos);

L734:
    remaining--;
    x = 0;
    y++;
    if (remaining != 0) goto L750;
    fn_8026D4DC(ctx);
    remaining = ctx->reset;

L750:
    fn_8026D4BC(ctx);
    if (ctx->done != 0) {
        fn_8026D514(ctx->state, &work->pos);
        return -3;
    }

L778:
    grid->x = x;
    work->x = x;
    grid->y = y;
    work->y = y;
    ctx->remaining = remaining;
    fn_8026D514(ctx->state, &work->pos);
    return (total - x) - y * grid->width;
}
