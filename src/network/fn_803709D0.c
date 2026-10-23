#pragma force_active on
extern int fn_8035B2D0(void *a, void *b, void *c);
extern void fn_80370944(void);
extern void fn_80370A58(void);

int fn_803709D0(void **arg0, int arg1, int arg2, int *arg3)
{
    int args[4];
    struct {
        void **obj;
        void *fn;
        int *args;
        int pad;
    } ctx;
    void *obj;

    args[1] = arg2;
    args[0] = arg1;
    args[2] = (int)arg3;
    args[3] = 0;
    obj = *arg0;
    ctx.obj = arg0;
    ctx.fn = (void *)fn_80370944;
    ctx.args = args;
    fn_8035B2D0(*(void **)((char *)obj + 0x444),
                (void *)fn_80370A58, &ctx);
    if (args[3] == 0) {
        *arg3 = 0;
    }
    return 0;
}
