#pragma force_active on

extern "C" {

struct clTarget {
    int m_a;
    int m_b;
};

extern char lbl_27_bss_12D8;
extern clTarget lbl_27_bss_12E0;
extern void* lbl_27_bss_F08[3];
extern void __dt__8clTargetFv(void*, int);
extern void* __register_global_object(void*, void*, void*);

clTarget* fn_27_85180() {
    if (!lbl_27_bss_12D8) {
        lbl_27_bss_12E0.m_b = -1;
        lbl_27_bss_12E0.m_a = -1;
        __register_global_object((void*)&lbl_27_bss_12E0, (void*)&__dt__8clTargetFv, &lbl_27_bss_F08);
        lbl_27_bss_12D8 = 1;
    }
    return &lbl_27_bss_12E0;
}

}
