#pragma force_active on
void fn_8035A4FC(int a);
void fn_8035E00C(void *p);

typedef struct Obj {
    int unk0;
    int unk4;
} Obj;

void fn_80362E0C(Obj *arg0) {
    fn_8035A4FC(arg0->unk4);
    fn_8035A4FC(arg0->unk0);
    fn_8035E00C(arg0);
}
