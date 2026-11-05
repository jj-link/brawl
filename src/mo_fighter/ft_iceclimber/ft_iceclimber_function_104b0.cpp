#pragma force_active on
extern "C" {
void fn_27_346284(void*, void*);
void fn_27_BEB00(void*);
void* fn_105_12BBC(void*, int);
void* fn_105_127E0(void*, int);
void* fn_105_12404(void*, int);
void* fn_105_12028(void*, int);
void* fn_105_11C4C(void*, int);
void* fn_105_11888(void*, int);
void* fn_105_114BC(void*, int);
void* fn_105_110EC(void*, int);
}

extern "C" void fn_105_104B0(unsigned char* object, void* src) {
    fn_27_346284(src, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_105_12BBC(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_105_127E0(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_105_12404(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_105_12028(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_105_11C4C(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_105_11888(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_105_114BC(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_105_110EC(object + 8, i));
}