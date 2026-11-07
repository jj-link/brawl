#pragma force_active on
class soModuleAccesser;
extern "C" {
void fn_27_15FA20(int, void*, soModuleAccesser*);
void fn_27_BEB00(void*);
void* fn_122_13A74(void*, int);
void* fn_122_1398C(void*, int);
void* fn_122_138A4(void*, int);
void* fn_122_137BC(void*, int);
void* fn_122_136D4(void*, int);
void* fn_122_135EC(void*, int);
void* fn_122_13504(void*, int);
void* fn_122_1341C(void*, int);
}
extern "C" void fn_122_12DAC(unsigned char* object, int kind, soModuleAccesser* accesser) {
    fn_27_15FA20(kind, object + 4, accesser);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_122_13A74(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_122_1398C(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_122_138A4(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_122_137BC(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_122_136D4(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_122_135EC(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_122_13504(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_122_1341C(object + 8, i));
}