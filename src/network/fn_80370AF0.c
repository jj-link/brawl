#pragma force_active on
extern int fn_8035B2D0(void *, void *, void *);
extern void fn_80370A58(void);
extern int fn_80370AC0(void *, int *, int *);
typedef struct { int arg; int result; } Args;
typedef struct { void *self; void *callback; Args *args; } Context;
int fn_80370AF0(void **self, int arg) {
    Args args;
    Context ctx;
    void *obj;
    args.arg = arg;
    args.result = 0;
    obj = *self;
    ctx.self = self;
    ctx.callback = (void *)fn_80370AC0;
    ctx.args = &args;
    fn_8035B2D0(*(void **)((char *)obj + 0x444), (void *)fn_80370A58, &ctx);
    return args.result;
}