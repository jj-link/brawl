#pragma force_active on
extern "C" void __dt__14snd3DGeneratorFv(void* self, int flags);
extern "C" void* fn_46_4570(void* self, int flag);
extern "C" void __dl__FPv(void* ptr);

extern "C" void* fn_46_5428(void* self, int flags) {
    if (self) {
        __dt__14snd3DGeneratorFv((char*)self + 0x168, -1);
        fn_46_4570(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
