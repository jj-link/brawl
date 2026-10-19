#pragma force_active on
extern "C" void fn_27_57ED8(void* member, void* argument);

extern "C" void fn_91_A5E0(void* object, void* argument) {
    for (int i = 0; i < 2; i++) {
        fn_27_57ED8(static_cast<unsigned char*>(object) + 4 + i * 8, argument);
    }
}
