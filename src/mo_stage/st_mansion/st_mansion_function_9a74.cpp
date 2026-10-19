#pragma force_active on
extern "C" void __dt__14snd3DGeneratorFv(void* self, int flags);
extern "C" void fn_47_17B4(void* p, int n);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_47_9A74(void* self, int flags) {
    if (self != 0) {
        __dt__14snd3DGeneratorFv((char*)self + 0x17C, -1);
        fn_47_17B4(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
