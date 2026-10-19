#pragma force_active on
extern "C" void fn_51_3C30(void* p, short flag);
extern "C" void __dt__14snd3DGeneratorFv(void* self, int flags);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_51_1146C(void* p, int flags) {
    if (p != 0) {
        __dt__14snd3DGeneratorFv((char*)p + 0x1A0, -1);
        fn_51_3C30(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
