#pragma force_active on
extern const float lbl_27_rodata_E58;
extern char lbl_27_data_174A0[];

struct fn_27_B7B54_Obj {
    void *vtbl;
    unsigned char m4;
    unsigned char m5;
    unsigned char m6;
    float m8;
    float mC;
    float m10;
};

extern "C" {
void fn_27_B7B54(fn_27_B7B54_Obj *p) {
    p->m4 = 0;
    p->m5 |= 0x80;
    p->m6 = 0;
    p->vtbl = lbl_27_data_174A0;
    p->m8 = lbl_27_rodata_E58;
    p->mC = lbl_27_rodata_E58;
    p->m10 = lbl_27_rodata_E58;
}
}
