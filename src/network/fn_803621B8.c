#pragma force_active on
typedef void (*Callback)(void);

typedef struct Context Context;
typedef struct Object Object;

struct Object {
    int field00;
    int field04;
    int field08;
    int field0C;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    Context *field24;
    int field28;
    int field2C;
    int field30;
};

struct Context {
    int padding[8];
    Object *field20;
    Callback field24;
    Callback field28;
    Callback field2C;
    Callback field30;
    Callback field34;
};

extern Object *fn_8035DFE8(int);
extern void fn_8035E00C(void *);
extern Context *fn_8035EA18(void);
extern void fn_8035E87C(Context *, int);
extern void fn_80362348(void);
extern void fn_80362384(void);
extern void fn_80362434(void);
extern void fn_80362488(void);
extern void fn_803624A8(void);

Object *fn_803621B8(int a, int b, int c, int d, int e)
{
    Object *object;
    Context *context;

    object = fn_8035DFE8(0x34);
    if (object == 0) {
        return 0;
    }

    object->field00 = d;
    object->field04 = 0;
    object->field08 = a;
    object->field0C = b;
    object->field10 = c;
    object->field1C = 0;
    object->field14 = 0;
    object->field18 = 0;
    object->field20 = e;
    object->field2C = 0;
    object->field30 = 0;

    context = fn_8035EA18();
    if (context == 0) {
        fn_8035E00C(object);
        return 0;
    }

    context->field28 = fn_80362488;
    context->field24 = fn_80362384;
    context->field34 = fn_80362348;
    context->field30 = fn_803624A8;
    context->field2C = fn_80362434;
    context->field20 = object;
    object->field24 = context;

    fn_8035E87C(context, 0);
    return object;
}
