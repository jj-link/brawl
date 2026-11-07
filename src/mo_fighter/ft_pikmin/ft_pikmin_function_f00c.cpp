#pragma force_active on
class soModuleAccesser;
extern "C" {
void fn_113_124E8(int, unsigned char*, soModuleAccesser*);
void fn_27_BEB00(void*);
void* fn_113_FCD4(void*, int);
void* fn_113_FBEC(void*, int);
void* fn_113_FB04(void*, int);
void* fn_113_FA1C(void*, int);
void* fn_113_F934(void*, int);
void* fn_113_F84C(void*, int);
void* fn_113_F764(void*, int);
void* fn_113_F67C(void*, int);
}
extern "C" void fn_113_F00C(unsigned char* object, int kind, soModuleAccesser* accesser) {
    fn_113_124E8(kind, object + 4, accesser);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_113_FCD4(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_113_FBEC(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_113_FB04(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_113_FA1C(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_113_F934(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_113_F84C(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_113_F764(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_113_F67C(object + 8, i));
}