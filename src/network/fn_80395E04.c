#pragma force_active on
typedef struct Obj { int a, b, pad8, padc; struct Obj *p10; void *p14; int n18; } Obj;
extern void *fn_803974FC(void);
extern void *fn_80397580(void *);
extern void *fn_80397578(void *);
extern Obj *fn_803970DC(void *, void *);
extern void fn_80390A64(void *, int);
extern void fn_80391A20(void *, int);
extern void fn_80391784(void *, Obj *);
extern void fn_80391B8C(void *, void *);
extern void fn_80396DE8(void *);
extern void fn_8039702C(void *, Obj *);
extern void fn_803900A0(Obj *);
int fn_80395E04(Obj *obj) {
    void *root = fn_803974FC();
    void *ctx = fn_80397580(root);
    void *x = fn_80397578(root);
    obj = fn_803970DC(ctx, obj);
    if (!obj) return -1;
    fn_80390A64(x, 1);
    if (obj->n18 >= 0) {
        fn_80391A20(root, obj->n18);
        obj->n18 = -1;
    }
    if (obj->p10 && obj->p10->b == 0)
        fn_80391784(root, obj->p10);
    if (obj->p14) {
        if (!obj->p10) {
            fn_80391B8C(ctx, obj->p14);
        } else {
            root = fn_803974FC();
            x = fn_80397578(root);
            root = fn_803970DC(fn_80397580(root), obj);
            if (root) {
                Obj *q = fn_803970DC(fn_80397580(fn_803974FC()), obj);
                int n = !q ? -1 : q->a;
                fn_80390A64(x, 1);
                if (n != -1 && n != 0) {
                    Obj *z = fn_803970DC(fn_80397580(fn_803974FC()), obj);
                    int v = z ? z->b : -1;
                    if (v == 15) fn_80396DE8(root);
                }
            }
            fn_80391B8C(ctx, obj->p14);
        }
    }
    fn_8039702C(ctx, obj);
    fn_803900A0(obj);
    return 0;
}