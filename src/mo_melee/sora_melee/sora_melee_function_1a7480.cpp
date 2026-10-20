#pragma force_active on
extern "C" {
extern unsigned char lbl_27_data_33770[0x90];
}

struct fn_27_Obj {
    unsigned char* unk0;
    unsigned char* unk4;
    unsigned int unk8;
};

extern "C" void fn_27_1A7480(fn_27_Obj* obj) {
    obj->unk0 = lbl_27_data_33770;
    obj->unk4 = lbl_27_data_33770 + 0x48;
    obj->unk8 = obj->unk8 & 0x3FFFFF;
}
