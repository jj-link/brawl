#include <new>
#pragma force_active on

extern "C" {
void* fn_98_5528(void*, short);
void* fn_98_5588(void*, short);

void* fn_98_54BC(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_5528(object + 0x3fa0, memberDeleting);
        fn_98_5588(object + 4, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
