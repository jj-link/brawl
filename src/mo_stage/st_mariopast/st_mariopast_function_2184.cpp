#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__14snd3DGeneratorFv(void* self, int flags);
void fn_48_1F8C(void* p, int del);
void __dl__FPv(void* p);
}

extern "C" void* fn_48_2184(void* p, int del) {
    if (p != 0) {
        __destroy_arr((char*)p + 0x194, __dt__14snd3DGeneratorFv, 8, 6);
        fn_48_1F8C(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
