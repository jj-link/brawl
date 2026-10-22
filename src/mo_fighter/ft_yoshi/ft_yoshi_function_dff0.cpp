#pragma force_active on
extern "C" {
void fn_95_144B8(void*, void*);
void fn_27_BEB00(void*);
void* fn_95_ECB8(void*, int);
void* fn_95_EBD0(void*, int);
void* fn_95_EAE8(void*, int);
void* fn_95_EA00(void*, int);
void* fn_95_E918(void*, int);
void* fn_95_E830(void*, int);
void* fn_95_E748(void*, int);
void* fn_95_E660(void*, int);
}

extern "C" void fn_95_DFF0(unsigned char* object, void* source) {
    fn_95_144B8(source, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_95_ECB8(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_95_EBD0(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_95_EAE8(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_95_EA00(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_95_E918(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_95_E830(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_95_E748(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_95_E660(object + 8, i));
}
