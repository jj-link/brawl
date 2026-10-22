#pragma force_active on
extern "C" {
void fn_27_15FA20(int, void*);
void fn_27_BEB00(void*);
void* fn_119_C47C(void*, int);
void* fn_119_C394(void*, int);
void* fn_119_C2AC(void*, int);
void* fn_119_C1C4(void*, int);
void* fn_119_C0DC(void*, int);
void* fn_119_BFF4(void*, int);
void* fn_119_BF0C(void*, int);
void* fn_119_BE24(void*, int);
}

extern "C" void fn_119_B7B4(unsigned char* object, int kind) {
    fn_27_15FA20(kind, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_119_C47C(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_119_C394(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_119_C2AC(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_119_C1C4(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_119_C0DC(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_119_BFF4(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_119_BF0C(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_119_BE24(object + 8, i));
}
