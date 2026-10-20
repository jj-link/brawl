#pragma force_active on
extern "C" {
void fn_800B8A0C(void*, int);
void fn_2_37C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
extern char lbl_2_data_23C0[];
}

extern "C" char* fn_2_19F14(char* self, int flags) {
    if (self) {
        *reinterpret_cast<char**>(self + 0x668) = lbl_2_data_23C0;
        fn_800B8A0C(*reinterpret_cast<void**>(self + 0x694), 1);
        if (self) {
            __destroy_arr(self + 0x48, fn_2_37C, 0xA8, 9);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
