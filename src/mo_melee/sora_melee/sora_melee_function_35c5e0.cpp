#pragma force_active on
extern "C" {
extern char lbl_27_data_8FF40[];
extern char lbl_27_bss_54EC[];
void fn_27_1E847C(void* self, int arg, char* data);
void __dl__FPv(void* p);
}

struct stDtorObj {
    void* vt0;
    int pad4;
    void* vt1;
};

extern "C" stDtorObj* fn_27_35C5E0(stDtorObj* self, int flag) {
    if (self) {
        self->vt1 = lbl_27_data_8FF40;
        self->vt0 = lbl_27_data_8FF40 + 8;
        fn_27_1E847C(self, 0x5a, lbl_27_bss_54EC);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
