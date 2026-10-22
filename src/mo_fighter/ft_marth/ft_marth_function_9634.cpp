#pragma force_active on
extern "C" {
void fn_27_15FA20(void*, void*);
void fn_27_BEB00(void*);
void* fn_106_A2FC(void*, int);
void* fn_106_A214(void*, int);
void* fn_106_A12C(void*, int);
void* fn_106_A044(void*, int);
void* fn_106_9F5C(void*, int);
void* fn_106_9E74(void*, int);
void* fn_106_9D8C(void*, int);
void* fn_106_9CA4(void*, int);
}

extern "C" void fn_106_9634(char* o, void* s) {
    fn_27_15FA20(s, o + 4);
    for (int i = 0; i < 1; ++i) fn_27_BEB00(fn_106_A2FC(o + 0x208, i));
    for (int i = 0; i < 1; ++i) fn_27_BEB00(fn_106_A214(o + 0x1cc, i));
    for (int i = 0; i < 1; ++i) fn_27_BEB00(fn_106_A12C(o + 0x180, i));
    for (int i = 0; i < 1; ++i) fn_27_BEB00(fn_106_A044(o + 0x138, i));
    for (int i = 0; i < 1; ++i) fn_27_BEB00(fn_106_9F5C(o + 0xf0, i));
    for (int i = 0; i < 1; ++i) fn_27_BEB00(fn_106_9E74(o + 0x98, i));
    for (int i = 0; i < 1; ++i) fn_27_BEB00(fn_106_9D8C(o + 0x64, i));
    for (int i = 0; i < 1; ++i) fn_27_BEB00(fn_106_9CA4(o + 8, i));
}
