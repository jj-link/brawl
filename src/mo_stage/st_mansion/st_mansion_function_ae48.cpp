#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void* self, int flags);
void* fn_47_17B4(void* p, int n);
void __dl__FPv(void* p);
}

extern "C" void* fn_47_AE48(void* p, int n) {
    if (p != 0) {
        __dt__14snd3DGeneratorFv((char*)p + 0x174, -1);
        fn_47_17B4(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
