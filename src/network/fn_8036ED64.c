#pragma force_active on

typedef struct Context {
    unsigned char pad0[0x228];
    int field228;
    unsigned char pad22C[0x440 - 0x22C];
    void *field440;
} Context;

typedef struct Req {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    void *unk20;
} Req;

extern unsigned char lbl_8048F518[];
extern void *fn_8035DFE8(int);
extern void fn_803732E0(Context **, const void *);

int fn_8036ED64(Context **arg0, int arg1, int arg2, Req **arg3, int arg4, int arg5, int arg6)
{
    Context *ctx;
    Req *obj;
    int t;

    ctx = *arg0;
    obj = fn_8035DFE8(0x24);
    if (obj == 0) {
        fn_803732E0(arg0, lbl_8048F518);
        return 1;
    }
    obj->unk0 = arg1;
    obj->unk4 = arg2;
    obj->unk8 = arg4;
    obj->unk14 = 0;
    if (arg1 == 0) {
        obj->unk18 = 1;
    } else {
        t = ctx->field228;
        obj->unk18 = t;
        ctx->field228 = t + 1;
        if (t + 1 < 2) {
            ctx->field228 = 2;
        }
    }
    obj->unk1C = 0;
    obj->unkC = arg5;
    obj->unk10 = arg6;
    obj->unk20 = ctx->field440;
    ctx->field440 = obj;
    *arg3 = obj;
    return 0;
}
