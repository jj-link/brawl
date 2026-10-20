#pragma force_active on
extern "C" {

struct Sub {
    char pad[8];
    float x8;
};

struct Obj {
    int pad0;
    Sub* sub;
    int pad8;
    float xc;
};

extern unsigned char lbl_27_data_91F78;
extern const float lbl_27_rodata_7B20;

void fn_27_368AAC(Obj* p) {
    if (!lbl_27_data_91F78) {
        return;
    }

    float v = p->xc - p->sub->x8;
    p->xc = v;
    if (v < lbl_27_rodata_7B20) {
        p->xc = lbl_27_rodata_7B20;
    }
}

}
