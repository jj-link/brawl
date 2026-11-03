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
    char pad28[0x1580-0x28];
    Grid grid;
    char pad158a[0x1634-0x158a];
    char state[0xc];
    u8 done;
} Context;
typedef struct Work {
    Context *ctx;
    char pad4[8];
    u16 x, y;
    u32 pos;
    char pad14[0x48-0x14];
    int a, b, c, d;
    int start, end1, end2, current;
} Work;
extern int fn_8026D53C(Context *, Work *, int, int);
extern void fn_8026D514(void *, u32 *);
extern void fn_8026D4DC(Context *);
extern int fn_8026D4BC(void *);

int fn_8026C930(Work *work, int count, int data, int interval)
{
    int remaining, processed, batch, total, width, height, x, y;
    int result;
    Context *ctx;
    Grid *grid;
    ctx = work->ctx;
    grid = &ctx->grid;

    work->start = data;
    work->current = data;
    work->end1 = data + work->a * work->b;
    work->end2 = data + work->c * work->d;
    if (grid->flag9 || grid->flag8)
        return fn_8026D53C(ctx, work, count, interval);
    width = grid->width;
    batch = 0;
    height = grid->height;
    processed = 0;
    x = work->x;
    total = width * height;
    y = work->y;
    remaining = ctx->remaining;
    while (y < height && processed < count) {
        while (x < width && processed < count) {
            batch++;
            if (batch >= interval) {
                result = ctx->callback(x, y, grid);
                if (result < 0)
                    return result;
                batch = 0;
                fn_8026D514(ctx->state, &work->pos);
            }
            remaining--;
            processed++;
            x++;
            if (remaining == 0) {
                fn_8026D4DC(ctx);
                remaining = ctx->reset;
            }
        }
        if (x >= width) {
            x = 0;
            y++;
        }
    }
    if (y == height && x == 0) {
        fn_8026D4BC(ctx);
        if (ctx->done == 1) {
            fn_8026D514(ctx->state, &work->pos);
            return -3;
        }
    }
    grid->x = x;
    work->x = x;
    grid->y = y;
    work->y = y;
    fn_8026D514(ctx->state, &work->pos);
    ctx->remaining = remaining;
    return total - x - y * width;
}