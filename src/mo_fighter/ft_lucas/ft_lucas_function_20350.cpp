#pragma force_active on
#include <types.h>

void operator delete(void* object);

extern "C" {
void fn_114_3BC4(void*, short);
void fn_114_3C20(void*, short);
void fn_114_204DC(void*, short);
void* fn_114_20538(void*, short);
void fn_114_3C7C(void*, short);
void fn_114_3D08(void*, short);
void fn_114_3E04(void*, short);
void* fn_114_20598(void*, short);
void fn_114_41F0(void*, short);
void fn_114_4324(void*, short);
void fn_114_43E4(void*, short);
void fn_114_4440(void*, short);
void fn_114_44AC(void*, short);
void fn_114_450C(void*, short);
void fn_114_456C(void*, short);
void fn_114_45C8(void*, short);
void fn_114_464C(void*, short);
void fn_114_4718(void*, short);
void fn_114_47E0(void*, short);
void fn_114_206F0(void*, short);
void fn_114_48DC(void*, short);
void fn_114_4948(void*, short);
void fn_114_4A00(void*, short);
void fn_114_4A40(void*, short);
void __dt__16soModuleAccesserFv(void*, short);
void fn_114_20768(void*, short);
}

extern "C" void* fn_114_20350(void* object, short deleting) {
    if (object != 0) {
        short memberDeleting = -1;
        fn_114_3BC4(static_cast<char*>(object) + 0x1990, memberDeleting);
        fn_114_3C20(static_cast<char*>(object) + 0x1978, memberDeleting);
        fn_114_204DC(static_cast<char*>(object) + 0x1820, memberDeleting);
        fn_114_20538(static_cast<char*>(object) + 0x17D0, memberDeleting);
        fn_114_3C7C(static_cast<char*>(object) + 0x163C, memberDeleting);
        fn_114_3D08(static_cast<char*>(object) + 0x15DC, memberDeleting);
        fn_114_3E04(static_cast<char*>(object) + 0x1528, memberDeleting);
        fn_114_20598(static_cast<char*>(object) + 0x1340, memberDeleting);
        fn_114_41F0(static_cast<char*>(object) + 0x129C, memberDeleting);
        fn_114_4324(static_cast<char*>(object) + 0x1268, memberDeleting);
        fn_114_43E4(static_cast<char*>(object) + 0x1250, memberDeleting);
        fn_114_4440(static_cast<char*>(object) + 0x10EC, memberDeleting);
        fn_114_44AC(static_cast<char*>(object) + 0x1084, memberDeleting);
        fn_114_450C(static_cast<char*>(object) + 0x1078, memberDeleting);
        fn_114_456C(static_cast<char*>(object) + 0x1050, memberDeleting);
        fn_114_45C8(static_cast<char*>(object) + 0xE80, memberDeleting);
        fn_114_464C(static_cast<char*>(object) + 0xE1C, memberDeleting);
        fn_114_4718(static_cast<char*>(object) + 0xDE0, memberDeleting);
        fn_114_47E0(static_cast<char*>(object) + 0xD28, memberDeleting);
        fn_114_206F0(static_cast<char*>(object) + 0xB1C, memberDeleting);
        fn_114_48DC(static_cast<char*>(object) + 0x93C, memberDeleting);
        fn_114_4948(static_cast<char*>(object) + 0x90C, memberDeleting);
        fn_114_4A00(static_cast<char*>(object) + 0x8FC, memberDeleting);
        fn_114_4A40(static_cast<char*>(object) + 0x8E4, memberDeleting);
        __dt__16soModuleAccesserFv(static_cast<char*>(object) + 0x804, memberDeleting);
        fn_114_20768(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
