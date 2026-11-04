#pragma force_active on
typedef struct Obj Obj;
struct Obj { char pad[44]; Obj *child; int value; };
extern void *fn_80395CBC(void *, void *, void *, void *, void *, void *);
extern int fn_8039632C(int, int, int *);
extern void *fn_803974FC(void);
extern void *fn_80397580(void *);
extern Obj *fn_803970DC(void *, void *);
extern Obj *fn_8039705C(void *, Obj *);
extern void fn_80391784(void *, Obj *);
extern void fn_8039702C(void *, Obj *);
extern void fn_803900A0(Obj *);

Obj *fn_8039651C(void *a, void *b, void *c, void *d, int e, void *f, int g, int h)
{
    Obj *obj = fn_80395CBC(a, b, c, d, fn_8039632C, f);
    Obj *result = 0;
    if (obj) {
        void *root = fn_803974FC();
        void *ctx = fn_80397580(root);
        obj = fn_803970DC(ctx, obj);
        result = fn_8039705C(ctx, obj);
        if (result) {
            if (result->child) {
                obj->value = e;
                result->child->child = (Obj *)g;
                result->child->value = h;
                return result;
            }
            fn_80391784(root, result);
            fn_8039702C(ctx, obj);
            fn_803900A0(obj);
            result = 0;
        }
    }
    return result;
}