#include <types.h>

extern "C" void fn_27_359014(void* context, void* embeddedState);
extern "C" void fn_27_BEB00(void* energy);
extern "C" void* fn_111_C2FC(void* array, int index);
extern "C" void* fn_111_C060(void* array, int index);
extern "C" void* fn_111_BDC4(void* array, int index);
extern "C" void* fn_111_BB28(void* array, int index);
extern "C" void* fn_111_B88C(void* array, int index);
extern "C" void* fn_111_B5F0(void* array, int index);
extern "C" void* fn_111_B360(void* array, int index);
extern "C" void* fn_111_B0C8(void* array, int index);

extern "C" void fn_111_A714(void* object, void* context) {
    u8* state = static_cast<u8*>(object);
    fn_27_359014(context, state + 4);
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_111_C2FC(state + 0x208, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_111_C060(state + 0x1CC, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_111_BDC4(state + 0x180, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_111_BB28(state + 0x138, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_111_B88C(state + 0xF0, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_111_B5F0(state + 0x98, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_111_B360(state + 0x64, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_111_B0C8(state + 8, i));
    }
}
