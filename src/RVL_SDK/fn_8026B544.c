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
    int counter;
    char pad1c[0x8];
    int (*callback)(int, int, Grid *);
    char pad28[0x1580 - 0x28];
    Grid grid;
    char pad158a[0x15a4 - 0x158a];
    int f15a4;
    char pad15a8[0x15d8 - 0x15a8];
    int f15d8;
    char pad15dc[0x160c - 0x15dc];
    int f160c;
    char pad1610[0x1634 - 0x1610];
    char state[0xc];
    u8 done;
} Context;

typedef struct Work {
    Context *ctx;
    char pad4[8];
    u16 x, y;
    u32 pos;
    char pad14[0x48 - 0x14];
    int a, b, c, d;
    int start, end1, end2, current;
} Work;

extern int fn_80269C98(void *, void *, int);
extern void fn_80269400(void *, u16);
extern void fn_80269508(void *);
extern void fn_802692A0(void *, u32 *);

int fn_8026B544(Work *work, int count, int data)
{
    int remaining, processed, total, width, height, x, y;
    int result;
    Context *ctx;
    Grid *grid;

    ctx = work->ctx;
    grid = &ctx->grid;

    work->start = data;
    work->current = data;
    work->end1 = data + work->a * work->b;
    work->end2 = data + work->c * work->d;

    if (grid->flag9 || grid->flag8) {
        return fn_80269C98(ctx, work, count);
    }

    width = grid->width;
    height = grid->height;
    processed = 0;
    x = work->x;
    total = width * height;
    y = work->y;
    remaining = ctx->remaining;

    while (y < height && processed < count) {
        while (x < width && processed < count) {
            result = ctx->callback(x, y, grid);
            if (result < 0) {
                return result;
            }
            processed++;
            x++;
            remaining--;
            if (remaining == 0) {
                fn_80269400(ctx->state, (u16) ((ctx->counter & 7) + 0xFFD0));
                ctx->counter++;
                ctx->f15a4 = 0;
                ctx->f15d8 = 0;
                ctx->f160c = 0;
                remaining = ctx->reset;
            }
        }
        if (x >= width) {
            x = 0;
            y++;
        }
    }

    if (y == height && x == 0) {
        fn_80269508(ctx->state);
        if (ctx->done == 1) {
            fn_802692A0(ctx->state, &work->pos);
            return -3;
        }
    }

    grid->x = x;
    work->x = x;
    grid->y = y;
    work->y = y;
    fn_802692A0(ctx->state, &work->pos);
    ctx->remaining = remaining;
    return total - x - y * width;
}
