#include <types.h>
#pragma force_active on

void operator delete(void*);

extern "C" {
void fn_114_3BC4(void*, short);
void fn_114_3C20(void*, short);
void fn_114_3C7C(void*, short);
void fn_114_3D08(void*, short);
void fn_114_1DF38(void*, short);
void fn_114_1E010(void*, short);
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
void fn_114_5A94(void*, short);
void fn_114_1E0AC(void*, short);
void fn_114_4948(void*, short);
void fn_114_4A00(void*, short);
void fn_114_4A40(void*, short);
void __dt__16soModuleAccesserFv(void*, short);
void fn_114_1E118(void*, short);
}

extern "C" void* fn_114_1DDC4(void* object, short deleting) {
    void* result = object;
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_114_3BC4(members + 0x149C, memberDeleting);
        fn_114_3C20(members + 0x1484, memberDeleting);
        fn_114_3C7C(members + 0x12E8, memberDeleting);
        fn_114_3D08(members + 0x1288, memberDeleting);
        fn_114_1DF38(members + 0x121C, memberDeleting);
        fn_114_1E010(members + 0x105C, memberDeleting);
        fn_114_41F0(members + 0xFB8, memberDeleting);
        fn_114_4324(members + 0xF84, memberDeleting);
        fn_114_43E4(members + 0xF6C, memberDeleting);
        fn_114_4440(members + 0xE08, memberDeleting);
        fn_114_44AC(members + 0xDA0, memberDeleting);
        fn_114_450C(members + 0xD94, memberDeleting);
        fn_114_456C(members + 0xD6C, memberDeleting);
        fn_114_45C8(members + 0xB9C, memberDeleting);
        fn_114_464C(members + 0xB38, memberDeleting);
        fn_114_4718(members + 0xAFC, memberDeleting);
        fn_114_47E0(members + 0xA44, memberDeleting);
        fn_114_5A94(members + 0x838, memberDeleting);
        fn_114_1E0AC(members + 0x6F4, memberDeleting);
        fn_114_4948(members + 0x6C4, memberDeleting);
        fn_114_4A00(members + 0x6B4, memberDeleting);
        fn_114_4A40(members + 0x69C, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x5BC, memberDeleting);
        fn_114_1E118(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return result;
}
