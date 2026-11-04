#pragma force_active on
extern "C" {
void fn_27_15FA20(void*, void*);
void fn_27_BEB00(void*);
void* fn_94_EA18(void*, int);
void* fn_94_E930(void*, int);
void* fn_94_E848(void*, int);
void* fn_94_E760(void*, int);
void* fn_94_E678(void*, int);
void* fn_94_E590(void*, int);
void* fn_94_E4A8(void*, int);
void* fn_94_E3C0(void*, int);
}

extern "C" void fn_94_DD50(unsigned char* object, void* src) {
    fn_27_15FA20(src, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_94_EA18(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_94_E930(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_94_E848(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_94_E760(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_94_E678(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_94_E590(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_94_E4A8(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_94_E3C0(object + 8, i));
}