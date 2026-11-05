#pragma force_active on
extern "C" {
void fn_121_ECC4(void*, void*);
void fn_27_BEB00(void*);
void* fn_121_E898(void*, int);
void* fn_121_E7B0(void*, int);
void* fn_121_E6C8(void*, int);
void* fn_121_E5E0(void*, int);
void* fn_121_E4F8(void*, int);
void* fn_121_E410(void*, int);
void* fn_121_E328(void*, int);
void* fn_121_E240(void*, int);
}
extern "C" void fn_121_DBD0(unsigned char* object, void* src) {
    fn_121_ECC4(src, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_121_E898(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_121_E7B0(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_121_E6C8(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_121_E5E0(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_121_E4F8(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_121_E410(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_121_E328(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_121_E240(object + 8, i));
}