#pragma force_active on
extern "C" {
void fn_27_35A6FC(void*, void*);
void fn_27_BEB00(void*);
void* fn_112_D9B4(void*, int);
void* fn_112_D8CC(void*, int);
void* fn_112_D7E4(void*, int);
void* fn_112_D6FC(void*, int);
void* fn_112_D614(void*, int);
void* fn_112_D52C(void*, int);
void* fn_112_D47C(void*, int);
void* fn_112_D394(void*, int);
}

extern "C" void fn_112_CD24(unsigned char* object, void* src) {
    fn_27_35A6FC(src, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_112_D9B4(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_112_D8CC(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_112_D7E4(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_112_D6FC(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_112_D614(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_112_D52C(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_112_D47C(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_112_D394(object + 8, i));
}
