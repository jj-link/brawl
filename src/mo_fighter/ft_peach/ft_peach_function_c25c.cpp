#pragma force_active on
namespace {
struct PeachEventEntry;
}

extern "C" {
void fn_103_D41C(int, unsigned char*);
void fn_27_BEB00(void*);
PeachEventEntry* fn_103_CE7C(void*, int);
PeachEventEntry* fn_103_CD94(void*, int);
PeachEventEntry* fn_103_CCAC(void*, int);
PeachEventEntry* fn_103_CBC4(void*, int);
PeachEventEntry* fn_103_CADC(void*, int);
PeachEventEntry* fn_103_CA2C(void*, int);
PeachEventEntry* fn_103_C97C(void*, int);
PeachEventEntry* fn_103_C894(void*, int);
}

extern "C" void fn_103_C25C(unsigned char* object, int kind) {
    fn_103_D41C(kind, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_103_CE7C(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_103_CD94(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_103_CCAC(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_103_CBC4(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_103_CADC(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_103_CA2C(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_103_C97C(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_103_C894(object + 8, i));
}
