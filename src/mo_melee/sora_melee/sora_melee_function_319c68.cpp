#pragma force_active on
extern "C" {
void fn_27_1E847C(void* self, int flags, void* arg);
void __dl__FPv(void*);
extern char lbl_27_data_84FE0[];
extern char lbl_27_bss_54EC[];

void* fn_27_319C68(void* self, int flags) {
    if (self) {
        ((void**)self)[2] = lbl_27_data_84FE0;
        ((void**)self)[0] = lbl_27_data_84FE0 + 8;
        fn_27_1E847C(self, 0x21, lbl_27_bss_54EC);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
