#pragma force_active on
extern char lbl_27_data_17BA4[];

struct Obj {
    void* vtbl;
    unsigned char f4;
};

extern "C" {
void fn_27_C2E38(Obj* p) {
    p->f4 = 0;
    p->vtbl = lbl_27_data_17BA4;
}
}
