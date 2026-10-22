#pragma force_active on
class soModuleAccesser;
extern "C" {
void fn_100_C9A4(void*, void*);
void fn_27_BEB00(void*);
void* fn_100_C598(void*, int);
void* fn_100_C4B0(void*, int);
void* fn_100_C3C8(void*, int);
void* fn_100_C2E0(void*, int);
void* fn_100_C1F8(void*, int);
void* fn_100_C110(void*, int);
void* fn_100_C060(void*, int);
void* fn_100_BF78(void*, int);
}

extern "C" void fn_100_B904(unsigned char* object, void* src) {
    fn_100_C9A4(src, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_100_C598(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_100_C4B0(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_100_C3C8(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_100_C2E0(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_100_C1F8(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_100_C110(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_100_C060(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_100_BF78(object + 8, i));
}
