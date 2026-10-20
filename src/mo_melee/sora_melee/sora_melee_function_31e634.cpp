#pragma force_active on
struct Obj {
    char* m0;
    int m4;
    char* m8;
};

extern "C" void fn_27_1E847C(void* self, int type, void* p);
extern char lbl_27_data_85928[];
extern char lbl_27_bss_54EC[];
extern "C" void __dl__FPv(void* p);

extern "C" Obj* fn_27_31E634(Obj* self, int isDelete) {
    if (self) {
        self->m8 = lbl_27_data_85928;
        self->m0 = lbl_27_data_85928 + 8;
        fn_27_1E847C(self, 0x22, lbl_27_bss_54EC);
        if (isDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
