#pragma force_active on
extern "C" {
struct Base27 {
    unsigned char pad[0x190];
};

struct Object27 : Base27 {
    virtual void f(int);
};

extern Object27* lbl_27_bss_5B98;

void fn_27_25E7E0() {
    Object27* object = lbl_27_bss_5B98;
    if (object != 0) {
        if (object != 0) {
            object->f(1);
        }
        lbl_27_bss_5B98 = 0;
    }
}
}
