#pragma force_active on
extern "C" {
void fn_27_15FA20(void*, void*);
void fn_27_BEB00(void*);
void* fn_126_95DC(void*, int);
void* fn_126_94F4(void*, int);
void* fn_126_940C(void*, int);
void* fn_126_9324(void*, int);
void* fn_126_923C(void*, int);
void* fn_126_9154(void*, int);
void* fn_126_906C(void*, int);
void* fn_126_8F84(void*, int);
}

extern "C" void fn_126_8914(unsigned char* object, void* src) {
    fn_27_15FA20(src, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_126_95DC(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_126_94F4(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_126_940C(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_126_9324(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_126_923C(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_126_9154(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_126_906C(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_126_8F84(object + 8, i));
}