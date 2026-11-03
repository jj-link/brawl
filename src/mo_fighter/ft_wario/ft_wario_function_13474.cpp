#pragma force_active on
class soModuleAccesser;
extern "C" {
void fn_110_13BF0(int, unsigned char*, soModuleAccesser*);
void fn_27_BEB00(void*);
void* fn_110_13980(void*, int);
void* fn_110_138D0(void*, int);
void* fn_110_13820(void*, int);
}
extern "C" void fn_110_13474(unsigned char* object, int kind, soModuleAccesser* accesser) {
    fn_110_13BF0(kind, object + 4, accesser);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_110_13980(object + 0x68, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_110_138D0(object + 0x48, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_110_13820(object + 8, i));
}