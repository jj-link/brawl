#pragma force_active on

typedef struct Sub {
    unsigned char pad0[8];
    void *field8;
    void *fieldC;
} Sub;

typedef struct Ctx {
    unsigned char pad0[0x104];
    int field104;
} Ctx;

typedef struct Obj {
    unsigned char pad0[8];
    Sub *field8;
    void *fieldC;
    void *field10;
    int field14;
    void *field18;
} Obj;

extern void fn_8035E00C(void *);
extern void fn_80370938(Ctx **, Obj *);

int fn_8036C2B8(Ctx **arg0, Obj *arg1)
{
    Ctx *temp_r30 = *arg0;

    if (arg1->field8 != 0 && temp_r30->field104 == 0) {
        fn_8035E00C(arg1->field8->field8);
        arg1->field8->field8 = 0;
        fn_8035E00C(arg1->field8->fieldC);
        arg1->field8->fieldC = 0;
        fn_8035E00C(arg1->field8);
        arg1->field8 = 0;
    }
    fn_8035E00C(arg1->field10);
    arg1->field10 = 0;
    fn_8035E00C(arg1->field18);
    arg1->field18 = 0;
    arg1->field14 = 0;
    if (arg1->fieldC == 0 || (temp_r30->field104 == 1 && arg1->field8 == 0)) {
        fn_80370938(arg0, arg1);
        return 0;
    }
    return 1;
}
