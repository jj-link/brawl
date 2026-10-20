#include <new>
#pragma force_active on

extern "C" {
void* fn_27_B5324(void*, short);
void* fn_98_6C08(void*, short);
void* fn_98_6C68(void*, short);
}

extern "C" void* fn_98_6B90(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_27_B5324(object + 0x30, memberDeleting);
        fn_98_6C08(object + 0x18, memberDeleting);
        fn_98_6C68(object + 0x4, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
