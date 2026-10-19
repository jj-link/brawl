#pragma force_active on
extern "C" void fn_27_57F78(void*);

extern "C" void fn_91_A58C(void* object) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(static_cast<unsigned char*>(object) + index * 8 + 4);
    }
}
