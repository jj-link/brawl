#include <new>
#pragma force_active on

extern "C" {
void* fn_98_42F8(void*, short);
void* fn_27_D2AA4(void*, short);
void* fn_27_CD934(void*, short);
}

extern "C" void* fn_98_49EC(void* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_42F8(static_cast<char*>(object) + 0x6c, memberDeleting);
        void* ptr = static_cast<char*>(object) + 0x20;
        if (ptr) if (ptr) if (ptr) fn_27_D2AA4(ptr, memberDeleting);
        fn_27_CD934(object, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
