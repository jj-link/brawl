#pragma force_active on
typedef struct {
    void **unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
} SomeStruct;

extern void *fn_8035DFE8(int);
extern void *fn_8035A460(int, int, int);

void *fn_8035AED0(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5) {
    SomeStruct *obj;
    int i;

    obj = fn_8035DFE8(0x14);
    obj->unk0 = fn_8035DFE8(arg1 * 4);
    for (i = 0; i < arg1; i++) {
        obj->unk0[i] = fn_8035A460(arg0, arg2, arg5);
    }
    obj->unk4 = arg1;
    obj->unk8 = arg5;
    obj->unk10 = arg4;
    obj->unkC = arg3;
    return obj;
}
