#pragma force_active on

struct Type_804A3E70 {
    int unk0[3];
    int unkC;
    int unk10[3];
    int unk1C;
};

extern "C" {
extern Type_804A3E70 lbl_804A3E70;
void fn_8015BF9C(void*, int);

void fn_8016F148() {
    fn_8015BF9C(&lbl_804A3E70, 4);
    fn_8015BF9C(&lbl_804A3E70.unk10[0], 4);
    lbl_804A3E70.unkC = 0;
    lbl_804A3E70.unk1C = 0;
}
}

__declspec(section ".ctors") extern void* const fn_8016F148_ctor = (void*)fn_8016F148;
