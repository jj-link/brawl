#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_27_57F78(void* member);

extern "C" void fn_99_888C(void* object) {
    u8* state = static_cast<u8*>(object);
    for (int i = 0; i < 2; ++i) {
        fn_27_57F78(state + (i << 3) + 4);
    }
}
