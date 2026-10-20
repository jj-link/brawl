#pragma force_active on
extern "C" void fn_800B8A0C(void*, int);
extern "C" void fn_2_37C(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_2_data_2630[];

extern "C" void* fn_2_1BC78(char* self, int flags) {
    if (self != 0) {
        *reinterpret_cast<char**>(self + 0x668) = lbl_2_data_2630;
        fn_800B8A0C(*reinterpret_cast<void**>(self + 0x66C), 1);
        if (self != 0) {
            __destroy_arr(self + 0x48, fn_2_37C, 0xA8, 9);
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
