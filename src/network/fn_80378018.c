#pragma force_active on

void fn_8035AF74(int);
void fn_8035A4FC(int);
void fn_8035E00C(void *);
void fn_8035D724(void);
int closesocket(int);

typedef struct Obj {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
} Obj;

void fn_80378018(Obj *arg0) {
    if (arg0->unk1C != 0) {
        arg0->unk14 = 1;
        return;
    }
    closesocket(arg0->unk0);
    fn_8035AF74(arg0->unkC);
    fn_8035A4FC(arg0->unk10);
    fn_8035E00C(arg0);
    fn_8035D724();
}
