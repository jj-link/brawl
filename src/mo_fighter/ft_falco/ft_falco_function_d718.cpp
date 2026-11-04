#pragma force_active on
class soModuleAccesser;

namespace {
typedef unsigned char Byte;
struct FalcoEventEntry;
}

extern "C" {
void fn_27_15FA20(int, void*, soModuleAccesser*);
void fn_27_BEB00(void*);
FalcoEventEntry* fn_108_E3E0(void*, int);
FalcoEventEntry* fn_108_E2F8(void*, int);
FalcoEventEntry* fn_108_E210(void*, int);
FalcoEventEntry* fn_108_E128(void*, int);
FalcoEventEntry* fn_108_E040(void*, int);
FalcoEventEntry* fn_108_DF58(void*, int);
FalcoEventEntry* fn_108_DE70(void*, int);
FalcoEventEntry* fn_108_DD88(void*, int);
}

extern "C" void fn_108_D718(Byte* object, int fighterKind, soModuleAccesser* moduleAccessor) {
    fn_27_15FA20(fighterKind, object + 4, moduleAccessor);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_108_E3E0(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_108_E2F8(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_108_E210(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_108_E128(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_108_E040(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_108_DF58(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_108_DE70(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_108_DD88(object + 8, i));
}
