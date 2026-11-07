#pragma force_active on
typedef unsigned short u16;

typedef struct Context {
    char pad0[0x18];
    int counter;
    char pad1c[0x15a4 - 0x1c];
    int f15a4;
    char pad15a8[0x15d8 - 0x15a8];
    int f15d8;
    char pad15dc[0x160c - 0x15dc];
    int f160c;
    char pad1610[0x1634 - 0x1610];
    char state[0xc];
} Context;

extern void fn_80269400(void *, u16);

void fn_8026B264(Context *ctx)
{
    fn_80269400(ctx->state, (u16) ((ctx->counter & 7) + 0xFFD0));
    ctx->counter++;
    ctx->f15a4 = 0;
    ctx->f15d8 = 0;
    ctx->f160c = 0;
}
