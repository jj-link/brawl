#include <types.h>

extern "C" void fn_27_3615F8(void* source, void* member);
extern "C" void fn_27_BEB00(void* member);
extern "C" void* fn_114_10470(void* object, int index);
extern "C" void* fn_114_10388(void* object, int index);
extern "C" void* fn_114_102A0(void* object, int index);
extern "C" void* fn_114_101B8(void* object, int index);
extern "C" void* fn_114_100D0(void* object, int index);
extern "C" void* fn_114_FFE8(void* object, int index);
extern "C" void* fn_114_FF00(void* object, int index);
extern "C" void* fn_114_FE18(void* object, int index);

extern "C" void fn_114_F7A8(void* object, void* source) {
    fn_27_3615F8(source, static_cast<char*>(object) + 4);
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_114_10470(static_cast<char*>(object) + 0x208, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_114_10388(static_cast<char*>(object) + 0x1cc, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_114_102A0(static_cast<char*>(object) + 0x180, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_114_101B8(static_cast<char*>(object) + 0x138, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_114_100D0(static_cast<char*>(object) + 0xf0, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_114_FFE8(static_cast<char*>(object) + 0x98, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_114_FF00(static_cast<char*>(object) + 0x64, i));
    }
    for (int i = 0; i < 1; ++i) {
        fn_27_BEB00(fn_114_FE18(static_cast<char*>(object) + 8, i));
    }
}
