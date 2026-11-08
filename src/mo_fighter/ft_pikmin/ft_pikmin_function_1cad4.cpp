#pragma force_active on
class soModuleAccesser;
extern "C" {
void fn_113_1DAB8(int, unsigned char*, soModuleAccesser*);
void fn_27_BEB00(void*);
void* fn_113_1D434(void*, int);
void* fn_113_1D34C(void*, int);
void* fn_113_1D264(void*, int);
void* fn_113_1D17C(void*, int);
void* fn_113_1D094(void*, int);
void* fn_113_1CFE4(void*, int);
}

extern "C" void fn_113_1CAD4(unsigned char* object, int kind, soModuleAccesser* accesser) {
    fn_113_1DAB8(kind, object + 4, accesser);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_113_1D434(object + 0x110, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_113_1D34C(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_113_1D264(object + 0xA4, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_113_1D17C(object + 0x68, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_113_1D094(object + 0x48, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_113_1CFE4(object + 8, i));
}
