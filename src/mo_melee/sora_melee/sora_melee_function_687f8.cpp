#pragma force_active on
extern "C" {
extern int lbl_27_data_78D0[];

struct fn_27_687F8_Obj {
    void* unk0;
    int unk4;
};

void fn_27_687F8(fn_27_687F8_Obj* p, int v) {
    p->unk4 = v;
    p->unk0 = lbl_27_data_78D0;
}
}
