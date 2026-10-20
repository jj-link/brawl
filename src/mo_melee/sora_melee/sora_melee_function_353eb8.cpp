#pragma force_active on
extern "C" {
extern char lbl_27_data_8EAC8[];
extern char lbl_27_bss_54EC[];
void fn_27_1E847C(void* self, int flags, void* data);
void __dl__FPv(void* p);

struct fn_27_353EB8_Obj {
    void* vt0;
    int pad4;
    void* vt8;
};

fn_27_353EB8_Obj* fn_27_353EB8(fn_27_353EB8_Obj* self, int doFree) {
    if (self) {
        self->vt8 = lbl_27_data_8EAC8;
        self->vt0 = lbl_27_data_8EAC8 + 8;
        fn_27_1E847C(self, 0x23, lbl_27_bss_54EC);
        if (doFree > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
