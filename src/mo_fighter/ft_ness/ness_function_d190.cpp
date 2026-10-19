#pragma force_active on
extern "C" void fn_27_57F78(void* member);

extern "C" void fn_101_D190(void* object) {
    for (int i = 0; i < 2; ++i) {
        fn_27_57F78(static_cast<char*>(object) + i * 8 + 4);
    }
}
