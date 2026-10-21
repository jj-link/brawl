#pragma force_active on
extern char lbl_8041AC68[];

typedef struct {
    void *unk0;
    int unk4;
} fn_803CACB4_Obj;

int fn_803CACB4(fn_803CACB4_Obj *p, int v) {
    p->unk4 = v;
    p->unk0 = lbl_8041AC68;
    return 0;
}
