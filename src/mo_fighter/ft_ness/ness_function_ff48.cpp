#include <types.h>

extern "C" void fn_27_32996C(void* context, void* embeddedState);
extern "C" void fn_27_BEB00(void* energy);
extern "C" void* fn_101_10C10(void* array, int index);
extern "C" void* fn_101_10B28(void* array, int index);
extern "C" void* fn_101_10A40(void* array, int index);
extern "C" void* fn_101_10958(void* array, int index);
extern "C" void* fn_101_10870(void* array, int index);
extern "C" void* fn_101_10788(void* array, int index);
extern "C" void* fn_101_106A0(void* array, int index);
extern "C" void* fn_101_105B8(void* array, int index);

extern "C" void fn_101_FF48(void* object, void* context) {
    u8* state = static_cast<u8*>(object);
    fn_27_32996C(context, state + 4);
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_101_10C10(state + 0x208, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_101_10B28(state + 0x1CC, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_101_10A40(state + 0x180, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_101_10958(state + 0x138, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_101_10870(state + 0xF0, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_101_10788(state + 0x98, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_101_106A0(state + 0x64, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_101_105B8(state + 8, i));
    }
}
