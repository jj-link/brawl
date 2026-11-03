#pragma force_active on
struct Vec { float x,y,z,w; };
struct Context {
    char pad[0x50];
    Vec a,b,c,d,e,f;
    char pad2[8];
    int count;
};
struct Work { Vec a,b,c; };
extern "C" void fn_8028D8C0(Work*, int, int);
extern "C" void fn_802DCA2C(void*, void*, void*, void*, Context* ctx, int a, int b) {
    Work first __attribute__((aligned(16)));
    Work second __attribute__((aligned(16)));
    first.a = ctx->a;
    first.c = ctx->e;
    first.b = ctx->c;
    fn_8028D8C0(&first, a, b);
    second.a = ctx->b;
    second.c = ctx->f;
    second.b = first.a;
    fn_8028D8C0(&second, a, b);
    second.c = ctx->d;
    second.b = second.a;
    second.a = first.b;
    fn_8028D8C0(&second, a, b);
    ctx->count += 3;
}