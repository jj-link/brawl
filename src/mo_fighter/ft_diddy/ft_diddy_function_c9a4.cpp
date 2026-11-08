#pragma force_active on
class soModuleAccesser;

extern "C" {
void fn_27_15FA20(int, void*, soModuleAccesser*);
void fn_27_BEB00(void*);
void* fn_115_D66C(void*, int);
void* fn_115_D584(void*, int);
void* fn_115_D49C(void*, int);
void* fn_115_D3B4(void*, int);
void* fn_115_D2CC(void*, int);
void* fn_115_D1E4(void*, int);
void* fn_115_D0FC(void*, int);
void* fn_115_D014(void*, int);
}

extern "C" void fn_115_C9A4(unsigned char* object, int kind, soModuleAccesser* accesser) {
    fn_27_15FA20(kind, object + 4, accesser);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_115_D66C(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_115_D584(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_115_D49C(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_115_D3B4(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_115_D2CC(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_115_D1E4(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_115_D0FC(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_115_D014(object + 8, i));
}
