#include <new>
#pragma force_active on

extern "C" {
void* fn_98_3370(char*, short);
void* fn_98_3508(char*, short);
}

extern "C" void* fn_98_32F4(char* obj, short deleting) {
    if (obj) {
        fn_98_3370(obj + 0x1cb4c, short(-1));
        if (obj) fn_98_3508(obj, short(0));
        if (deleting > 0) operator delete(obj);
    }
    return obj;
}
