#pragma force_active on
extern "C" {

extern char lbl_20_data_8[];
extern void* lbl_20_bss_8;
extern void fn_20_8470(void*, void*);
extern void __dl__FPv(void*);

void* fn_20_120(void* self, int flag) {
    if (self != 0) {
        *(void**)self = lbl_20_data_8;
        fn_20_8470(lbl_20_bss_8, self);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

}
