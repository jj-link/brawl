#include <new>
#pragma force_active on

extern "C" {
void* fn_98_5528(void*, short);
void* fn_98_55F4(void*, short);

void* fn_98_5588(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_98_5528(object + 0x1fd4, memberDeleting);
        fn_98_55F4(object + 4, memberDeleting);
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
