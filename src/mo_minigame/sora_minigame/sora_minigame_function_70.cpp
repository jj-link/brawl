#pragma force_active on
extern char lbl_20_data_8[];
extern char lbl_20_data_0[];
extern void* lbl_20_bss_8;
extern "C" void fn_20_8468(void* a, void* self, void* p);

struct Obj {
    void* vtbl;
    unsigned char flag;
};

extern "C" void* fn_20_70(Obj* self) {
    self->vtbl = lbl_20_data_8;
    self->flag = 1;
    fn_20_8468(lbl_20_bss_8, self, lbl_20_data_0);
    return self;
}
