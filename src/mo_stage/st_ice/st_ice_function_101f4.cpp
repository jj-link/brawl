#pragma force_active on
extern "C" {
void __dt__14snd3DGeneratorFv(void* self, int flags);
void* fn_62_2CE8(void* p, int flags);
void __dl__FPv(void* p);
void* fn_62_101F4(void* p, int flags);
}

extern "C" {
void* fn_62_101F4(void* p, int flags)
{
    if (p != 0) {
        __dt__14snd3DGeneratorFv((char*)p + 0x194, -1);
        fn_62_2CE8(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
