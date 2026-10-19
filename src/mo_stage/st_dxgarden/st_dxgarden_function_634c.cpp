#pragma force_active on
extern "C" void fn_77_F54(void* self, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void __dt__14snd3DGeneratorFv(void* self, int flags);

extern "C" void* fn_77_634C(void* self, int flags) {
    if (self) {
        __dt__14snd3DGeneratorFv((char*)self + 0x15c, -1);
        fn_77_F54(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
