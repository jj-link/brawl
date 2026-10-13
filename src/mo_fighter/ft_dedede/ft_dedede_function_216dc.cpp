class soModuleAccesser;

namespace {
typedef unsigned char Byte;
struct DededeEventEntry;
}

extern "C" {
void fn_117_15C48(int, unsigned char*, soModuleAccesser*);
void fn_27_BEB00(void*);
DededeEventEntry* fn_117_21F38(void*, int);
DededeEventEntry* fn_117_21E50(void*, int);
DededeEventEntry* fn_117_21D70(void*, int);
DededeEventEntry* fn_117_21CC0(void*, int);
DededeEventEntry* fn_117_21BD8(void*, int);
}

// Reset the selected kinetic mode, then activate each embedded energy entry.
extern "C" void fn_117_216DC(Byte* object, int kind, soModuleAccesser* accesser) {
    fn_117_15C48(kind, object + 4, accesser);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_117_21F38(object + 0xE4, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_117_21E50(object + 0xA8, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_117_21D70(object + 0x68, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_117_21CC0(object + 0x48, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_117_21BD8(object + 8, i));
}
