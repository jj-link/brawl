#pragma force_active on
namespace {
typedef unsigned char Byte;
struct PurinEventEntry;
}

extern "C" {
void fn_27_15FA20(int, void*);
void fn_27_BEB00(void*);
PurinEventEntry* fn_124_B060(void*, int);
PurinEventEntry* fn_124_AF78(void*, int);
PurinEventEntry* fn_124_AE90(void*, int);
PurinEventEntry* fn_124_ADA8(void*, int);
PurinEventEntry* fn_124_ACC0(void*, int);
PurinEventEntry* fn_124_ABD8(void*, int);
PurinEventEntry* fn_124_AAF0(void*, int);
PurinEventEntry* fn_124_AA08(void*, int);
}

// Reset the selected kinetic mode, then activate each embedded event entry.
extern "C" void fn_124_A398(Byte* object, int kind) {
    fn_27_15FA20(kind, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_124_B060(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_124_AF78(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_124_AE90(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_124_ADA8(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_124_ACC0(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_124_ABD8(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_124_AAF0(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_124_AA08(object + 8, i));
}
