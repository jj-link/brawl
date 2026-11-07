#pragma force_active on
typedef int s32;
extern void fn_8035A5C8(s32, void *);

typedef struct { s32 type; s32 pad; s32 val; s32 rest[2]; } Msg;
typedef struct { s32 unk0; s32 pad[2]; s32 unkC; s32 unk10; s32 unk14; } Obj;

s32 fn_8037F2DC(Obj *o, s32 arg1) {
    Msg m;
    m.val = arg1;
    m.type = 3;
    fn_8035A5C8(o->unk0, &m);
    o->unk10 = 1;
    if (o->unkC == 1) {
        o->unk14 = 1;
    }
    return 1;
}
