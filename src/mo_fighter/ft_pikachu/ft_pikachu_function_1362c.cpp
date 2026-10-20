#include <new>
#pragma force_active on

extern "C" {
void* fn_98_38F0(void*, short);
void* fn_27_1DBB60(void*, short);
void* fn_98_136B4(void*, short);
void* fn_27_1D81C8(void*, short);
}

extern "C" void* fn_98_1362C(void* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_38F0(static_cast<char*>(object) + 0x2138, memberDeleting);
        fn_27_1DBB60(static_cast<char*>(object) + 0x2100, memberDeleting);
        fn_98_136B4(static_cast<char*>(object) + 0xcc, memberDeleting);
        fn_27_1D81C8(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
