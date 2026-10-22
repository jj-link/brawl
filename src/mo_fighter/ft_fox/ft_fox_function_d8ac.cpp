#pragma force_active on
extern "C" {
void fn_27_15FA20(void*, void*);
void fn_27_BEB00(void*);
void* fn_97_E574(void*, int);
void* fn_97_E48C(void*, int);
void* fn_97_E3A4(void*, int);
void* fn_97_E2BC(void*, int);
void* fn_97_E1D4(void*, int);
void* fn_97_E0EC(void*, int);
void* fn_97_E004(void*, int);
void* fn_97_DF1C(void*, int);
}

extern "C" void fn_97_D8AC(char* object, void* source) {
    fn_27_15FA20(source, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_97_E574(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_97_E48C(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_97_E3A4(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_97_E2BC(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_97_E1D4(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_97_E0EC(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_97_E004(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_97_DF1C(object + 8, i));
}
