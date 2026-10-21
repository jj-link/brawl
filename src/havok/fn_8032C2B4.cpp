#pragma force_active on
struct Holder {
    void* unk0;
    void* unk4;
    void* unk8;
    int unkC;
};

extern "C" int fn_8032BE40(void);
extern "C" void fn_8032BDE4(void);
extern "C" void fn_8032BE2C(void);
extern "C" char lbl_804146C0[];
extern "C" Holder lbl_80533300;

extern "C" {
void fn_8032C2B4(void) {
    int temp_r3 = fn_8032BE40();
    lbl_80533300.unk0 = lbl_804146C0;
    lbl_80533300.unk4 = (void*)fn_8032BDE4;
    lbl_80533300.unk8 = (void*)fn_8032BE2C;
    lbl_80533300.unkC = temp_r3;
}
}

__declspec(section ".ctors") extern void* const fn_8032C2B4_ctor = (void*)fn_8032C2B4;
