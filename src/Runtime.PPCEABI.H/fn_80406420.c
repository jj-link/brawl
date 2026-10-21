#pragma force_active on
extern void fn_804064CC(void *, int, int);

struct Obj {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
};

void fn_80406420(struct Obj *arg0, int arg1, int arg2) {
    int temp_r4;

    arg0->unk8 = arg1;
    arg0->unkC = arg2;
    arg0->unk0 = arg0->unk8;
    temp_r4 = arg0->unk8;
    arg0->unk4 = temp_r4;
    arg0->unk10 = 0;
    arg0->unk14 = arg0->unkC;
    fn_804064CC((char *)arg0 + 0x18, temp_r4, arg2);
}
