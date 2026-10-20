#pragma force_active on
extern char lbl_27_data_7CA70[];
extern char lbl_27_bss_54EC[];

extern "C" void fn_27_1E847C(void* self, int arg, void* bss);
extern "C" void __dl__FPv(void* p);

struct soSomeObj {
    void* vtbl0;
    int unk4;
    void* vtbl8;
};

extern "C" soSomeObj* fn_27_2E0C9C(soSomeObj* self, int doDelete) {
    if (self) {
        self->vtbl8 = lbl_27_data_7CA70;
        self->vtbl0 = lbl_27_data_7CA70 + 8;
        fn_27_1E847C(self, 4, lbl_27_bss_54EC);
        if (doDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
