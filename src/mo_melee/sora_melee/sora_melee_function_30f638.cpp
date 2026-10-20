#pragma force_active on
extern char lbl_27_data_836D0[];
extern char lbl_27_bss_54EC[];
extern "C" void fn_27_1E847C(void* self, int arg, void* data);

struct Obj {
    void* vtbl;
    int pad4;
    void* data;
};

void operator delete(void* p);

extern "C" {
void* fn_27_30F638(Obj* self, int flag) {
    if (self) {
        self->vtbl = lbl_27_data_836D0 + 8;
        self->data = lbl_27_data_836D0;
        fn_27_1E847C(self, 0x96, lbl_27_bss_54EC);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
