#pragma force_active on
class soModuleAccesser;
extern "C" {
void fn_96_20B50(void*, void*, soModuleAccesser*);
void fn_27_BEB00(void*);
void* fn_96_13260(void*, int);
void* fn_96_13178(void*, int);
void* fn_96_13090(void*, int);
void* fn_96_12FA8(void*, int);
void* fn_96_12EC0(void*, int);
void* fn_96_12E10(void*, int);
void* fn_96_12D60(void*, int);
void* fn_96_12CB0(void*, int);
}

extern "C" void fn_96_12640(unsigned char* object, void* src, soModuleAccesser* accesser) {
    fn_96_20B50(src, object + 4, accesser);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_96_13260(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_96_13178(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_96_13090(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_96_12FA8(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_96_12EC0(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_96_12E10(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_96_12D60(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_96_12CB0(object + 8, i));
}
