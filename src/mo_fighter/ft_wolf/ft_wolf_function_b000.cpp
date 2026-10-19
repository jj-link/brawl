#pragma force_active on
extern "C" void fn_27_57F78(void* member);

extern "C" void fn_125_B000(void* array) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78((char*)array + index * 8 + 4);
    }
}
