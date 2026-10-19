#include <new>
#pragma force_active on

extern "C" {
void* fn_105_2028(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_105_28E0(void*, short);

void* fn_105_1FA4(char* object, short deleting) {
    if (object) {
        short memberDeleting = -1;
        fn_105_2028(object + 0x1e11c, memberDeleting);
        fn_27_C74E8(object + 0x1e10c, memberDeleting);
        fn_105_28E0(object, short(0));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
}
