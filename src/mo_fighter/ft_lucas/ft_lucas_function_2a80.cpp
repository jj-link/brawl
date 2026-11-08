#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_114_2D2C(void*, short);
void* fn_114_2D88(void*, short);
void* fn_114_2DE4(void*, short);
void* fn_114_2E40(void*, short);
void* fn_114_2E9C(void*, short);
void* fn_114_2EF8(void*, short);
void* fn_114_2FD4(void*, short);
void* fn_114_3030(void*, short);
void* fn_114_308C(void*, short);
void* fn_114_3100(void*, short);
void* fn_114_3198(void*, short);
void* fn_114_31F4(void*, short);
void* fn_114_3344(void*, short);
void* fn_114_4324(void*, short);
void* fn_114_4718(void*, short);
void* fn_114_4774(void*, short);
void* fn_114_47E0(void*, short);
void* fn_114_4A40(void*, short);
void* fn_114_6CC4(void*, short);
void* fn_114_6D24(void*, short);
void* fn_114_6E78(void*, short);
void* fn_114_79E8(void*, short);
void* fn_114_7AC4(void*, short);
void* fn_114_7B38(void*, short);
void* fn_114_7C14(void*, short);
void* fn_114_7C70(void*, short);
void* fn_114_7CDC(void*, short);
void* fn_114_7D88(void*, short);
void* fn_114_7DFC(void*, short);
void* fn_114_7E58(void*, short);
void* fn_114_7EB4(void*, short);
void* fn_114_7F10(void*, short);
void* fn_114_7F6C(void*, short);
void* fn_114_7FE0(void*, short);
void* fn_114_804C(void*, short);
void* fn_114_80DC(void*, short);
void* fn_114_816C(void*, short);
void* fn_114_81FC(void*, short);
void* fn_114_8280(void*, short);
void* fn_114_8304(void*, short);
void* fn_114_8438(void*, short);
void* fn_114_87FC(void*, short);
void* fn_114_88D0(void*, short);
void* fn_114_8948(void*, short);
void* fn_114_89A4(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
}

extern "C" void* fn_114_2A80(void* object, short deleting) {
    if (object != 0) {
        unsigned char* members = static_cast<unsigned char*>(object);
        short memberDeleting = -1;
        fn_114_2D2C(members + 0x46DFC, memberDeleting);
        fn_114_2D88(members + 0x46DC0, memberDeleting);
        fn_114_2DE4(members + 0x46D58, memberDeleting);
        fn_114_2E40(members + 0x46D0C, memberDeleting);
        fn_114_2E9C(members + 0x46BB8, memberDeleting);
        fn_114_2EF8(members + 0x46AA8, memberDeleting);
        fn_114_2FD4(members + 0x46A60, memberDeleting);
        fn_114_3030(members + 0x469E0, memberDeleting);
        fn_114_308C(members + 0x4691C, memberDeleting);
        fn_114_3100(members + 0x465A8, memberDeleting);
        fn_114_3198(members + 0x46578, memberDeleting);
        fn_114_31F4(members + 0x463D4, memberDeleting);
        fn_114_3344(members + 0x5BC0, memberDeleting);
        fn_114_6CC4(members + 0x59DC, memberDeleting);
        fn_114_6D24(members + 0x56D4, memberDeleting);
        fn_114_6E78(members + 0x484C, memberDeleting);
        fn_114_79E8(members + 0x4758, memberDeleting);
        fn_114_4324(members + 0x4724, memberDeleting);
        fn_114_7AC4(members + 0x46B0, memberDeleting);
        fn_114_7B38(members + 0x3F8C, memberDeleting);
        fn_114_7C14(members + 0x3F5C, memberDeleting);
        fn_114_7C70(members + 0x3D90, memberDeleting);
        fn_114_7CDC(members + 0x3D20, memberDeleting);
        fn_114_7D88(members + 0x3C88, memberDeleting);
        fn_114_7DFC(members + 0x3C50, memberDeleting);
        fn_114_7E58(members + 0x3C2C, memberDeleting);
        fn_114_7EB4(members + 0x3BF8, memberDeleting);
        fn_114_7F10(members + 0x3B94, memberDeleting);
        fn_114_7F6C(members + 0x39E4, memberDeleting);
        fn_114_7FE0(members + 0x3780, memberDeleting);
        fn_114_804C(members + 0x3568, memberDeleting);
        fn_114_80DC(members + 0x2C10, memberDeleting);
        fn_114_816C(members + 0x29F8, memberDeleting);
        fn_114_81FC(members + 0x209C, memberDeleting);
        fn_114_8280(members + 0x19E0, memberDeleting);
        fn_114_8304(members + 0x196C, memberDeleting);
        fn_114_4718(members + 0x1930, memberDeleting);
        fn_114_4774(members + 0x1888, memberDeleting);
        fn_114_47E0(members + 0x17D4, memberDeleting);
        fn_114_8438(members + 0x1440, memberDeleting);
        fn_114_87FC(members + 0x1180, memberDeleting);
        fn_114_88D0(members + 0x115C, memberDeleting);
        fn_114_8948(members + 0xAC8, memberDeleting);
        fn_114_4A40(members + 0xAB0, memberDeleting);
        __dt__16soModuleAccesserFv(members + 0x9D0, memberDeleting);
        fn_114_89A4(object, memberDeleting);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
