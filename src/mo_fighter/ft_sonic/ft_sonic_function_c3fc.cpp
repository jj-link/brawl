#pragma force_active on
extern "C" {
void fn_27_3BBC90(void*, void*);
void fn_27_BEB00(void*);
void* fn_123_EC84(void* object, int index);
void* fn_123_E880(void* object, int index);
void* fn_123_E47C(void* object, int index);
void* fn_123_E078(void* object, int index);
void* fn_123_DC74(void* object, int index);
void* fn_123_D884(void* object, int index);
void* fn_123_D488(void* object, int index);
void* fn_123_D08C(void* object, int index);
}

extern "C" void fn_123_C3FC(unsigned char* object, void* src) {
    fn_27_3BBC90(src, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_123_EC84(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_123_E880(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_123_E47C(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_123_E078(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_123_DC74(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_123_D884(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_123_D488(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_123_D08C(object + 0x8, i));
}