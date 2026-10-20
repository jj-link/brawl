#include <new>
#pragma force_active on

extern "C" void* fn_27_75E0C(void*, short);
extern "C" void* fn_27_64930(void*, short);
extern "C" void* fn_98_1E98(void*, short);

extern "C" void* fn_98_418C(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_27_75E0C(object + 0x4C, memberDeleting);
        char* ptr = object + 0x20;
        if (ptr) fn_27_64930(ptr, 0);
        fn_98_1E98(object + 0x14, 0);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
