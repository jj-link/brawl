#pragma force_active on
class soModuleAccesser;
extern "C" {
void fn_93_ECC8(void*, void*);
void fn_27_BEB00(void*);
void* fn_93_E89C(void*, int);
void* fn_93_E7B4(void*, int);
void* fn_93_E6CC(void*, int);
void* fn_93_E5E4(void*, int);
void* fn_93_E4FC(void*, int);
void* fn_93_E414(void*, int);
void* fn_93_E32C(void*, int);
void* fn_93_E244(void*, int);
}

extern "C" void fn_93_DBD4(unsigned char* object, void* src) {
    fn_93_ECC8(src, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_93_E89C(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_93_E7B4(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_93_E6CC(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_93_E5E4(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_93_E4FC(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_93_E414(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_93_E32C(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_93_E244(object + 8, i));
}
