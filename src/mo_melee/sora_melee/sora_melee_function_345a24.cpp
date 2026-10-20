#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern char lbl_27_data_8CA18[];
extern char lbl_27_bss_54EC[];
void fn_27_1E847C(void* self, int id, void* arg);
void __dl__FPv(void* p);
}

struct soObj {
    void* vt;
    u32 pad;
    void* base;
};

extern "C" soObj* fn_27_345A24(soObj* self, int doFree) {
    if (self != 0) {
        self->base = lbl_27_data_8CA18;
        self->vt = lbl_27_data_8CA18 + 8;
        fn_27_1E847C(self, 0x45, lbl_27_bss_54EC);
        if (doFree > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
