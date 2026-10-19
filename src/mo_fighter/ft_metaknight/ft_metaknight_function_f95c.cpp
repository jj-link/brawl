#include <types.h>
#pragma force_active on

extern "C" void* fn_111_FAE8(void*, s16);
extern "C" void* fn_111_FB44(void*, s16);
extern "C" void* fn_111_FBA0(void*, s16);
extern "C" void* fn_111_2D78(void*, s16);
extern "C" void* fn_111_FBFC(void*, s16);
extern "C" void* fn_111_FCE4(void*, s16);
extern "C" void* fn_111_FD44(void*, s16);
extern "C" void* fn_111_FED0(void*, s16);
extern "C" void* fn_111_1015C(void*, s16);
extern "C" void* fn_111_3D98(void*, s16);
extern "C" void* fn_111_10228(void*, s16);
extern "C" void* fn_111_10284(void*, s16);
extern "C" void* fn_111_102F0(void*, s16);
extern "C" void* fn_111_1039C(void*, s16);
extern "C" void* fn_111_103FC(void*, s16);
extern "C" void* fn_111_10458(void*, s16);
extern "C" void* fn_111_104DC(void*, s16);
extern "C" void* fn_111_3E34(void*, s16);
extern "C" void* fn_111_3E90(void*, s16);
extern "C" void* fn_111_105BC(void*, s16);
extern "C" void* fn_111_10634(void*, s16);
extern "C" void* fn_111_106A0(void*, s16);
extern "C" void* fn_111_10774(void*, s16);
extern "C" void* fn_111_3FA0(void*, s16);
extern "C" void* __dt__16soModuleAccesserFv(void*, s16);
extern "C" void* fn_111_10870(void*, s16);
extern "C" void* __dl__FPv(void*);

extern "C" void* fn_111_F95C(void* object, s16 deleting) {
    if (object != 0) {
        s16 memberDeleting = -1;
        u8* members = static_cast<u8*>(object);
        fn_111_FAE8(members + 0x1938, memberDeleting);
        fn_111_FB44(members + 0x1920, memberDeleting);
        fn_111_FBA0(members + 0x17C8, memberDeleting);
        fn_111_2D78(members + 0x177C, memberDeleting);
        fn_111_FBFC(members + 0x15E4, memberDeleting);
        fn_111_FCE4(members + 0x1584, memberDeleting);
        fn_111_FD44(members + 0x14D0, memberDeleting);
        fn_111_FED0(members + 0x1310, memberDeleting);
        fn_111_1015C(members + 0x126C, memberDeleting);
        fn_111_3D98(members + 0x1238, memberDeleting);
        fn_111_10228(members + 0x1220, memberDeleting);
        fn_111_10284(members + 0x10BC, memberDeleting);
        fn_111_102F0(members + 0x1054, memberDeleting);
        fn_111_1039C(members + 0x1048, memberDeleting);
        fn_111_103FC(members + 0x1020, memberDeleting);
        fn_111_10458(members + 0x0E50, memberDeleting);
        fn_111_104DC(members + 0x0DEC, memberDeleting);
        fn_111_3E34(members + 0x0DB0, memberDeleting);
        fn_111_3E90(members + 0x0CF8, memberDeleting);
        fn_111_105BC(members + 0x0B34, memberDeleting);
        fn_111_10634(members + 0x0954, memberDeleting);
        fn_111_106A0(members + 0x0924, memberDeleting);
        fn_111_10774(members + 0x0914, memberDeleting);
        fn_111_3FA0(members + 0x08FC, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x081C, memberDeleting);
        fn_111_10870(object, memberDeleting);
        if (deleting > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
