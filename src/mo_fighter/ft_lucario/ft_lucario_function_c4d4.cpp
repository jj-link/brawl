#pragma force_active on
extern "C" {
void fn_27_15FA20(void*, void*);
void fn_27_BEB00(void*);
void* fn_118_D19C(void*, int);
void* fn_118_D0B4(void*, int);
void* fn_118_CFCC(void*, int);
void* fn_118_CEE4(void*, int);
void* fn_118_CDFC(void*, int);
void* fn_118_CD14(void*, int);
void* fn_118_CC2C(void*, int);
void* fn_118_CB44(void*, int);
}

extern "C" void fn_118_C4D4(unsigned char* object, void* src) {
    fn_27_15FA20(src, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_118_D19C(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_118_D0B4(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_118_CFCC(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_118_CEE4(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_118_CDFC(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_118_CD14(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_118_CC2C(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_118_CB44(object + 8, i));
}