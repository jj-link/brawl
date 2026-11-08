#pragma force_active on
class soModuleAccesser;

namespace {
typedef unsigned char Byte;
struct GameWatchEventEntry;
}

extern "C" {
void fn_107_100FC(int, void*);
void fn_27_BEB00(void*);
GameWatchEventEntry* fn_107_FCB4(void*, int);
GameWatchEventEntry* fn_107_FBCC(void*, int);
GameWatchEventEntry* fn_107_FAE4(void*, int);
GameWatchEventEntry* fn_107_F9FC(void*, int);
GameWatchEventEntry* fn_107_F914(void*, int);
GameWatchEventEntry* fn_107_F82C(void*, int);
GameWatchEventEntry* fn_107_F744(void*, int);
GameWatchEventEntry* fn_107_F65C(void*, int);
}

extern "C" void fn_107_EFEC(Byte* object, int kind) {
    fn_107_100FC(kind, object + 4);
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_107_FCB4(object + 0x208, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_107_FBCC(object + 0x1CC, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_107_FAE4(object + 0x180, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_107_F9FC(object + 0x138, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_107_F914(object + 0xF0, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_107_F82C(object + 0x98, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_107_F744(object + 0x64, i));
    for (int i = 0; i < 1; ++i)
        fn_27_BEB00(fn_107_F65C(object + 8, i));
}
