#pragma force_active on
extern "C" char lbl_27_data_1F88[];
extern "C" char lbl_27_bss_FB0[];
extern "C" signed char lbl_27_bss_1670;
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);
extern "C" void* fn_27_86D8C(void* p, int n);

struct SoStaticObj {
    int unk0;
    char* vtbl;
    int unk8;
    int unkC;
    int unk10;
};

extern "C" SoStaticObj lbl_27_bss_1674;

extern "C" SoStaticObj* fn_27_85A00() {
    if (lbl_27_bss_1670 == 0) {
        lbl_27_bss_1674.unk8 = 0;
        lbl_27_bss_1674.vtbl = lbl_27_data_1F88;
        lbl_27_bss_1674.unkC = 0;
        lbl_27_bss_1674.unk10 = 0;
        __register_global_object(&lbl_27_bss_1674, (void*)fn_27_86D8C, lbl_27_bss_FB0);
        lbl_27_bss_1670 = 1;
    }
    return &lbl_27_bss_1674;
}
