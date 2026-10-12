class soModuleAccesser;

namespace {
typedef unsigned char Byte;
struct DededeEventEntry;
}

extern "C" {
void fn_27_15FA20(int, void*, soModuleAccesser*);
void fn_27_BEB00(void*);
DededeEventEntry* fn_117_DEE4(void*, int);
DededeEventEntry* fn_117_DDFC(void*, int);
DededeEventEntry* fn_117_DD14(void*, int);
DededeEventEntry* fn_117_DC2C(void*, int);
DededeEventEntry* fn_117_DB44(void*, int);
DededeEventEntry* fn_117_DA5C(void*, int);
DededeEventEntry* fn_117_D974(void*, int);
DededeEventEntry* fn_117_D88C(void*, int);
}

// Initialize the fighter-specific state and activate each embedded event entry.
extern "C" void fn_117_D21C(Byte* object, int fighterKind, soModuleAccesser* moduleAccessor) {
    fn_27_15FA20(fighterKind, object + 4, moduleAccessor);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_117_DEE4(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_117_DDFC(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_117_DD14(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_117_DC2C(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_117_DB44(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_117_DA5C(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_117_D974(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_117_D88C(object + 8, i));
}
