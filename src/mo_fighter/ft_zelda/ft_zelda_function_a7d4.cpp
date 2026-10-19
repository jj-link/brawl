#pragma force_active on
extern "C" void fn_27_57F78(void* member);

extern "C" void fn_104_A7D4(void* object) {
    for (int i = 0; i < 2; ++i) {
        fn_27_57F78((char*)object + i * 8 + 4);
    }
}
