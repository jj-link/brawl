#pragma force_active on
class soModuleAccesser;

namespace {
typedef unsigned char Byte;
}

extern "C" {
void fn_27_15FA20(int, void*, soModuleAccesser*);
void fn_27_BEB00(void*);
void* fn_102_BDD8(void*, int);
void* fn_102_BCF0(void*, int);
void* fn_102_BC08(void*, int);
void* fn_102_BB20(void*, int);
void* fn_102_BA38(void*, int);
void* fn_102_B950(void*, int);
void* fn_102_B868(void*, int);
void* fn_102_B780(void*, int);
}

extern "C" void fn_102_B110(Byte* object, int kind, soModuleAccesser* accesser) {
    fn_27_15FA20(kind, object + 4, accesser);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_102_BDD8(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_102_BCF0(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_102_BC08(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_102_BB20(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_102_BA38(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_102_B950(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_102_B868(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_102_B780(object + 8, i));
}
