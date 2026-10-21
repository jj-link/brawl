#include <new>
#pragma force_active on

extern "C" {
void* fn_98_1A54(void*, short);
void* fn_98_1B14(void*, short);
void* fn_98_1B70(void*, short);
void* fn_98_1BCC(void*, short);
void* fn_98_1C28(void*, short);
void* fn_98_1C84(void*, short);
void* fn_98_1CE0(void*, short);
void* fn_98_1D3C(void*, short);
}

extern "C" void* fn_98_199C(void* object, short deleting) {
    if (object != 0) {
        char* members = static_cast<char*>(object);
        short memberDeleting = -1;
        fn_98_1A54(members + 0x84, memberDeleting);
        fn_98_1B14(members + 0x70, memberDeleting);
        fn_98_1B70(members + 0x5C, memberDeleting);
        fn_98_1BCC(members + 0x48, memberDeleting);
        fn_98_1C28(members + 0x34, memberDeleting);
        fn_98_1C84(members + 0x20, memberDeleting);
        fn_98_1CE0(members + 0x8, memberDeleting);
        fn_98_1D3C(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
