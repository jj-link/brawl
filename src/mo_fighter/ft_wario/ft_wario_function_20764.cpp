#pragma force_active on

class soModuleAccesser;

extern "C" {
void fn_110_20FE8(int, unsigned char*, soModuleAccesser*);
void fn_27_BEB00(void*);
void* fn_110_C614(void*, int);
void* fn_110_C52C(void*, int);
void* fn_110_C444(void*, int);
void* fn_110_C35C(void*, int);
void* fn_110_C274(void*, int);
void* fn_110_C18C(void*, int);
void* fn_110_C0A4(void*, int);
void* fn_110_BFBC(void*, int);
}

extern "C" void fn_110_20764(unsigned char* object, int kind, soModuleAccesser* accesser) {
    fn_110_20FE8(kind, object + 4, accesser);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_110_C614(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_110_C52C(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_110_C444(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_110_C35C(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_110_C274(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_110_C18C(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_110_C0A4(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_110_BFBC(object + 8, i));
}
