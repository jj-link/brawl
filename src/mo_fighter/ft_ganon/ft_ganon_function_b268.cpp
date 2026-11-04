#pragma force_active on
extern "C" {
void fn_109_E200(int, void*);
void fn_27_BEB00(void*);
void* fn_109_BEF8(void*, int);
void* fn_109_BE10(void*, int);
void* fn_109_BD28(void*, int);
void* fn_109_BC40(void*, int);
void* fn_109_BB58(void*, int);
void* fn_109_BA70(void*, int);
void* fn_109_B9C0(void*, int);
void* fn_109_B8D8(void*, int);
}

extern "C" void fn_109_B268(unsigned char* object, int kind, void* accesser) {
    fn_109_E200(kind, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_109_BEF8(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_109_BE10(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_109_BD28(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_109_BC40(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_109_BB58(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_109_BA70(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_109_B9C0(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_109_B8D8(object + 8, i));
}