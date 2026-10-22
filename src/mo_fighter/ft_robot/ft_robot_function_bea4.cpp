#pragma force_active on
extern "C" {
void fn_27_15FA20(void*, void*);
void fn_27_BEB00(void*);
void* fn_120_CB6C(void*, int);
void* fn_120_CA84(void*, int);
void* fn_120_C99C(void*, int);
void* fn_120_C8B4(void*, int);
void* fn_120_C7CC(void*, int);
void* fn_120_C6E4(void*, int);
void* fn_120_C5FC(void*, int);
void* fn_120_C514(void*, int);
}

extern "C" void fn_120_BEA4(char* object, void* source) {
    fn_27_15FA20(source, object + 4);
    for (int i = 0; i < 1; ++i) fn_27_BEB00(fn_120_CB6C(object + 0x208, i));
    for (int i = 0; i < 1; ++i) fn_27_BEB00(fn_120_CA84(object + 0x1cc, i));
    for (int i = 0; i < 1; ++i) fn_27_BEB00(fn_120_C99C(object + 0x180, i));
    for (int i = 0; i < 1; ++i) fn_27_BEB00(fn_120_C8B4(object + 0x138, i));
    for (int i = 0; i < 1; ++i) fn_27_BEB00(fn_120_C7CC(object + 0xf0, i));
    for (int i = 0; i < 1; ++i) fn_27_BEB00(fn_120_C6E4(object + 0x98, i));
    for (int i = 0; i < 1; ++i) fn_27_BEB00(fn_120_C5FC(object + 0x64, i));
    for (int i = 0; i < 1; ++i) fn_27_BEB00(fn_120_C514(object + 8, i));
}
