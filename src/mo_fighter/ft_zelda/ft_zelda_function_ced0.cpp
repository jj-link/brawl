#pragma force_active on
class soModuleAccesser;

namespace {
typedef unsigned char Byte;
struct ZeldaProcessEntry;
}

extern "C" {
void fn_27_338FE0(void*, void*);
void fn_27_BEB00(void*);
ZeldaProcessEntry* fn_104_DB98(void*, int);
ZeldaProcessEntry* fn_104_DAB0(void*, int);
ZeldaProcessEntry* fn_104_D9C8(void*, int);
ZeldaProcessEntry* fn_104_D8E0(void*, int);
ZeldaProcessEntry* fn_104_D7F8(void*, int);
ZeldaProcessEntry* fn_104_D710(void*, int);
ZeldaProcessEntry* fn_104_D628(void*, int);
ZeldaProcessEntry* fn_104_D540(void*, int);
}

extern "C" void fn_104_CED0(Byte* object, void* src) {
    fn_27_338FE0(src, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_104_DB98(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_104_DAB0(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_104_D9C8(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_104_D8E0(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_104_D7F8(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_104_D710(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_104_D628(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_104_D540(object + 8, i));
}
