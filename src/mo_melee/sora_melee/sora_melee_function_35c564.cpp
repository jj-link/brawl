#pragma force_active on
extern "C" {
extern char lbl_27_data_8FF40[];
extern char lbl_27_bss_80C0[];
void fn_27_1E82E8(void* self, int flag);
void fn_27_1E847C(void* self, int arg, void* data);
void __register_global_object(void* obj, void* dtor, void* handle);
void fn_27_35C5E0(void);
}

struct stDtorObj {
    void* vt0;
    int pad4;
    void* vt1;
};

extern stDtorObj lbl_27_bss_80CC;

extern "C" void fn_27_35C564() {
    stDtorObj* self = &lbl_27_bss_80CC;
    fn_27_1E82E8(self, 0);
    self->vt1 = lbl_27_data_8FF40;
    lbl_27_bss_80CC.vt0 = lbl_27_data_8FF40 + 8;
    fn_27_1E847C(self, 0x5a, self);
    __register_global_object(self, (void*)fn_27_35C5E0, lbl_27_bss_80C0);
}

__declspec(section ".ctors") extern void* const fn_27_35C564_ctor = (void*)fn_27_35C564;
