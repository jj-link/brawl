#pragma force_active on
extern "C" {
extern char lbl_2_data_39A0[];
void fn_800B8A0C(void*, int);
void fn_2_37C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_2_2DD30(char* self, int doFree) {
    if (self) {
        *reinterpret_cast<void**>(self + 0x668) = (void*)lbl_2_data_39A0;
        fn_800B8A0C(*reinterpret_cast<void**>(self + 0x66c), 1);
        if (self) {
            __destroy_arr(self + 0x48, fn_2_37C, 0xA8, 9);
        }
        if (doFree > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
