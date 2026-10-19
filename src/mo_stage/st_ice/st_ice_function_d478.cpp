#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void*, int);
void* fn_62_2CE8(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_62_D478(void* self, int flags)
{
    if (self != 0) {
        __dt__14snd3DGeneratorFv((char*)self + 0x188, -1);
        fn_62_2CE8(self, 0);
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
