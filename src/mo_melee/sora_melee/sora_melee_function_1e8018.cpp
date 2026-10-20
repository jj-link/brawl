#pragma force_active on
extern "C" {
extern char lbl_27_data_47AF8[];
extern char lbl_27_bss_54EC[];
void fn_27_1E847C(void* self, int size, void* arg);
void __dl__FPv(void* p);
}

extern "C" void* fn_27_1E8018(void* self, int isDelete) {
    if (self) {
        *(void**)self = lbl_27_data_47AF8 + 8;
        *((void**)self + 2) = lbl_27_data_47AF8;
        fn_27_1E847C(self, 0x98, lbl_27_bss_54EC);
        if (isDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
