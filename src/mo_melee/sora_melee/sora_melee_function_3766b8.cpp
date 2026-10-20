#pragma force_active on
extern "C" {
extern char lbl_27_data_937D0[];
extern char lbl_27_bss_54EC[];
void fn_27_1E847C(void* self, int flag, void* data);
void __dl__FPv(void* p);

void* fn_27_3766B8(void* self, int flag) {
    if (self) {
        *(char**)((char*)self + 8) = lbl_27_data_937D0;
        *(char**)self = lbl_27_data_937D0 + 8;
        fn_27_1E847C(self, 0x5f, lbl_27_bss_54EC);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
