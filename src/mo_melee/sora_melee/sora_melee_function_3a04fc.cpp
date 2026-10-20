#pragma force_active on
extern "C" {
void fn_27_1E847C(void* self, int arg, void* p);
void __dl__FPv(void* p);
}

extern char lbl_27_data_9BE20[];
extern char lbl_27_bss_54EC[];

extern "C" void* fn_27_3A04FC(void* self, int flag) {
    if (self) {
        ((void**)self)[2] = lbl_27_data_9BE20;
        ((void**)self)[0] = lbl_27_data_9BE20 + 8;
        fn_27_1E847C(self, 0x63, lbl_27_bss_54EC);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
