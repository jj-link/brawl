#pragma force_active on
typedef struct Obj {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    void *unk14;
} Obj;

void *fn_8035DFE8(int);

void *fn_8035A460(int arg0, int arg1, int arg2) {
    Obj *obj;
    int count;

    obj = fn_8035DFE8(0x18);
    count = arg1;
    if (count == 0) {
        count = 8;
    }
    obj->unk0 = 0;
    obj->unk4 = count;
    obj->unk8 = arg0;
    obj->unkC = count;
    obj->unk10 = arg2;
    if (count != 0) {
        obj->unk14 = fn_8035DFE8(count * obj->unk8);
    } else {
        obj->unk14 = 0;
    }
    return obj;
}
