#pragma force_active on

class soModuleAccesser;

extern "C" {
void fn_116_1A5B8(int, unsigned char*, soModuleAccesser*);
void fn_27_BEB00(void*);
void* fn_116_D8EC(void*, int);
void* fn_116_D804(void*, int);
void* fn_116_D71C(void*, int);
void* fn_116_D634(void*, int);
void* fn_116_D54C(void*, int);
void* fn_116_D464(void*, int);
void* fn_116_D37C(void*, int);
void* fn_116_D294(void*, int);
}

extern "C" void fn_116_19704(unsigned char* object, int kind, soModuleAccesser* accesser) {
    fn_116_1A5B8(kind, object + 4, accesser);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_116_D8EC(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_116_D804(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_116_D71C(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_116_D634(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_116_D54C(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_116_D464(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_116_D37C(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_116_D294(object + 8, i));
}
