#pragma force_active on
extern char lbl_27_data_872C8[];
extern char lbl_27_bss_54EC[];
extern "C" void fn_27_1E847C(void* self, int kind, char* data);
extern "C" void __dl__FPv(void*);

struct soSomeObj {
    void* vtbl0;
    int unk4;
    void* vtbl1;
};

extern "C" {
soSomeObj* fn_27_326538(soSomeObj* self, int del) {
    if (self) {
        self->vtbl0 = lbl_27_data_872C8 + 8;
        self->vtbl1 = lbl_27_data_872C8;
        fn_27_1E847C(self, 9, lbl_27_bss_54EC);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
