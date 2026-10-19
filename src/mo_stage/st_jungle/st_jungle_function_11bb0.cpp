#pragma force_active on
extern "C" void fn_51_3C30(void* p, short flag);
extern "C" void __dt__14snd3DGeneratorFv(void* self, int flags);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_51_11BB0(void* self, int flag) {
    if (self != 0) {
        __dt__14snd3DGeneratorFv((char*)self + 0x1A0, -1);
        fn_51_3C30(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
