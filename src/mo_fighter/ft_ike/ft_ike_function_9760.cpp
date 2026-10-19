#pragma force_active on
extern "C" void fn_27_57F78(void* member);

extern "C" void fn_119_9760(char* object) {
    for (int i = 0; i < 2; i++) {
        fn_27_57F78(object + i * 8 + 4);
    }
}
