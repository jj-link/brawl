#pragma force_active on
extern "C" {
void fn_27_15FA20(void*, void*);
void fn_27_BEB00(void*);
void* fn_125_E48C(void*, int);
void* fn_125_E3A4(void*, int);
void* fn_125_E2BC(void*, int);
void* fn_125_E1D4(void*, int);
void* fn_125_E0EC(void*, int);
void* fn_125_E004(void*, int);
void* fn_125_DF1C(void*, int);
void* fn_125_DE34(void*, int);
}

extern "C" void fn_125_D7C4(unsigned char* object, void* source) {
    fn_27_15FA20(source, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_125_E48C(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_125_E3A4(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_125_E2BC(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_125_E1D4(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_125_E0EC(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_125_E004(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_125_DF1C(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_125_DE34(object + 8, i));
}
