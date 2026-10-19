#pragma force_active on
extern "C" void fn_27_57F78(void*);

extern "C" void fn_95_B624(void* array) {
    for (int i = 0; i < 2; ++i) {
        fn_27_57F78((char*)array + i * 8 + 4);
    }
}
