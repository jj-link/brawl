#pragma force_active on
extern "C" {
void fn_123_17B48(int a, void* b);
void* fn_123_17A3C(void* object, int index);
void fn_27_BEB00(void*);
void* fn_123_1798C(void* object, int index);
}

extern "C" void fn_123_176AC(unsigned char* object, int kind) {
    fn_123_17B48(kind, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_123_17A3C(object + 0x48, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_123_1798C(object + 8, i));
}
