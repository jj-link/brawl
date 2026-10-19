#pragma force_active on
extern "C" void __dt__14snd3DGeneratorFv(void*, int);
extern "C" void* fn_71_276C(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_71_DD60(void* self, int flags)
{
    if (self) {
        __dt__14snd3DGeneratorFv((char*)self + 0x178, -1);
        fn_71_276C(self, 0);
        if (flags > 0)
            __dl__FPv(self);
    }
    return self;
}
