#pragma force_active on
#pragma optimization_level 1
typedef struct Ctx { char pad[0xC]; int *c; int d; } Ctx;
extern void fn_803908A4(int, int);
extern void fn_8039094C(void);
extern void fn_80390950(int);
extern void fn_80392664(int, int *, int);
extern int fn_80397568(void *);
extern int fn_80397580(void *);
extern Ctx **fn_80397570(void);
void fn_80391AE4(void *arg0) {
    Ctx **pp;
    int a;
    int b;
    Ctx *c;
    pp = fn_80397570();
    a = fn_80397568(arg0);
    b = fn_80397580(arg0);
    arg0 = *pp;
    c = arg0;
    fn_8039094C();
    if (c != 0 && *c->c == 0) {
        *c->c = 1;
        fn_80392664(b, c->c, c->d);
    }
    fn_803908A4(a, b);
    fn_80390950(b);
}
