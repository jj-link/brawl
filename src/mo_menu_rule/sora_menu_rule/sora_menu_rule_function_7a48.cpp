#pragma force_active on
extern "C" {
void fn_18_CE0(void* p, int n);
void fn_800B8A0C(void* p, int n);
void __destroy_arr(void* p, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void* p);
extern char lbl_18_data_1748[];
}

extern "C" void* fn_18_7A48(void* p, int flag) {
    if (p) {
        *reinterpret_cast<void**>((char*)p + 0x668) = lbl_18_data_1748;
        fn_800B8A0C(*reinterpret_cast<void**>((char*)p + 0x66C), 1);
        if (p) {
            __destroy_arr((char*)p + 0x48, fn_18_CE0, 0xa8, 9);
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
