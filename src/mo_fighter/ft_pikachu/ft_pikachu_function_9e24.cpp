#pragma force_active on
extern "C" void fn_27_57F78(void* member);

extern "C" void fn_98_9E24(void* array) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(static_cast<char*>(array) + index * 8 + 4);
    }
}
